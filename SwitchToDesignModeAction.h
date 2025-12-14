#pragma once
#ifndef SWITCH_TO_DESIGN_MODE_ACTION_H
#define SWITCH_TO_DESIGN_MODE_ACTION_H
#include "Actions/Action.h"

class SwitchToDesignModeAction : public Action
{
public:
    SwitchToDesignModeAction(ApplicationManager* pApp);
    virtual void ReadActionParameters() {}
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif