#pragma once
#include "Window.h"
#include "Menu_header.h"



sf::RectangleShape title;
sf::Texture title_texture;
sf::RectangleShape controls;
sf::Texture controls_texture;

menu_button allocate_buttons(int i);
font_methods t;

std::vector <menu_button> buttons;

sf::RectangleShape thumb1;
sf::RectangleShape thumb2;
sf::Texture thumbnail;

int init;
int limit;
const int button_number = 20;
bool collision = false;
bool collision2[button_number];
int collision3 = 0;

planet t_planet;

menu_button move("MOVE", 20, { 578,310 });
menu_button shoot("SHOOT", 20, { 325,310 });
menu_button select_spaceship("SELECT SPACESHIP", 40, { 345,90 });

sf::SoundBuffer menu_hover;
sf::SoundBuffer menu_click;
sf::Sound m_hover;
sf::Sound m_click;

int current_scene = 0;
int prev_scene = 0;

class menu_methods {
public:
	selector events(selector m);
	selector logic(selector m);
	void display(int scene);
};

selector menu_methods::events(selector m){

	for (int i = 0; i < button_number; i++) {
		buttons.push_back(allocate_buttons(i));
		//std::cout << i << "-" << buttons[i].text.getLocalBounds().width << std::endl;
	}

	buttons[17].text_box.setSize(sf::Vector2f(buttons[17].text_box.getSize().x, buttons[17].text_box.getSize().y * 14));
	buttons[18].text_box.setSize(sf::Vector2f(buttons[18].text_box.getSize().x, buttons[18].text_box.getSize().y * 14));

	title.setSize(sf::Vector2f(600, 48));
	title.setOrigin(sf::Vector2f(title.getSize().x / 2, title.getSize().y / 2));
	title.setPosition(sf::Vector2f(345, 90));
	title_texture.loadFromFile("res/images/title.png");
	title.setTexture(&title_texture);

	controls.setSize(sf::Vector2f(600, 210));
	controls.setOrigin(sf::Vector2f(controls.getSize().x / 2, controls.getSize().y / 2));
	controls.setPosition(sf::Vector2f(345, 180));
	controls_texture.loadFromFile("res/images/keyboard.png");
	controls.setTexture(&controls_texture);

	thumbnail.loadFromFile("res/images/thumbnail.png");
	thumb1.setSize(sf::Vector2f(65, 80));
	thumb1.setTexture(&thumbnail);
	thumb1.setTextureRect(sf::IntRect(0, 0, 199, 256));
	
	thumb2.setSize(sf::Vector2f(65, 80));
	thumb2.setTexture(&thumbnail);
	thumb2.setTextureRect(sf::IntRect(0, 383, 200, 257));

	thumb1.setPosition(sf::Vector2f(430, 220));
	thumb2.setPosition(sf::Vector2f(200, 220));

	menu_hover.loadFromFile("res/sfx/blip1.wav");
	menu_click.loadFromFile("res/sfx/blip2.wav");
	m_hover.setBuffer(menu_hover);
	m_click.setBuffer(menu_click);
	
	return m;
}

