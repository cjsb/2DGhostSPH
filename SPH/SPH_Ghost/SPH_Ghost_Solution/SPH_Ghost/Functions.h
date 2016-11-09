#include "Structs.h"

double distance2D(Vector2D <double> a,Vector2D <double> b);

double round(double number);

void createFluidParticles2D( vector<Particle2D> *particles, double &h);

void createBoundaryParticles2D( vector<Particle2D> *particles);

void createFluidDamBreak2D( vector<Particle2D> *particles, double &h);

void createBoundaryDamBreak2D( vector<Particle2D> *particles);

void createBoundaryDamBreak2D2( vector<Particle2D> *particles);

void createBoundaryDamBreak2D2Second( vector<Particle2D> *particles);

void createPovRayScene(vector<Particle2D> *particles, int step);

double	divPosition(vector<Particle2D> *particles, Particle2D particle);