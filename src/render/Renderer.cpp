#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow& window, sf::Font& font)
    : window_{window}, font_{font} {}

void Renderer::drawWordEntities(
    const std::vector<std::unique_ptr<WordEntity>>& words_) {
    for (auto& word : words_) {
        const std::string& text = word->getText();

        sf::Text sfText(font_, text, 48);
        sfText.setPosition(word->getPos());
        sfText.setFillColor(sf::Color::Black);

        window_.draw(sfText);
    }
}
