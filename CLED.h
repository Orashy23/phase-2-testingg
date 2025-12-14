#pragma once

#ifndef CLED_H
#define CLED_H
#include "Components/Component.h"
#include "Components/InputPin.h"

class CLED : public Component
{
private:
    InputPin m_InputPin;
    bool m_IsOn;

public:
    CLED(const GraphicsInfo& r_GfxInfo);
    virtual ~CLED() {}

    virtual void Operate();
    virtual void Draw(Output* pOut);
    virtual int GetOutPinStatus();
    virtual int GetInputPinStatus(int n);
    virtual void setInputPinStatus(int n, STATUS s);
};

#endif