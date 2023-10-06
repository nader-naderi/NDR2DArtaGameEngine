#include "AssetsManager.hpp"
#include <iostream>

void ArtaEngine::AssetsManager::LoadTexture(std::string name, std::string fileName)
{
    sf::Texture tex;

    if (tex.loadFromFile(fileName))
    {
        this->_textures[name] = tex;
    }
    else
    {
        std::cerr << "Failed to load texture: " << name << " from " << fileName << std::endl;
    }
}


sf::Texture& ArtaEngine::AssetsManager::GetTexture(std::string name)
{
	return this->_textures.at(name);
}

void ArtaEngine::AssetsManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->_fonts[name] = font;
	}
    else
    {
        std::cerr << "Failed to load font: " << name << " from " << fileName << std::endl;
    }
}

sf::Font& ArtaEngine::AssetsManager::GetFont(std::string name)
{
	return this->_fonts.at(name);
}
