#pragma once
#ifndef SWITCH_TO_SIM_MODE_ACTION_H
#define SWITCH_TO_SIM_MODE_ACTION_H
#include "Actions/Action.h"

class SwitchToSimModeAction : public Action
{
public:
    SwitchToSimModeAction(ApplicationManager* pApp);
    virtual void ReadActionParameters() {}
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif