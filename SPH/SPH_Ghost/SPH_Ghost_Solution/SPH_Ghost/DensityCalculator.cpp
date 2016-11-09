#include "Calculators.h"

#include <math.h>

void densityCalculator2D(vector<Particle2D> *particles, double radius){

	bool normalization = false;
	
	double selfKernel = 0.0;

	for(int i = 0; i < particles->size(); ++i){

		double distance = 0; //self density
		particles->at(i).density = 0.0;//kernelCalc(distance, radius)*particles->at(i).mass;
		//particles->at(i).density = 0.0;
		//selfKernel = kernelCalc(distance, radius);

	}


	for(int i = 0; i < particles->size(); ++i){

		for(int j = 0;  j< particles->at(i).neighbors.size(); ++j){

			int neighbor = particles->at(i).neighbors.at(j);
			
			double massNeigh = particles->at(neighbor).mass;
			double kernelNeig = particles->at(i).kernel.at(j);

			double rho = massNeigh*kernelNeig;
			
			particles->at(i).density = (particles->at(i).density) + rho;
			
		}


	}

	//normalization
	if(normalization == true){
	for(int i = 0; i < particles->size(); ++i){

		double norm = 0;
		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){
			
			int neighbor = particles->at(i).neighbors.at(j);
			
			double massNeigh = particles->at(neighbor).mass;
			double densityNeigh = particles->at(neighbor).density;
			double kernelNeig = particles->at(i).kernel.at(j);

			norm = norm + ( (massNeigh/densityNeigh)*kernelNeig);
			

		}
		particles->at(i).density  = particles->at(i).density /norm;

	}

	}

	//for(int i = 0; i < particles->size(); ++i){

	//	double d = particles->at(i).density;

	//	if(d > 1000.0){
	//		particles->at(i).density  = 1000.0;
	//	}
	//	//particles->at(i).density  = 1000.0;
	//}

	
	FILE *file;
	
	file = fopen("density.txt", "w");
	
	
	for(int i = 0; i < particles->size();++i){
		fprintf(file, "%d: %lf", i, particles->at(i).density);
		fprintf(file, "\n");
		
	}

		fprintf(file, "\n");

	fclose(file);



}

void densityCalculator22D(vector<Particle2D> *particles, double radius){

	
	for(int i = 0; i < particles->size(); ++i){
		double sum = 0.0;

		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){

			int neighbor = particles->at(i).neighbors.at(j);
			
			double massNeigh = particles->at(neighbor).mass;
			double kernelNeig = particles->at(i).kernel.at(j);

			double diffX = particles->at(i).velocity.x - particles->at(neighbor).velocity.x;
			double diffY = particles->at(i).velocity.y - particles->at(neighbor).velocity.y;

			double gradX = particles->at(i).kernelGrad.at(j).x;
			double gradY = particles->at(i).kernelGrad.at(j).y;

			sum = sum + massNeigh*( (diffX*gradX) + ( diffY*gradY));
			
			

		}

		particles->at(i).density = (particles->at(i).density) + (sum*0.0005);
		if(particles->at(i).type == -1){
			particles->at(i).density = 1000.0;
		}
	}

	
	/*FILE *file;
	
	file = fopen("density.txt", "w");
	
	
	for(int i = 0; i < particles->size();++i){
		fprintf(file, "%d: %lf", i, particles->at(i).density);
		fprintf(file, "\n");
		
	}

		fprintf(file, "\n");

	fclose(file);
*/


}

void IdentifyFreeSurface(vector<Particle2D> *particles, int value){	

	for(int i = 0; i < particles->size(); ++i){

		Particle2D p = particles->at(i);
		double result = divPosition(particles,p);
		result = round(result);

		if(result > value){

			particles->at(i).freeSurface = 0;
		
		}else{

			if(particles->at(i).type == 0){
			
				particles->at(i).freeSurface = 1;
			
			}		
		}

	}

}