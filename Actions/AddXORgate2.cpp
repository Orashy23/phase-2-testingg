#include "AddXORgate2.h"
#include "..\ApplicationManager.h"

AddXORgate2::AddXORgate2(ApplicationManager* pApp) :Action(pApp)
{
	pA = NULL;
	isUndone = false;
}

AddXORgate2::~AddXORgate2(void)
{
	if (isUndone && pA) delete pA;
}

void AddXORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message

	//Wait for User Input
	do {
		pOut->PrintMsg("2-Input XOR Gate: Click to add the gate (in the white screen)");
		pIn->GetPointClicked(Cx, Cy);
		if (Cy<(UI.ToolBarHeight + UI.XOR2_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.XOR2_Width / 2)) {
		}
	} while (Cy<(UI.ToolBarHeight + UI.XOR2_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.XOR2_Width / 2));


	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.XOR2_Width;
	int Wdth = UI.XOR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	pA = new XOR2(GInfo, XOR2_FANOUT);
	pManager->AddComponent(pA);
	isUndone = false;
}

void AddXORgate2::Undo()
{
	if (pA)
	{
		pManager->RemoveComponentOnly(pA);
		isUndone = true;
	}
}

void AddXORgate2::Redo()
{
	if (pA)
	{
		pManager->AddComponent(pA);
		isUndone = false;
	}
}