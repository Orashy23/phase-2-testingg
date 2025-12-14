#include "AddNOTgate.h"
#include "..\ApplicationManager.h"

AddNOTgate::AddNOTgate(ApplicationManager* pApp) :Action(pApp)
{
	pA = NULL;
	isUndone = false;
}

AddNOTgate::~AddNOTgate(void)
{
	if (isUndone && pA) delete pA;
}

void AddNOTgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message

	//Wait for User Input
	do {
		pOut->PrintMsg("ADD inverter : Click to add the gate (in the white screen)");
		pIn->GetPointClicked(Cx, Cy);
		if (Cy<(UI.ToolBarHeight + UI.NOT_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.NOT_Width / 2)) {
		}
	} while (Cy<(UI.ToolBarHeight + UI.NOT_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.NOT_Width / 2));


	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNOTgate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.NOT_Width;
	int Wdth = UI.NOT_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	pA = new NOT(GInfo, NOT_FANOUT);
	pManager->AddComponent(pA);
	isUndone = false;
}

void AddNOTgate::Undo()
{
	if (pA)
	{
		pManager->RemoveComponentOnly(pA);
		isUndone = true;
	}
}

void AddNOTgate::Redo()
{
	if (pA)
	{
		pManager->AddComponent(pA);
		isUndone = false;
	}
}
	