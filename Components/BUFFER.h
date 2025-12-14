#ifndef _BUFFER_H
#define _BUFFER_H

/*
  Class BUFFER
  ------------
  Represents the 1-input Buffer gate
*/

#include "Gate.h"

class BUFFER : public Gate
{
public:
    BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut);

    virtual void Operate();	                    // Calculates the output of the buffer (out = in)
    virtual void Draw(Output* pOut);	            // Draws 1-input buffer gate

    virtual int GetOutPinStatus();               // returns status of output pin
    virtual int GetInputPinStatus(int n);        // returns status of input pin (only pin #1 exists)
    virtual void setInputPinStatus(int n, STATUS s); // sets input pin #1
    virtual Component* Clone() const;

};

#endif
