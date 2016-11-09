#include "Calculators.h"


void pressureForceCalculator2D( vector<Particle2D> *particles ){

	for(int i = 0; i < particles->size();++i){
		particles->at(i).acceleration.x = 0.0;
		particles->at(i).acceleration.y = 0.0;
	}

	for(int i = 0; i < particles->size();++i){
		double forceX = 0.0;
		double forceY = 0.0;

		double mass = particles->at(i).mass;
		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){

			int neighbor = particles->at(i).neighbors[j];
			double neighMass = particles->at(neighbor).mass;

			double force = particles->at(neighbor).pressure / (particles->at(neighbor).density*particles->at(neighbor).density);
			force = force + particles->at(i).pressure / (particles->at(i).density*particles->at(i).density);
			if(particles->at(neighbor).type >= 0){
			forceX = forceX  + (neighMass*force*particles->at(i).kernelGrad.at(j).x);
			forceY = forceY  + (neighMass*force*particles->at(i).kernelGrad.at(j).y);
			}
		}

		/*particles->at(i).acceleration.x += -mass*forceX;
		particles->at(i).acceleration.y += -mass*forceY;*/
		particles->at(i).acceleration.x += -forceX;
		particles->at(i).acceleration.y += -forceY;

		//add gravity
		particles->at(i).acceleration.y += -9.8;
	}
	
}