#include "Select.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager* pApp) : Action(pApp) {}

void Select::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    int x, y;
    pOut->PrintMsg("Click to select a component or connection");
    pIn->GetPointClicked(x, y);

    Component* clicked = pManager->GetComponentAt(x, y);
    Component* prev = pManager->GetSelectedComponent();
    if (prev && prev == clicked) {
        prev->SetSelected(false);
        pManager->SetSelectedComponent(nullptr);
        pOut->PrintMsg("Deselected.");
        return;
    }

    pManager->ClearSelection();
    if (clicked) {
        clicked->SetSelected(true);
        pManager->SetSelectedComponent(clicked);
        pOut->PrintMsg("Selected.");
    }
    else pOut->PrintMsg("No item selected.");
	pManager->UpdateInterface();
}
