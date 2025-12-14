#include "SwitchToDesignModeAction.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp) {}

void SwitchToDesignModeAction::Execute()
{
    pManager->GetOutput()->CreateDesignToolBar();
    pManager->GetOutput()->PrintMsg("Switched to Design Mode.");
}