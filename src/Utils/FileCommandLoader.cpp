#include "FileCommandLoader.h"
#include <fstream>
#include <iostream>
#include "Color.h"
#include "Vec2D.h"

void FileCommandLoader::AddCommand(const Command& command)
{
    mCommands.push_back(command);
}

void FileCommandLoader::LoadFile(const std::string& filePath)
{

}


Color FileCommandLoader::ReadColor(const ParseFuncParams& params)
{
    size_t nextSpacePos = params.line.find_first_of(" ", params.delimitPos+1);
    int r = std::stoi(params.line.substr(params.delimitPos, (nextSpacePos - params.delimitPos)));
    
    size_t lastSpacePos = nextSpacePos;
    nextSpacePos = params.line.find_first_of(" ", lastSpacePos + 1);
    int g = std::stoi(params.line.substr(lastSpacePos+1, nextSpacePos - lastSpacePos));

    lastSpacePos = nextSpacePos;
    nextSpacePos = params.line.find_first_of(" ", lastSpacePos + 1);
    int b = std::stoi(params.line.substr(lastSpacePos+1, nextSpacePos - lastSpacePos));

    int a = std::stoi(params.line.substr(nextSpacePos+1));

    return Color(r, g, b, a);
}

Vec2D FileCommandLoader::ReadSize(const ParseFuncParams& params)
{

}

int FileCommandLoader::ReadInt(const ParseFuncParams& params)
{

}

std::string FileCommandLoader::ReadString(const ParseFuncParams& params)
{

}

char FileCommandLoader::ReadChar(const ParseFuncParams& params)
{

}