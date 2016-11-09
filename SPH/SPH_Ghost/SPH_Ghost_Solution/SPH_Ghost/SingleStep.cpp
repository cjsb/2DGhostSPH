#include "Calculators.h"

void singleStepCalculator2D( vector<Particle2D> *particles, double dt, double rho0, double h, double viscosity, int step, int &numberGhost){
	
	neighborCalculatorBruteForce2D(particles, 3*h); //find the neighbors
		
	kernelCalculator2D(particles, h); //calculate the kernels

	kernelGradCalculator2D( particles, h); //calculate the kernel gradients
	
	IdentifyFreeSurface(particles, 1.5); //identify the free surface

	CreateGhostParticles2D(particles, h, rho0, numberGhost); //create the ghost particles

	neighborCalculatorBruteForce2D(particles, 3*h);
		
	kernelCalculator2D(particles, h);

	kernelGradCalculator2D( particles, h);
	
	//densityCalculator2D(particles, h);

	densityCalculator22D(particles, h); //calculate the density
	
	pressureCalculator2D( particles, rho0); //calculate the pressure

	//pressureCalculator2D2(particles, rho0, step);

	pressureForceCalculator2D( particles ); //add pressure and gravity forces

	//artificialViscosity2D( particles, viscosity, h);

	//lennardJonesCalculator2D( particles, h);

	velocityCalculator2D( particles, dt ); //calculate the velocity

	velocityXSPHCalculator2D( particles, dt, 0.05); //Calculate the viscosity

	positionCalculator2D( particles, dt ); //update the position

	//FILE *file;
	//file = fopen("div.txt", "w");
	//

	//for(int i = 0; i < particles->size(); ++i){
	//	Particle2D p = particles->at(i);
	//	double result = divPosition(particles,p);
	//	fprintf(file, "%lf %lf %lf\n", result, p.position.x, p.position.y);

	//}
	//fclose(file);

	//IdentifyFreeSurface(particles, 1.5);

	//CreateGhostParticles2D(particles, h, rho0, numberGhost);
	
	createPovRayScene(particles,step); //create the pov ray blob scene
}