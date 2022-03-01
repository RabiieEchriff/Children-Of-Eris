#pragma once
#include "Drop.h"

drop healing("res/images/wrench.png");

drop drop_methods::spawn_drop() {
	sf::Vector2f drop_origin;
	int spawn = rand() % 595 - 5;

	switch (int r1 = rand() % 2) {
		
	case 0:
		drop_origin.x = healing.m_texture.getSize().x / 2;
		drop_origin.y = healing.m_texture.getSize().y / 2;
		healing.m_sprite.setPosition(sf::Vector2f(spawn, -(drop_origin.y) - 50));
		return healing; break;

	case 1:
		drop_origin.x = healing.m_texture.getSize().x / 2;
		drop_origin.y = healing.m_texture.getSize().y / 2;
		healing.m_sprite.setPosition(sf::Vector2f(spawn, -(drop_origin.y) - 50));
		return healing; break;
	}

}