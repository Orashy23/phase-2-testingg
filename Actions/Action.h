class Action
{
protected:
    ApplicationManager* pManager;
public:
    Action(ApplicationManager* pApp) { pManager = pApp; }
    virtual ~Action() {} // <--- ENSURE THIS LINE EXISTS

    virtual void ReadActionParameters() = 0;
    virtual void Execute() = 0;
    virtual void Undo() = 0;
    virtual void Redo() = 0;
};