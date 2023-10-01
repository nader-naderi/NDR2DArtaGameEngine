#include "InputManager.hpp"

bool ArtaEngine::InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect tempRect(object.getPosition().x, object.getPosition().y,
            object.getGlobalBounds().width, object.getGlobalBounds().height);

        return tempRect.contains(sf::Mouse::getPosition(window));
    }
}

sf::Vector2i ArtaEngine::InputManager::GetMousePosition(sf::RenderWindow& window)
{
    return sf::Mouse::getPosition(window);
}
