#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow& window, sf::Font& font)
    : window_{window}, font_{font} {}

void Renderer::drawWordEntities(
    const std::vector<std::unique_ptr<WordEntity>>& words_) {
    for (auto& word : words_) {
        sf::Text sfText(font_, word->getText(), 16);

        sf::FloatRect bounds = sfText.getLocalBounds();
        float originX =
            bounds.getCenter().x - (float)sfText.getCharacterSize() / 2;

        sfText.setOrigin({originX, bounds.getCenter().y + 15});
        sfText.setPosition({word->getPos().x, word->getPos().y});
        sfText.setFillColor(WORDS_COLOR);

        window_.draw(sfText);

        if (word->getTyped() != 0) {
            sf::Text sfTypedText(
                font_,
                std::string(word->getText().begin(),
                            word->getText().begin() + word->getTyped()),
                sfText.getCharacterSize());

            sfTypedText.setOrigin(sfText.getOrigin());

            sfTypedText.setPosition(sfText.getPosition());
            sfTypedText.setFillColor(TYPED_WORDS_COLOR);

            window_.draw(sfTypedText);
        }

        sf::CircleShape sfCircle(8);
        sfCircle.setPosition(word->getPos());
        sfCircle.setFillColor(WORDS_COLOR);

        window_.draw(sfCircle);
    }
}
