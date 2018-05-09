


#include "CgQtGLRenderWidget.h"
#include "CgQtGui.h"
#include "CgQtMainApplication.h"
#include "../CgBase/CgEnums.h"
#include "../CgEvents/CgMouseEvent.h"
#include "../CgEvents/CgKeyEvent.h"
#include "../CgEvents/CgWindowResizeEvent.h"
#include "../CgEvents/CgColorChangedEvent.h"
#include "../CgEvents/CgUnterteilungsEvent.h"
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>
#include <QMessageBox>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QMenuBar>
#include <QActionGroup>
#include <iostream>



CgQtGui::CgQtGui(CgQtMainApplication *mw)
    : m_mainWindow(mw)
{
    m_glRenderWidget = new CgQtGLRenderWidget;

    connect(m_glRenderWidget, SIGNAL(mouseEvent(QMouseEvent*)), this, SLOT(mouseEvent(QMouseEvent*)));
    connect(m_glRenderWidget, SIGNAL(viewportChanged(int,int)), this, SLOT(viewportChanged(int,int)));


    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *container = new QHBoxLayout;


    QWidget *opt = new QWidget;
    createOptionPanelExample1(opt);

    QWidget *otheropt = new QWidget;
    createOptionPanelExample2(otheropt);

    QWidget *slide_color = new QWidget;
    createOptionPanelExample3(slide_color);

    QWidget *lane = new QWidget;
    createOptionPanelExample4(lane);

    QTabWidget* m_tabs = new QTabWidget();      //Tabs hinzufügen
    m_tabs->addTab(opt,"&My Tab1");
    m_tabs->addTab(otheropt,"&My Tab2");
    m_tabs->addTab(slide_color, "&Farbe");
    m_tabs->addTab(lane,"&Lane");
    container->addWidget(m_tabs);

    m_tabs->setMaximumWidth(400);

    container->addWidget(m_glRenderWidget);

    QWidget *w = new QWidget;
    w->setLayout(container);
    mainLayout->addWidget(w);

    setLayout(mainLayout);
    setWindowTitle(tr("Übung Computergrafik 1 -  SoSe 2018"));


    /* create Menu Bar */
    m_menuBar = new QMenuBar;
    QMenu *file_menu = new QMenu("&File" );
    file_menu->addAction("&Open Mesh Model", this, SLOT(slotLoadMeshFile()));
    // todo: Add Quit-Action
    m_menuBar->addMenu( file_menu );
    QMenu *settings_menu = new QMenu("&Setting" );
    QMenu *polygon_mode_menu = new QMenu("&Polygon Mode" );

    QAction* m_custom_rot=settings_menu->addAction("&Custom Rotations", m_glRenderWidget, SLOT(slotCustomRotation()));
    m_custom_rot->setCheckable(true);
    m_custom_rot->setChecked(false);

    QAction* m_lighting=settings_menu->addAction("&Lighting on", m_glRenderWidget, SLOT(slotLighting()));
    m_lighting->setCheckable(true);
    m_lighting->setChecked(false);


    QActionGroup* polygonmode_group = new QActionGroup(this);
    polygonmode_group->setExclusive(true);

    QAction* points=polygon_mode_menu->addAction("&Points", m_glRenderWidget, SLOT(slotPolygonPoints()));
    points->setCheckable(true);
    points->setChecked(false);


    QAction* wireframe=polygon_mode_menu->addAction("&Wireframe", m_glRenderWidget, SLOT(slotPolygonWireframe()));
    wireframe->setCheckable(true);
    wireframe->setChecked(true);

    QAction* filled=polygon_mode_menu->addAction("&Filled", m_glRenderWidget, SLOT(slotPolygonFilled()));
    filled->setCheckable(true);
    filled->setChecked(false);

void createOptionPanelExample3(QWidget* panel);

    polygonmode_group->addAction(points);
    polygonmode_group->addAction(wireframe);
    polygonmode_group->addAction(filled);



    // todo: Add Quit-Action
    m_menuBar->addMenu( file_menu );
    m_menuBar->addMenu( settings_menu );
    m_menuBar->addMenu( polygon_mode_menu );


    m_mainWindow->setMenuBar(m_menuBar);

}

