#include <SFML/Graphics.hpp>
#include "VehicleSystem.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");



	
	VehicleSystem vs =  VehicleSystem();
	
	vs.vehicles.push_back(new Vehicle(sf::Vector2f(50.f, 50.f)));
	vs.vehicles.push_back(new Vehicle(sf::Vector2f(100.f, 100.f)));
	vs.vehicles.push_back(new Vehicle(sf::Vector2f(200.f, 200.f)));
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		
		Vector2f mousePos = window.mapPixelToCoords(mouse);
		
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		
		float dt = clock.restart().asSeconds();
		
		for each (Vehicle* v in vs.vehicles)
		{
			v->update(dt);
			v->render(&window);
			v->target = Vector2f(mousePos);
		}
		

		window.display();
	}
	
	return 0;
}
