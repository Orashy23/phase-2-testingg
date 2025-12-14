#include "Cut.h"
#include "..\\ApplicationManager.h"
#include "..\GUI\Output.h"

Cut::Cut(ApplicationManager* pApp) : Action(pApp) {}
void Cut::Execute()
{
	Output* pOut = pManager->GetOutput();
	Component* sel = pManager->GetSelectedComponent();
	if (!sel) { pOut->PrintMsg("No component selected to cut."); return; }
	Component* clone = sel->Clone();
	if (!clone) { pOut->PrintMsg("Cannot cut this component."); return; }
	pManager->SetClipboard(clone);
	pManager->RemoveComponent(sel);
	pOut->ClearDrawingArea();
	pManager->UpdateInterface();
	pManager->SetSelectedComponent(nullptr);
	pOut->PrintMsg("Cut to clipboard.");
}