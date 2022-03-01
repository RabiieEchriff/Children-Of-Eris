#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class player {
public:
	sf::Texture pt;
	sf::Sprite ps;
	float speed;

	sf::SoundBuffer sb_firing;
	sf::Sound sfx_firing;

	sf::Vector2f sprite_scale;
	sf::Vector2u original_size;
	float text_width;
	float text_height;

	player(std::string t,std::string s, sf::Vector2f rect, float movement_speed) : speed(movement_speed) {
		pt.loadFromFile(t);

		sb_firing.loadFromFile(s);
		sfx_firing.setBuffer(sb_firing);

		text_width = pt.getSize().x;
		text_height = rect.y;

		sprite_scale.x = text_width;
		sprite_scale.y = text_height;

		ps.setScale(sf::Vector2f(0.55, 0.55));
		ps.setOrigin(sf::Vector2f(text_width / 2, text_height / 2));
		ps.setTexture(pt);
		ps.setTextureRect(sf::IntRect(0, rect.x, text_width, rect.y));



	}

	player(int dim) {
		ps.setScale(sf::Vector2f(dim, dim));
		speed = 500;
	}

	void player_controls(float dt, float speed);

};


