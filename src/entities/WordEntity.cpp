#include "WordEntity.hpp"

WordEntity::WordEntity(const std::string& text, const sf::Vector2f& position,
                       const sf::Vector2f& velocity)
    : text_{text}, Entity(position, velocity) {}

const std::string& WordEntity::getText() const { return text_; }

char WordEntity::getCurrentLetter() const { return *(text_.begin() + typed_); }

void WordEntity::incTyped() {
    if (typed_ <= text_.size()) {
        ++typed_;
    }
}

size_t WordEntity::getTyped() const { return typed_; }

void WordEntity::flushTyped() { typed_ = 0; }
