#include "Move.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"

Move::Move(ApplicationManager* pApp) : Action(pApp) {}

void Move::Execute()
{
    ApplicationManager* pM = pManager;
    Output* pOut = pM->GetOutput();
    Input* pIn = pM->GetInput();

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    // Ask for reference point
    pOut->PrintMsg("Click reference point for move.");
    pIn->GetPointClicked(x1, y1);

    // Ask for destination point
    pOut->PrintMsg("Click destination point for move.");
    pIn->GetPointClicked(x2, y2);

    int dx = x2 - x1;
    int dy = y2 - y1;

    // Case 1: Multiple selection
    if (pM->GetSelectedCount() > 0)
    {
        pM->MoveSelected(dx, dy);
        pOut->PrintMsg("Moved multiple selected components.");
    }
    // Case 2: Single selection
    else if (pM->GetSelectedComponent())
    {
        Component* sel = pM->GetSelectedComponent();
        GraphicsInfo g = sel->GetGraphicsInfo();
        g.x1 += dx; g.y1 += dy;
        g.x2 += dx; g.y2 += dy;
        sel->SetPosition(g);
        pM->UpdateConnectionsFor(sel);
        pOut->PrintMsg("Moved selected component.");
    }
    else
    {
        pOut->PrintMsg("No component selected to move.");
        return;
    }

    // Redraw
    pOut->ClearDrawingArea();
    pM->UpdateInterface();
}
