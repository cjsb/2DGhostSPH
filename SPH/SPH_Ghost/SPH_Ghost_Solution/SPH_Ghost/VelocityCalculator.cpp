#include "Calculators.h"

void velocityCalculator2D( vector<Particle2D> *particles, double dt ){

	for(int i = 0; i < particles->size(); ++i){
		if(particles->at(i).type == 0){
		particles->at(i).intVelocity.x = 0.0;
		particles->at(i).intVelocity.y = 0.0;
		}
	}

	for(int i = 0; i < particles->size(); ++i){

		if(particles->at(i).type == 0){
		//v* = v + at
		particles->at(i).intVelocity.x = particles->at(i).velocity.x + ((particles->at(i).acceleration.x) * dt);
		particles->at(i).intVelocity.y = particles->at(i).velocity.y + ((particles->at(i).acceleration.y) * dt);
		}
	}


}