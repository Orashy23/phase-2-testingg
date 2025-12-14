#pragma once
#ifndef SIMULATE_ACTION_H
#define SIMULATE_ACTION_H
#include "Actions/Action.h"

class SimulateAction : public Action
{
public:
    SimulateAction(ApplicationManager* pApp);
    virtual void ReadActionParameters() {}
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif