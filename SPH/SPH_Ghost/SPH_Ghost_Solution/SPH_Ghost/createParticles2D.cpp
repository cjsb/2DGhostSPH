#include "Functions.h"


void createFluidParticles2D( vector<Particle2D> *particles, double &h){

	int mp = 40;
	int np = 40;

	double xl = 1.e-3;
	double yl = 1.e-3;
	
	double dx = xl/mp;
	double dy = yl/mp;

	for(int i = 0; i < mp; ++i){

		for(int j = 0; j < np; ++j){

			Particle2D particle;

			particle.position.x = i*dx + dx/2;
			particle.position.y = j*dy + dy/2;

			particles->push_back(particle);


		}
	}

	for(int i = 0; i < particles->size(); ++i){

		particles->at(i).velocity.x = 0.0;
		particles->at(i).velocity.y = 0.0;

		particles->at(i).density = 1000;
		particles->at(i).mass = dx*dy*1000;

		particles->at(i).pressure = 0.0;
		particles->at(i).type = 0;


	}

	h = dx;

}


void createFluidDamBreak2D( vector<Particle2D> *particles, double &h){


	int mp = 60;
	int np = 60;

	double xl = 0.6;
	double yl = 0.6;
	
	double dx = xl/mp;
	double dy = yl/mp;

	for(int i = 0; i < mp; ++i){

		for(int j = 0; j < np; ++j){

			Particle2D particle;

			particle.position.x = i*dx + dx/2;
			particle.position.y = j*dy + dy/2;

			particles->push_back(particle);


		}
	}

	for(int i = 0; i < particles->size(); ++i){

		particles->at(i).velocity.x = 0.0;
		particles->at(i).velocity.y = 0.0;

		particles->at(i).density = 1000;
		particles->at(i).mass = dx*dy*1000;

		particles->at(i).pressure = 0.0;
		particles->at(i).initialPressure = 1000.0*9.8*(0.6- particles->at(i).position.y);
		particles->at(i).type = 0;
		particles->at(i).freeSurface = 0;


	}

	h = dx;

}


void createBoundaryDamBreak2D( vector<Particle2D> *particles){


	double mp = 40;
	double xl = 0.6;
	double dx = xl/mp;

	

	for( int i = 1; i < 4*2*mp+1; ++i){ //down

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = i*dx/2;
		particle.position.y = 0.0;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;
		particle.freeSurface = 0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp+10; ++i){ //left

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = 0.0;
		particle.position.y = i*dx/2;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;
		particle.freeSurface = 0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp+10; ++i){ //right

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = 4*xl;
		particle.position.y = i*dx/2;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;
		particle.freeSurface = 0;

		particles->push_back(particle);
	}



}


void createBoundaryDamBreak2D2( vector<Particle2D> *particles){


	double mp = 40;
	double xl = 0.6;
	double dx = xl/mp;

	

	for( int i = 1; i < 4*2*mp+1; ++i){ //down

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = i*dx;
		particle.position.y = 0.0;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp+10; ++i){ //left

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = 0.0;
		particle.position.y = i*dx;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp+10; ++i){ //right

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = 8*xl;
		particle.position.y = i*dx;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}



}


void createBoundaryDamBreak2D2Second( vector<Particle2D> *particles){


	double mp = 40;
	double xl = 0.6;
	double dx = xl/mp;

	

	for( int i = 1; i < 4*2*mp+1; ++i){ //down

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = i*dx;
		particle.position.y = dx;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp+10; ++i){ //left

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = -dx;
		particle.position.y = i*dx;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp+10; ++i){ //right

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = (8*xl)+dx;
		particle.position.y = i*dx;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}



}



