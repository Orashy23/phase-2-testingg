#ifndef CSWITCH_H
#define CSWITCH_H

#include "Components/Component.h"
#include "Components/Pin.h"
#include "Components/OutputPin.h"

class CSwitch : public Component
{
private:
    OutputPin m_OutputPin;
    STATUS m_SwitchStatus;

public:
    CSwitch(const GraphicsInfo& r_GfxInfo, int r_FanOut = 10);
    virtual ~CSwitch() {}

    virtual void Operate();
    virtual void Draw(Output* pOut);
    virtual int GetOutPinStatus();
    virtual int GetInputPinStatus(int n);
    virtual void setInputPinStatus(int n, STATUS s);

    void SetSwitchStatus(STATUS s) { m_SwitchStatus = s; }
};

#endif