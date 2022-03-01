#pragma once
#include <SFML/Graphics.hpp>
#include "Common.h"
#include "Animator.h"

sf::Time elapsed_time1;
sf::Time elapsed_time2;
sf::Time elapsed_time3;


background space("res/images/background4.png");
player ship(0);
player ship1("res/images/players.png","res/sfx/woosh.wav", { 192,128 }, 500);
player ship2("res/images/players.png","res/sfx/pew.wav", { 0,131 }, 750);
std::vector <enemy> enemies;
enemy_methods em;
std::vector <drop> drops;
drop_methods dm;
std::vector <projectile> pprojectiles;


projectile pprojectile(0);
projectile pprojectile1("res/images/missile.png", { 7.5,30 }, 1000, 0.3, 2);
projectile pprojectile2("res/images/laser.png", { 5,15 }, 1000, 0.15, 1);

std::vector <animation> explosions;
animation explosion("res/images/explosion.png", { 80,80 }, { 0,0,64,64 }, { 5,5 }, 0.04);

planet bg_planet;


enemy e_null(0);
projectile p_null(0);
drop d_null(0);

font_methods hud;
sf::Text kills;
std::string str_kills;
sf::Text score;
std::string str_score;
sf::Text death_message;
std::string d_message;

sf::RectangleShape p_healthbar;
sf::Text p_health;
std::string ph_str;


int enemy_counter = 0;
int p_counter = 0;
int kill_count = 0;
int scr = 0;
int enemy_wave;
int spawn_interval;
int player_health = 100;
bool barrel_selector;
bool death = false;

sf::Clock clock1;
sf::Clock clock2;
sf::Clock clock3;

sf::SoundBuffer sb_boom;
sf::Sound sfx_boom;

sf::SoundBuffer sb_heal;
sf::Sound sfx_heal;

sf::SoundBuffer sb_damage;
sf::Sound sfx_damage;

class game_methods {
public:
    void events();
	int logic(selector m);
	void display();
	void reset();
};

void game_methods::events() {

	hud.load_pixelex();

	score = hud.set_text(score, score.getCharacterSize(), { 30,30 });
	kills = hud.set_text(kills, kills.getCharacterSize(), { 30,30 });
	death_message= hud.set_text(death_message, death_message.getCharacterSize(), { 20,20 });

	p_health = hud.set_text(p_health, p_health.getCharacterSize(), { 640,470 });

	p_healthbar.setSize(sf::Vector2f(player_health, 20));
	p_healthbar.setOrigin(sf::Vector2f(p_healthbar.getSize().x, 0));
	p_healthbar.setFillColor(sf::Color(sf::Color::Green));
	p_healthbar.setPosition(sf::Vector2f(620, 464));

	d_message = R"(
             press R to respawn 
      or ESC to return to menu 
                        anytime
)";

	barrel_selector = false;

	sb_boom.loadFromFile("res/sfx/boom3.wav");
	sfx_boom.setBuffer(sb_boom);
	sb_heal.loadFromFile("res/sfx/heal.wav");
	sfx_heal.setBuffer(sb_heal);
    sb_damage.loadFromFile("res/sfx/damage.wav");
	sfx_damage.setBuffer(sb_damage);


}