void createBoundaryParticles2D( vector<Particle2D> *particles){

	double mp = 40;
	double xl = 1.0e-3;
	double dx = xl/mp;

	double v = 1.e-3;

	for( int i = 0; i < 2*mp+1; ++i){ //up

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;

		particle.position.x = i*dx/2;
		particle.position.y = xl;

		particle.velocity.x = v;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = v;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp+1; ++i){ //down

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;

		particle.position.x = i*dx/2;
		particle.position.y = 0.0;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp; ++i){ //left

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;

		particle.position.x = 0.0;
		particle.position.y = i*dx/2;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp; ++i){ //right

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;

		particle.position.x = xl;
		particle.position.y = i*dx/2;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}



}

void createFluidDamBreak2D2( vector<Particle2D> *particles, double &h){


	int mp = 60;
	int np = 60;

	double xl = 0.6;
	double yl = 0.6;
	
	double dx = xl/mp;
	double dy = yl/mp;

	for(int i = 0; i < mp; ++i){

		for(int j = 0; j < np; ++j){

			Particle2D particle;

			particle.position.x = (i*dx) + (dx/2) + (3*xl/2);
			particle.position.y = j*dy + dy/2;

			particles->push_back(particle);


		}
	}

	for(int i = 0; i < particles->size(); ++i){

		particles->at(i).velocity.x = 0.0;
		particles->at(i).velocity.y = 0.0;

		particles->at(i).density = 1000;
		particles->at(i).mass = dx*dy*1000;

		particles->at(i).pressure = 0.0;
		particles->at(i).initialPressure = 1000.0*9.8*(0.6- particles->at(i).position.y);
		particles->at(i).type = 0;


	}

	h = dx;

}

void createFluidDamBreak2D3( vector<Particle2D> *particles, double &h){


	int mp = 60;
	int np = 60;

	double xl = 0.6;
	double yl = 0.6;
	
	double dx = xl/mp;
	double dy = yl/mp;

	for(int i = 0; i < mp; ++i){

		for(int j = 0; j < np; ++j){

			Particle2D particle;

			particle.position.x = i*dx + dx/2;
			particle.position.y = j*dy + dy/2;

			particles->push_back(particle);


		}
	}

	for(int i = 0; i < particles->size(); ++i){

		particles->at(i).velocity.x = 0.0;
		particles->at(i).velocity.y = 0.0;

		particles->at(i).density = 1000;
		particles->at(i).mass = dx*dy*1000;

		particles->at(i).pressure = 0.0;
		particles->at(i).initialPressure = 1000.0*9.8*(0.6- particles->at(i).position.y);
		particles->at(i).type = 0;


	}

	h = dx;

}


void createBoundaryDamBreak2D3( vector<Particle2D> *particles){


	double mp = 40;
	double xl = 0.6;
	double dx = xl/mp;

	

	for( int i = 1; i < 4*2*mp+1; ++i){ //down

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = i*dx/2;
		particle.position.y = 0.0;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp+10; ++i){ //left

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = 0.0;
		particle.position.y = i*dx/2;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}

		for( int i = 0; i < 2*mp+10; ++i){ //right

		Particle2D particle;
		particle.density = 1000;
		particle.mass = 1000*dx*dx;
		particle.type = 1;
		particle.pressure = 0;
		particle.initialPressure = 0;

		particle.position.x = 4*xl;
		particle.position.y = i*dx/2;

		particle.velocity.x = 0.0;
		particle.velocity.y = 0.0;

		particle.intVelocity.x = 0.0;
		particle.intVelocity.y = 0.0;

		particles->push_back(particle);
	}
	
	//for( int i = 1; i < mp/2; ++i){ //right

	//	Particle2D particle;
	//	particle.density = 1000;
	//	particle.mass = 1000*dx*dx;
	//	particle.type = 1;
	//	particle.pressure = 0;
	//	particle.initialPressure = 0;

	//	particle.position.x = 2*xl;
	//	particle.position.y = i*dx/2;

	//	particle.velocity.x = 0.0;
	//	particle.velocity.y = 0.0;

	//	particle.intVelocity.x = 0.0;
	//	particle.intVelocity.y = 0.0;

	//	particles->push_back(particle);
	//}


}