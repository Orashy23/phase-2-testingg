#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar(bool x) const
{
	UI.AppMode = DESIGN;	//Design Mode
	string MenuItemImages[ITM_DSN_CNT];
	if (x == true) {


		MenuItemImages[ITM_BUFFER] = "Images\\Menu\\GATE_BUFFER.jpg";
		MenuItemImages[ITM_NOT] = "Images\\Menu\\GATE_NOT.jpg";

		MenuItemImages[ITM_AND2] = "Images\\Menu\\GATE_AND2.jpg";
		MenuItemImages[ITM_OR2] = "Images\\Menu\\GATE_OR2.jpg";
		MenuItemImages[ITM_NAND2] = "Images\\Menu\\GATE_NAND2.jpg";
		MenuItemImages[ITM_NOR2] = "Images\\Menu\\GATE_NOR2.jpg";
		MenuItemImages[ITM_XOR2] = "Images\\Menu\\GATE_XOR2.jpg";
		MenuItemImages[ITM_XNOR2] = "Images\\Menu\\GATE_XNOR2.jpg";

		MenuItemImages[ITM_AND3] = "Images\\Menu\\GATE_AND3.jpg";

		MenuItemImages[ITM_NOR3] = "Images\\Menu\\GATE_NOR3.jpg";
		MenuItemImages[ITM_XOR3] = "Images\\Menu\\GATE_XOR3.jpg";

		MenuItemImages[ITM_SWITCHES] = "Images\\Menu\\SWITCH_OFF.jpg";
		MenuItemImages[ITM_LEDS] = "Images\\Menu\\LAMP_OFF.jpg";
		MenuItemImages[ITM_CONNECTIONCOMPONENT] = "Images\\Menu\\CONNECTION_WIRE.jpg";


		MenuItemImages[ITM_SELECT] = "Images\\Menu\\SELECT.jpg";
		MenuItemImages[ITM_UNSELECT] = "Images\\Menu\\UNSELECT.jpg";
		MenuItemImages[ITM_COPY] = "Images\\Menu\\COPY1.jpg";
		MenuItemImages[ITM_CUT] = "Images\\Menu\\CUT.jpg";
		MenuItemImages[ITM_PASTE] = "Images\\Menu\\PASTE.jpg";
		MenuItemImages[ITM_DELETE] = "Images\\Menu\\DELETE.jpg";
		MenuItemImages[ITM_UNDO] = "Images\\Menu\\UNDO.jpg";
		MenuItemImages[ITM_REDO] = "Images\\Menu\\REDO.jpg";
		MenuItemImages[ITM_SAVE] = "Images\\Menu\\SAVE.jpg";
		MenuItemImages[ITM_LOAD] = "Images\\Menu\\LOAD.jpg";
		MenuItemImages[ITM_MOVE] = "Images\\Menu\\MOVE.jpg";
		MenuItemImages[ITM_MULTIPLE] = "Images\\Menu\\MULTIPLE.jpg";
		MenuItemImages[ITM_LABEL] = "Images\\Menu\\LABEL.jpg";
		MenuItemImages[ITM_EDITLABEL] = "Images\\Menu\\EDITLABEL.jpg";

		MenuItemImages[ITM_SWITCH] = "Images\\Menu\\sim_mood.jpg";
		MenuItemImages[ITM_EXIT] = "Images\\Menu\\Exit.jpg";
		MenuItemImages[ITM_EMTY] = "Images\\Menu\\EMTY.jpg";



		for (int i = 0; i < ITM_DSN_CNT - 1; i++)
			pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);

		// Draw a line under the toolbar
		pWind->SetPen(BLACK, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	}
	else {
		MenuItemImages[ITM_EMTY] = "Images\\Menu\\EMTY.jpg";
		for (int i = 0; i < ITM_DSN_CNT - 1; i++)
			pWind->DrawImage(MenuItemImages[ITM_DSN_CNT - 1], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);

		// Draw a line under the toolbar
		pWind->SetPen(BLACK, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	}
}
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar(bool x) const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	string SimItemImages[ITM_SIM_CNT];
	if (x == true) {

		string SimItemImages[ITM_SIM_CNT];
		SimItemImages[ITM_SIM] = "Images\\Menu\\sim-Run.jpg"; // Run Simulation
		SimItemImages[ITM_SIM_VALIDATE] = "Images\\Menu\\Validate.jpg"; // Validate Circuit 
		SimItemImages[ITM_TRUTH] = "Images\\Menu\\Truth_Table.jpg";	// Truth Table 
		SimItemImages[ITM_SIM_PROBE] = "Images\\Menu\\Probe.jpg"; // Probe
		SimItemImages[ITM_Back_DSN_MODE] = "Images\\Menu\\dsn_mood.jpg";	//switch back to design mode 


		for (int i = 0; i < 5; i++) // Hna 3lshan Yrsm The Tool Bar Buttons 
		{
			pWind->DrawImage(SimItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		}
		pWind->SetPen(BLACK, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	}
	else {
		for (int i = 0; i < 5; i++) // Hna 3lshan Yrsm The Tool Bar Buttons 
		{
			SimItemImages[ITM_EMTY1] = "Images\\Menu\\EMTY.jpg";
			pWind->DrawImage(SimItemImages[5], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		}
	}
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_AND2_HI.jpg";
	else
		GateImage = "Images\\Gates\\GATE_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\BUFFER_Hi.jpg";
	else
		GateImage = "Images\\Gates\\BUFFER.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_NOT_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_NOT.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_OR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_NAND2_HI.jpg";
	else
		GateImage = "Images\\Gates\\GATE_NAND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_NOR2_HI.jpg";
	else
		GateImage = "Images\\Gates\\GATE_NOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_XOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_XNOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_AND3_HI.jpg";
	else
		GateImage = "Images\\Gates\\GATE_AND3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\GATE_XOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_NOR3_HI.jpg";
	else
		GateImage = "Images\\Gates\\GATE_NOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawSWITCHS(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWITCH_ON.jpg";
	else
		GateImage = "Images\\Gates\\SWITCH_OFF.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LAMP_ON.jpg";
	else
		GateImage = "Images\\Gates\\LAMP_OFF.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	// Set Wire Color (3lshan A3raf A Highlight Or No)
	if (selected) {
		pWind->SetPen(UI.SelectColor, 3);
	}
	else {
		pWind->SetPen(UI.ConnColor, 3);
	}
	// Ageeb El Points Mn F(x);
	double X1 = r_GfxInfo.x1;
	double X2 = r_GfxInfo.x2;
	double Y1 = r_GfxInfo.y1;
	double Y2 = r_GfxInfo.y2;
	double Midx = (X1 + X2) / 2;
	// Horizontal Segment ;
	pWind->DrawLine(X1, Y1, Midx, Y1);
	// Vertical Segment 
	pWind->DrawLine(Midx, Y1, Midx, Y2);
	// Final Segment 
	// MODIFIED: Corrected the final segment endpoint to (X2, Y2) for a proper 3-segment connection path.
	pWind->DrawLine(Midx, Y2, X2, Y2); // Corrected from pWind->DrawLine(Midx,Y2,X2,Y1);
}


Output::~Output()
{
	delete pWind;
}
