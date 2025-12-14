#include "saveAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <fstream>

saveAction::saveAction(ApplicationManager* pApp) : Action(pApp)
{
}

void saveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Enter the file name required to save ");
	fileName = pIn->GetSrting(pOut);
}

void saveAction::Execute()
{
	ReadActionParameters();

	ofstream outputFile(fileName + ".txt");
	if (!outputFile) {
		pManager->GetOutput()->PrintMsg(" Error creating the file!!");
		return;
	}

	pManager->SaveAll(outputFile); // Save each figure

	outputFile.close();

	pManager->GetOutput()->PrintMsg("Saved successfully to " + fileName + ".txt");
}



