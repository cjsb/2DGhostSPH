#include "Functions.h"

double distance2D(Vector2D <double> a,Vector2D <double> b){
	double distance = 0;

	distance = ((b.x - a.x)*(b.x - a.x)) + ((b.y - a.y)*(b.y - a.y));
	distance = sqrt(distance);

	return distance;
}


double	divPosition(vector<Particle2D> *particles, Particle2D particle){

	double result = 0.0;

	for(int j = 0; j < particle.neighbors.size(); ++j){

		int neighbor = particle.neighbors.at(j);
			
			double massNeigh = particles->at(neighbor).mass;
			double densityNeigh = particles->at(neighbor).density;
			
			double diffX = particle.position.x - particles->at(neighbor).position.x;
			double diffY = particle.position.y - particles->at(neighbor).position.y;

			double gradX = particle.kernelGrad.at(j).x;
			double gradY = particle.kernelGrad.at(j).y;

			result = result + ( (massNeigh/densityNeigh) * ((diffX*gradX) + ( diffY*gradY)) );
			


	}
	result = fabs(result);
	return result;
}

double round(double number)
{
    return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}