#include "Calculators.h"

void artificialViscosity2D( vector<Particle2D> *particles, double viscosity, double h){

	double epsilon = 0.001;

	for(int i = 0; i < particles->size();++i){
		double forceX = 0.0;
		double forceY = 0.0;

		double mass = particles->at(i).mass;
		double density = particles->at(i).density;

		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){

			int neighbor = particles->at(i).neighbors[j];

			double diffVelocityX = particles->at(i).intVelocity.x - particles->at(neighbor).intVelocity.x;  
			double diffVelocityY = particles->at(i).intVelocity.y - particles->at(neighbor).intVelocity.y;  

			double diffPositionX = particles->at(i).position.x - particles->at(neighbor).position.x;  
			double diffPositionY = particles->at(i).position.y - particles->at(neighbor).position.y;  

			double distance = distance2D(particles->at(i).position, particles->at(neighbor).position);

			double product = (diffVelocityX*diffPositionX) + (diffVelocityY*diffPositionY);


			if(product < 0){
				double neighMass = particles->at(neighbor).mass;
				double neighDensity = particles->at(neighbor).density;

				double v = 2.0*h*35.0/*8.8*0.01*/*0.01/(density + neighDensity);
				double force = -v * product;
				force = force/ ((distance*distance) + (h*h*epsilon));

				/*double viscousTerm = (2*h*0.01) / (density + neighDensity);


				double force = -viscousTerm * product;
				force = force/ ((distance*distance) + (h*epsilon));*/

				

				forceX = forceX  + (neighMass*force*particles->at(i).kernelGrad.at(j).x);
				forceY = forceY  + (neighMass*force*particles->at(i).kernelGrad.at(j).y);


			}

		}

		particles->at(i).acceleration.x += -forceX;
		particles->at(i).acceleration.y += -forceY;

	}







}

//void artificialViscosity2D( vector<Particle2D> *particles, double viscosity, double h){
//	 
//	double epsilon = 0.001;
//	double c = 0.6;
//
//	for(int i = 0; i < particles->size();++i){
//		double forceX = 0.0;
//		double forceY = 0.0;
//
//		double mass = particles->at(i).mass;
//		double density = particles->at(i).density;
//
//		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){
//
//			int neighbor = particles->at(i).neighbors[j];
//
//			double diffVelocityX = particles->at(i).intVelocity.x - particles->at(neighbor).intVelocity.x;  
//			double diffVelocityY = particles->at(i).intVelocity.y - particles->at(neighbor).intVelocity.y;  
//
//			double diffPositionX = particles->at(i).position.x - particles->at(neighbor).position.x;  
//			double diffPositionY = particles->at(i).position.y - particles->at(neighbor).position.y;  
//
//			double distance = distance2D(particles->at(i).position, particles->at(neighbor).position);
//
//			double product = (diffVelocityX*diffPositionX) + (diffVelocityY*diffPositionY);
//
//
//			if(product < 0){
//				double neighMass = particles->at(neighbor).mass;
//				double neighDensity = particles->at(neighbor).density;
//
//				double muv = (h*product) / ( (distance*distance) * (0.1*0.1) );
//
//				double mrho = (neighDensity + density) /2.0;
//
//				double piv = (2*muv - c)*muv/mrho;
//
//			
//				forceX = forceX  - (neighMass*piv*particles->at(i).kernelGrad.at(j).x);
//				forceY = forceY  - (neighMass*piv*particles->at(i).kernelGrad.at(j).y);
//
//
//			}
//
//		}
//
//		particles->at(i).acceleration.x += forceX;
//		particles->at(i).acceleration.y += forceY;
//
//	}
//
//
//
//
//
//
//
//}

//void artificialViscosity2D( vector<Particle2D> *particles, double viscosity, double h){
//
//	double alpha = 1;
//	double beta = 0;
//	double etq = 0.1;
//
//	double c = 0.01;
//
//
//	for(int i = 0; i < particles->size();++i){
//	
//		double mass = particles->at(i).mass;
//		double density = particles->at(i).density;
//
//		for(int j = 0; j < particles->at(i).neighbors.size(); ++j){
//
//			int neighbor = particles->at(i).neighbors[j];
//
//			double diffVelocityX = particles->at(i).intVelocity.x - particles->at(neighbor).intVelocity.x;  
//			double diffVelocityY = particles->at(i).intVelocity.y - particles->at(neighbor).intVelocity.y;  
//
//			double diffPositionX = particles->at(i).position.x - particles->at(neighbor).position.x;  
//			double diffPositionY = particles->at(i).position.y - particles->at(neighbor).position.y;  
//
//			double distance = distance2D(particles->at(i).position, particles->at(neighbor).position);
//
//			double product = (diffVelocityX*diffPositionX) + (diffVelocityY*diffPositionY);
//
//
//
//			if(product < 0){
//
//				double neighMass = particles->at(neighbor).mass;
//				double neighDensity = particles->at(neighbor).density;
//
//				double muv = h*product / (distance*distance +h*h*etq*etq);
//
//				double mrho = (neighDensity + density) /2.0;
//
//				double piv = (beta*muv - alpha*c)*muv/mrho;
//
//				double hx = -piv*particles->at(i).kernelGrad.at(j).x;
//				double hy = -piv*particles->at(i).kernelGrad.at(j).y;
//
//
//				particles->at(i).acceleration.x += neighMass*hx;
//				particles->at(i).acceleration.y += neighMass*hy;
//			}
//
//
//		}
//
//	}
//
//}