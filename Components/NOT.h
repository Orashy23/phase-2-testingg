#ifndef _NOT_H
#define _NOT_H

/*
  Class NOT
  -----------
  Represents the 1-input NOT (Inverter) gate
*/

#include "Gate.h"

class NOT : public Gate
{
public:
    NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut);

    virtual void Operate();	                    // Calculates the output of the NOT gate (invert input)
    virtual void Draw(Output* pOut);	            // Draws NOT gate

    virtual int GetOutPinStatus();               // returns status of output pin
    virtual int GetInputPinStatus(int n);        // returns status of input pin (only 1 exists)
    virtual void setInputPinStatus(int n, STATUS s);
    virtual Component* Clone() const;


};
#endif
