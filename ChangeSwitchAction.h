#pragma once
#ifndef CHANGE_SWITCH_ACTION_H
#define CHANGE_SWITCH_ACTION_H
#include "Actions/Action.h"
#include "Defs.H"
#include "CSwitch.h"

class ChangeSwitchAction : public Action
{
private:
    GraphicsInfo GfxInfo;
public:
    ChangeSwitchAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif