#pragma once

#include "entities/LivingEntity.hpp"

class Player : public LivingEntity {
   public:
    Player(int health, const sf::Vector2f& pos);

   private:
};
