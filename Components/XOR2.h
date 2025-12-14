#ifndef _XOR2_H
#define _XOR2_H

/*
  Class XOR2
  -----------
  Represents the 2-input XOR gate
*/

#include "Gate.h"

class XOR2 : public Gate
{
public:
    XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);

    virtual void Operate();	                   // Calculates the output of the XOR gate
    virtual void Draw(Output* pOut);	           // Draws 2-input XOR gate

    virtual int GetOutPinStatus();               // returns status of output pin
    virtual int GetInputPinStatus(int n);        // returns status of Input pin # n
    virtual void setInputPinStatus(int n, STATUS s); // sets input pin # n
    virtual Component* Clone() const;


};

#endif
