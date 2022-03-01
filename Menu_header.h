#pragma once
#include <SFML/Graphics.hpp>
#include "Common.h"

font_methods mf;

sf::RectangleShape cursor;

bool coll;

class menu_button {
public:
	sf::Text text;
	sf::RectangleShape text_box;
	
	
	bool button_collision();
	

	menu_button(std::string str,int char_size,sf::Vector2f pos) {
		text.setString(str);
		mf.load_pixelex();

		text = mf.set_text(text, char_size, { pos.x,pos.y });
		text_box.setFillColor(sf::Color(sf::Color::Red));
		text_box.setPosition(text.getPosition());
		text_box.setSize(sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height));

		text_box.setOrigin(sf::Vector2f(text_box.getSize().x / 2, text_box.getSize().y / 2));
		text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2, (text.getLocalBounds().height/2)+11));

	
	}
	
	

};

bool menu_button::button_collision() {

	if ((cursor.getPosition().x <= (text_box.getPosition().x)+text_box.getSize().x/2)
		&& (cursor.getPosition().x >= (text_box.getPosition().x) - text_box.getSize().x / 2)
		&&(cursor.getPosition().y <= (text_box.getPosition().y) + text_box.getSize().y / 2)
		&& (cursor.getPosition().y >= (text_box.getPosition().y) - text_box.getSize().y / 2)) {
		
		text.setFillColor(sf::Color(sf::Color::Yellow));
		coll = true;
	}
	else { text.setFillColor(sf::Color(sf::Color::White)); coll = false;  }
	return coll;
}

