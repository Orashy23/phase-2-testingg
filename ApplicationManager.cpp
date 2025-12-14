#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddBUFFERgate.h"
#include "Actions\AddNOTgate.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddConnection.h"
#include "Actions\Select.h"
#include "Actions\Delete.h"
#include "Actions\Move.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Components\Connection.h"
#include "Multiple.h"    
#include <vector>     
#include <cmath>      
#include <iostream>
#include "CLED.h"
#include "CSwitch.h"
#include"AddSwitchAction.h"
#include"SimulateAction.h"
#include"ValidateAction.h"
#include"TruthTableAction.h"
#include"ChangeSwitchAction.h"
#include"SwitchToDesignModeAction.h"
#include"SwitchToSimModeAction.h"
#include"AddProbeAction.h"
#include"AddLEDAction.h"
#include "Actions/undo.h"
#include "Actions/redo.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	SelectedComp = nullptr;
	ClipboardComp = nullptr;
	SelectedCount = 0; // Initialize SelectedCount

	for (int i = 0; i < MaxCompCount; i++) {
		CompList[i] = NULL;
		SelectedArr[i] = nullptr; // Initialize SelectedArr
	}

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}

////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user

	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////
/**************************************************************************************************/
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	int x, y;
	GraphicsInfo GfxInfo;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;
	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;
	case ADD_Buff:
		pAct = new AddBUFFERgate(this);
		break;
	case ADD_INV:
		pAct = new AddNOTgate(this);
		break;
	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;
	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;
	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;
	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;
	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;
	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		break;
	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;
	case ADD_CONNECTION:
		pAct = new AddConnection(this);
		break;
	case SELECT:
		pAct = new Select(this);
		break;
	case DEL:
		pAct = new Delete(this);
		break;
	case MOVE:
		pAct = new Move(this);
		break;
	case COPY:
		pAct = new Copy(this);
		break;
	case CUT:
		pAct = new Cut(this);
		break;
	case PASTE:
		pAct = new Paste(this);
		break;
	case Multi:
		pAct = new Multiple(this);
		break;
	case ADD_Switch:
		pAct = new AddSwitchAction(this);
		break;

	case ADD_LED:
		pAct = new AddLEDAction(this);
		break;

		// ** Simulation and Analysis Actions **
	case SIMULATE:
		pAct = new SimulateAction(this);
		break;

	case VALIDATE:
		pAct = new ValidateAction(this);
		break;

	case TRUTH_TABLE:
		pAct = new TruthTableAction(this);
		break;

	case Change_Switch:
		pAct = new ChangeSwitchAction(this);
		break;

	case ADD_Probe:
		pAct = new AddProbeAction(this);
		break;

		// ** Mode Switching Actions **
	case SIM_MODE:
		pAct = new SwitchToSimModeAction(this);
		break;

	case DSN_MODE:
		pAct = new SwitchToDesignModeAction(this);
		break;
	case EXIT:
		///TODO: create ExitAction here
		break;
	case UNDO:
		pAct = new UndoAction(this); 
		break;

	case REDO:
		pAct = new RedoAction(this); 
		break;
	if (pAct)
	{
		pAct->Execute(); // Execute the action

		// Identify if the action should be recorded in history
		bool isUndoable = true; // Assume true by default

		switch (ActType)
		{
			// List of  actions that should NOT be recorded in history(undoable actions)
		case UNDO:
		case REDO:
		case SAVE:
		case LOAD:
		case EXIT:
		case SIM_MODE:
		case DSN_MODE:
		case SIMULATE:
		case VALIDATE:
		case TRUTH_TABLE:
		case Change_Switch:
			isUndoable = false;
			break;
		}

		if (isUndoable)
		{
			RecordAction(pAct); // Save to UndoStack
		}
		else
		{
			delete pAct; // Delete immediately if not needed for history
			pAct = NULL;
		}
	}

}

void ApplicationManager::SaveAll(ofstream& OutputFile)
{
	/*OutputFile << CompCount << endl;
	for (int i = 0; i < CompCount; i++) {
		Component[i]->Save(OutputFile);
	}*/
}

/////////////////////////////////*************************************************///////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;

	if (ClipboardComp)
		delete ClipboardComp;
}

