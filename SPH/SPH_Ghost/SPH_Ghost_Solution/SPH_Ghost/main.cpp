#include "Calculators.h"

int main(){


	vector<Particle2D> *particles;
	particles = new vector<Particle2D>;

	double dt = 0.0005;
	int numberInterections = 6000;
	
	double h = 0;
	
	createFluidDamBreak2D(particles,h);
	createBoundaryDamBreak2D( particles);
	
	timeIntegrationCalculator2D(particles,numberInterections,dt, h );


}