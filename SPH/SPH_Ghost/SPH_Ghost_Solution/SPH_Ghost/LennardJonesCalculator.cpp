#include "Calculators.h"


void lennardJonesCalculator2D( vector<Particle2D> *particles, double radius){

	int n1 = 12;
	int n2 = 6;//4;

	double d = 1.e-2;//10*0.6;//1.e-2;

	double dist = radius;//1.25e-5; //radius;//0.75*radius;//1.25e-5;

	for(int i = 0; i < particles->size();++i){

		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){

			int neighbor = particles->at(i).neighbors[j];

			if(particles->at(i).type == 0 && particles->at(neighbor).type == 1){

				double distance = distance2D(particles->at(i).position,particles->at(neighbor).position);
				
				if( distance < dist){

					double f = pow((dist/distance),n1) - pow((dist/distance),n2);
					f = f/pow(distance,2);
					
					double distanceX = particles->at(i).position.x - particles->at(neighbor).position.x;
					double distanceY = particles->at(i).position.y - particles->at(neighbor).position.y;

					//printf("%lf \n",d*f*distanceX);

					particles->at(i).acceleration.x += d*f*distanceX;
					particles->at(i).acceleration.y += d*f*distanceY;



				}



			}
		
		
		
		}



	}










}