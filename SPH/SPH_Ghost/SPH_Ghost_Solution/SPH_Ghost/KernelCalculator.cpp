#include "Calculators.h"

double kernelCalc(double q, double h){
	
	double pi = 3.1415926535897931e+0;

	double factor = 15.0 / (7.0*pi*h*h);
	double w = 0;

	if(q >=0 && q < 1){
				
		w = (2.0/3.0) - (q*q) + (q*q*q/2.0);
		w = factor * w;
	}else if(q >= 1 && q < 2){

		w =(pow((2.0 - q),3))/6.0;
		w = factor * w;
		

	}else{
		w = 0.0;
		
	}

	



	return w;

}

void kernelCalculator2D(vector<Particle2D> *particles, double h){

	for(int i = 0; i < particles->size(); ++i){
		particles->at(i).kernel.clear();
	}

	for(int i = 0; i < particles->size(); ++i){

		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){

			int neighbor = particles->at(i).neighbors.at(j);

			double R = distance2D(particles->at(i).position, particles->at(neighbor).position);
			R = R/h;

			double w = kernelCalc(R,h);

			particles->at(i).kernel.push_back(w);
			

		}

	}


	/*FILE *kernelF;
	
	kernelF = fopen("kernel.txt", "w");
	
	for(int i = 0; i < particles->size(); ++i){

		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){

			fprintf(kernelF,  "%lf ",particles->at(i).kernel[j]); 
		}

		fprintf(kernelF, "\n ");
	}

		fclose(kernelF);*/


}