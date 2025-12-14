#include "Multiple.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Components\Component.h"

Multiple::Multiple(ApplicationManager* pApp) : Action(pApp) {}

void Multiple::Execute()
{
    ApplicationManager* pM = pManager;
    Input* pIn = pM->GetInput();
    Output* pOut = pM->GetOutput();

    int x = 0, y = 0;

    // Clear previous multi-selection
    pM->ClearSelections();

    pOut->PrintMsg("Click components to select. Click empty space to finish.");

    while (true)
    {
        pIn->GetPointClicked(x, y);

        Component* C = pM->GetComponentAt(x, y);

        if (C)
        {
            // Toggle selection
            if (C->IsSelected())
            {
                C->SetSelected(false);
            }
            else
            {
                C->SetSelected(true);
                pM->AddToSelected(C);
            }

            pM->UpdateInterface();
        }
        else{

            return;
        }
    }

    pOut->PrintMsg("Multi-selection complete. Use Delete or Move to act on selected components.");
    pOut->ClearStatusBar();
}
