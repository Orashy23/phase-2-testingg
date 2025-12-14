#pragma once
#include "Action.h"
#include "..\Components\Component.h"
#include <vector>

class Delete : public Action
{
private:
	std::vector<Component*> DeletedComponents; // List of deleted items
	bool isUndone;

public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete(); // Destructor to clean up memory if needed

	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};