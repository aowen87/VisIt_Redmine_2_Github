#include <silo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Silo Version with compression features enabled
export LD_LIBRARY_PATH=/tmp/visit/silo-4.8/lib:/tmp/visit/hdf5/1.8.4/linux-x86_64_gcc/lib:$LD_LIBRARY_PATH
gcc -I/tmp/visit/silo-4.8/include -L/tmp/visit/silo-4.8/lib -L/tmp/visit/hdf5/1.8.4/linux-x86_64_gcc/lib visit_one_mater.c -lsiloh5 -lhdf5  -lstdc++ && ./a.out

 */

int main (int argc, char ** argv) {
    DBfile         *dbfile = NULL;
    int n = 50 ;
    float x[n] ;
    int i,j,k,m ;
    char           *coordnames[3];
    int             dims[3];
    int ndims = 3 ;
    float          *coords[3];
    float * field ;
    int ier ;
    char * gzopt = "METHOD=GZIP" ; // "METHOD=FPZIP" "METHOD=HZIP" : OK
    char * szopt = "METHOD=SZIP BLOCK=10 MASK=NN" ; // "METHOD=SZIP MINRATIO=1.0" "MINRATIO=1.0 METHOD=SZIP" : KO
    int nmat = 2 ;
    int matnos[nmat] ;
    int * matlist ;

    dbfile = DBCreate("visit_one_mater_c_sz.silo", DB_CLOBBER, DB_LOCAL, "One Material", DB_HDF5);
    DBSetCompression(szopt) ;

    // Builds a uniform 3D Cartesian mesh:
    for (i=0; i<= n;i++) {
        x[i] = (float) i/(float )n ;
    }
    coordnames[0] = strdup("x"); // On the fly allocate = "x" ;
    coordnames[1] = strdup("y"); // strdup("y");
    coordnames[2] = strdup("z");
    dims[0] = n+1;
    dims[1] = n+1;
    dims[2] = n+1;
    coords[0] = x ;
    coords[1] = x ;
    coords[2] = x ;
    ier = DBPutQuadmesh (dbfile, "quadmesh", coordnames, coords, dims, ndims, DB_FLOAT, DB_COLLINEAR, NULL);

    // Sets a constant field value:
    field = (float *)malloc(n*n*n*sizeof(float)) ;
    for (i=0; i< n*n*n;i++)
        field[i] = 1.E0 ;

    dims[0] = n;
    dims[1] = n;
    dims[2] = n;
    DBPutQuadvar1 (dbfile, "field", "quadmesh", field, dims, ndims, NULL, 0, DB_FLOAT, DB_ZONECENT, NULL) ;

    // Sets a material:
    for (i=0; i<= nmat;i++) {
        matnos[i] = i ;
    }
    matlist = (int *)malloc(n*n*n*sizeof(int)) ;
    for (i=0; i< n*n*n;i++)
        matlist[i] = 0 ;
    for (i=n/3; i< 2*n/3;i++) {
        for (j=n/3; j< 2*n/3;j++) {
            for (k=n/3; k< 2*n/3;k++) {
                matlist[i+j*n+k*n*n] = 1 ;
            }
        }
    }
    //DBSetCompression(gzopt) ;
    ier = DBPutMaterial (dbfile, "materials", "quadmesh", nmat, matnos, matlist, dims, ndims, NULL, NULL, NULL, NULL, 0, DB_FLOAT, NULL) ;

    DBClose(dbfile);
    exit(0) ;
}
