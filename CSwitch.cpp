#include "CSwitch.h"

CSwitch::CSwitch(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Component(r_GfxInfo), m_OutputPin(r_FanOut)
{
    m_SwitchStatus = LOW;

}

void CSwitch::Operate()
{
    m_OutputPin.setStatus(m_SwitchStatus);
}

void CSwitch::Draw(Output* pOut)
{
    pOut->DrawSWITCHS(m_GfxInfo, m_SwitchStatus);
}

int CSwitch::GetOutPinStatus()
{
    return m_OutputPin.getStatus();
}

int CSwitch::GetInputPinStatus(int n)
{
    return -1; // No input pins
}

void CSwitch::setInputPinStatus(int n, STATUS s)
{
    return; // Not used
}
