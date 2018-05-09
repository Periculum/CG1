#include "CgPolyline.h"
#include "CgTriangle.h"

#include "CgBase/CgEnums.h"

CgPolyline::CgPolyline(unsigned int id, glm::vec3 start, glm::vec3 end, glm::vec3 color, unsigned int lineWidth):
    m_id(id),
    m_type(Cg::Polyline)
{
    m_verticies.push_back(start);
    m_verticies.push_back(end);
    m_color = color;
    m_lineWidth = lineWidth;
}

CgPolyline::~CgPolyline(){
    m_verticies.clear();
}

const std::vector<glm::vec3>& CgPolyline::getVertices() const{
    return m_verticies;
}

glm::vec3 CgPolyline::getColor() const{
    return m_color;
}

unsigned int CgPolyline::getLineWidth() const{
    return m_lineWidth;
}

void CgPolyline::setColor(glm::vec3 color){
    m_color = color;
}