QSlider *CgQtGui::createSlider()
{
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 255);
    slider->setSingleStep(16);
    slider->setPageStep(15 * 16);
    slider->setTickInterval(15 * 16);
    slider->setTickPosition(QSlider::TicksRight);
    connect(slider, SIGNAL( sliderMoved(int)) , this, SLOT(slotMySliderChanged()));
    return slider;
}

QSlider *CgQtGui::createLaneSlider()
{
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 40);
    slider->setSingleStep(16);
    slider->setPageStep(15 * 16);
    slider->setTickInterval(15 * 16);
    slider->setTickPosition(QSlider::TicksRight);
    connect(slider, SIGNAL( sliderMoved(int)) , this, SLOT(slotMySliderLaneChanged()));
    return slider;
}








void CgQtGui::createOptionPanelExample1(QWidget* parent)
{
    QVBoxLayout *tab1_control = new QVBoxLayout();


    /*Example for using a label */

    QLabel *options_label = new QLabel("Options");
    tab1_control->addWidget(options_label);
    options_label->setAlignment(Qt::AlignCenter);


    /*Example for using a spinbox */

    mySpinBox1 = new QSpinBox();
    tab1_control->addWidget(mySpinBox1);
    mySpinBox1->setMinimum(1);
    mySpinBox1->setMaximum(50);
    mySpinBox1->setValue(3);
   // mySpinBox1->setSuffix("   suffix");
   // mySpinBox1->setPrefix("Prefix:  ");
    connect(mySpinBox1, SIGNAL(valueChanged(int) ), this, SLOT(slotMySpinBox1Changed()) );
    tab1_control->addWidget(mySpinBox1);


    /*Example for using a checkbox */

    myCheckBox1 = new QCheckBox("enable Option 1");
    myCheckBox1->setCheckable(true);
    myCheckBox1->setChecked(false);
    connect(myCheckBox1, SIGNAL( clicked() ), this, SLOT(slotMyCheckBox1Changed()) );
    tab1_control->addWidget(myCheckBox1);


    /*Example for using a button */

    QPushButton* myButton1 = new QPushButton("&Button"
                                             "");
    tab1_control->addWidget(myButton1);

    connect(myButton1, SIGNAL( clicked() ), this, SLOT(slotMyButton1Pressed()) );



    parent->setLayout(tab1_control);

}

void CgQtGui::createOptionPanelExample2(QWidget* parent)
{


    QVBoxLayout *tab2_control = new QVBoxLayout();
    QHBoxLayout *subBox = new QHBoxLayout();



    /*Example for using a button group */

    QGroupBox* myGroupBox = new QGroupBox("Radiobutton Group Example ");

    myButtonGroup = new QButtonGroup(subBox);
    myButtonGroup->setExclusive(true);

    QRadioButton* radiobutton1 = new QRadioButton( "&Option1");
    QRadioButton* radiobutton2 = new QRadioButton( "&Option2");
    QRadioButton* radiobutton3 = new QRadioButton( "&Option3");
    QRadioButton* radiobutton4 = new QRadioButton( "&Option4");
    QRadioButton* radiobutton5 = new QRadioButton( "&Option5");

    radiobutton2->setChecked(true);

    myButtonGroup->addButton(radiobutton1,0);
    myButtonGroup->addButton(radiobutton2,1);
    myButtonGroup->addButton(radiobutton3,2);
    myButtonGroup->addButton(radiobutton4,3);
    myButtonGroup->addButton(radiobutton5,4);


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radiobutton1);
    vbox->addWidget(radiobutton2);
    vbox->addWidget(radiobutton3);
    vbox->addWidget(radiobutton4);
    vbox->addWidget(radiobutton5);
    vbox->addStretch(1);
    myGroupBox->setLayout(vbox);
    subBox->addWidget(myGroupBox);
    tab2_control->addLayout(subBox);

    connect(myButtonGroup, SIGNAL( buttonClicked(int) ), this, SLOT( slotButtonGroupSelectionChanged() ) );
    parent->setLayout(tab2_control);

}

