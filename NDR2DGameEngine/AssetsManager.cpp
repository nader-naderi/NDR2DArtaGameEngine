#include "AssetsManager.hpp"
#include <iostream>

void ArtaEngine::AssetsManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;

	if (tex.loadFromFile(fileName))
	{
		this->_textures[name] = tex;
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
}

sf::Font& ArtaEngine::AssetsManager::GetFont(std::string name)
{
	return this->_fonts.at(name);
}
