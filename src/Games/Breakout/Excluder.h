#ifndef GAMES_BREAKOUT_EXCLUDER_H_
#define GAMES_BREAKOUT_EXCLUDER_H_

#include "Rectangle.h"
#include "BoundaryEdge.h"

class Excluder
{
public:
    virtual ~Excluder() {}
    void Init(const Rectangle& rect, bool reverseNormals = false);
    bool HasCollided(const Rectangle& rect, BoundaryEdge& edge) const;
    Vec2D GetCollisionOffset(const Rectangle& rect) const;
    inline Rectangle& GetRectangle() {return mRect;}
    void MoveBy(const Vec2D& delta);
    void MoveTo(const Vec2D& point);
    const BoundaryEdge& GetEdge(EdgeType edge) const;
private:
    void SetupEdges();
    Rectangle mRect;
    BoundaryEdge mEdges[NUM_EDGES];
    bool mReverseNormals;
};

#endif /* GAMES_BREAKOUT_EXCLUDER_H_ */