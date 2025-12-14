#pragma once
#ifndef ADD_SWITCH_ACTION_H
#define ADD_SWITCH_ACTION_H

#include "Actions\Action.h" // Points down to Actions folder
#include "Defs.h"

// Forward declaration avoids include errors
class Component;

class AddSwitchAction : public Action
{
private:
    GraphicsInfo GfxInfo;

    // Undo/Redo members
    Component* pA;
    bool isUndone;

public:
    AddSwitchAction(ApplicationManager* pApp);
    virtual ~AddSwitchAction();

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
    virtual void Redo();
};
#endif