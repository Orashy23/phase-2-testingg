
#include "CLED.h"

CLED::CLED(const GraphicsInfo& r_GfxInfo) : Component(r_GfxInfo)
{
    m_IsOn = false;
}

void CLED::Operate()
{
    STATUS s = m_InputPin.getStatus();
    m_IsOn = (s == HIGH);
}

void CLED::Draw(Output* pOut)
{
    pOut->DrawLED(m_GfxInfo, m_IsOn);
}

int CLED::GetOutPinStatus()
{
    return -1; // LED is a sink
}

int CLED::GetInputPinStatus(int n)
{
    if (n == 1) return m_InputPin.getStatus();
    return -1;
}

void CLED::setInputPinStatus(int n, STATUS s)
{
    if (n == 1) m_InputPin.setStatus(s);
}