#ifndef ADD_PROBE_ACTION_H
#define ADD_PROBE_ACTION_H
#include "Actions/Action.h"
#include "Defs.h"

class AddProbeAction : public Action
{
private:
    GraphicsInfo GfxInfo;
public:
    AddProbeAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif