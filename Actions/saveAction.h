#pragma once
#include "..\ApplicationManager.h"
#include"..\components\AND2.h"
#include"..\components\OR2.h"
#include"..\components\NAND2.h"
#include"..\components\NOR2.h"
#include"..\components\BUFFER.h"
#include"..\components\NOT.h"
#include"..\components\XNOR2.h"
#include"..\components\XOR2.h"
#include"..\components\XOR3.h"
#include"..\components\NOR3.h"
#include"..\components\AND3.h"
#include <fstream>



#pragma once  
#ifndef SAVE_ACTION_H  
#define SAVE_ACTION_H  

#include "Action.h" // Updated include path to correctly locate Action.h  
#include <string>  
using namespace std;
class saveAction : public Action
{
private:
	string fileName;
public:
	saveAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};
#endif
