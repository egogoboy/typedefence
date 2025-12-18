#include "Entity.hpp"

#include <SFML/System/Vector2.hpp>

Entity::Entity() : text_{""}, pos_{0, 0}, velocity_{0, 0} {}

Entity::Entity(const std::string& text, const sf::Vector2f& pos,
               const sf::Vector2f velocity)
    : text_{text}, pos_{pos}, velocity_{velocity} {}

const std::string& Entity::getText() const { return this->text_; }

void Entity::setPos(const sf::Vector2f& new_pos) { this->pos_ = new_pos; }

const sf::Vector2f& Entity::getPos() const { return this->pos_; }

void Entity::setVelocity(const sf::Vector2f& new_velocity) {
    this->velocity_ = new_velocity;
}

const sf::Vector2f& Entity::getVelocity() const { return this->velocity_; }

void Entity::incTyped() { ++typed_; }
size_t Entity::getTyped() const { return typed_; }
void Entity::flushTyped() { typed_ = 0; }
