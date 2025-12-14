#include "AddProbeAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

AddProbeAction::AddProbeAction(ApplicationManager* pApp) : Action(pApp) {}

void AddProbeAction::ReadActionParameters()
{
    pManager->GetOutput()->PrintMsg("Probe: Click on the pin or wire you want to read.");
    pManager->GetInput()->GetPointClicked(GfxInfo.x1, GfxInfo.y1);
    pManager->GetOutput()->ClearStatusBar();
}

void AddProbeAction::Execute()
{
    ReadActionParameters();
    Component* pCmp = pManager->GetComponentAt(GfxInfo.x1, GfxInfo.y1);

    if (pCmp)
    {
        STATUS s = (STATUS)pCmp->GetOutPinStatus();

        if (s == HIGH)
            pManager->GetOutput()->PrintMsg("PROBE: Status is HIGH (1)");
        else if (s == LOW)
            pManager->GetOutput()->PrintMsg("PROBE: Status is LOW (0)");
        else
            pManager->GetOutput()->PrintMsg("PROBE: Status is UNDEFINED (-1)");
    }
    else
    {
        pManager->GetOutput()->PrintMsg("PROBE: No component or pin found at this location.");
    }
}