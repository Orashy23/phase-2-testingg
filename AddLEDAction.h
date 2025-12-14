#pragma once
#ifndef ADD_LED_ACTION_H
#define ADD_LED_ACTION_H

#include "Actions\Action.h"
#include "Defs.h"

class Component;

class AddLEDAction : public Action
{
private:
    GraphicsInfo GfxInfo;

    // Undo/Redo members
    Component* pA;
    bool isUndone;

public:
    AddLEDAction(ApplicationManager* pApp);
    virtual ~AddLEDAction();

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
    virtual void Redo();
};
#endif