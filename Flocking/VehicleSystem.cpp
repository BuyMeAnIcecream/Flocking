#include "VehicleSystem.h"

void VehicleSystem::flock(std::vector<Vehicle*> veh, Vector2f targ)
{
	for each (Vehicle * var in veh)
	{
		var->separate(veh);
		var->seek(targ);
	}
	/*
	Vector2f sep = separate(veh);


	Vector2f ali = align(veh);
	Vector2f coh = cohesion( veh);

	sep*sep_weight;
	ali*al_weight;
	coh*coh_weight;
	//HOWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	
	applyForce(sep);
	applyForce(ali);
	applyForce(coh);
	*/
}


	