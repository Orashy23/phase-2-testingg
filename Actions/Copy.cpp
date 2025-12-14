#include "Copy.h"
#include "..\\ApplicationManager.h"
#include "..\\GUI\Output.h"

Copy::Copy(ApplicationManager* pApp) : Action(pApp) {}

void Copy::Execute()
{
    Output* pOut = pManager->GetOutput();
    Component* sel = pManager->GetSelectedComponent();
    if (!sel) { pOut->PrintMsg("No component selected to copy."); return; }
    Component* clone = sel->Clone();
    if (!clone) { pOut->PrintMsg("Cannot copy this component."); return; }
    pManager->SetClipboard(clone);
    pOut->PrintMsg("Copied to clipboard.");
}