void CgQtGui::createOptionPanelExample3(QWidget* parent)
{
    QVBoxLayout *tab3_control = new QVBoxLayout();  //Layout erstellenQSlider *CgQtGui::createLaneSlider()

    QLabel *options_label = new QLabel("Slider");   //Name erstellen
    tab3_control->addWidget(options_label);
    options_label->setAlignment(Qt::AlignTop);

    mySlider = createSlider();   //slider
    mySlider1 = createSlider();
    mySlider2 = createSlider();
    tab3_control->addWidget(mySlider);
    tab3_control->addWidget(mySlider1);
    tab3_control->addWidget(mySlider2);

    parent->setLayout(tab3_control);

}

void CgQtGui::createOptionPanelExample4(QWidget* parent)
{
    QVBoxLayout *tab4_control = new QVBoxLayout();  //Layout erstellen

    QLabel *options_label = new QLabel("Rotationskörper und Glättung");   //Name erstellen
    tab4_control->addWidget(options_label);
    options_label->setAlignment(Qt::AlignTop);

    myLaneSlider = createLaneSlider();
    tab4_control->addWidget(myLaneSlider);


    parent->setLayout(tab4_control);

}



void CgQtGui::slotButtonGroupSelectionChanged()
{

}

void CgQtGui::slotMySpinBox1Changed()
{

}

void CgQtGui::slotMyCheckBox1Changed()
{

}


void CgQtGui::slotLoadMeshFile()
{
    std::cout << "load Mesh file callback reached, but not implemented..." << std::endl;
    // Hier FileChooser öffnen, datei selektieren
    // und dann neuen Event implementieren, der das an den Controller schickt.
    // dort wird dann die Datei tatsächliche geöffnet und ein entsprechendes Mesh Objekt angelegt
    // im View(GUI) passiert nichts außer festellung DASS geladen werden soll und welche Datei und zu welchem Zweck (Mesh)
}

void CgQtGui::slotMyButton1Pressed()
{
   std::cout << "button 1 pressed " << std::endl;

}

void CgQtGui::slotMySliderChanged()
{
    CgBaseEvent* e = new CgColorChangedEvent((mySlider->value())/255.0,(mySlider1->value())/255.0,(mySlider2->value())/255.0);

    notifyObserver(e);

}

void CgQtGui::slotMySliderLaneChanged()
{
    CgBaseEvent* e = new CgUnterteilungsEvent((myLaneSlider->value()), 2);

    notifyObserver(e);

}




void CgQtGui::mouseEvent(QMouseEvent* event)
{

   // std::cout << QApplication::keyboardModifiers() << std::endl;

  //  if(QApplication::keyboardModifiers().testFlag(Qt::ControlModifier)==true)
    //    std::cout << Cg::ControlModifier << endl;


   if(event->type()==QEvent::MouseButtonPress)
   {


        CgBaseEvent* e = new CgMouseEvent(Cg::CgMouseButtonPress,
                                          glm::vec2(event->localPos().x() ,event->localPos().y()),
                                          (Cg::MouseButtons)event->button());

        notifyObserver(e);
   }

   if(event->type()==QEvent::MouseMove)
   {
       CgBaseEvent* e= new CgMouseEvent(Cg::CgMouseMove,
                                        glm::vec2(event->localPos().x() ,event->localPos().y()),
                                        (Cg::MouseButtons)event->button());
       notifyObserver(e);
   }



}

void CgQtGui::keyPressEvent(QKeyEvent *event)
{
   CgBaseEvent* e= new CgKeyEvent(Cg::CgKeyPressEvent,(Cg::Key)event->key(),(Cg::KeyboardModifiers)event->nativeModifiers(),event->text().toStdString());
   notifyObserver(e);
}


void CgQtGui::viewportChanged(int w, int h)
{
     CgBaseEvent* e = new CgWindowResizeEvent(Cg::WindowResizeEvent,w,h);
     notifyObserver(e);
}


CgBaseRenderer* CgQtGui::getRenderer()
{
    return m_glRenderWidget;
}



