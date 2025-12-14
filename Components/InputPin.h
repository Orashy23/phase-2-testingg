//what this class does?
//1-it inherits from pin class to get basic functions from it( logic status).
// 2-It stores a pointer to the gate that owns this input pin and It has setters / getters for the owner component.
//3-it stores pointer to the connection and has setters and getters for the wire connected to the pin. 
//4-The connection must know whether it is linking to input 0 or input 1 of a gate so, it stores pin index. 

#ifndef _INPUTPIN_H
#define _INPUTPIN_H
#include "Pin.h"
class Component;// Forward declaration( for components)

class Connection; // Forward declaration ( for wires)


class InputPin : public Pin// Inherits logic status from Pin(already done function in pin.h class)

{
	Component* pComp; // The component this pin belongs to

	Connection* pConn;// The wire connected to this input pin

	int m_InputNumber; // which bit is the wire connected to 

	bool Connected;
public:
	InputPin();

	// Component association (Note: Your original file is missing setComponent implementation)
	void setComponent(Component* pCmp);
	Component* getComponent() const;

	// Connection 
	void setConnection(Connection* c);
	Connection* getConnection() const;

	// pin index
	void setInputNumber(int n);
	int getInputNumber() const;
	bool isConnected() const;
	void RemoveConnection();
};

#endif