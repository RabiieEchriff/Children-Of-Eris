#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Planet.h"


sf::Font pixelex;

class font_methods {
public:
	void load_pixelex();
	sf::Text set_text(sf::Text text, unsigned int char_size, sf::Vector2f pos);
};

void font_methods::load_pixelex() {
	pixelex.loadFromFile("res/fonts/pixelex.ttf");
}

sf::Text font_methods::set_text(sf::Text text, unsigned int char_size, sf::Vector2f pos) {
	text.setFont(pixelex);
	text.setCharacterSize(char_size);
	text.setOrigin(sf::Vector2f(text.getCharacterSize() / 2, text.getCharacterSize() / 2));
	text.setPosition(sf::Vector2f(pos.x, pos.y));
	return text;
}

struct selector {
	int scene;
	int level;
	int ship;
};