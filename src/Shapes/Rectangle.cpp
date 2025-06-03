#include "Rectangle.h"
#include "Utils.h"
#include <cmath>

Rectangle::Rectangle(): Rectangle(Vec2D::Zero, Vec2D::Zero)
{

}

Rectangle::Rectangle(const Vec2D& topLeft, unsigned int width, unsigned int height)
{
    mPoints.push_back(topLeft);
    mPoints.push_back(Vec2D(topLeft.GetX() + width - 1, topLeft.GetY() + height - 1));
}

Rectangle::Rectangle(const Vec2D& topLeft, const Vec2D& bottomRight)
{
    mPoints.push_back(topLeft);
    mPoints.push_back(bottomRight);
}

float Rectangle::GetWidth() const
{
    return GetBottomRightPoint().GetX() - GetTopLeftPoint().GetX() + 1;
}

float Rectangle::GetHeight() const
{
    return GetBottomRightPoint().GetY() - GetTopLeftPoint().GetY() + 1;
}

void Rectangle::MoveTo(const Vec2D& position)
{
    float width = GetWidth();
    float height = GetHeight();

    SetTopLeftPoint(position);
    SetBottomRightPoint(Vec2D(position.GetX() + width - 1, position.GetY() + height - 1));
}

Vec2D Rectangle::GetCenterPoint() const
{
    return Vec2D(GetTopLeftPoint().GetX() + GetWidth()/2.0f, GetTopLeftPoint().GetY() + GetHeight()/2.0f);
}

bool Rectangle::Intersects(const Rectangle& otherRect) const
{
    return !(otherRect.GetBottomRightPoint().GetX() < GetTopLeftPoint().GetX() ||
            otherRect.GetTopLeftPoint().GetX() > GetBottomRightPoint().GetX() ||
            otherRect.GetBottomRightPoint().GetY() < GetTopLeftPoint().GetY() ||
            otherRect.GetTopLeftPoint().GetY() > GetBottomRightPoint().GetY());
}

bool Rectangle::ContainsPoint(const Vec2D& point) const
{
    bool withinX = point.GetX() >= GetTopLeftPoint().GetX() && point.GetX() <= GetBottomRightPoint().GetX();
    bool withinY = point.GetY() >= GetTopLeftPoint().GetY() && point.GetY() <= GetBottomRightPoint().GetY();

    return withinX && withinY;
}

Rectangle Rectangle::Inset(const Rectangle rect, Vec2D& insets)
{
    return Rectangle(rect.GetTopLeftPoint() + insets, rect.GetWidth() - 2*insets.GetX(), rect.GetHeight() -2*insets.GetY());
}

std::vector<Vec2D> Rectangle::GetPoints() const
{
    std::vector<Vec2D> points;

    points.push_back(mPoints[0]);
    points.push_back(Vec2D(mPoints[1].GetX(), mPoints[0].GetY()));
    points.push_back(mPoints[1]);
    points.push_back(Vec2D(mPoints[0].GetX(), mPoints[1].GetY()));
    
    return points;
}