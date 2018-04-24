#include "CgSceneControl.h"
#include "CgBase/CgEnums.h"
#include "CgEvents/CgMouseEvent.h"
#include "CgEvents/CgKeyEvent.h"
#include "CgEvents/CgWindowResizeEvent.h"
#include "CgEvents/CgColorChangedEvent.h"
#include "CgBase/CgBaseRenderer.h"
#include "CgTriangle.h"
#include "CgPolyline.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

CgSceneControl::CgSceneControl()
{
     //m_triangle=new CgExampleTriangle(21,true);
     m_triangle = new CgTriangle(21);

     m_polyline = new CgPolyline(14568, glm::vec3(0,0,0), glm::vec3(0,1,0), glm::vec3(1,0,0), 10);

     m_current_transformation=glm::mat4(1.);
     m_proj_matrix= glm::mat4x4(glm::vec4(1.792591, 0.0, 0.0, 0.0), glm::vec4(0.0, 1.792591, 0.0, 0.0), glm::vec4(0.0, 0.0, -1.0002, -1.0), glm::vec4(0.0, 0.0, -0.020002, 0.0));

}


CgSceneControl::~CgSceneControl()
{
     delete m_triangle;
    delete m_polyline;
}

void CgSceneControl::setRenderer(CgBaseRenderer* r)
{
    m_renderer=r;
    m_renderer->setSceneControl(this);

    m_renderer->init(m_triangle);
    m_renderer->init(m_polyline);
}


void CgSceneControl::renderObjects()
{
    m_renderer->setProjectionMatrix(m_proj_matrix);
    m_renderer->setLookAtMatrix(glm::mat4x4(glm::vec4(1.0, 0.0, 0.0, 0.0), glm::vec4(0.0, 1.0, 0.0, 0.0), glm::vec4(0.0, 0.0, 1.0, -1.0), glm::vec4(0.0, 0.0, -1.0, 1.0)));

    m_renderer->render(m_triangle,m_current_transformation);
    m_renderer->render(m_polyline,m_current_transformation);

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
        m_polyline->setColor(ev->getColor());
        m_renderer->redraw();

    }


    // an der Stelle an der ein Event abgearbeitet ist wird es auch gelöscht.
    delete e;


}
