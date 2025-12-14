#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
    pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
    pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{
    string userInput = "";
    char pressedKey;

    // Print empty string to the status bar
    pOut->PrintMsg(userInput);

    while (true)
    {
        pWind->WaitKeyPress(pressedKey);

        // If user presses ESC ? Cancel input
        if (pressedKey == 27)   // ESC key
        {
            pOut->ClearStatusBar();
            return "";
        }

        // If user presses ENTER ? Finish input
        if (pressedKey == 13)   // Enter key
            return userInput;

        // If Backspace:
        if (pressedKey == 8 && userInput.size() > 0)
        {
            userInput.pop_back();
        }
        else if (pressedKey >= 32 && pressedKey <= 126) // Printable characters
        {
            userInput += pressedKey;
        }

        // Display updated text
        pOut->PrintMsg(userInput);
    }
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
    int x, y;
    pWind->WaitMouseClick(x, y);

    // ------------ DESIGN MODE --------------
    if (UI.AppMode == DESIGN)
    {
        // Click in the toolbar area
        if (y >= 0 && y < UI.ToolBarHeight)
        {
            // Calculate which icon was clicked
            int clickedItemOrder = x / UI.ToolItemWidth;

            switch (clickedItemOrder)
            {
                // MODIFIED: Corrected undefined names to use the constants from Defs.H.
                // Assumes ITM_BUFFER and ITM_NOT were corrected in Defs.H from ITM_BUFFER2/ITM_NOT2.
            case ITM_BUFFER:
                return ADD_Buff; break;
            case ITM_NOT:
                return ADD_INV; break;

            case ITM_AND2:
                return ADD_AND_GATE_2; break;
            case ITM_OR2:
                return ADD_OR_GATE_2; break;
            case ITM_NAND2:
                return ADD_NAND_GATE_2; break;
            case ITM_NOR2:
                return ADD_NOR_GATE_2; break;
            case ITM_XOR2:
                return ADD_XOR_GATE_2; break;
            case ITM_XNOR2:
                return ADD_XNOR_GATE_2; break;
            case ITM_AND3:
                return ADD_AND_GATE_3; break;
            case ITM_NOR3:
                return ADD_NOR_GATE_3; break;
            case ITM_XOR3:
                return ADD_XOR_GATE_3; break;

                // MODIFIED: Corrected ITM_Switch to ITM_SWITCHES
            case ITM_SWITCHES:
                return ADD_Switch; break;
                // MODIFIED: Corrected ITM_LED to ITM_LEDS
            case ITM_LEDS:
                return ADD_LED; break;
                // MODIFIED: Corrected ITM_Connection to ITM_CONNECTIONCOMPONENT
            case ITM_CONNECTIONCOMPONENT:
                return ADD_CONNECTION; break;

                // The undefined names (ITM_Label and ITM_TRUTH_TABLE) are removed from the Design Mode switch block, 
                // as they are not defined as DsgnMenuItem constants. The rest of the actions are correct.
            case ITM_SELECT:
                return SELECT; break;
            case ITM_UNSELECT:
                return UNSELECT;
                break;
            case ITM_COPY:
                return COPY; break;
            case ITM_CUT:
                return CUT; break;
            case ITM_PASTE:
                return PASTE; break;
            case ITM_DELETE:
                return DEL; break;
            case ITM_UNDO:
                return UNDO; break;
            case ITM_REDO:
                return REDO; break;
            case ITM_SAVE:
                return SAVE; break;
            case ITM_LOAD:
                return LOAD; break;
            case ITM_MOVE:
                return MOVE; break;
            case ITM_MULTIPLE:
                return Multi; break;
            case ITM_LABEL:
                return ADD_Label; break;
            case ITM_EDITLABEL:
                return EDIT_Label; break;
            case ITM_SWITCH:
                return SIM_MODE; break;

            case ITM_EXIT:
                return EXIT; break;

            default:
                return DSN_TOOL; // Clicked empty area in toolbar
            }
        }

        // Click in the drawing area
       /* else if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
        {
            return SELECT;
        }*/

        // Status bar
        else
        {
            return STATUS_BAR;
        }
    }

    // ------------ SIMULATION MODE --------------
    else if (UI.AppMode == SIMULATION)
    {
        if (y >= 0 && y < UI.ToolBarHeight)
        {
            int clickedItemOrder = x / UI.ToolItemWidth;

            switch (clickedItemOrder)
            {
            case ITM_SIM:      return SIMULATE; break;
            case ITM_TRUTH:    return TRUTH_TABLE; break;
            case ITM_SIM_VALIDATE: return VALIDATE;
            case ITM_SIM_PROBE: return ADD_Probe;
            case ITM_Back_DSN_MODE: return DSN_MODE;
            case ITM_EXIT:     return EXIT; break;

            default:           return DSN_TOOL;
            }
        }
    }
}



Input::~Input()
{
}
