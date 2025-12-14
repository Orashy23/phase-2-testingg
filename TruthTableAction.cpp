#include "TruthTableAction.h"
#include "ApplicationManager.h"

TruthTableAction::TruthTableAction(ApplicationManager* pApp) : Action(pApp) {}

void TruthTableAction::Execute()
{
    pManager->CreateTruthTable();
}