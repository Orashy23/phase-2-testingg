#include "XOR2.h"

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR2::Operate()
{
	// XOR Truth Table:
	// Output = HIGH if ONLY ONE input is HIGH
	int in1 = m_InputPins[0].getStatus();
	int in2 = m_InputPins[1].getStatus();

	if ((in1 == HIGH && in2 == LOW) || (in1 == LOW && in2 == HIGH)) {
		m_OutputPin.setStatus(HIGH);
	}
	else {
		m_OutputPin.setStatus(LOW);
	}
}


// Draws 2-input XOR gate
void XOR2::Draw(Output* pOut)
{
	pOut->DrawXOR2(m_GfxInfo, IsSelected());
}


//returns status of output pin
int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}


//Set status of an input pin to HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
Component* XOR2::Clone() const
{
	XOR2* p = new XOR2(m_GfxInfo, m_OutputPin.getFanOut());
	p->SetLabel(this->GetLabel());
	return p;
}
