#include "visit_writer.h"
#include<stdlib.h>
#include <math.h>

#define pi 4.0*atan(1.0)

int
main(int argc, char **argv)
{
    // Set up storage
    int nCellsX = 10;
    int nCellsY = 10;
    float cellCentered[nCellsX][nCellsY];
    float nodeCentered[nCellsX+1][nCellsY+1];

float dx = 1.0/(float)nCellsX;
float dy = dx;

    // Put data in the arrays.
    int x, y;
    for(x=0;x<nCellsX;x++)
        for(y=0;y<nCellsY;y++)
            cellCentered[x][y] = sin(pi*dx*x) * sin(pi*dy*y);

    for(x=0;x<nCellsX+1;x++)
        for(y=0;y<nCellsY+1;y++)
            nodeCentered[x][y] = 1/(x*y+0.1);

    // Write out the mesh and the arrays.
    int dims[] = { nCellsX+1, nCellsY+1, 1 };    // The number of nodes in the mesh.
    int vardims[] = { 1, 1 };   // Two scalars
    int centering[] = { 1, 0 }; // node centered, cell centered
    const char * const varnames[] = { "nodeCentered", "cellCentered" };
    float *arrays[] = { (float*)nodeCentered, (float*)cellCentered };

/*    write_regular_mesh("example.vtk", 0, dims, 2, vardims, centering,
                       varnames, arrays); */ //original ASCII format output version

write_regular_mesh("example2_bin.vtk", 0, dims, 2, vardims, centering,
                       varnames, arrays);

/*
void write_regular_mesh(const char *filename, int ub, int *dims,
                        int nvars, int *vardim, int *centering,
                        const char * const *varnames, float **vars)
{
    int  i;
 
    float *x = (float *) malloc(sizeof(float)*dims[0]);
    float *y = (float *) malloc(sizeof(float)*dims[1]);
    float *z = (float *) malloc(sizeof(float)*dims[2]);
 
    for (i = 0 ; i < dims[0] ; i++)
        x[i] = (float) i;
    for (i = 0 ; i < dims[1] ; i++)
        y[i] = (float) i;
    for (i = 0 ; i < dims[2] ; i++)
        z[i] = (float) i;
 
    write_rectilinear_mesh(filename, ub, dims, x, y, z, nvars, vardim,
                           centering, varnames, vars);
 
    free(x);
    free(y);
    free(z);
}
*/

 float *xg = (float *) malloc(sizeof(float)*dims[0]);
 float *yg = (float *) malloc(sizeof(float)*dims[1]);
 float *zg = (float *) malloc(sizeof(float)*dims[2]);

 for(int i=0; i<dims[0]; ++i)
   xg[i] = (float)i*dx;
 for(int i=0; i<dims[1]; ++i)
   yg[i] = (float)i*dy;
 for(int i=0; i<dims[2]; ++i)
   zg[i] = (float)i;
 
 write_rectilinear_mesh("example2xyz.vtk", 0, dims, xg,yg,zg, 2, vardims, centering,
                       varnames, arrays);


}
