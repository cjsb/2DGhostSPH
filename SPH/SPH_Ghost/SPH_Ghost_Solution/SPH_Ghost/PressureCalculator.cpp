#include "Calculators.h"

void pressureCalculator2D( vector<Particle2D> *particles, double rho0){

	
	for(int i = 0; i < particles->size(); ++i){

		//double k = 2000.0;//500;//2000.0;//1.013e5;//2000;
		//double rho = particles->at(i).density;
		//double division = pow(rho/rho0,7);
		//particles->at(i).pressure = k*(division-1);
		double y = particles->at(i).position.y;
		double B = 2000;//500;//(200*9.8*0.6/*(0.6-y)*/*1000.0)/(7.0);//(200*9.8*(0.6-y)*1000.0)/(7.0);//0.6*9.8*1000.0/7.0;//(200.0*9.8*0.6)/(1000.0*7.0);

		//double rhoAdjust = 1 + ((rho0*9.8*(0.6 - particles->at(i).position.y))/B);
		//particles->at(i).density = rho0*pow(rhoAdjust, 1/7);
		//printf("%lf ", particles->at(i).density);
		double rho = particles->at(i).density;
		//printf("%lf \n", rho);
		double div = rho/rho0;
		double division = pow(div,7);
		//particles->at(i).pressure = (B*(division-1)) + (rho*9.8*(0.6 - particles->at(i).position.y));
		particles->at(i).pressure = (B*(division-1));
		if(particles->at(i).type == -1){
			particles->at(i).pressure == 0;
		}
	/*	double rho = particles->at(i).density;
		double c = 0.01;
		double pressure = pow(c,2)*rho;
		particles->at(i).pressure = pressure;*/
		
		/*particles->at(i).pressure = (1400.0*1400.0)*(particles->at(i).density-rho0);*/
	}

}

void pressureCalculator2D2( vector<Particle2D> *particles, double rho0, int step){
		for(int i = 0; i < particles->size(); ++i){

		//double k = 2000.0;//500;//2000.0;//1.013e5;//2000;
		//double rho = particles->at(i).density;
		//double division = pow(rho/rho0,7);
		//particles->at(i).pressure = k*(division-1);
	if(step == 1){
		double rho = particles->at(i).density;
		particles->at(i).pressure = (rho*9.8*(0.6 - particles->at(i).position.y));

	}else{
		double B = (200.0*9.8*0.6)/(1000.0*7.0);

		//double rhoAdjust = 1 + ((rho0*9.8*(0.6 - particles->at(i).position.y))/B);
		//particles->at(i).density = rho0*pow(rhoAdjust, 1/7);
		//printf("%lf ", particles->at(i).density);
		double rho = particles->at(i).density;
		//printf("%lf \n", rho);
		double div = rho/rho0;
		double division = pow(div,7);
		//particles->at(i).pressure = (B*(division-1)) + (rho*9.8*(0.6 - particles->at(i).position.y));
		particles->at(i).pressure = (B*(division-1));
	}
	/*	double rho = particles->at(i).density;
		double c = 0.01;
		double pressure = pow(c,2)*rho;
		particles->at(i).pressure = pressure;*/
		
		/*particles->at(i).pressure = (1400.0*1400.0)*(particles->at(i).density-rho0);*/
	}

}
