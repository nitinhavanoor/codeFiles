#include <iostream>

using namespace std;

int warp(unsigned char*** dest, unsigned char*** source, double** A_mat, double U[], double V[]);

int Image_warp(unsigned char*** dest, unsigned char*** source, double* X, double* Y, double* x1, double* y1)
{
	int i,j,k,temp1_int = 0, temp2_int = 0, temp3_int = 0,size1,size2,format;



	double* U;
	double* V;

	U = new double [3];
	V = new double [3];

	  U[0] = X[0]; U[1] =  X[3]; U[2] =  X[4];
	  V[0] = Y[0]; V[1] =  Y[3]; V[2] =  Y[4];

	double** A_mat;

	A_mat = new double* [3];

	A_mat[0] = new double [3];
	A_mat[1] = new double [3];
	A_mat[2] = new double [3];

	A_mat[0][0] = x1[0];A_mat[0][1] = x1[3];A_mat[0][2] = x1[4];
	A_mat[1][0] = y1[0];A_mat[1][1] = y1[3];A_mat[1][2] = y1[4];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

	/*triangle 2*/ 
	
	U[0] = X[0]; U[1] =  X[4]; U[2] =  X[5];
	V[0] = Y[0]; V[1] =  Y[4]; V[2] =  Y[5];


	A_mat[0][0] = x1[0];A_mat[0][1] = x1[4];A_mat[0][2] = x1[5];
	A_mat[1][0] = y1[0];A_mat[1][1] = y1[4];A_mat[1][2] = y1[5];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;	
	
	warp(dest,source,A_mat,U,V);



	/*triangle 3*/ 
	
	  U[0] = X[0]; U[1] =  X[1]; U[2] =  X[5];
	  V[0] = Y[0]; V[1] =  Y[1]; V[2] =  Y[5];


	A_mat[0][0] = x1[0];A_mat[0][1] = x1[1];A_mat[0][2] = x1[5];
	A_mat[1][0] = y1[0];A_mat[1][1] = y1[1];A_mat[1][2] = y1[5];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);
	

	/*triangle 4*/ 
	
	  U[0] = X[1]; U[1] =  X[6]; U[2] =  X[5];
	  V[0] = Y[1]; V[1] =  Y[6]; V[2] =  Y[5];


	A_mat[0][0] = x1[1];A_mat[0][1] = x1[6];A_mat[0][2] = x1[5];
	A_mat[1][0] = y1[1];A_mat[1][1] = y1[6];A_mat[1][2] = y1[5];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

	/*triangle 5*/ 
	
	  U[0] = X[1]; U[1] =  X[2]; U[2] =  X[6];
	  V[0] = Y[1]; V[1] =  Y[2]; V[2] =  Y[6];


	A_mat[0][0] = x1[1];A_mat[0][1] = x1[2];A_mat[0][2] = x1[6];
	A_mat[1][0] = y1[1];A_mat[1][1] = y1[2];A_mat[1][2] = y1[6];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);
	
	/*triangle 6*/ 
	
	  U[0] = X[2]; U[1] =  X[7]; U[2] =  X[6];
	  V[0] = Y[2]; V[1] =  Y[7]; V[2] =  Y[6];


	A_mat[0][0] = x1[2];A_mat[0][1] = x1[7];A_mat[0][2] = x1[6];
	A_mat[1][0] = y1[2];A_mat[1][1] = y1[7];A_mat[1][2] = y1[6];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);
	
	/*triangle 7*/ 
	
	 U[0] = X[2]; U[1] =  X[8]; U[2] =  X[7];
	  V[0] = Y[2]; V[1] =  Y[8]; V[2] =  Y[7];


	A_mat[0][0] = x1[2];A_mat[0][1] = x1[8];A_mat[0][2] = x1[7];
	A_mat[1][0] = y1[2];A_mat[1][1] = y1[8];A_mat[1][2] = y1[7];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

	/*triangle 8*/ 
	
	 U[0] = X[4]; U[1] =  X[3]; U[2] =  X[9];
	  V[0] = Y[4]; V[1] =  Y[3]; V[2] =  Y[9];


	A_mat[0][0] = x1[4];A_mat[0][1] = x1[3];A_mat[0][2] = x1[9];
	A_mat[1][0] = y1[4];A_mat[1][1] = y1[3];A_mat[1][2] = y1[9];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;	
	
	warp(dest,source,A_mat,U,V);
	/*triangle 9*/ 
	
	  U[0] = X[3]; U[1] =  X[11]; U[2] =  X[13];
	  V[0] = Y[3]; V[1] =  Y[11]; V[2] =  Y[13];


	A_mat[0][0] = x1[3];A_mat[0][1] = x1[11];A_mat[0][2] = x1[13];
	A_mat[1][0] = y1[3];A_mat[1][1] = y1[11];A_mat[1][2] = y1[13];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);
		/*triangle 10*/ 
	
	U[0] = X[11]; U[1] =  X[13]; U[2] =  X[14];
	  V[0] = Y[11]; V[1] =  Y[13]; V[2] =  Y[14];


	A_mat[0][0] = x1[11];A_mat[0][1] = x1[13];A_mat[0][2] = x1[14];
	A_mat[1][0] = y1[11];A_mat[1][1] = y1[13];A_mat[1][2] = y1[14];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);
		/*triangle 11*/ 
	
	 U[0] = X[11]; U[1] =  X[12]; U[2] =  X[14];
	  V[0] = Y[11]; V[1] =  Y[12]; V[2] =  Y[14];


	A_mat[0][0] = x1[11];A_mat[0][1] = x1[12];A_mat[0][2] = x1[14];
	A_mat[1][0] = y1[11];A_mat[1][1] = y1[12];A_mat[1][2] = y1[14];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);


			/*triangle 12*/ 
	
	  U[0] = X[12]; U[1] =  X[14]; U[2] =  X[15];
	  V[0] = Y[12]; V[1] =  Y[14]; V[2] =  Y[15];


	A_mat[0][0] = x1[12];A_mat[0][1] = x1[14];A_mat[0][2] = x1[15];
	A_mat[1][0] = y1[12];A_mat[1][1] = y1[14];A_mat[1][2] = y1[15];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 13*/ 
	
	  U[0] = X[8]; U[1] =  X[12]; U[2] =  X[15];
	  V[0] = Y[8]; V[1] =  Y[12]; V[2] =  Y[15];


	A_mat[0][0] = x1[8];A_mat[0][1] = x1[12];A_mat[0][2] = x1[15];
	A_mat[1][0] = y1[8];A_mat[1][1] = y1[12];A_mat[1][2] = y1[15];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);


			/*triangle 14*/ 
	
		 U[0] = X[7]; U[1] =  X[8]; U[2] =  X[12];
	  V[0] = Y[7]; V[1] =  Y[8]; V[2] =  Y[12];


	A_mat[0][0] = x1[7];A_mat[0][1] = x1[8];A_mat[0][2] = x1[12];
	A_mat[1][0] = y1[7];A_mat[1][1] = y1[8];A_mat[1][2] = y1[12];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 15*/ 
	
	  U[0] = X[4]; U[1] =  X[9]; U[2] =  X[11];
	  V[0] = Y[4]; V[1] =  Y[9]; V[2] =  Y[11];


	A_mat[0][0] = x1[4];A_mat[0][1] = x1[9];A_mat[0][2] = x1[11];
	A_mat[1][0] = y1[4];A_mat[1][1] = y1[9];A_mat[1][2] = y1[11];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 16*/ 
	
	 U[0] = X[4]; U[1] =  X[5]; U[2] =  X[9];
	  V[0] = Y[4]; V[1] =  Y[5]; V[2] =  Y[9];


	A_mat[0][0] = x1[4];A_mat[0][1] = x1[5];A_mat[0][2] = x1[9];
	A_mat[1][0] = y1[4];A_mat[1][1] = y1[5];A_mat[1][2] = y1[9];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);
			/*triangle 17*/ 
	
	 U[0] = X[6]; U[1] =  X[5]; U[2] =  X[9];
	  V[0] = Y[6]; V[1] =  Y[5]; V[2] =  Y[9];


	A_mat[0][0] = x1[6];A_mat[0][1] = x1[5];A_mat[0][2] = x1[9];
	A_mat[1][0] = y1[6];A_mat[1][1] = y1[5];A_mat[1][2] = y1[9];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 18*/ 
	
	  U[0] = X[6]; U[1] =  X[9]; U[2] =  X[10];
	  V[0] = Y[6]; V[1] =  Y[9]; V[2] =  Y[10];


	A_mat[0][0] = x1[6];A_mat[0][1] = x1[9];A_mat[0][2] = x1[10];
	A_mat[1][0] = y1[6];A_mat[1][1] = y1[9];A_mat[1][2] = y1[10];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 19*/ 
	
	 U[0] = X[9]; U[1] =  X[10]; U[2] =  X[11];
	  V[0] = Y[9]; V[1] =  Y[10]; V[2] =  Y[11];


	A_mat[0][0] = x1[9];A_mat[0][1] = x1[10];A_mat[0][2] = x1[11];
	A_mat[1][0] = y1[9];A_mat[1][1] = y1[10];A_mat[1][2] = y1[11];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);
			/*triangle 20*/ 
	
	 U[0] = X[10]; U[1] =  X[11]; U[2] =  X[12];
	  V[0] = Y[10]; V[1] =  Y[11]; V[2] =  Y[12];


	A_mat[0][0] = x1[10];A_mat[0][1] = x1[11];A_mat[0][2] = x1[12];
	A_mat[1][0] = y1[10];A_mat[1][1] = y1[11];A_mat[1][2] = y1[12];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);
			/*triangle 21*/ 
	
	 U[0] = X[7]; U[1] =  X[6]; U[2] =  X[10];
	  V[0] = Y[7]; V[1] =  Y[6]; V[2] =  Y[10];


	A_mat[0][0] = x1[7];A_mat[0][1] = x1[6];A_mat[0][2] = x1[10];
	A_mat[1][0] = y1[7];A_mat[1][1] = y1[6];A_mat[1][2] = y1[10];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 22*/ 
	
	  U[0] = X[7]; U[1] =  X[10]; U[2] =  X[12];
	  V[0] = Y[7]; V[1] =  Y[10]; V[2] =  Y[12];


	A_mat[0][0] = x1[7];A_mat[0][1] = x1[10];A_mat[0][2] = x1[12];
	A_mat[1][0] = y1[7];A_mat[1][1] = y1[10];A_mat[1][2] = y1[12];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);
	return(0);}