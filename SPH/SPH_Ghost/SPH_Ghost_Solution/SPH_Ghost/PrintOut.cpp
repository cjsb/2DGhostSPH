#include "Calculators.h"

void printOut(FILE *output, vector<Particle2D> *particles){

	fprintf(output, "<?xml version='1.0' encoding='UTF-8'?>\n");
	fprintf(output, "<VTKFile xmlns='VTK' byte_order='LittleEndian' version='0.1' type='UnstructuredGrid'>\n");
	fprintf(output, " <UnstructuredGrid>\n");

	fprintf(output,"  <Piece NumberOfCells='%d' NumberOfPoints='%d'>\n",particles->size(),particles->size());

	fprintf(output,"   <Points>\n");
	fprintf(output, "    <DataArray NumberOfComponents='3' type='Float32' Name='Position' format='ascii'>\n");

	for(int i = 0; i < particles->size(); i++)
			{
				fprintf(output, "%lf %lf 0 ", particles->at(i).position.x, particles->at(i).position.y);
				
			
			}
	
	fprintf(output, "\n");
	fprintf(output,"    </DataArray>\n");
	fprintf(output,"   </Points>\n");

	fprintf(output, "   <PointData>\n");
	
	fprintf(output,"    <DataArray NumberOfComponents='3' type='Float32' Name='Velocity' format='ascii'>\n");
			for(int i = 0; i < particles->size(); i++)
			{
				
				fprintf(output, "%lf %lf 0 ", particles->at(i).velocity.x, particles->at(i).velocity.y);
			}
	fprintf(output,"\n");
	fprintf(output, "    </DataArray>\n");

	fprintf(output,"    <DataArray NumberOfComponents='1' type='Float32' Name='Pressure' format='ascii'>\n");
			for( int i = 0; i < particles->size(); i++)
			{
				fprintf(output, "%lf ", particles->at(i).pressure);				
			}
			fprintf(output,"\n");
			fprintf(output,"    </DataArray>\n");

			//More to add soon...

			fprintf(output,"   </PointData>\n");

			//VTK specific information
			fprintf(output,"   <Cells>\n");

			//Connectivity			
			fprintf(output,"    <DataArray type='Int32' Name='connectivity' format='ascii'>\n");
			for( int i = 0; i < particles->size(); i++)
			{
				fprintf(output, "%d ",i);
			}
			fprintf(output,"\n");
			fprintf(output,"    </DataArray>\n");

			//Offsets			
			fprintf(output,"    <DataArray type='Int32' Name='offsets' format='ascii'>\n");
			for( int i = 1; i <= particles->size(); i++)
			{
				fprintf(output, "%d ",i);
			}
			fprintf(output,"\n");
			fprintf(output,"    </DataArray>\n");

			//Types			
			fprintf(output,"    <DataArray type='UInt8' Name='types' format='ascii'>\n");
			for( int i = 0; i < particles->size(); i++)
			{
				fprintf(output,"1 ");
			}
			fprintf(output,"\n");
			fprintf(output,"    </DataArray>\n");

			fprintf(output,"   </Cells>\n");

			fprintf(output,"  </Piece>\n");
			fprintf(output," </UnstructuredGrid>\n");
			fprintf(output,"</VTKFile>");






}


void printOut2(FILE *output, vector<Particle2D> *particles){

	fprintf(output, "<?xml version='1.0' encoding='UTF-8'?>\n");
	fprintf(output, "<VTKFile xmlns='VTK' byte_order='LittleEndian' version='0.1' type='UnstructuredGrid'>\n");
	fprintf(output, " <UnstructuredGrid>\n");

	fprintf(output,"  <Piece NumberOfCells='%d' NumberOfPoints='%d'>\n",particles->size(),particles->size());

	fprintf(output,"   <Points>\n");
	fprintf(output, "    <DataArray NumberOfComponents='3' type='Float32' Name='Position' format='ascii'>\n");

	for(int i = 0; i < particles->size(); i++)
			{
				
				Particle2D p = particles->at(i);
				double result = divPosition(particles,p);
				if(result > 1.5){
				fprintf(output, "%lf %lf 0 ", particles->at(i).position.x, particles->at(i).position.y);
				}else{
					fprintf(output, "0 0 0 ");
				
				}
			
			}
	
	fprintf(output, "\n");
	fprintf(output,"    </DataArray>\n");
	fprintf(output,"   </Points>\n");

	fprintf(output, "   <PointData>\n");
	
	fprintf(output,"    <DataArray NumberOfComponents='3' type='Float32' Name='Velocity' format='ascii'>\n");
			for(int i = 0; i < particles->size(); i++)
			{
				
				fprintf(output, "%lf %lf 0 ", particles->at(i).velocity.x, particles->at(i).velocity.y);
			}
	fprintf(output,"\n");
	fprintf(output, "    </DataArray>\n");

	fprintf(output,"    <DataArray NumberOfComponents='1' type='Float32' Name='Pressure' format='ascii'>\n");
			for( int i = 0; i < particles->size(); i++)
			{
				fprintf(output, "%lf ", particles->at(i).pressure);				
			}
			fprintf(output,"\n");
			fprintf(output,"    </DataArray>\n");

			//More to add soon...

			fprintf(output,"   </PointData>\n");

			//VTK specific information
			fprintf(output,"   <Cells>\n");

			//Connectivity			
			fprintf(output,"    <DataArray type='Int32' Name='connectivity' format='ascii'>\n");
			for( int i = 0; i < particles->size(); i++)
			{
				fprintf(output, "%d ",i);
			}
			fprintf(output,"\n");
			fprintf(output,"    </DataArray>\n");

			//Offsets			
			fprintf(output,"    <DataArray type='Int32' Name='offsets' format='ascii'>\n");
			for( int i = 1; i <= particles->size(); i++)
			{
				fprintf(output, "%d ",i);
			}
			fprintf(output,"\n");
			fprintf(output,"    </DataArray>\n");

			//Types			
			fprintf(output,"    <DataArray type='UInt8' Name='types' format='ascii'>\n");
			for( int i = 0; i < particles->size(); i++)
			{
				fprintf(output,"1 ");
			}
			fprintf(output,"\n");
			fprintf(output,"    </DataArray>\n");

			fprintf(output,"   </Cells>\n");

			fprintf(output,"  </Piece>\n");
			fprintf(output," </UnstructuredGrid>\n");
			fprintf(output,"</VTKFile>");






}