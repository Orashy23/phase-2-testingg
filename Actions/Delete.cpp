#include "Delete.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

// Constructor
Delete::Delete(ApplicationManager* pApp) : Action(pApp)
{
	isUndone = false; // Initially, the action is executed, not undone.
}

// Destructor
Delete::~Delete()
{
	// If the action is destroyed and isUndone is false, it means the components 
	// are currently "deleted" (held in our vector, not in the ApplicationManager).
	// We must delete them from memory to prevent memory leaks.
	if (!isUndone)
	{
		for (size_t i = 0; i < DeletedComponents.size(); i++)
		{
			if (DeletedComponents[i])
				delete DeletedComponents[i];
		}
	}
}

void Delete::ReadActionParameters()
{
	// No parameters required from the user for the delete action.
}

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();

	// 1. Check for Multiple Selection
	if (pManager->GetSelectedCount() > 0)
	{
		// Retrieve the list of selected components
		Component* const* selArr = pManager->GetSelectedList();
		int count = pManager->GetSelectedCount();

		for (int i = 0; i < count; ++i)
		{
			if (selArr[i])
			{
				// Add pointer to our backup list and remove from screen.
				// IMPORTANT: We use RemoveComponentOnly (or similar) to remove it from 
				// the Manager's list WITHOUT deleting the object from memory.
				DeletedComponents.push_back(selArr[i]);
				pManager->RemoveComponentOnly(selArr[i]);
			}
		}

		// Clear the selection list in the Manager since they are now removed
		pManager->ClearSelections(); // Assuming you have a function to clear all selections
		pOut->PrintMsg("Deleted multiple selected components.");
	}
	// 2. Check for Single Selection (Backup if multiple selection logic isn't used)
	else if (pManager->GetSelectedComponent())
	{
		Component* sel = pManager->GetSelectedComponent();

		// Backup and remove
		DeletedComponents.push_back(sel);
		pManager->RemoveComponentOnly(sel);

		pManager->ClearSelection(); 