#include "Breakout.h"
#include <iostream>

void Breakout::Init(GameController& controller)
{
    std::cout << "Break Out Game Init()" << std::endl;
}

void Breakout::Update(uint64_t dt)
{
    std::cout << "Break Out Game Init()" << std::endl;
}

void Breakout::Draw(Screen& screen)
{
    std::cout << "Break Out Game Draw()" << std::endl;
}

std::string Breakout::GetName() const
{
    return "Breakout";
}