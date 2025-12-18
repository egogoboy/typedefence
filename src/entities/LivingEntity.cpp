#include "LivingEntity.hpp"

LivingEntity::LivingEntity(int max_health)
    : max_health_{max_health}, health_{max_health_} {}

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
