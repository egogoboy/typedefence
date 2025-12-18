#include "Renderer.hpp"

#include "entities/Player.hpp"

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

void Renderer::drawPlayer(const Player& player) {
    constexpr float outer_radius = 20.f;
    constexpr float inner_radius = 14.f;

    sf::CircleShape border(outer_radius);

    border.setOrigin({outer_radius, outer_radius});
    border.setPosition(player.getPos());
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(TYPED_WORDS_COLOR);
    border.setOutlineThickness(2);

    sf::CircleShape inner_body(inner_radius);
    inner_body.setOrigin({inner_radius, inner_radius});
    inner_body.setPosition(border.getPosition());
    inner_body.setFillColor(TYPED_WORDS_COLOR);

    sf::Text health(font_, "", 14);
    health.setString(std::to_string(player.getHealth()));

    sf::FloatRect bounds = health.getLocalBounds();
    float originX = bounds.getCenter().x - (float)health.getCharacterSize() / 2;

    health.setOrigin(bounds.getCenter());
    health.setPosition({border.getPosition().x, border.getPosition().y + 35});
    health.setFillColor(WORDS_COLOR);

    window_.draw(border);
    window_.draw(inner_body);
    window_.draw(health);
}
