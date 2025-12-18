#pragma once

#include "entities/Entity.hpp"

class LivingEntity : public Entity {
   public:
    LivingEntity(int max_health);

    int getHealth() const;

    void decreaseHealth(int damage);
    void increaseHealth(int healing);

   private:
    bool alive_ = true;
    int max_health_;
    int health_;
};
