#pragma once
#include <SFML/Graphics.hpp>


class planet{
public:
	sf::RectangleShape globe;

	sf::Texture planet_texture;

	std::string set_planet(int i,int scene);

	void inmenu(int i);

	void ingame(int level);

	
	int spawn;
	
};


