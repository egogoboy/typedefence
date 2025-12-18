#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Game {
   public:
    Game();
    void run();

   private:
    void handleInput();
    void update();
    void render();

    sf::RenderWindow window_;

    const std::string WINDOW_NAME = "typedefence";
};
