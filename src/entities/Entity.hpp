#pragma once

#include <SFML/System/Vector2.hpp>

class Entity {
   public:
    Entity();
    Entity(const sf::Vector2f& pos, const sf::Vector2f velocity);

    void setPos(const sf::Vector2f& new_pos);
    const sf::Vector2f& getPos() const;

    void setVelocity(const sf::Vector2f& new_velocity);
    const sf::Vector2f& getVelocity() const;

   private:
    sf::Vector2f pos_;
    sf::Vector2f velocity_;
};
