#include "Calculators.h"

void positionCalculator2D( vector<Particle2D> *particles, double dt ){

	for(int i = 0; i < particles->size(); ++i){

		if(particles->at(i).type == 0){
		particles->at(i).position.x += particles->at(i).velocity.x * dt;
		particles->at(i).position.y += particles->at(i).velocity.y * dt;
		}
	}


}