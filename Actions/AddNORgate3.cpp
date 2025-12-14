#include "AddNORgate3.h"

#include "..\ApplicationManager.h"

AddNORgate3::AddNORgate3(ApplicationManager* pApp) :Action(pApp)
{
	pA = NULL;
	isUndone = false;
}

AddNORgate3::~AddNORgate3(void)
{
	if (isUndone && pA) delete pA;
}

void AddNORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message

	//Wait for User Input
	do {
		pOut->PrintMsg("3-Input NOR Gate: Click to add the gate (in the white screen)");
		pIn->GetPointClicked(Cx, Cy);
		if (Cy<(UI.ToolBarHeight + UI.NOR3_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.NOR3_Width / 2)) {
		}
	} while (Cy<(UI.ToolBarHeight + UI.NOR3_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.NOR3_Width / 2));


	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.NOR3_Width;
	int Wdth = UI.NOR3_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	pA = new NOR3(GInfo, NOR3_FANOUT);
	pManager->AddComponent(pA);
	isUndone = false;
}

void AddNORgate3::Undo()
{
	if (pA)
	{
		pManager->RemoveComponentOnly(pA);
		isUndone = true;
	}
}

void AddNORgate3::Redo()
{
	if (pA)
	{
		pManager->AddComponent(pA);
		isUndone = false;
	}
}