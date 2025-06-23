#ifndef SHAPES_RECTANGLE_H_
#define SHAPES_RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape 
{
    public:
        Rectangle();
        Rectangle(const Vec2D& topLeft, unsigned int width, unsigned int height);
        Rectangle(const Vec2D& topLeft, const Vec2D& bottomRight);

        void SetTopLeftPoint(const Vec2D& topLeft) {mPoints[0] = topLeft;}
        void SetBottomRightPoint(const Vec2D& bottomRight) {mPoints[1] = bottomRight;}

        Vec2D GetTopLeftPoint() const {return mPoints[0];}
        Vec2D GetBottomRightPoint() const {return mPoints[1];}

        float GetWidth() const;
        float GetHeight() const;

        void MoveTo(const Vec2D& position);

        virtual Vec2D GetCenterPoint() const override;

        bool Intersects(const Rectangle& otherRect) const;
        bool ContainsPoint(const Vec2D& point) const;

        static Rectangle Inset(const Rectangle rect, Vec2D& insets);

        virtual std::vector<Vec2D> GetPoints() const override;
};

#endif /* SHAPES_RECTANGLE_H_*/