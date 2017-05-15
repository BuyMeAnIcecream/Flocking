#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;
#pragma once
class Vehicle {

private:
	
	
	Vector2f velocity;
	Vector2f acceleration;
	
	Vector2f steer;
	Vector2f desired;
	float maxSpeed;
	float maxForce;
	float r;
	Vector2f orientation;
	
public:
	Vector2f location;

	Vector2f target;
	sf::ConvexShape* triangle;
	
	void setLocation(Vector2f loc);
	Vehicle(Vector2f loc);
	
	void update(float dt);
	void render(sf::RenderWindow* window);
	
	void Vehicle::applyForce(Vector2f force);
	void seek(Vector2f target);
	void calculate_steer();

	void separate(std::vector<Vehicle*> veh);
	
};

