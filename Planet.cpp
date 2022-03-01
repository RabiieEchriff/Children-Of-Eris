#pragma once
#include <time.h>
#include "Planet.h"


std::string planet::set_planet(int i,int scene) {
	std::string pn;
	switch (i) {
	case 0:pn = "null"; break;
	case 1:pn = "mercury"; break;
	case 2:pn = "venus"; break;
	case 3:pn = "earth"; break;
	case 4:pn = "mars"; break;
	case 5:pn = "ceres"; break;
	case 6:pn = "jupiter"; break;
	case 7:pn = "saturn"; break;
	case 8:pn = "uranus"; break;
	case 9:pn = "neptune"; break;
	case 10:pn = "pluto_charon"; break;
	case 11:pn = "eris"; break;
	default:pn = "null"; break;
	}
	

	std::string path;

	switch(scene){
	case 1: path = "res/images/planets/t_" + pn + ".png"; break;
	case 2: path = "res/images/planets/" + pn + ".png"; break;
	default: break;
	}
	//planet_texture.loadFromFile("res/images/planets/mars.png");
	planet_texture.loadFromFile(path);
	globe.setTexture(&planet_texture);

	return path;

}


void planet::inmenu(int i) {
	std::string path;
	path = set_planet(i, 1);

	globe.setSize(sf::Vector2f(300, 300));
	globe.setOrigin(sf::Vector2f(globe.getSize().x, 0));
	globe.setPosition(sf::Vector2f(670, 20));
	
}

/*
void planet::ingame(float dt_seconds, int i) {
	int size = rand() % 900 + 600;
	int spawn = rand() % 640 + 50;

	//set_planet(i, 2);

	globe.setSize(sf::Vector2f(size, size));
	globe.setOrigin(sf::Vector2f(globe.getScale().x / 2, globe.getScale().y / 2));
	globe.setPosition(sf::Vector2f(spawn, -((size / 2) + 20)));


	//globe.move(sf::Vector2f(0, 5 * dt_seconds));
}
*/

void planet::ingame(int level) {
	srand(time(0));

	int size = rand() % 6 + 5;

	spawn = rand() % 690 ;


	set_planet(level, 2);



	globe.setSize(sf::Vector2f(100 * size, 100 * size));
	globe.setOrigin(sf::Vector2f(globe.getSize().x / 2, globe.getSize().y / 2));


	globe.setPosition(sf::Vector2f(spawn, -(globe.getSize().y / 2 + 20)));
}