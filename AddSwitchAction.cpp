#include "AddSwitchAction.h"
#include "ApplicationManager.h"
#include "CSwitch.h"            
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Components\Component.h" 

AddSwitchAction::AddSwitchAction(ApplicationManager* pApp) : Action(pApp)
{
    pA = NULL;
    isUndone = false;
}

AddSwitchAction::~AddSwitchAction()
{
    if (isUndone && pA) delete pA;
}

void AddSwitchAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    pOut->PrintMsg("Switch: Click to add a new Switch.");
    pIn->GetPointClicked(GfxInfo.x1, GfxInfo.y1);

    // Default size 50x50
    GfxInfo.x2 = GfxInfo.x1 + 50;
    GfxInfo.y2 = GfxInfo.y1 + 50;

    pOut->ClearStatusBar();
}

void AddSwitchAction::Execute()
{
    ReadActionParameters();
    pA = new CSwitch(GfxInfo);
    pManager->AddComponent(pA);
    isUndone = false;
}

void AddSwitchAction::Undo()
{
    if (pA)
    {
        pManager->RemoveComponentOnly(pA);
        isUndone = true;
    }
}

void AddSwitchAction::Redo()
{
    if (pA)
    {
        pManager->AddComponent(pA);
        isUndone = false;
    }
}