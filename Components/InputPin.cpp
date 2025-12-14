#include "InputPin.h"    
#include "Connection.h"   

// intialize new variables to the constructor 
InputPin::InputPin()
{
    pComp = nullptr;
    pConn = nullptr;
    m_InputNumber = -1;
    m_Status = LOW;
    Connected = false;
}

// components association handling 
void InputPin::setComponent(Component* pCmp)
{
    this->pComp = pCmp;
}

Component* InputPin::getComponent() const
{
    return pComp;
}
// connection ( connected wire) handling 
void InputPin::setConnection(Connection* c)
{
    pConn = c;
    Connected = (c != nullptr);
    if (!c)
        m_InputNumber = -1;
}

Connection* InputPin::getConnection() const
{
    return pConn;
}
// pin index handling 
void InputPin::setInputNumber(int n)
{
    m_InputNumber = n;
}

int InputPin::getInputNumber() const
{
    return m_InputNumber;
}

bool InputPin::isConnected() const
{
    return Connected;
}
void InputPin::RemoveConnection()
{
    pConn = nullptr;
    Connected = false;
    m_InputNumber = -1;
}