#ifndef _NAND2_H
#define _NAND2_H

#include "Gate.h"

class NAND2 : public Gate
{
public:
    NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut);

    virtual void Operate();	//Calculates the output of the NAND gate
    virtual void Draw(Output* pOut);	//Draws 2-input NAND gate

    virtual int GetOutPinStatus();
    virtual int GetInputPinStatus(int n);
    virtual void setInputPinStatus(int n, STATUS s);
    virtual Component* Clone() const;
};

#endif
