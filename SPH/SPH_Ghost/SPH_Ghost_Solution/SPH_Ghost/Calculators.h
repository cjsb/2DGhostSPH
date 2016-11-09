#include "Structs.h"
#include "Functions.h"
#include "TimerWin32.hpp"

using namespace std;

void pressureCalculator2D( vector<Particle2D> *particles, double rho0);

void pressureCalculator2D2( vector<Particle2D> *particles, double rho0, int step);

void neighborCalculatorBruteForce2D(vector<Particle2D> *particles, double radius);

double kernelCalc(double q, double h);

void kernelCalculator2D(vector<Particle2D> *particles, double h);

void kernelGradCalculator2D(vector<Particle2D> *particles, double h);

void densityCalculator2D(vector<Particle2D> *particles, double radius);

void densityCalculator22D(vector<Particle2D> *particles, double radius);

void pressureForceCalculator2D( vector<Particle2D> *particles );

void lennardJonesCalculator2D( vector<Particle2D> *particles, double radius);

void velocityCalculator2D( vector<Particle2D> *particles, double dt );

void artificialViscosity2D( vector<Particle2D> *particles, double viscosity, double h);

void velocityXSPHCalculator2D( vector<Particle2D> *particles, double dt, double epsilon);

void positionCalculator2D( vector<Particle2D> *particles, double dt );

void singleStepCalculator2D( vector<Particle2D> *particles, double dt, double rho0, double h, double viscosity, int step, int &numberGhost);

void timeIntegrationCalculator2D( vector<Particle2D> *particles, int numberInteractions, double dt, double h);

void printOut(FILE *output, vector<Particle2D> *particles);

void printOut2(FILE *output, vector<Particle2D> *particles);

void IdentifyFreeSurface(vector<Particle2D> *particles, int value);

void CreateGhostParticles2D(vector<Particle2D> *particles, double r, double rho0, int &numberGhost);

void createFluidDamBreak2D2( vector<Particle2D> *particles, double &h);

void createFluidDamBreak2D3( vector<Particle2D> *particles, double &h);

void createBoundaryDamBreak2D3( vector<Particle2D> *particles);
