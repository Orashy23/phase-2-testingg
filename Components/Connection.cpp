#include "Connection.h"
#include <cmath>
#include <algorithm>

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo, IsSelected());
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
bool Connection::ContainsPoint(int x, int y) const
{
    int x1 = m_GfxInfo.x1, y1 = m_GfxInfo.y1, x2 = m_GfxInfo.x2, y2 = m_GfxInfo.y2;
    int minx = (std::min)(x1, x2) - 6;
    int maxx = (std::max)(x1, x2) + 6;
    int miny = (std::min)(y1, y2) - 6;
    int maxy = (std::max)(y1, y2) + 6;
    if (x < minx || x > maxx || y < miny || y > maxy) return false;
    double dx = x2 - x1, dy = y2 - y1, L2 = dx * dx + dy * dy;
    if (L2 == 0.0) return (hypot(x - x1, y - y1) <= 6.0);
    double t = ((x - x1) * dx + (y - y1) * dy) / L2;
    if (t < 0.0) t = 0.0; if (t > 1.0) t = 1.0;
    double px = x1 + t * dx, py = y1 + t * dy;
    return (hypot(x - px, y - py) <= 6.0);
}
