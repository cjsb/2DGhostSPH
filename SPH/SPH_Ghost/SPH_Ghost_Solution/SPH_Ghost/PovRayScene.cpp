#include "Functions.h"


void createPovRayScene(vector<Particle2D> *particles, int step){
		
	char nome[1000] = "";
	int n;
	n = sprintf (nome, "SPHScene%d.pov", step);
	FILE *file;
	file = fopen(nome, "w");



	fprintf(file, "#include \"colors.inc\"\n");
	fprintf(file, "background{Black}\n");
	fprintf(file, "camera{\n");
	fprintf(file, "	angle 0\n");
	fprintf(file, "	location <1.5,0.3,-2.5>\n");
	fprintf(file, "	look_at <1.5,0.3,0>}\n");
	fprintf(file, "light_source { <10, 20, -10> color White }\n\n\n");

	fprintf(file, "plane{\n");
	fprintf(file, "<0,0,1>, -.001\n");
	fprintf(file, "pigment{color White}\n");
	fprintf(file, "finish{reflection .7 }} \n\n\n");
	
	fprintf(file, "blob{\n");
	fprintf(file, "threshold 0.1\n");
	bool first = false;
	for(int i = 0; i < particles->size(); ++i){
		if(particles->at(i).type == 0){
		fprintf(file, "sphere{<%lf,%lf,0>, 0.025 1 pigment{rgbt<0, 1, 1, .3>}}\n",particles->at(i).position.x, particles->at(i).position.y);
		}else if(particles->at(i).type == 1){
			if(first == false){
				fprintf(file, "}\n");
				first = true;
			}
			fprintf(file, "sphere{<%lf,%lf,0>, 0.01 pigment{Black}}\n",particles->at(i).position.x, particles->at(i).position.y);
		}

	}

	fclose(file);

}