selector menu_methods::logic(selector m) {

	cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition(w)));

	switch (m.scene) {//Initalize's where the for loops for collision and display will begin and end.
	case 1:
		init = 0; limit = 4; break;
	case 2:
		init = 4; limit = 16; break;
	case 3:
		init = 16; limit = 17; break;
	case 4:
		init = 17; limit = 20; break;
	default:
		break;
	}

	cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition(w)));

	for (int j = init; j < limit; j++) {
		collision = buttons[j].button_collision();
		///*
		if (collision == true) {
			if (collision2[j] == false) {
				m_hover.play();
				collision2[j] = true;
			}

		}
		
		else { collision2[j] = false; }
		//*/

		/*
		if (buttons[j].text.getFillColor() == sf::Color::Yellow) {
			if (collision2 == 0) {
				m_hover.play();
				collision2 = true;
			}
		}
		if (buttons[j].text.getFillColor() == sf::Color::White) { collision3 = 0; }

		*/
		
		
		prev_scene = m.scene;
		

			if (e.type == sf::Event::MouseButtonReleased) {
				if (e.mouseButton.button == sf::Mouse::Left) {
		//if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == true) {
			//w.setKeyRepeatEnabled(false);
					
					//if (current_scene == prev_scene) {

			switch (j) {
			case 0://Main menu
				if (collision == true && m.scene == 1) { m.scene = 2; break; }
			case 1:
				if (collision == true && m.scene == 1) { m.scene = 4; m.level = 12; break; }
			case 2:
				if (collision == true && m.scene == 1) { m.scene = 3; break; }
			case 3:
				if (collision == true && m.scene == 1) { w.close(); break; }

			case 4://Level Selection
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 1; break; }
			case 5:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 2; break; }
			case 6:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 3; break; }
			case 7:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 4; break; }
			case 8:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 5; break; }
			case 9:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 6; break; }
			case 10:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 7; break; }
			case 11:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 8; break; }
			case 12:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 9; break; }
			case 13:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 10; break; }
			case 14:
				if (collision == true && m.scene == 2) { m.scene = 4; m.level = 11; break; }
			case 15:
				if (collision == true && m.scene == 2) { m.scene = 1; break; }

			case 16://Controls
				if (collision == true && m.scene == 3) { m.scene = 1; break; }

			case 17://Ship selection
				if (collision == true && m.scene == 4) { m.ship = 1; m.scene = 5;  break; }
			case 18:
				if (collision == true && m.scene == 4) { m.ship = 2; m.scene = 5;  break; }
			case 19:
				if (collision == true && m.scene == 4) { m.scene = 1; break; }
			default:break;
			}

			

			current_scene = m.scene;

			if (current_scene != prev_scene) {
				
				m_click.play();
	
				sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y),w);
			}


					//}
	            }
		    }
		
			/*
			if (current_scene != prev_scene) {
				cursor.setPosition(sf::Vector2f(0, 0));
			}
			*/

		if (collision == true && init == 4 && limit == 16) {
			t_planet.inmenu(j - 3);
		}
	}

	if (m.ship == 1) {
		ship = ship1;
		pprojectile = pprojectile1;
	}

	if (m.ship == 2) {
		ship = ship2;
		pprojectile = pprojectile2;
	}
	
	bg_planet.ingame(m.level);

	return m;
}

void menu_methods::display(int scene) {
	switch (scene) {
	case 1:
		w.draw(title); break;
	case 2:
		w.draw(t_planet.globe); break;
	case 3:
		w.draw(controls);
		w.draw(move.text);
		w.draw(shoot.text);
		break;
	case 4:
		w.draw(select_spaceship.text);
		w.draw(thumb1);
		w.draw(thumb2);
		break;
	}
	for (int i = init; i < limit; i++) {
		//w.draw(buttons[i].text_box);
		w.draw(buttons[i].text);
	}
}

menu_button allocate_buttons(int i) {

	menu_button button(" ", 40, { -200,-200 });

	switch (i) {
		//Main menu
	case 0:
		button = menu_button("LEVEL SELECT", 40, { 345,220 }); break;
	case 1:
		button = menu_button("ENDLESS MODE", 40, { 345,280 }); break;
	case 2:
		button = menu_button("CONTROLS", 40, { 345,340 }); break;
	case 3:
		button = menu_button("QUIT", 40, { 345,400 }); break;

		//Level Selection
	case 4:
		button = menu_button("MERCURY", 40, { 130.5,30 });  break;
	case 5:
		button = menu_button("VENUS", 40, { 96,70 });  break;
	case 6:
		button = menu_button("EARTH", 40, { 94.5,110 });  break;
	case 7:
		button = menu_button("MARS", 40, { 77.5,150 });  break;
	case 8:
		button = menu_button("CERES", 40, { 96,190 });  break;
	case 9:
		button = menu_button("JUPITER", 40, { 130,230 });  break;
	case 10:
		button = menu_button("SATURN", 40, { 112.5,270 }); break;
	case 11:
		button = menu_button("URANUS", 40, { 113,310 });  break;
	case 12:
		button = menu_button("NEPTUNE", 40, { 131,350 });  break;
	case 13:
		button = menu_button("PLUTO & CHARON", 40, { 230.5,390 });  break;
	case 14:
		button = menu_button("ERIS", 40, { 77.5,430 });  break;
	case 15:
		button = menu_button("<< RETURN", 40, { 142,470 }); break;

		//Controls
	case 16:
		button = menu_button("<< RETURN", 40, { 142,470 }); break;

		//Ship Selection
	case 17:
		button = menu_button("SHIP 1", 20, { 230,200 }); break;
	case 18:
		button = menu_button("SHIP 2", 20, { 460,200 }); break;
	case 19:
		button = menu_button("<< RETURN", 40, { 142,470 }); break;

	default: break;
	}
	return button;

}