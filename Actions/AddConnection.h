#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H

#include "Action.h" // In same folder
// We use forward declarations for Pins to avoid include errors here
class Connection;
class InputPin;
class OutputPin;

class AddConnection : public Action
{
private:
    OutputPin* SrcPin;
    InputPin* DstPin;
    int x1, y1, x2, y2;

    // Undo/Redo members
    Connection* pConn;
    bool isUndone;

public:
    AddConnection(ApplicationManager* pApp);
    virtual ~AddConnection();

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
    virtual void Redo();
};

#endif