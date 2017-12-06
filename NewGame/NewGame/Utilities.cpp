#include "Utilities.h"


sf::Sound& loadSound(std::string filename)
{
	sf::SoundBuffer *buffer = new sf::SoundBuffer();
	buffer->loadFromFile(filename);
	return sf::Sound(*buffer);
}

float Length(const sf::Vector2f vec)
{
	return std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
}

sf::Vector2f Normalize(const sf::Vector2f vec)
{
	float length = Length(vec);
	return sf::Vector2f(vec.x / length, vec.y / length);
}