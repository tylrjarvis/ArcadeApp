#include "GameScene.h"

GameScene::GameScene(std::unique_ptr<Game> optrGame):mGame(std::move(optrGame))
{

}

void GameScene::Init()
{
    mGame->Init(mGameController);
}

void GameScene::Update(uint64_t dt)
{
    mGame->Update(dt);
}

void GameScene::Draw(Screen& screen)
{
    mGame->Draw(screen);
}

const std::string& GetSceneName()
{
    std::string name = "";
    return name;
}