#include "NOT.h"

NOT::NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOT::Operate()
{
	//Logic
	STATUS in = m_InputPins[0].getStatus();

	if (in == HIGH)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
}


// Draw NOT gate
void NOT::Draw(Output* pOut)
{
	pOut->DrawNOT(m_GfxInfo, IsSelected());
}


// returns status of output pin
int NOT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


// returns status of input pin #n
int NOT::GetInputPinStatus(int n)
{
	if (n != 1)
		return -1;

	return m_InputPins[0].getStatus();
}


// Set status of input pin
void NOT::setInputPinStatus(int n, STATUS s)
{
	if (n == 1)
		m_InputPins[0].setStatus(s);
}

Component* NOT::Clone() const
{
	NOT* p = new NOT(m_GfxInfo, m_OutputPin.getFanOut());
	p->SetLabel(this->GetLabel());
	return p;
}
