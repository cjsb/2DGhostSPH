#include "Calculators.h"

double kernelGradCalc2D(double r, double h, double dx){

	double pi = 3.1415926535897931e+0;
	
	double q = r/h;

	double factor = 15.0 / (7.0*pi*h*h);

	double gradW = 0;

	if( q >= 0 && q < 1){

		gradW = ( (-2.0) + ((3.0*q)/2.0) );
		gradW = gradW * dx;
		gradW = gradW / (h*h);

		gradW = factor * gradW;

	}else if( q >= 1 && q < 2){

		gradW = (-0.5)*(2-q)*(2-q);
		gradW = gradW * dx;
		gradW = gradW / (h*r);

		gradW = factor * gradW;

	}else{
		gradW = 0.0;
	}


	return gradW;
}



void kernelGradCalculator2D(vector<Particle2D> *particles, double h){

	for(int i = 0; i < particles->size(); ++i){
		particles->at(i).kernelGrad.clear();
	}

	for(int i = 0; i < particles->size(); ++i){

		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){

			int neighbor = particles->at(i).neighbors.at(j);

			double r = distance2D(particles->at(i).position, particles->at(neighbor).position);
			double rX = particles->at(i).position.x - particles->at(neighbor).position.x; 
			double rY = particles->at(i).position.y - particles->at(neighbor).position.y;

			Vector2D<double> gradW;
			gradW.x = kernelGradCalc2D(r, h, rX);
			gradW.y = kernelGradCalc2D(r, h, rY);

			particles->at(i).kernelGrad.push_back(gradW);
			
			 
		}

	}





}