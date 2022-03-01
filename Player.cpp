#pragma once
#include "Player.h"




void player::player_controls(float dt,float speed) {
	
	sf::Vector2f playerxy = ps.getPosition();

	if (playerxy.y > 50) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			ps.move(sf::Vector2f(0, -speed * dt));
		}
	}

	if (playerxy.y < 450) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			ps.move(sf::Vector2f(0, speed * dt));
		}
	}

	if (playerxy.x > 50) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			ps.move(sf::Vector2f(-speed * dt, 0));
		}
	}

	if (playerxy.x < 640) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
			ps.move(sf::Vector2f(speed * dt, 0));
		}
	}
}

