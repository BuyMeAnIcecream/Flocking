#include "Vehicle.h"
#include "MyVector.h"

void Vehicle::setLocation(Vector2f loc)
{
	location = loc;
}

Vehicle::Vehicle(Vector2f loc)
{
	location = loc;
	acceleration = Vector2f(0.f, 0.f);
	velocity = Vector2f(0.f, 0.f);

	r = 7;
	maxSpeed = 100;
	maxForce = 0.1f;

	triangle = new sf::ConvexShape();
	triangle->setPointCount(3);
	triangle->setFillColor(sf::Color(100, 250, 50));
	triangle->setPoint(0, sf::Vector2f( 0,  17));
	triangle->setPoint(2, sf::Vector2f( 10,  17));
	triangle->setPoint(1, sf::Vector2f(5,  0));
	 

	
}

void Vehicle::update(float dt)
{
//	orientation =  (triangle->getPoint(1) + triangle->getPoint(0)) / 2.f - triangle->getPoint(2);
	
	
//	seek(target);
	velocity += acceleration;
	velocity = limit(velocity ,maxSpeed);
	location += velocity*dt;
	triangle->setPosition(location);
	triangle->setRotation(atan2f(velocity.y, velocity.x) * 180 / 3.14159365 + 90);
//  triangle->setRotation(atan2(velocity.y, velocity.x) * 180 / 3.14159365 - 30);
//	triangle->setRotation(getVectorAngle(target, orientation));
	acceleration *= 0.f;
	
}

void Vehicle::applyForce(Vector2f force) {
	acceleration += force;
}

void Vehicle::seek(Vector2f target) {
	Vector2f desired = target - location;
	desired = getNormal(desired);
	desired *= maxSpeed;
	Vector2f steer = desired - velocity;
	steer = limit(steer, maxForce);
	applyForce(steer);
}

void Vehicle::render(sf::RenderWindow * window)
{
	window->draw(*triangle);

}

void Vehicle::calculate_steer()
{
	steer = desired - velocity;
}
/*
void Vehicle::separate(std::vector<Vehicle*> veh, float s_w)
{

	float desiredseparation = veh[0]->r * 2;
	Vector2f sum = Vector2f(0.f, 0.f);
	int count = 0;
	for (Vehicle* other : veh) {
		float d = getDistance(location, other->location);
		if ((d > 0) && (d < desiredseparation)) {
			Vector2f diff = location - other->location;
			diff = getNormal(diff);
			diff /= d;
			sum+=diff;
			count++;
		}
	}
	if (count > 0) {
		sum = sum / (float)count;
		getNormal(sum);
		sum *= maxSpeed;
		Vector2f steer = sum -velocity;
		limit(steer,maxForce);
		
		applyForce(steer* s_w) ;
	}
	
	
}
*/