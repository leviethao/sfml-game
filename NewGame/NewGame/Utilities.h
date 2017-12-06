#ifndef UTILITIES_H
#define UTILITIES_H

#include "SFML\Audio.hpp"

sf::Sound& loadSound(std::string filename);

float Length(const sf::Vector2f vec);

sf::Vector2f Normalize(const sf::Vector2f vec);

#endif //UTILITIES_H