int game_methods::logic(selector m) {

	if (enemies.size() == 0 && kill_count == 0 && ship.ps.getPosition().x==0 && ship.ps.getPosition().y == 0) {
		ship.ps.setPosition(sf::Vector2f(345, 450));
	}

	enemy_wave = rand() % 3 + 1;
	//spawn_interval = rand() % 2000;
	spawn_interval = rand() % (2000 - ((m.level - 1) * 100));
	//spawn_interval = 2000 - ((m.level - 1) * 100);
	//if (m.level = 12) { spawn_interval = rand() % 2000; }

	sf::Time delta_time1 = clock1.restart();
	sf::Time delta_time2 = clock2.restart();
	sf::Time delta_time3 = clock3.restart();

	elapsed_time1 += delta_time1;

	if (elapsed_time1 > sf::seconds(spawn_interval)) {
		for (int i = 0; i < enemy_wave; i++) {
			enemies.push_back(em.spawn_enemy(m.level));
			elapsed_time1 = clock1.restart();
		}
	}

	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i].es.getPosition().y >= 700) {
			enemies.erase(enemies.begin() + i);
		}
	}

	for (int i = 0; i < explosions.size(); i++) {
		if (explosions[i].m_sprite.getPosition().y >= 700) {
			explosions.erase(explosions.begin() + i);
		}
	}

	elapsed_time2 += delta_time2;

	if (elapsed_time2 > sf::seconds(pprojectile.fire_rate)) {
		if(death==false){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			sf::Vector2f pl_pos = ship.ps.getPosition();
			pprojectiles.push_back(pprojectile);
			ship.sfx_firing.play();

			if(m.ship==1){
			pprojectiles[pprojectiles.size() - 1].m_shape.setPosition(sf::Vector2f(pl_pos.x, pl_pos.y-30));
			}
			if (m.ship == 2) {
				switch (barrel_selector) {
				case false:
					pprojectiles[pprojectiles.size() - 1].m_shape.setPosition(sf::Vector2f(pl_pos.x-13, pl_pos.y));
					barrel_selector = true;
					break;
				case true:
					pprojectiles[pprojectiles.size() - 1].m_shape.setPosition(sf::Vector2f(pl_pos.x+13, pl_pos.y));
					barrel_selector = false;
					break;
				default:break;
				}
			}

			elapsed_time2 = clock2.restart();
		}
		}
	}

	for (int i = 0; i < pprojectiles.size(); i++) {
		if (pprojectiles[i].m_shape.getPosition().y <= -30) {
			pprojectiles.erase(pprojectiles.begin() + i);
		}
	}

	for (int i = 0; i < pprojectiles.size(); i++) {
		for (int j = 0; j < enemies.size(); j++) {
			if (Collision::PixelPerfectTest(pprojectiles[i].m_shape, enemies[j].es)) {
				pprojectiles[i] = p_null;
				if (enemies[j].health > 0) {
					enemies[j].health = enemies[j].health - pprojectile.damage;
				}

				if (enemies[j].health <= 0) {
					scr = scr + enemies[j].og_health * 10;
					explosions.push_back(explosion);
					explosions[explosions.size() - 1].m_sprite.setPosition(enemies[j].es.getPosition().x, enemies[j].es.getPosition().y );
					explosions[explosions.size() - 1].m_sprite.move(sf::Vector2f(50,45));
					enemies[j] = e_null;
					kill_count++;
					sfx_boom.play();
				}
			}
		}
	}



	elapsed_time3 += delta_time3;

	if (elapsed_time3 > sf::seconds(20)) {
		for (int i = 0; i < 1; i++) {
			drops.push_back(dm.spawn_drop());
			elapsed_time3 = clock3.restart();
		}

	}

	for (int i = 0; i < explosions.size(); i++) {
		explosions[i].animate_once();
	}

	for (int i = 0; i < enemies.size(); i++) {
		if (Collision::PixelPerfectTest(ship.ps, enemies[i].es)) {

			if (player_health > 0) {
				player_health = player_health - 20;
				explosions.push_back(explosion);
				explosions[explosions.size() - 1].m_sprite.setPosition(enemies[i].es.getPosition().x, enemies[i].es.getPosition().y);
				explosions[explosions.size() - 1].m_sprite.move(sf::Vector2f(50, 45));
				enemies[i] = e_null;
				kill_count++;
				sfx_boom.play();
				sfx_damage.play();
			}

			
			if (player_health <= 0) {
				death = true;
				score.setPosition(sf::Vector2f(100, 140));
				kills.setPosition(sf::Vector2f(410, 140));
				death_message.setPosition(sf::Vector2f(45, 250));
			}				
		}

		for (int i = 0; i < drops.size(); i++) {

			if (player_health >= 100) { player_health = 100; }
			if (Collision::PixelPerfectTest(ship.ps, drops[i].m_sprite)) {
				/*
				if (player_health >= 100) {
					drops[i] = d_null;
					sfx_heal.play();
				}
				*/
				if (player_health < 100) {
					player_health = player_health + 10;
					drops[i] = d_null;
					sfx_heal.play();
				}
			}
		}

		if (player_health > 50) { p_healthbar.setFillColor(sf::Color::Green); }
		if (player_health < 50 && player_health > 25) { p_healthbar.setFillColor(sf::Color(255, 60, 0)); }
		if (player_health < 25) { p_healthbar.setFillColor(sf::Color::Red); }

		p_healthbar.setSize(sf::Vector2f(player_health, 20));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
		reset();
	}
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		m.scene = 1;
		reset();
	}



	str_score = std::to_string(scr);
	str_kills = std::to_string(kill_count);
	score.setString("score>"+ str_score);
	kills.setString("kills>" + str_kills);
	ph_str = std::to_string(player_health);
	p_health.setString(ph_str);
	death_message.setString(d_message);

	float dt_seconds1 = delta_time1.asSeconds();

	if(death==false){
	ship.player_controls(dt_seconds1,ship.speed);
	}

	elapsed_time1 += delta_time1;

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].es.move(sf::Vector2f(0, enemies[i].ms * dt_seconds1));
	}

	for (int i = 0; i < pprojectiles.size(); i++) {
		pprojectiles[i].m_shape.move(sf::Vector2f(0, -pprojectiles[i].m_speed * dt_seconds1));
	}

	for (int i = 0; i < drops.size(); i++) {
		drops[i].m_sprite.move(sf::Vector2f(0, drops[i].m_speed * dt_seconds1));
	}

	for (int i = 0; i < explosions.size(); i++) {
		explosions[i].m_sprite.move(sf::Vector2f(0, 250 * dt_seconds1));
	}

	bg_planet.globe.move(sf::Vector2f(0, 5 * dt_seconds1));


	return m.scene;
}

void game_methods::display() {
	//w.draw(death_message);
	///*
	switch (death) {
	case false:
			w.draw(bg_planet.globe);

			for (int i = 0; i < enemies.size(); i++) {
				w.draw(enemies[i].es);
			}

			for (int i = 0; i < pprojectiles.size(); i++) {
				w.draw(pprojectiles[i].m_shape);
			}

			w.draw(ship.ps);

			for (int i = 0; i < explosions.size(); i++) {
				w.draw(explosions[i].m_sprite);
			}

			for (int i = 0; i < drops.size(); i++) {
				w.draw(drops[i].m_sprite);
			}
			w.draw(p_health);
			w.draw(p_healthbar);
			break;
		
	case true:
			w.draw(kills);
			w.draw(death_message);
			break;
	default:break;
	}
	w.draw(score);
	//*/
}

void game_methods::reset() {
	
		pprojectiles.clear();
		enemies.clear();
		explosions.clear();
		ship.ps.setPosition(sf::Vector2f(345, 450));
		bg_planet.globe.setPosition(sf::Vector2f(bg_planet.spawn, -(bg_planet.globe.getSize().y / 2 + 20)));
		kill_count = 0;
		scr = 0;
		player_health = 100;
		score.setPosition(sf::Vector2f(30, 30));
		death = false;
	
	
}