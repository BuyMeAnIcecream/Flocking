#include "VehicleSystem.h"


VehicleSystem::VehicleSystem()
{
	interaction_radius = 100;
	al_weight = 0.5;
	sep_weight = 0.3;
	coh_weight = 0.2;
}

void VehicleSystem::flock(std::vector<Vehicle*> veh, Vector2f targ)
{
	for each (Vehicle * var in veh)
	{ 
		var->seek(targ);
		align(var, veh);
		separate(var, veh);
		cohese(var, veh);
	}
}

void VehicleSystem::align(Vehicle* v, std::vector<Vehicle*> veh)
{
	
		Vector2f align_force = Vector2f(0.f, 0.f);
		int neighborCount = 0;
		for each (Vehicle* neighbor in veh)
		{
			if (v != neighbor) {
				if (getDistance(v->location, neighbor->location) <interaction_radius)
				{
					align_force += neighbor->velocity;			
					neighborCount++;
				}
			}
		}
	if (neighborCount == 0)
		return;
	align_force /= (float)neighborCount;
	align_force = getNormal(align_force);
		
	
	v->applyForce( align_force * al_weight);
}

void VehicleSystem::separate(Vehicle * v, std::vector<Vehicle*> veh)
{
	Vector2f separ_force = Vector2f(0.f, 0.f);
	int neighborCount = 0;
	for each (Vehicle* neighbor in veh)
	{
		if (v != neighbor) {
			if (getDistance(v->location, neighbor->location) < interaction_radius)
			{
				separ_force += neighbor->location - v->location;

				neighborCount++;
			}
		}
	}
	if (neighborCount == 0)
		return;
	separ_force /= (float)neighborCount;
	separ_force *= -1.f;
	separ_force = getNormal(separ_force);
	v->applyForce(separ_force * sep_weight);
}

void VehicleSystem::cohese(Vehicle * v, std::vector<Vehicle*> veh)
{
	Vector2f center_of_mass = Vector2f(0.f, 0.f);
	int neighborCount = 0;
	for each (Vehicle* neighbor in veh)
	{
		if (v != neighbor) {
			if (getDistance(v->location, neighbor->location) < interaction_radius)
			{
				center_of_mass += neighbor->location;
				neighborCount++;
			}
		}
	}
	if (neighborCount == 0) 
		return; 
	center_of_mass /= (float)neighborCount;
	Vector2f cohese_force = center_of_mass - v->location;
	cohese_force = getNormal(cohese_force);
	v->applyForce(cohese_force * coh_weight);
}

void VehicleSystem::add_vehicle()
{
	vehicles.push_back(new Vehicle(sf::Vector2f(50.f, 50.f)));
}

void VehicleSystem::remove_vehicle()
{
	if(vehicles.size()!=0)
	vehicles.erase(vehicles.begin());
}

void VehicleSystem::increment_separation()
{
	sep_weight += 0.1f;
}

void VehicleSystem::increment_cohesion()
{
	coh_weight += 0.1f;
}

void VehicleSystem::increment_alignment()
{
	al_weight += 0.1f;
}

void VehicleSystem::decrement_separation()
{
	sep_weight -= 0.1f;
}

void VehicleSystem::decrement_cohesion()
{
	coh_weight -= 0.1f;
}

void VehicleSystem::decrement_alignment()
{
	al_weight -= 0.1f;
}


	