#pragma once
#ifndef VALIDATE_ACTION_H
#define VALIDATE_ACTION_H
#include "Actions/Action.h"

class ValidateAction : public Action
{
public:
    ValidateAction(ApplicationManager* pApp);
    virtual void ReadActionParameters() {}
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif