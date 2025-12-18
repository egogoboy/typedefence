#include "Game.hpp"

#include <SFML/Graphics.hpp>

Game::Game() : window_(sf::VideoMode({800, 600}), WINDOW_NAME) {}

void Game::run() {
    while (window_.isOpen()) {
        while (auto event = window_.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window_.close();
        }

        window_.clear(sf::Color(219, 216, 208));
        window_.display();
    }
}
