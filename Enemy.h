#pragma once
#include <SFML/Graphics.hpp>


class enemy {
public:
	sf::Texture et;
	sf::Sprite es;
	float ms;

	sf::Vector2f sprite_scale;
	sf::Vector2u original_size;
	float text_width;
	float text_height;
	int health;
	int og_health;

	enemy(std::string texture, int dim, float movement_speed):ms(movement_speed) {
		et.loadFromFile(texture);

		original_size = et.getSize();
		text_width = static_cast<float>(original_size.x);
		text_height = static_cast<float>(original_size.y);
		sprite_scale.x = dim / text_width;
		sprite_scale.y = dim / text_height;

		es.setScale(sf::Vector2f(sprite_scale.x, sprite_scale.y));
		es.setOrigin(sf::Vector2f(original_size.x / 2, original_size.y / 2));
		es.setTexture(et);
	}

	enemy(sf::Texture t, sf::Vector2f rect, float movement_speed) :et(t), ms(movement_speed) {
		
		text_width = t.getSize().x;
		text_height = rect.y;
		
		sprite_scale.x = text_width;
		sprite_scale.y = text_height;

		es.setScale(sf::Vector2f(2, 2));
		es.setOrigin(sf::Vector2f(original_size.x / 2, original_size.y / 2));
		es.setTexture(et);
		es.setTextureRect(sf::IntRect(0, rect.x, text_width, rect.y));
		
	}

	enemy(std::string t, sf::Vector2f rect, int health, float movement_speed) : ms(movement_speed),health(health) {
		og_health = health;
		et.loadFromFile(t);
		text_width = et.getSize().x;
		text_height = rect.y;

		sprite_scale.x = text_width;
		sprite_scale.y = text_height;

		es.setScale(sf::Vector2f(1, 1));
		es.setOrigin(sf::Vector2f(original_size.x / 2, original_size.y / 2));
		es.setTexture(et);
		es.setTextureRect(sf::IntRect(0, rect.x, text_width, rect.y));

	}
	
	enemy(int dim) {
		es.setScale(sf::Vector2f(dim,dim));
		ms = 500;
	}



};



class enemy_methods {
public:
	enemy spawn_enemy(int e);

};







