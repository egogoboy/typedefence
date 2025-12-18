#include "LivingEntity.hpp"

LivingEntity::LivingEntity(int max_health, const sf::Vector2f& pos,
                           const sf::Vector2f& velocity)
    : max_health_{max_health}, health_{max_health}, Entity(pos, velocity) {}

int LivingEntity::getHealth() const { return health_; }

void LivingEntity::decreaseHealth(int damage) {
    health_ -= damage;
    if (health_ <= 0) {
        alive_ = false;
    }
}

void LivingEntity::increaseHealth(int healing) {
    health_ += healing;

    if (health_ > max_health_) {
        health_ = max_health_;
    }
}
