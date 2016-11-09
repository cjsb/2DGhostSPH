#include "Calculators.h"


void velocityXSPHCalculator2D( vector<Particle2D> *particles, double dt, double epsilon){


	for(int i = 0; i < particles->size(); ++i){
		if(particles->at(i).type == 0){
		double sumX = 0.0;
		double sumY = 0.0;

		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){

			int neighbor = particles->at(i).neighbors.at(j);
			if(particles->at(neighbor).type  >= 0){
			double massNeigh = particles->at(neighbor).mass;
			double densityNeigh = particles->at(neighbor).density;

			double kernelNeig = particles->at(i).kernel.at(j);

			double diffVelX =  particles->at(i).intVelocity.x - particles->at(neighbor).intVelocity.x;
			double diffVelY =  particles->at(i).intVelocity.y - particles->at(neighbor).intVelocity.y;
			//if(particles->at(neighbor).type == 0){
			sumX = sumX + ( (massNeigh/densityNeigh)*diffVelX*kernelNeig );
			sumY = sumY + ( (massNeigh/densityNeigh)*diffVelY*kernelNeig );
			//}
			}
		}

		
		particles->at(i).velocity.x = particles->at(i).intVelocity.x - (epsilon*sumX);
		particles->at(i).velocity.y = particles->at(i).intVelocity.y - (epsilon*sumY);
		

		}
	}



}

//void velocityXSPHCalculator2D( vector<Particle2D> *particles, double dt, double epsilon){
//
//
//	for(int i = 0; i < particles->size(); ++i){
//		if(particles->at(i).type==0){
//		
//
//		particles->at(i).velocity.x = particles->at(i).intVelocity.x;
//		particles->at(i).velocity.y = particles->at(i).intVelocity.y;
//
//		}
//	}
//
//
//
//}