#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
#include "..\Components\InputPin.h"  // Needed for methods
#include "..\Components\OutputPin.h" // Needed for methods

AddConnection::AddConnection(ApplicationManager* pApp) : Action(pApp), SrcPin(NULL), DstPin(NULL)
{
    pConn = NULL;
    isUndone = false;
}

AddConnection::~AddConnection()
{
    if (isUndone && pConn) delete pConn;
}

void AddConnection::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Click on the source component's output area");
    pIn->GetPointClicked(x1, y1);
    Component* c1 = pManager->GetComponentAt(x1, y1);
    if (!c1) { pOut->PrintMsg("No component at that position"); return; }

    SrcPin = c1->GetOutputPin();
    if (!SrcPin) { pOut->PrintMsg("Selected component has no output pin"); SrcPin = NULL; return; }

    pOut->PrintMsg("Click on the destination component's input area");
    pIn->GetPointClicked(x2, y2);
    Component* c2 = pManager->GetComponentAt(x2, y2);
    if (!c2) { pOut->PrintMsg("No component at that position"); SrcPin = NULL; return; }

    DstPin = c2->GetFreeInputPin();
    if (!DstPin) { pOut->PrintMsg("No free input pin on selected component"); SrcPin = NULL; DstPin = NULL; return; }

    pOut->ClearStatusBar();
}

void AddConnection::Execute()
{
    // If pConn exists, we are redoing, don't read params again
    if (!pConn) {
        ReadActionParameters();
        if (!SrcPin || !DstPin) return;

        GraphicsInfo g; g.x1 = x1; g.y1 = y1; g.x2 = x2; g.y2 = y2;
        pConn = new Connection(g, SrcPin, DstPin);
    }

    // Try to connect
    if (SrcPin->ConnectTo(pConn))
    {
        DstPin->setConnection(pConn);
        pManager->AddComponent(pConn);
        isUndone = false;
    }
    else
    {
        // Cleanup if connection failed (e.g. max fanout)
        delete pConn;
        pConn = NULL;
    }
}

void AddConnection::Undo()
{
    if (pConn && !isUndone)
    {
        // 1. Remove from Application Manager
        pManager->RemoveComponentOnly(pConn);

        // 2. Disconnect from Source Pin
        if (SrcPin) SrcPin->RemoveConnection(pConn);

        // 3. Disconnect from Destination Pin
        if (DstPin) DstPin->setConnection(NULL);

        isUndone = true;
    }
}

void AddConnection::Redo()
{
    if (pConn && isUndone)
    {
        // 1. Add back to Application Manager
        pManager->AddComponent(pConn);

        // 2. Reconnect to Source Pin
        if (SrcPin) SrcPin->ConnectTo(pConn);

        // 3. Reconnect to Destination Pin
        if (DstPin) DstPin->setConnection(pConn);

        isUndone = false;
    }
}