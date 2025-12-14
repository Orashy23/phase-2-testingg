#ifndef _AND2_H
#define _AND2_H

/*
  Class AND2
  -----------
  Represents the 2-input AND gate
*/

#include "Gate.h"

class AND2 : public Gate
{
public:
    AND2(const GraphicsInfo& r_GfxInfo, int r_FanOut);

    virtual void Operate();	                   // Calculates the output of the AND gate
    virtual void Draw(Output* pOut);	           // Draws 2-input AND gate

    virtual int GetOutPinStatus();               // returns status of output pin
    virtual int GetInputPinStatus(int n);        // returns status of Input pin # n
    virtual void setInputPinStatus(int n, STATUS s); // sets input pin # n
    virtual Component* Clone() const;


};

#endif
