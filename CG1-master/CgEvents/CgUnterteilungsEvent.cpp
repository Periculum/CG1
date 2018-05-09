#include "CgUnterteilungsEvent.h"
#include "CgBase/CgEnums.h"

CgUnterteilungsEvent::CgUnterteilungsEvent(int schritt, int mittel):
m_type(Cg::CgUnterteilungsEvent)
{
    m_schritt = schritt;
    m_mittel = mittel;
}

CgUnterteilungsEvent::~CgUnterteilungsEvent(){

}

Cg::EventType CgUnterteilungsEvent::getType()
{
    return m_type;
}

CgBaseEvent* CgUnterteilungsEvent::clone()
{
    return new CgUnterteilungsEvent(m_schritt, m_mittel);
}

std::ostream& operator <<(std::ostream& os, const CgUnterteilungsEvent& e){

    os << "slider bewegt sich mit "<< e.m_schritt  << std::endl;
    return os;
}

