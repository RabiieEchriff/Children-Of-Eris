#pragma once
#include <SFML/Graphics.hpp>

sf::Time elapsed_time4;
sf::Time delta_time4;
float dt_seconds4;
sf::Clock clock4;

class background {
public:
	sf::Texture bg_texture;
	sf::RectangleShape bg;

	background(std::string texture) {
		bg_texture.loadFromFile(texture);
		bg_texture.setRepeated(true);
		bg.setSize(sf::Vector2f(690, 500 * 2));
		bg.setTextureRect(sf::IntRect(0, 0, 690, 500 * 2));
		bg.setTexture(&bg_texture);
		bg.setPosition(sf::Vector2f(0, -500));
	}

	void bg_move();

};

void background::bg_move() {

	sf::Time delta_time4 = clock4.restart();
	elapsed_time4 += delta_time4;

	dt_seconds4 = delta_time4.asSeconds();

	sf::Vector2f bgxy = bg.getPosition();

	if (bgxy.y < 0) {
		bg.move(sf::Vector2f(0, 280 * dt_seconds4));
	}
	if (bgxy.y >= 0) {
		bg.setPosition(sf::Vector2f(0, -499.9));
	}
}

