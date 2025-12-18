#include "Player.hpp"

Player::Player(int health, const sf::Vector2f& pos)
    : LivingEntity(health, pos, {0, 0}) {}
