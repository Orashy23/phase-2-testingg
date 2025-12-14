#include "AddLEDAction.h"
#include "ApplicationManager.h"
#include "CLED.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Components\Component.h"

AddLEDAction::AddLEDAction(ApplicationManager* pApp) : Action(pApp)
{
    pA = NULL;
    isUndone = false;
}

AddLEDAction::~AddLEDAction()
{
    if (isUndone && pA) delete pA;
}

void AddLEDAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    pOut->PrintMsg("LED: Click to add a new LED.");
    pIn->GetPointClicked(GfxInfo.x1, GfxInfo.y1);

    GfxInfo.x2 = GfxInfo.x1 + 50;
    GfxInfo.y2 = GfxInfo.y1 + 50;
    pOut->ClearStatusBar();
}

void AddLEDAction::Execute()
{
    ReadActionParameters();
    pA = new CLED(GfxInfo);
    pManager->AddComponent(pA);
    isUndone = false;
}

void AddLEDAction::Undo()
{
    if (pA)
    {
        pManager->RemoveComponentOnly(pA);
        isUndone = true;
    }
}

void AddLEDAction::Redo()
{
    if (pA)
    {
        pManager->AddComponent(pA);
        isUndone = false;
    }
}