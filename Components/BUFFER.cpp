#include "BUFFER.h"

BUFFER::BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFFER::Operate()
{
	// Buffer logic:
	// Output = Input (no change)
	m_OutputPin.setStatus(m_InputPins[0].getStatus());
}


// Draw 1-input buffer gate
void BUFFER::Draw(Output* pOut)
{
	pOut->DrawBUFFER(m_GfxInfo, IsSelected());
}


// returns status of output pin
int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


// returns status of input pin #n
int BUFFER::GetInputPinStatus(int n)
{
	if (n != 1)
		return -1;

	return m_InputPins[0].getStatus();
}


// Set status of input pin
void BUFFER::setInputPinStatus(int n, STATUS s)
{
	if (n == 1)
		m_InputPins[0].setStatus(s);
}
Component* BUFFER::Clone() const
{
	BUFFER* p = new BUFFER(m_GfxInfo, m_OutputPin.getFanOut());
	p->SetLabel(this->GetLabel());
	return p;
}
