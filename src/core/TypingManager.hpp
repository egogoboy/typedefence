#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

class TypingManager {
   public:
    TypingManager() = default;

    std::optional<char> getChar(const sf::Event& event) {
        if (auto type_event = event.getIf<sf::Event::TextEntered>()) {
            char symbol = type_event->unicode;
            if (isLetter(symbol)) {
                return symbol;
            }
        }
        return std::nullopt;
    }

   private:
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};
