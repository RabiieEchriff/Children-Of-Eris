#pragma once
#include <SFML/Graphics.hpp>


class projectile {
public:
	std::string m_path;
	sf::Texture m_texture;
	sf::Vector2f m_size;
	sf::Sprite m_shape;
	int m_speed;
	double fire_rate;
	int damage;
	
	sf::Vector2f sprite_scale;
	sf::Vector2u original_size;
	float text_width;
	float text_height;

	projectile(std::string path, sf::Vector2f size, int speed, double f_rate,int dmg)
		:m_path(path),m_size(size), m_speed(speed), fire_rate(f_rate),damage(dmg)
	{
		
		//sprite_size((m_size.x/ text_width), (m_size.y / text_height));
		
		m_texture.loadFromFile(path);

		original_size = m_texture.getSize();
		text_width = static_cast<float>(original_size.x);
		text_height = static_cast<float>(original_size.y);
		sprite_scale.x = m_size.x / text_width;
		sprite_scale.y = m_size.y / text_height;


		m_shape.setTexture(m_texture);
		m_shape.setScale(sf::Vector2f(sprite_scale));
		//m_shape.setSize(m_size);
	
		m_shape.setOrigin(sf::Vector2f(original_size.x / 2, original_size.y / 2));

	}
	projectile(int dim) {
		m_shape.setScale(sf::Vector2f(dim, dim));
		m_speed = 1000;
}
	

};