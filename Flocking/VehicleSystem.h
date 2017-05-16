#pragma once
#include "Vehicle.h"
#include <vector>
class VehicleSystem {
public:
	float interaction_radius;
	float al_weight;
	float sep_weight;
	float coh_weight;
	VehicleSystem();
	std::vector<Vehicle *> vehicles;
	void flock(std::vector<Vehicle *> veh, Vector2f targ);
	void align(Vehicle * v, std::vector<Vehicle*> veh);
	void separate(Vehicle * v, std::vector<Vehicle*> veh);
	void cohese(Vehicle * v, std::vector<Vehicle*> veh);
	void add_vehicle();
	void remove_vehicle();
	void increment_separation();
	void increment_cohesion();
	void increment_alignment();
	void decrement_separation();
	void decrement_cohesion();
	void decrement_alignment();

};