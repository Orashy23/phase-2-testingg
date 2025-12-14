#ifndef _NOR2_H
#define _NOR2_H

/*
  Class NOR2
  -----------
  Represents the 2-input NOR gate
*/

#include "Gate.h"

class NOR2 : public Gate
{
public:
    NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);

    virtual void Operate();	                    // Calculates the output of the NOR gate
    virtual void Draw(Output* pOut);	            // Draws 2-input NOR gate

    virtual int GetOutPinStatus();               // returns status of output pin
    virtual int GetInputPinStatus(int n);        // returns status of Input pin # n
    virtual void setInputPinStatus(int n, STATUS s);  // sets input pin # n
    virtual Component* Clone() const;

};

#endif
