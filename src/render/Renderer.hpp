#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "entities/Player.hpp"
#include "entities/WordEntity.hpp"

class Renderer {
   public:
    Renderer(sf::RenderWindow& window, sf::Font& font);

    void drawWordEntities(
        const std::vector<std::unique_ptr<WordEntity>>& words_);

    void drawPlayer(const Player& player);

   private:
    sf::RenderWindow& window_;
    sf::Font& font_;

    const sf::Color WORDS_COLOR = sf::Color(61, 83, 148);
    const sf::Color TYPED_WORDS_COLOR = sf::Color(1, 23, 88);
};
