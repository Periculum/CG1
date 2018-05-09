#ifndef CGUNTERTEILUNGSEVENT_H
#define CGUNTERTEILUNGSEVENT_H

#include "CgBase/CgBaseEvent.h"
#include <glm/glm.hpp>
#include <iostream>


class CgUnterteilungsEvent: public CgBaseEvent
{

public:
    CgUnterteilungsEvent(int schritt, int mittel);


    ~CgUnterteilungsEvent();

    Cg::EventType getType();
    CgBaseEvent* clone();

    friend std::ostream& operator <<(std::ostream& os, const CgUnterteilungsEvent& e);

private:
    Cg::EventType m_type;
    int m_schritt;
    int m_mittel;

};

#endif // CGUNTERTEILUNGSEVENT_H
