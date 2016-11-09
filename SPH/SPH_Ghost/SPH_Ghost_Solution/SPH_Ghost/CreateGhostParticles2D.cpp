#include "Calculators.h"

void CreateGhostParticles2D(vector<Particle2D> *particles, double r, double rho0, int &numberGhost){

	numberGhost = 0;

	double pi = 3.14159265359;

	vector<Particle2D> ghostCreators;
	
	for(int i = 0; i < particles->size(); ++i){

		if(particles->at(i).freeSurface == 1){
			ghostCreators.push_back(particles->at(i));

		}

	}
	

	for(int i = 0; i < ghostCreators.size() && i < 500; ++i){

		bool gotIt = false;

		for(int dart = 0; dart < 30 && gotIt == false; ++dart){

			
		double randomPos = (double)rand() / (double)RAND_MAX;
		double randomAngle = (double)rand() / (double)RAND_MAX;

		double distance = r * (randomPos + 1);
	
		double angle = 2 * pi * randomAngle;

		Particle2D ghost;
		ghost.position.x = ghostCreators.at(i).position.x + distance * cos(angle);
		ghost.position.y = ghostCreators.at(i).position.y + distance * sin(angle);

		bool valid = true;
		for(int j = 0; j < particles->size() && valid == true; ++j){

			distance = distance2D(particles->at(j).position, ghost.position);
			
			if(distance < r){
				valid = false;
			}


		}

		if(valid == true){
			
			numberGhost++;
			ghost.density = rho0;
			ghost.mass = ghostCreators.at(i).mass;
			ghost.pressure = 0.0;
			ghost.type = -1;

			ghost.velocity.x = ghostCreators.at(i).velocity.x;
			ghost.velocity.y = ghostCreators.at(i).velocity.y;


			ghostCreators.push_back(ghost);
			particles->push_back(ghost);
			gotIt = true;
		}




		}


	}





}