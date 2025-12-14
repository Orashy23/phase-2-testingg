#include "AddNANDgate2.h"
#include "..\ApplicationManager.h"

AddNANDgate2::AddNANDgate2(ApplicationManager* pApp) :Action(pApp)
{
	pA = NULL;
	isUndone = false;
}

AddNANDgate2::~AddNANDgate2(void)
{
	if (isUndone && pA) delete pA;
}

void AddNANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message

	//Wait for User Input
	do {
		pOut->PrintMsg("2-Input NAND Gate: Click to add the gate (in the white screen)");
		pIn->GetPointClicked(Cx, Cy);
		if (Cy<(UI.ToolBarHeight + UI.NAND2_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.NAND2_Width / 2)) {
		}
	} while (Cy<(UI.ToolBarHeight + UI.NAND2_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.NAND2_Width / 2));


	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.NAND2_Width;
	int Wdth = UI.NAND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	pA = new NAND2(GInfo, NAND2_FANOUT);
	pManager->AddComponent(pA);
	isUndone = false;
}

void AddNANDgate2::Undo()
{
	if (pA)
	{
		pManager->RemoveComponentOnly(pA);
		isUndone = true;
	}
}

void AddNANDgate2::Redo()
{
	if (pA)
	{
		pManager->AddComponent(pA);
		isUndone = false;
	}
}