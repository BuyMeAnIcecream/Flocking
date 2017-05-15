#pragma once
#include "Vehicle.h"
#include <vector>
class VehicleSystem {
public:
	float al_weight;
	float sep_weight;
	float coh_weight;

	std::vector<Vehicle *> vehicles;
	void flock(std::vector<Vehicle *> veh, Vector2f targ);
	Vector2f separate(std::vector<Vehicle *> veh);
	Vector2f align(std::vector<Vehicle *> veh);
	Vector2f cohesion(std::vector<Vehicle *> veh);

};