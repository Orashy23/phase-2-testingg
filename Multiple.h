#pragma once
#include "Actions\Action.h"

class Multiple : public Action
{
	public:
	Multiple(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters() {}
	virtual void Undo() {}
	virtual void Redo() {}
};