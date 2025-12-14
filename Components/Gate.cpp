#include "Gate.h"
#include "..\Actions\Select.h"
#include "..\Actions\Delete.h"
#include "..\Actions\Move.h"
#include "..\Actions\Copy.h"
#include "..\Actions\Cut.h"
#include "..\Actions\Paste.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Components\Connection.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}
//Gate::~Gate() {}

InputPin* Gate::GetFreeInputPin()
{
	for (int i = 0; i < m_Inputs; ++i)
		if (!m_InputPins[i].isConnected())
			return &m_InputPins[i];
	return nullptr;
}

OutputPin* Gate::GetOutputPin() { return &m_OutputPin; }

InputPin* Gate::GetInputPin(int n)
{
	if (n >= 1 && n <= m_Inputs) return &m_InputPins[n - 1];
	return nullptr;
}