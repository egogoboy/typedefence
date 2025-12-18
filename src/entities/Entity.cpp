#include "Entity.hpp"

#include <SFML/System/Vector2.hpp>

Entity::Entity() : pos_{0, 0}, velocity_{0, 0} {}

Entity::Entity(const sf::Vector2f& pos, const sf::Vector2f velocity)
    : pos_{pos}, velocity_{velocity} {}

void Entity::setPos(const sf::Vector2f& new_pos) { this->pos_ = new_pos; }

const sf::Vector2f& Entity::getPos() const { return this->pos_; }

void Entity::setVelocity(const sf::Vector2f& new_velocity) {
    this->velocity_ = new_velocity;
}

const sf::Vector2f& Entity::getVelocity() const { return this->velocity_; }

void Entity::move(float dt) { pos_ += velocity_ * dt; }
