#include "SwitchToSimModeAction.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"

SwitchToSimModeAction::SwitchToSimModeAction(ApplicationManager* pApp) : Action(pApp) {}

void SwitchToSimModeAction::Execute()
{
    pManager->GetOutput()->CreateSimulationToolBar();
    pManager->GetOutput()->PrintMsg("Switched to Simulation Mode.");
}