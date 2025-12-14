#include "Component.h"


Component::Component(const GraphicsInfo& r_GfxInfo)
    : m_GfxInfo(r_GfxInfo), SelectedFlag(false), m_Label("") {
}

Component::Component() : SelectedFlag(false), m_Label("") {}

Component::~Component() {}

bool Component::ContainsPoint(int x, int y) const
{
    int left = m_GfxInfo.x1;
    int right = m_GfxInfo.x2;
    int top = m_GfxInfo.y1;
    int bottom = m_GfxInfo.y2;
    return (x >= left && x <= right && y >= top && y <= bottom);
}
