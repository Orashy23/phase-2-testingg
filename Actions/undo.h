#ifndef UNDO_ACTION_H
#define UNDO_ACTION_H
#include "Action.h"
#include "..\ApplicationManager.h"

class UndoAction : public Action
{
public:
    UndoAction(ApplicationManager* pApp) : Action(pApp) {}
    virtual void ReadActionParameters() {}
    virtual void Execute()
    {
        pManager->UndoLastAction();
    }
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif