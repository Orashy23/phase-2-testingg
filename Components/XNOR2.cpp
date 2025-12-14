#include "XNOR2.h"

XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Gate(2, r_FanOut)
{
    m_GfxInfo.x1 = r_GfxInfo.x1;
    m_GfxInfo.y1 = r_GfxInfo.y1;
    m_GfxInfo.x2 = r_GfxInfo.x2;
    m_GfxInfo.y2 = r_GfxInfo.y2;
}

void XNOR2::Operate()
{
    // XNOR logic 
    if ((m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH) ||
        (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW))
    {
        m_OutputPin.setStatus(HIGH);
    }
    else
    {
        m_OutputPin.setStatus(LOW);
    }
}

void XNOR2::Draw(Output* pOut)
{
    pOut->DrawXNOR2(m_GfxInfo, IsSelected());
}

int XNOR2::GetOutPinStatus()
{
    return m_OutputPin.getStatus();
}

int XNOR2::GetInputPinStatus(int n)
{
    return m_InputPins[n - 1].getStatus();
}

void XNOR2::setInputPinStatus(int n, STATUS s)
{
    m_InputPins[n - 1].setStatus(s);
}
Component* XNOR2::Clone() const
{
    XNOR2* p = new XNOR2(m_GfxInfo, m_OutputPin.getFanOut());
    p->SetLabel(this->GetLabel());
    return p;
}
