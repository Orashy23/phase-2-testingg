#include "SimulateAction.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"

SimulateAction::SimulateAction(ApplicationManager* pApp) : Action(pApp) {}

void SimulateAction::Execute()
{
    pManager->RunSimulation();
    pManager->GetOutput()->PrintMsg("Simulation complete. Component statuses updated.");
}