
#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"     // <--- Solves STATUS/MAX_CONNS undefined
#include "..\GUI\Output.h" // <--- Solves GraphicsInfo/Output undefined

class InputPin;
class OutputPin;
class Connection;
//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
	bool SelectedFlag;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	// Selection
	void SetLabel(const string& L) { m_Label = L; }
	string GetLabel() const { return m_Label; }
	void SetSelected(bool s) { SelectedFlag = s; }
	bool IsSelected() const { return SelectedFlag; }

	// Hit box check
	virtual bool ContainsPoint(int x, int y) const;

	// Position helpers
	virtual void SetPosition(const GraphicsInfo& G) { m_GfxInfo = G; }
	const GraphicsInfo& GetGraphicsInfo() const { return m_GfxInfo; }
	virtual int getWidth() const { return m_GfxInfo.x2 - m_GfxInfo.x1; }
	virtual int getHeight() const { return m_GfxInfo.y2 - m_GfxInfo.y1; }

	// Pin helpers to be overridden in Gate
	virtual OutputPin* GetOutputPin() { return nullptr; }
	virtual InputPin* GetInputPin(int n) { return nullptr; }
	virtual InputPin* GetFreeInputPin() { return nullptr; }

	// Clone for copy/paste
	virtual Component* Clone() const { return nullptr; }



	
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
