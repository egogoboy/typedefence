#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>

#include "entities/WordEntity.hpp"

class Game {
   public:
    Game();
    void run();

   private:
    void handleInput();
    void update();
    void render();

    sf::RenderWindow window_;
    std::vector<std::unique_ptr<WordEntity>> words_;

    const std::string WINDOW_NAME = "typedefence";
};
