#include "ChangeSwitchAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

ChangeSwitchAction::ChangeSwitchAction(ApplicationManager* pApp) : Action(pApp) {}

void ChangeSwitchAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    pOut->PrintMsg("Change Switch: Click on the Switch component to toggle its status.");
    pIn->GetPointClicked(GfxInfo.x1, GfxInfo.y1);
    pOut->ClearStatusBar();
}

void ChangeSwitchAction::Execute()
{
    ReadActionParameters();
    Component* pCmp = pManager->GetComponentAt(GfxInfo.x1, GfxInfo.y1);
    CSwitch* pSwitch = dynamic_cast<CSwitch*>(pCmp);

    if (pSwitch)
    {
        STATUS currentStatus = (STATUS)pSwitch->GetOutPinStatus();
        STATUS newStatus = (currentStatus == HIGH) ? LOW : HIGH;
        pSwitch->SetSwitchStatus(newStatus);

        pManager->RunSimulation();
        pManager->UpdateInterface();
        pManager->GetOutput()->PrintMsg("Switch status toggled and simulation re-run.");
    }
    else
    {
        pManager->GetOutput()->PrintMsg("Action failed: No Switch found at this location.");
    }
}