void ApplicationManager::SetSelectedComponent(Component* C) { SelectedComp = C; }
Component* ApplicationManager::GetSelectedComponent() const { return SelectedComp; }
void ApplicationManager::ClearSelection()
{
	if (SelectedComp) SelectedComp->SetSelected(false);
	SelectedComp = nullptr;
}
void ApplicationManager::ClearSelections()
{
	for (int i = 0; i < SelectedCount; ++i)
	{
		if (SelectedArr[i])
			SelectedArr[i]->SetSelected(false);
		SelectedArr[i] = nullptr;
	}
	SelectedCount = 0;
}
void ApplicationManager::AddToSelected(Component* C)
{
	if (SelectedCount < MaxCompCount)
	{
		SelectedArr[SelectedCount++] = C;
	}
}
void ApplicationManager::DeleteSelected()
{
	for (int i = 0; i < SelectedCount; ++i)
	{
		if (SelectedArr[i])
		{
			RemoveComponent(SelectedArr[i]);
			SelectedArr[i] = nullptr;
		}
	}
	SelectedCount = 0;
}

void ApplicationManager::MoveSelected(int dx, int dy) const
{
	for (int i = 0; i < SelectedCount; ++i)
	{
		Component* C = SelectedArr[i];
		if (C)
		{
			GraphicsInfo g = C->GetGraphicsInfo();
			g.x1 += dx;
			g.y1 += dy;
			g.x2 += dx;
			g.y2 += dy;
			C->SetPosition(g);
			UpdateConnectionsFor(C);
		}
	}
}

int ApplicationManager::GetSelectedCount() const
{
	return SelectedCount;
}

Component* ApplicationManager::GetComponentAt(int x, int y) const
{
	for (int i = CompCount - 1; i >= 0; --i)
		if (CompList[i] && CompList[i]->ContainsPoint(x, y))
			return CompList[i];
	return nullptr;
}

void ApplicationManager::RemoveComponent(Component* C)
{
	if (!C) return;

	// 1. Delete ALL connections attached to this component
	for (int i = 0; i < CompCount; i++)
	{
		Connection* conn = dynamic_cast<Connection*>(CompList[i]);
		if (!conn) continue;

		Component* srcOwner = conn->getSourcePin() ? conn->getSourcePin()->getComponent() : nullptr;
		Component* dstOwner = conn->getDestPin() ? conn->getDestPin()->getComponent() : nullptr;

		if (srcOwner == C || dstOwner == C)
		{
			// --- CLEAN OUTPUT PIN ---
			OutputPin* out = conn->getSourcePin();
			if (out)
				out->RemoveConnection(conn);

			// --- CLEAN INPUT PIN ---
			InputPin* in = conn->getDestPin();
			if (in)
				in->RemoveConnection();   // <--- THIS MAKES THE PIN FREE AGAIN

			// NOW it is safe to delete the connection
			delete conn;

			// Shift component list
			for (int j = i; j < CompCount - 1; j++)
				CompList[j] = CompList[j + 1];

			CompList[CompCount - 1] = nullptr;
			CompCount--;
			i--; // stay at same index
		}
	}

	// 2. Remove the component itself
	int idx = -1;
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] == C) { idx = i; break; }

	if (idx != -1)
	{
		delete C;

		for (int j = idx; j < CompCount - 1; j++)
			CompList[j] = CompList[j + 1];

		CompList[CompCount - 1] = nullptr;
		CompCount--;
	}

}

void ApplicationManager::UpdateConnectionsFor(Component* C) const
{
	// Recompute connection endpoints to point to center of owner components (simple approach)
	for (int i = 0; i < CompCount; ++i)
	{
		Connection* conn = static_cast<Connection*>(CompList[i]);
		if (!conn) continue;
		OutputPin* op = conn->getSourcePin();
		InputPin* ip = conn->getDestPin();
		if (op && ip)
		{
			Component* ownerOut = op->getComponent();
			Component* ownerIn = ip->getComponent();
			if (ownerOut)
			{
				GraphicsInfo gg = conn->GetGraphicsInfo();
				GraphicsInfo go = ownerOut->GetGraphicsInfo();
				gg.x1 = (go.x1 + go.x2) / 2; gg.y1 = (go.y1 + go.y2) / 2;
				conn->SetGraphicsInfo(gg);
			}
			if (ownerIn)
			{
				GraphicsInfo gg = conn->GetGraphicsInfo();
				GraphicsInfo gi = ownerIn->GetGraphicsInfo();
				gg.x2 = (gi.x1 + gi.x2) / 2; gg.y2 = (gi.y1 + gi.y2) / 2;
				conn->SetGraphicsInfo(gg);
			}
		}
	}
}

void ApplicationManager::SetClipboard(Component* C)
{
	if (ClipboardComp) { delete ClipboardComp; ClipboardComp = nullptr; }
	if (C) ClipboardComp = C->Clone();
}

Component* ApplicationManager::GetClipboard() const { return ClipboardComp; }

void ApplicationManager::RunSimulation()
{
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Operate();
	}
}

