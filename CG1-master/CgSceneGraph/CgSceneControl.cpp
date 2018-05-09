#include "CgSceneControl.h"
#include "CgBase/CgEnums.h"
#include "CgEvents/CgMouseEvent.h"
#include "CgEvents/CgKeyEvent.h"
#include "CgEvents/CgWindowResizeEvent.h"
#include "CgEvents/CgColorChangedEvent.h"
#include "CgEvents/CgUnterteilungsEvent.h"
#include "CgBase/CgBaseRenderer.h"
#include "CgTriangle.h"
#include "CgPolyline.h"
#include "CgCylinder.h"
#include "CgKegel.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

CgSceneControl::CgSceneControl()
{
     /*m_triangle = new CgTriangle(21);

     m_polyline1= new CgPolyline(14568, m_triangle->getFaceNormals().at(0), m_triangle->getFaceNormals().at(0)+ m_triangle->getVertexNormals().at(0), glm::vec3(1,0,0), 5);
     m_polyline2= new CgPolyline(14569, m_triangle->getFaceNormals().at(1), m_triangle->getFaceNormals().at(1)+ m_triangle->getVertexNormals().at(1), glm::vec3(1,0,0), 5);
     m_polyline3= new CgPolyline(14570, m_triangle->getFaceNormals().at(2), m_triangle->getFaceNormals().at(2)+ m_triangle->getVertexNormals().at(2), glm::vec3(1,0,0), 5);
     m_polyline4= new CgPolyline(14571, m_triangle->getFaceNormals().at(3), m_triangle->getFaceNormals().at(3)+ m_triangle->getVertexNormals().at(3), glm::vec3(1,0,0), 5);
     m_polyline5= new CgPolyline(14572, m_triangle->getFaceNormals().at(4), m_triangle->getFaceNormals().at(4)+ m_triangle->getVertexNormals().at(4), glm::vec3(1,0,0), 5);
     m_polyline6= new CgPolyline(14573, m_triangle->getFaceNormals().at(5), m_triangle->getFaceNormals().at(5)+ m_triangle->getVertexNormals().at(5), glm::vec3(1,0,0), 5);
     m_polyline7= new CgPolyline(14574, m_triangle->getFaceNormals().at(6), m_triangle->getFaceNormals().at(6)+ m_triangle->getVertexNormals().at(6), glm::vec3(1,0,0), 5);
     m_polyline8= new CgPolyline(14575, m_triangle->getFaceNormals().at(7), m_triangle->getFaceNormals().at(7)+ m_triangle->getVertexNormals().at(7), glm::vec3(1,0,0), 5);
     m_polyline9= new CgPolyline(14576, m_triangle->getFaceNormals().at(8), m_triangle->getFaceNormals().at(8)+ m_triangle->getVertexNormals().at(8), glm::vec3(1,0,0), 5);
     m_polyline10= new CgPolyline(14577, m_triangle->getFaceNormals().at(9), m_triangle->getFaceNormals().at(9)+ m_triangle->getVertexNormals().at(9), glm::vec3(1,0,0), 5);
     m_polyline11= new CgPolyline(14578, m_triangle->getFaceNormals().at(10), m_triangle->getFaceNormals().at(10)+ m_triangle->getVertexNormals().at(10), glm::vec3(1,0,0), 5);
     m_polyline12= new CgPolyline(14579, m_triangle->getFaceNormals().at(11), m_triangle->getFaceNormals().at(11)+ m_triangle->getVertexNormals().at(11), glm::vec3(1,0,0), 5);
    */ //cube mit normalen

     //m_cylinder = new CgCylinder(1,10,5,0.5); //cylinder

     //m_kegel = new CgKegel(1,10,5,0.5); //Kegel

    m_polyline1 = new CgPolyline(1,glm::vec3(-0.4,0.4,0), glm::vec3(-0.1,0.1,0),glm::vec3(0,0,1),2);


     m_current_transformation=glm::mat4(1.);
     m_proj_matrix= glm::mat4x4(glm::vec4(1.792591, 0.0, 0.0, 0.0), glm::vec4(0.0, 1.792591, 0.0, 0.0), glm::vec4(0.0, 0.0, -1.0002, -1.0), glm::vec4(0.0, 0.0, -0.020002, 0.0));

}


CgSceneControl::~CgSceneControl()
{
    /*delete m_triangle;

    delete m_polyline2;
    delete m_polyline3;
    delete m_polyline4;
    delete m_polyline5;
    delete m_polyline6;
    delete m_polyline7;
    delete m_polyline8;
    delete m_polyline9;
    delete m_polyline10;
    delete m_polyline11;
    delete m_polyline12;*/

    delete m_polyline1;

   // delete m_cylinder;

   // delete m_kegel;


}

