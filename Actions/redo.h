#ifndef REDO_ACTION_H
#define REDO_ACTION_H
#include "Action.h"
#include "..\ApplicationManager.h"

class RedoAction : public Action
{
public:
    RedoAction(ApplicationManager* pApp) : Action(pApp) {}
    virtual void ReadActionParameters() {}
    virtual void Execute()
    {
        pManager->RedoLastAction();
    }
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif