#include "Calculators.h"

void neighborCalculatorBruteForce2D(vector<Particle2D> *particles, double radius){

	for(int i = 0; i < particles->size(); ++i){
	
		particles->at(i).neighbors.clear();
	}

		
	for(int i = 0; i < particles->size();++i){

		for(int j = 0; j < particles->size(); ++j){

			if(i != j){ // i is not neighobor of i

				double distanceNeigh = distance2D(particles->at(i).position, particles->at(j).position);
				
				if(distanceNeigh < radius){
					particles->at(i).neighbors.push_back(j);
				}


			}


		}
	}

	/*FILE *file;
	
	file = fopen("neighbors.txt", "w");
	
	
	for(int i = 0; i < particles->size();++i){
		fprintf(file, "%d: ", i);
		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){

			fprintf(file, "%d ", particles->at(i).neighbors.at(j));

		}
		fprintf(file, "\n");
	}

		

	fclose(file);*/



}