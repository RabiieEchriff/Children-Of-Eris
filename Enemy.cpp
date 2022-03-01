#pragma once
#include "Enemy.h"

//enemy basic_enemy1("res/images/enemy1.png", 70, 400);
//enemy basic_enemy2("res/images/enemy2.png", 100, 300);

enemy n1("res/images/enemies.png", { 0,42 }, 1, 700);
enemy n2("res/images/enemies.png", { 114,70 }, 4, 400);
enemy n3("res/images/enemies.png", { 240,64 }, 3, 400);
enemy n4("res/images/enemies.png", { 378,68 }, 2, 350);
enemy n5("res/images/enemies.png", { 502,68 }, 4, 250);
enemy n6("res/images/enemies.png", { 626,86 }, 6, 150);
enemy n7("res/images/enemies.png", { 752,82 }, 3, 350);
enemy n8("res/images/enemies.png", { 886,66 }, 2, 250);
enemy n9("res/images/enemies.png", { 1010,66 }, 2, 500);
enemy n10("res/images/enemies.png", { 1150,50 }, 2, 400);

enemy n(0);

enemy enemy_methods::spawn_enemy(int e) {
	
	
	

	sf::Vector2f enemy_origin;
	int spawn = rand() % 595 - 5;
	//int spawn = 345;

	switch (int r1 = rand() % e+1) {
	case 1://Mercury
		n = n8; break;
	case 2://Venus
		n = n4; break;
	case 3://Earth
		n = n7; break;
	case 4://Mars
		n = n10; break;
	case 5://Ceres
		n = n5; break;
	case 6://Jupiter
		n = n3; break;
	case 7://Saturn
		n = n2; break;
	case 8://Uranus
		n = n6; break;
	case 9://Neptune
		n = n9; break;
	case 10://Pluto & Charon
		n = n1; break;
	default:break;
		
	}
	
	enemy_origin = n.es.getOrigin();
	n.es.setPosition(sf::Vector2f(spawn, -100));//'50' could be replaced with a 'rand();' value.
	
	return n;

}

