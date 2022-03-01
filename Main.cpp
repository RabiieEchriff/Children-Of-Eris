#include "Window.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "collision.h"
#include "Drop.h"
#include "Game.h"
#include "Menu_header.h"
#include "Menu.h"
#include <iostream>
#include <string>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

menu_methods menu;
game_methods game;

selector m;

int main() {
	//handle events here
	m.scene = 1;
	m = menu.events(m);
	game.events();
	//handle events here
	while (w.isOpen()) {
		while (w.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::Closed:
				w.close();
				break;
			}
		}

		
		//update game logic here
		space.bg_move();
		if(m.scene!=5){
		m = menu.logic(m);
		}
		else {
			m.scene = game.logic(m);
		}
		//std::cout << "x: " << cursor.getPosition().x << " y: " << cursor.getPosition().y << std::endl;
		//std::cout <<spawn_interval << std::endl;
		//update game logic here

		w.clear();

		//draw objects here
		w.clear(sf::Color::Black);
		w.draw(space.bg);
		if(m.scene!=5){
		menu.display(m.scene);
		}
		else { game.display(); }
		//draw objects here
		w.display();
	}
}