void CgSceneControl::setRenderer(CgBaseRenderer* r)
{
    m_renderer=r;
    m_renderer->setSceneControl(this);

    /*m_renderer->init(m_triangle);

    m_renderer->init(m_polyline2);
    m_renderer->init(m_polyline3);
    m_renderer->init(m_polyline4);
    m_renderer->init(m_polyline5);
    m_renderer->init(m_polyline6);
    m_renderer->init(m_polyline7);
    m_renderer->init(m_polyline8);
    m_renderer->init(m_polyline9);
    m_renderer->init(m_polyline10);
    m_renderer->init(m_polyline11);
    m_renderer->init(m_polyline12);*/

    //m_renderer->init(m_cylinder);

    m_renderer->init(m_polyline1);

    //m_renderer->init(m_kegel);
}


void CgSceneControl::renderObjects()
{
    m_renderer->setProjectionMatrix(m_proj_matrix);
    m_renderer->setLookAtMatrix(glm::mat4x4(glm::vec4(1.0, 0.0, 0.0, 0.0), glm::vec4(0.0, 1.0, 0.0, 0.0), glm::vec4(0.0, 0.0, 1.0, -1.0), glm::vec4(0.0, 0.0, -1.0, 1.0)));

    /*m_renderer->render(m_triangle,m_current_transformation);

    m_renderer->render(m_polyline2,m_current_transformation);
    m_renderer->render(m_polyline3,m_current_transformation);
    m_renderer->render(m_polyline4,m_current_transformation);
    m_renderer->render(m_polyline5,m_current_transformation);
    m_renderer->render(m_polyline6,m_current_transformation);
    m_renderer->render(m_polyline7,m_current_transformation);
    m_renderer->render(m_polyline8,m_current_transformation);
    m_renderer->render(m_polyline9,m_current_transformation);
    m_renderer->render(m_polyline10,m_current_transformation);
    m_renderer->render(m_polyline11,m_current_transformation);
    m_renderer->render(m_polyline12,m_current_transformation);*/

    //m_renderer->render(m_cylinder,m_current_transformation);

    m_renderer->render(m_polyline1,m_current_transformation);

    //m_renderer->render(m_kegel, m_current_transformation);
}



void CgSceneControl::handleEvent(CgBaseEvent* e)
{
    // die Enums sind so gebaut, dass man alle Arten von MausEvents über CgEvent::CgMouseEvent abprüfen kann,
    // siehe dazu die CgEvent enums im CgEnums.h


    if(e->getType() & Cg::CgMouseEvent)
    {
        CgMouseEvent* ev = (CgMouseEvent*)e;
        std::cout << *ev << std::endl;

         // hier kommt jetzt die Abarbeitung des Events hin...
    }

    // die Enums sind so gebaut, dass man alle Arten von KeyEvents über CgEvent::CgKeyEvent abprüfen kann,
    // siehe dazu die CgEvent enums im CgEnums.h
    // momentan werden nur KeyPressEvents gefangen.

    if(e->getType() & Cg::CgKeyEvent)
    {
        CgKeyEvent* ev = (CgKeyEvent*)e;
        std::cout << *ev <<std::endl;

        // hier kommt jetzt die Abarbeitung des Events hin...
    }

    if(e->getType() & Cg::WindowResizeEvent)
    {
         CgWindowResizeEvent* ev = (CgWindowResizeEvent*)e;
         std::cout << *ev <<std::endl;
         m_proj_matrix=glm::perspective(45.0f, (float)(ev->w()) / ev->h(), 0.01f, 100.0f);
    }

    if(e->getType() & Cg::CgColorChangedEvent)
    {
        CgColorChangedEvent* ev = (CgColorChangedEvent*)e;
        std::cout << *ev <<std::endl;
        m_polyline1->setColor(ev->getColor());
        m_polyline2->setColor(ev->getColor());
        m_polyline3->setColor(ev->getColor());
        m_polyline4->setColor(ev->getColor());
        m_polyline5->setColor(ev->getColor());
        m_polyline6->setColor(ev->getColor());
        m_polyline7->setColor(ev->getColor());
        m_polyline8->setColor(ev->getColor());
        m_polyline9->setColor(ev->getColor());
        m_polyline10->setColor(ev->getColor());
        m_polyline11->setColor(ev->getColor());
        m_polyline12->setColor(ev->getColor());
        m_renderer->redraw();

    }

    if(e->getType() & Cg::CgUnterteilungsEvent)
    {
         CgUnterteilungsEvent* ev = (CgUnterteilungsEvent*)e;
         std::cout << *ev <<std::endl;


    }


    // an der Stelle an der ein Event abgearbeitet ist wird es auch gelöscht.
    delete e;


}
