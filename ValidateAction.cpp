#include "ValidateAction.h"
#include "ApplicationManager.h"

ValidateAction::ValidateAction(ApplicationManager* pApp) : Action(pApp) {}

void ValidateAction::Execute()
{
    pManager->ValidateCircuit();
}