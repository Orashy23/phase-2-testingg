#ifndef _OUTPUTPIN_H
#define _OUTPUTPIN_H


#include "Pin.h" // Sibling in Pins folder
// FIX: Component is in the sibling Components folder
#include "..\Components\Component.h"
/*class OutputPin
  ---------------
 An output pin obtains its value as a result of calculating the outputs of
 a component. The output pin propagates its value immediately to the associated connections
*/

class OutputPin : public Pin
{
private:
	//Array of connections (poniters) to be connected to that OutputPin
	//For simplicity, we consider it a constant length
	// MAX_CONNS is defined in Defs.h
	Connection* m_Connections[MAX_CONNS];// array of connection pointers 
	int m_FanOut; // Maximum No.of connections connected to that output pin(depends on the component)

	int m_Conn;//Actual No. of connections connected to that output pin

	Component* m_pComp;
public:
	OutputPin(int r_FanOut = 0);
	bool ConnectTo(Connection* r_Conn);//connect to a new connection

	void RemoveConnection(Connection* pConn);// remove a specific connection
	void UnconnectAll();// when a component is deleted
	int getFanOut() const { return m_FanOut; }

	int GetOutPinStatus(); // getter for the state of output( high, low,udefined)

	void SetOutPinStatus(int s); // setter for the state of output(high, low, udefined)


	bool HasSpace() const; // checks if you can connect more connections
	int getConnCount() const;// how many connections are connected 


	Component* getComponent() const;
	Connection* getConnectionAt(int idx) const {
		return (idx >= 0 && idx < m_Conn) ? m_Connections[idx] : nullptr;
	}
	Connection** getConnections();/// returns a pointer to the array of all
};

#endif