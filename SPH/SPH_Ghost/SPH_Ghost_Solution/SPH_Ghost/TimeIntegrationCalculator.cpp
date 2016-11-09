#include "Calculators.h"

void timeIntegrationCalculator2D( vector<Particle2D> *particles,  int numberInteractions, double dt, double h){
	
	int numberGhost = 0;

	double time = 0.0;
	double rho0 = 1000.0; //water
	double viscosity = 0.0005;
	FILE *out;
	
	out = fopen("out0.vtu", "w");
	printOut(out, particles);
	fclose(out);

	FILE *fileTime;
	fileTime = fopen("timeSPHCPUCAVITY.txt", "w");
	
	TimerWin32 timer;
	timer.reset();

	for(int step = 1; step <= numberInteractions /*&& time < 0.05*/; ++step){
		numberGhost = 0;
		timer.reset();

		singleStepCalculator2D( particles,  dt,  rho0,  h,  viscosity, step, numberGhost);
		
		unsigned long time = timer.getMicroseconds();
		
		//std::cout << "Kernel time: " << (static_cast<float>(time)/1000.f) << " milliseconds." << std::endl;
		fprintf(fileTime, "%lf\n", (static_cast<float>(time)/1000.f));
		 
		char nome[1000] = "";
		int n;
		n = sprintf (nome, "out%d.vtu", step+1);
		FILE *file;
	
		file = fopen(nome, "w");
		//printOut(file, particles);
		printOut(file, particles);
		fclose(file);

		time = time + dt;

		for(int n = 0; n < numberGhost; ++n){
			particles->pop_back();
		}

	}


}