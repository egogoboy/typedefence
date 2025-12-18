#pragma once

#include <SFML/System/Vector2.hpp>
#include <string>

class Entity {
   public:
    Entity();
    Entity(const std::string& text, const sf::Vector2f& pos,
           const sf::Vector2f velocity);

    const std::string& getText() const;

    void setPos(const sf::Vector2f& new_pos);
    const sf::Vector2f& getPos() const;

    void setVelocity(const sf::Vector2f& new_velocity);
    const sf::Vector2f& getVelocity() const;

    void incTyped();
    size_t getTyped() const;
    void flushTyped();

   private:
    std::string text_;
    size_t typed_ = 0;
    sf::Vector2f pos_;
    sf::Vector2f velocity_;
};
