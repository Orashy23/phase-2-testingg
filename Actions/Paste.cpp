#include "Paste.h"
#include "..\\ApplicationManager.h"
#include "..\\GUI\\Input.h"
#include "..\\GUI\\Output.h"

Paste::Paste(ApplicationManager* pApp) : Action(pApp) {}

void Paste::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    Component* clip = pManager->GetClipboard();
    if (!clip) { pOut->PrintMsg("Clipboard empty."); return; }

    pOut->PrintMsg("Click where to paste the component");
    int x, y; pIn->GetPointClicked(x, y);

    Component* newC = clip->Clone();
    if (!newC) { pOut->PrintMsg("Cannot paste this component."); return; }

    int w = newC->getWidth();
    int h = newC->getHeight();
    GraphicsInfo G; G.x1 = x - w / 2; G.y1 = y - h / 2; G.x2 = G.x1 + w; G.y2 = G.y1 + h;
    newC->SetPosition(G);

    pManager->AddComponent(newC);
    pOut->PrintMsg("Pasted.");
}