bool ApplicationManager::ValidateCircuit()
{
	int switchCount = 0;
	int ledCount = 0;

	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<CSwitch*>(CompList[i]))
			switchCount++;
		if (dynamic_cast<CLED*>(CompList[i]))
			ledCount++;
	}

	if (switchCount == 0 || ledCount == 0)
	{
		GetOutput()->PrintMsg("Validation Failed: Circuit must contain at least one Switch AND one LED.");
		return false;
	}

	GetOutput()->PrintMsg("Validation Succeeded! Circuit ready for simulation.");
	return true;
}

void ApplicationManager::CreateTruthTable()
{
	if (!ValidateCircuit()) return;

	std::vector<CSwitch*> switches;
	std::vector<CLED*> leds;

	// 1. Gather all Switches and LEDs
	for (int i = 0; i < CompCount; i++)
	{
		if (CSwitch* pS = dynamic_cast<CSwitch*>(CompList[i]))
			switches.push_back(pS);

		if (CLED* pL = dynamic_cast<CLED*>(CompList[i]))
			leds.push_back(pL);
	}

	int N = switches.size(); // Number of input variables
	int M = leds.size();     // Number of output variables

	if (N == 0 || M == 0) return;

	int numRows = 1 << N; // 2^N rows

	// Output the table header
	std::cout << "\n--- TRUTH TABLE ---\n";
	std::cout << "Inputs (S): ";
	for (int i = 0; i < N; i++)
		std::cout << "S" << i + 1 << " ";
	std::cout << "| Outputs (L): ";
	for (int i = 0; i < M; i++)
		std::cout << "L" << i + 1 << " ";
	std::cout << "\n";

	// 2. Loop through all 2^N input combinations
	for (int i = 0; i < numRows; i++)
	{
		// Set CSwitch status for the current pattern (j-th bit of i)
		for (int j = 0; j < N; j++)
		{
			STATUS currentStatus = (i & (1 << j)) ? HIGH : LOW;
			switches[j]->SetSwitchStatus(currentStatus);
			std::cout << (currentStatus == HIGH ? 1 : 0) << "  ";
		}

		// 3. Run the simulation to propagate values
		RunSimulation();

		std::cout << " | ";

		// 4. Read CLED status (the output)
		for (int j = 0; j < M; j++)
		{
			STATUS outputStatus = (STATUS)leds[j]->GetInputPinStatus(1);
			std::cout << (outputStatus == HIGH ? 1 : 0) << "  ";
		}
		std::cout << "\n";
	}

	std::cout << "-------------------\n";
	GetOutput()->PrintMsg("Truth Table generated and output to console/terminal.");
}
////////////////////////////////////////////////////////UNDO AND REDO Functions///////////////////////////////////////////////////

// record Action function( a function that stores any action done in the projec in the undo stack ) 

void ApplicationManager::RecordAction(Action* pAct)
{
	if (pAct != NULL)
	{
		UndoStack.push(pAct);//When a user performs a new action(e.g., adds an AND gate), it is pushed onto the top of the undo stack

		// Clear the Redo stack because a new action invalidates the redo history
		while (!RedoStack.empty())
		{
			Action* pDel = RedoStack.top();
			RedoStack.pop();
			delete pDel; // pDel destructor will handle its components
		}
	}
}
// undo function 
void ApplicationManager::UndoLastAction()
{
	if (UndoStack.empty())
	{
		GetOutput()->PrintMsg("No actions to undo.");
		return;
	}

	Action* pAct = UndoStack.top();
	UndoStack.pop();

	pAct->Undo(); // Perform the specific undo behavior
	RedoStack.push(pAct); // Move to Redo stack

	GetOutput()->PrintMsg("Action Undone");
	UpdateInterface();
}




// Redo function 

void ApplicationManager::RedoLastAction()
{
	if (RedoStack.empty())
	{
		GetOutput()->PrintMsg("No actions to redo.");
		return;
	}

	Action* pAct = RedoStack.top();
	RedoStack.pop();

	pAct->Redo(); // Perform the specific redo behavior
	UndoStack.push(pAct); // Move back to Undo stack

	GetOutput()->PrintMsg("Action Redone");
	UpdateInterface();
}



// safe removal function 


void ApplicationManager::RemoveComponentOnly(Component* C)
{
	if (!C) return;

	// Find the component in the list
	int index = -1;
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] == C) { index = i; break; }

	if (index != -1)
	{
		// Shift elements to fill the gap
		for (int j = index; j < CompCount - 1; j++)
			CompList[j] = CompList[j + 1];

		CompList[CompCount - 1] = NULL;
		CompCount--;
	}
}