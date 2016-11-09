#ifndef _types_h
#define _types_h

#include <iostream>
#include <fstream>
#include "math.h"
#include <stdio.h>
#include <vector>

using namespace std;

template <typename T> 
struct Vector2D { 
  T x;
  T y;
};

template <typename T> 
struct Vector3D{
	T x;
	T y;
	T z;
};



struct Particle2D{

	Vector2D <double> position;
	Vector2D <double> velocity;
	Vector2D <double> intVelocity;
	Vector2D <double> acceleration;
	
	double mass;
	double pressure;
	double initialPressure;
	double density;
	
	int type; // 0 for fluid, 1 for board, -1 for ghost
	int freeSurface; //1 for true, 0 for false
	vector<int> neighbors;
	
	vector< double > kernel;
	vector< Vector2D<double> > kernelGrad;


};

#endif