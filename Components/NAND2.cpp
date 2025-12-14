#include "NAND2.h"

NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NAND2::Operate()
{
	// NAND Truth Table:
	// Output = LOW only when both inputs are HIGH
	if ((m_InputPins[0].getStatus() == HIGH) && (m_InputPins[1].getStatus() == HIGH)) {
		m_OutputPin.setStatus(LOW);     
	}
	else {
		m_OutputPin.setStatus(HIGH);    // otherwise output HIGH
	}
}


// Draws 2-input NAND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(m_GfxInfo,IsSelected());
}


//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}


//Set status of an input pin to HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
Component* NAND2::Clone() const
{
	NAND2* p = new NAND2(m_GfxInfo, m_OutputPin.getFanOut());
	p->SetLabel(this->GetLabel());
	return p;
}
