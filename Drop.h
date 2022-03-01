#pragma once
#include <SFML/Graphics.hpp>


class drop {
public:
	std::string m_path;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	int m_speed = 500;
	
	
	drop(std::string path)
		:m_path(path) {
		m_texture.loadFromFile(m_path);
		m_sprite.setTexture(m_texture);
		m_sprite.setScale(sf::Vector2f(1, 1));
	}
	

	drop(std::string path, float scale) 
		:m_path(path) {
			m_texture.loadFromFile(m_path);
			m_sprite.setTexture(m_texture);
			m_sprite.setScale(sf::Vector2f(scale, scale));
	}
	drop(int dim) {
		m_sprite.setScale(sf::Vector2f(dim, dim));
	}
};

class drop_methods {
public:
	drop spawn_drop();

};