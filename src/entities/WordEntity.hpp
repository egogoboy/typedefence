#pragma once

#include <string>

#include "entities/LivingEntity.hpp"

class WordEntity : public LivingEntity {
   public:
    explicit WordEntity(const std::string& text, const sf::Vector2f& position,
                        const sf::Vector2f& velocity);

    const std::string& getText() const;

    char getCurrentLetter() const;

    void incTyped();

    size_t getTyped() const;

    void flushTyped();

   private:
    std::string text_;
    size_t typed_ = 0;
};
