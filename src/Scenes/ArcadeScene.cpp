#include "ArcadeScene.h"
#include "Screen.h"
#include "Line2D.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Color.h"

ArcadeScene::ArcadeScene()
{

}

void ArcadeScene::Init()
{

}

void ArcadeScene::Update(uint64_t dt)
{

}

void ArcadeScene::Draw(Screen& theScreen)
{
        Line2D line = {Vec2D(0, 0), Vec2D(theScreen.GetWidth(), theScreen.GetHeight())};
        Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};
        Rectangle rectangle = {Vec2D(theScreen.GetWidth()/2 - 25, theScreen.GetWidth()/2 - 25), 50, 50};
        Circle circle {Vec2D(theScreen.GetWidth()/2 + 50, theScreen.GetWidth()/2 + 50), 50};

        theScreen.Draw(triangle, Color::Red(), true, Color::Red());
        theScreen.Draw(rectangle, Color::Pink(), true, Color::Pink());
        theScreen.Draw(circle, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));
}

const std::string& ArcadeScene::GetSceneName() const
{
    static std::string sceneName = "Arcade Scene";
    return sceneName;
}

std::unique_ptr<Scene> GetScene(eGame game)
{
    switch(game)
    {
        case TETRIS:
            break;
        case BREAKOUT:
            break;
        case ASTEROIDS:
            break;
        case PACMAN:
            break;
        default:
            break;
    }

    return nullptr;
}