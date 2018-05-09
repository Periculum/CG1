#ifndef CGSCENECONTROL_H
#define CGSCENECONTROL_H

#include <vector>
#include "CgBase/CgObserver.h"
#include "CgBase/CgBaseSceneControl.h"
#include <glm/glm.hpp>

class CgBaseEvent;
class CgBaseRenderer;
class CgTriangle;
class CgPolyline;
class CgCylinder;
class CgKegel;

class CgSceneControl : public CgObserver, public CgBaseSceneControl
{
public:
    CgSceneControl();
    ~CgSceneControl();
    void handleEvent(CgBaseEvent* e);
    void setRenderer(CgBaseRenderer* r);

    void renderObjects();

private:

    CgBaseRenderer* m_renderer;

    CgTriangle* m_triangle;
    CgPolyline *m_polyline1;
    CgPolyline *m_polyline2;
    CgPolyline *m_polyline3;
    CgPolyline *m_polyline4;
    CgPolyline *m_polyline5;
    CgPolyline *m_polyline6;
    CgPolyline *m_polyline7;
    CgPolyline *m_polyline8;
    CgPolyline *m_polyline9;
    CgPolyline *m_polyline10;
    CgPolyline *m_polyline11;
    CgPolyline *m_polyline12;

    CgCylinder *m_cylinder;

    CgKegel *m_kegel;

    std::vector<CgPolyline*> v_polyline;
    glm::mat4 m_current_transformation;
    glm::mat4 m_proj_matrix;

};

#endif // CGSCENECONTROL_H
