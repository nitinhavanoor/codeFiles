#include <iostream>

using namespace std;
//warping helper function
int warp(unsigned char*** dest, unsigned char*** source, double** A_mat, double U[], double V[]);

int Image_warp(unsigned char*** dest, unsigned char*** source, double* X, double* Y, double* x1, double* y1)
{
	int i,j,k,temp1_int = 0, temp2_int = 0, temp3_int = 0,size1,size2,format;



	double* U;
	double* V;

	U = new double [3];
	V = new double [3];

	  U[0] = X[0]; U[1] =  X[2]; U[2] =  X[15];
	  V[0] = Y[0]; V[1] =  Y[2]; V[2] =  Y[15];

	double** A_mat;

	A_mat = new double* [3];

	A_mat[0] = new double [3];
	A_mat[1] = new double [3];
	A_mat[2] = new double [3];
    
    //transform matrix initialization
	A_mat[0][0] = x1[0];A_mat[0][1] = x1[2];A_mat[0][2] = x1[15];
	A_mat[1][0] = y1[0];A_mat[1][1] = y1[2];A_mat[1][2] = y1[15];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	// transform all the triangles in order.
	warp(dest,source,A_mat,U,V);

	/*triangle 2*/ 
	
	U[0] = X[0]; U[1] =  X[2]; U[2] =  X[4];
	V[0] = Y[0]; V[1] =  Y[2]; V[2] =  Y[4];


	A_mat[0][0] = x1[0];A_mat[0][1] = x1[2];A_mat[0][2] = x1[4];
	A_mat[1][0] = y1[0];A_mat[1][1] = y1[2];A_mat[1][2] = y1[4];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;	
	
	warp(dest,source,A_mat,U,V);



	/*triangle 3*/ 
	
	  U[0] = X[0]; U[1] =  200; U[2] =  X[4];
	  V[0] = Y[0]; V[1] =  0; V[2] =  Y[4];


	A_mat[0][0] = x1[0];A_mat[0][1] = 200;A_mat[0][2] = x1[4];
	A_mat[1][0] = y1[0];A_mat[1][1] = 0;A_mat[1][2] = y1[4];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);
	

	/*triangle 4*/ 
	
	  U[0] = 200; U[1] =  X[4]; U[2] =  X[8];
	  V[0] = 0; V[1] =  Y[4]; V[2] =  Y[8];


	A_mat[0][0] = 200;A_mat[0][1] = x1[4];A_mat[0][2] = x1[8];
	A_mat[1][0] = 0;A_mat[1][1] = y1[4];A_mat[1][2] = y1[8];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

	/*triangle 5*/ 
	
	  U[0] = 200; U[1] =  X[10]; U[2] =  X[8];
	  V[0] = 0; V[1] =  Y[10]; V[2] =  Y[8];


	A_mat[0][0] = 200;A_mat[0][1] = x1[10];A_mat[0][2] = x1[8];
	A_mat[1][0] = 0;A_mat[1][1] = y1[10];A_mat[1][2] = y1[8];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);
	
	/*triangle 6*/ 
	
	  U[0] = 200; U[1] =  X[1]; U[2] =  X[10];
	  V[0] = 0; V[1] =  Y[1]; V[2] =  Y[10];


	A_mat[0][0] = 200;A_mat[0][1] = x1[1];A_mat[0][2] = x1[10];
	A_mat[1][0] = 0;A_mat[1][1] = y1[1];A_mat[1][2] = y1[10];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);
	
	/*triangle 7*/ 
	
	 U[0] = X[1]; U[1] =  X[14]; U[2] =  X[10];
	  V[0] = Y[1]; V[1] =  Y[14]; V[2] =  Y[10];


	A_mat[0][0] = x1[1];A_mat[0][1] = x1[14];A_mat[0][2] = x1[10];
	A_mat[1][0] = y1[1];A_mat[1][1] = y1[14];A_mat[1][2] = y1[10];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

	/*triangle 8*/ 
	
	 U[0] = X[1]; U[1] =  X[14]; U[2] =  X[20];
	  V[0] = Y[1]; V[1] =  Y[14]; V[2] =  Y[20];


	A_mat[0][0] = x1[1];A_mat[0][1] = x1[14];A_mat[0][2] = x1[20];
	A_mat[1][0] = y1[1];A_mat[1][1] = y1[14];A_mat[1][2] = y1[20];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;	
	
	warp(dest,source,A_mat,U,V);

	/*triangle 9*/ 
	
	  U[0] = X[2]; U[1] =  X[15]; U[2] =  X[16];
	  V[0] = Y[2]; V[1] =  Y[15]; V[2] =  Y[16];


	A_mat[0][0] = x1[2];A_mat[0][1] = x1[15];A_mat[0][2] = x1[16];
	A_mat[1][0] = y1[2];A_mat[1][1] = y1[15];A_mat[1][2] = y1[16];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

		/*triangle 10*/ 
	
	U[0] = X[2]; U[1] =  X[3]; U[2] =  X[16];
	  V[0] = Y[2]; V[1] =  Y[3]; V[2] =  Y[16];


	A_mat[0][0] = x1[2];A_mat[0][1] = x1[3];A_mat[0][2] = x1[16];
	A_mat[1][0] = y1[2];A_mat[1][1] = y1[3];A_mat[1][2] = y1[16];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

		/*triangle 11*/ 
	
	 U[0] = X[2]; U[1] =  X[4]; U[2] =  X[3];
	  V[0] = Y[2]; V[1] =  Y[4]; V[2] =  Y[3];


	A_mat[0][0] = x1[2];A_mat[0][1] = x1[4];A_mat[0][2] = x1[3];
	A_mat[1][0] = y1[2];A_mat[1][1] = y1[4];A_mat[1][2] = y1[3];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);


			/*triangle 12*/ 
	
	  U[0] = X[4]; U[1] =  X[5]; U[2] =  X[3];
	  V[0] = Y[4]; V[1] =  Y[5]; V[2] =  Y[3];


	A_mat[0][0] = x1[4];A_mat[0][1] = x1[5];A_mat[0][2] = x1[3];
	A_mat[1][0] = y1[4];A_mat[1][1] = y1[5];A_mat[1][2] = y1[3];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 13*/ 
	
	  U[0] = X[4]; U[1] =  X[5]; U[2] =  X[7];
	  V[0] = Y[4]; V[1] =  Y[5]; V[2] =  Y[7];


	A_mat[0][0] = x1[4];A_mat[0][1] = x1[5];A_mat[0][2] = x1[7];
	A_mat[1][0] = y1[4];A_mat[1][1] = y1[5];A_mat[1][2] = y1[7];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);


			/*triangle 14*/ 
	
		 U[0] = X[5]; U[1] =  X[3]; U[2] =  X[7];
	  V[0] = Y[5]; V[1] =  Y[3]; V[2] =  Y[7];


	A_mat[0][0] = x1[5];A_mat[0][1] = x1[3];A_mat[0][2] = x1[7];
	A_mat[1][0] = y1[5];A_mat[1][1] = y1[3];A_mat[1][2] = y1[7];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 15*/ 
	
	  U[0] = X[3]; U[1] =  X[7]; U[2] =  X[6];
	  V[0] = Y[3]; V[1] =  Y[7]; V[2] =  Y[6];


	A_mat[0][0] = x1[3];A_mat[0][1] = x1[7];A_mat[0][2] = x1[6];
	A_mat[1][0] = y1[3];A_mat[1][1] = y1[7];A_mat[1][2] = y1[6];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 16*/ 
	
	 U[0] = X[4]; U[1] =  X[8]; U[2] =  X[7];
	  V[0] = Y[4]; V[1] =  Y[8]; V[2] =  Y[7];


	A_mat[0][0] = x1[4];A_mat[0][1] = x1[8];A_mat[0][2] = x1[7];
	A_mat[1][0] = y1[4];A_mat[1][1] = y1[8];A_mat[1][2] = y1[7];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 17*/ 
	
	 U[0] = X[3]; U[1] =  X[16]; U[2] =  X[17];
	  V[0] = Y[3]; V[1] =  Y[16]; V[2] =  Y[17];


	A_mat[0][0] = x1[3];A_mat[0][1] = x1[16];A_mat[0][2] = x1[17];
	A_mat[1][0] = y1[3];A_mat[1][1] = y1[16];A_mat[1][2] = y1[17];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 18*/ 
	
	  U[0] = X[3]; U[1] =  X[6]; U[2] =  X[17];
	  V[0] = Y[3]; V[1] =  Y[6]; V[2] =  Y[17];


	A_mat[0][0] = x1[3];A_mat[0][1] = x1[6];A_mat[0][2] = x1[17];
	A_mat[1][0] = y1[3];A_mat[1][1] = y1[6];A_mat[1][2] = y1[17];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 19*/ 
	
	 U[0] = X[7]; U[1] =  X[6]; U[2] =  X[17];
	  V[0] = Y[7]; V[1] =  Y[6]; V[2] =  Y[17];


	A_mat[0][0] = x1[7];A_mat[0][1] = x1[6];A_mat[0][2] = x1[17];
	A_mat[1][0] = y1[7];A_mat[1][1] = y1[6];A_mat[1][2] = y1[17];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 20*/ 
	
	 U[0] = X[8]; U[1] =  X[7]; U[2] =  X[17];
	  V[0] = Y[8]; V[1] =  Y[7]; V[2] =  Y[17];


	A_mat[0][0] = x1[8];A_mat[0][1] = x1[7];A_mat[0][2] = x1[17];
	A_mat[1][0] = y1[8];A_mat[1][1] = y1[7];A_mat[1][2] = y1[17];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 21*/ 
	
	 U[0] = X[8]; U[1] =  X[18]; U[2] =  X[17];
	  V[0] = Y[8]; V[1] =  Y[18]; V[2] =  Y[17];


	A_mat[0][0] = x1[8];A_mat[0][1] = x1[18];A_mat[0][2] = x1[17];
	A_mat[1][0] = y1[8];A_mat[1][1] = y1[18];A_mat[1][2] = y1[17];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 22*/ 
	
	  U[0] = X[8]; U[1] =  X[9]; U[2] =  X[18];
	  V[0] = Y[8]; V[1] =  Y[9]; V[2] =  Y[18];


	A_mat[0][0] = x1[8];A_mat[0][1] = x1[9];A_mat[0][2] = x1[18];
	A_mat[1][0] = y1[8];A_mat[1][1] = y1[9];A_mat[1][2] = y1[18];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 23*/ 
	
	 U[0] = X[9]; U[1] =  X[12]; U[2] =  X[18];
	  V[0] = Y[9]; V[1] =  Y[12]; V[2] =  Y[18];


	A_mat[0][0] = x1[9];A_mat[0][1] = x1[12];A_mat[0][2] = x1[18];
	A_mat[1][0] = y1[9];A_mat[1][1] = y1[12];A_mat[1][2] = y1[18];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 24*/ 
	
	 U[0] = X[13]; U[1] =  X[12]; U[2] =  X[18];
	  V[0] = Y[13]; V[1] =  Y[12]; V[2] =  Y[18];


	A_mat[0][0] = x1[13];A_mat[0][1] = x1[12];A_mat[0][2] = x1[18];
	A_mat[1][0] = y1[13];A_mat[1][1] = y1[12];A_mat[1][2] = y1[18];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 25*/ 
	
	 U[0] = X[10]; U[1] =  X[8]; U[2] =  X[9];
	  V[0] = Y[10]; V[1] =  Y[8]; V[2] =  Y[9];


	A_mat[0][0] = x1[10];A_mat[0][1] = x1[8];A_mat[0][2] = x1[9];
	A_mat[1][0] = y1[10];A_mat[1][1] = y1[8];A_mat[1][2] = y1[9];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 26*/ 
	
	 U[0] = X[10]; U[1] =  X[11]; U[2] =  X[9];
	  V[0] = Y[10]; V[1] =  Y[11]; V[2] =  Y[9];


	A_mat[0][0] = x1[10];A_mat[0][1] = x1[11];A_mat[0][2] = x1[9];
	A_mat[1][0] = y1[10];A_mat[1][1] = y1[11];A_mat[1][2] = y1[9];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 27*/ 
	
	  U[0] = X[10]; U[1] =  X[11]; U[2] =  X[13];
	  V[0] = Y[10]; V[1] =  Y[11]; V[2] =  Y[13];


	A_mat[0][0] = x1[10];A_mat[0][1] = x1[11];A_mat[0][2] = x1[13];
	A_mat[1][0] = y1[10];A_mat[1][1] = y1[11];A_mat[1][2] = y1[13];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 28*/ 
	
	 U[0] = X[11]; U[1] =  X[13]; U[2] =  X[9];
	  V[0] = Y[11]; V[1] =  Y[13]; V[2] =  Y[9];


	A_mat[0][0] = x1[11];A_mat[0][1] = x1[13];A_mat[0][2] = x1[9];
	A_mat[1][0] = y1[11];A_mat[1][1] = y1[13];A_mat[1][2] = y1[9];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 29*/ 
	
	 U[0] = X[13]; U[1] =  X[9]; U[2] =  X[12];
	  V[0] = Y[13]; V[1] =  Y[9]; V[2] =  Y[12];


	A_mat[0][0] = x1[13];A_mat[0][1] = x1[9];A_mat[0][2] = x1[12];
	A_mat[1][0] = y1[13];A_mat[1][1] = y1[9];A_mat[1][2] = y1[12];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 30*/ 
	
	 U[0] = X[14]; U[1] =  X[10]; U[2] =  X[13];
	  V[0] = Y[14]; V[1] =  Y[10]; V[2] =  Y[13];


	A_mat[0][0] = x1[14];A_mat[0][1] = x1[10];A_mat[0][2] = x1[13];
	A_mat[1][0] = y1[14];A_mat[1][1] = y1[10];A_mat[1][2] = y1[13];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 31*/ 
	
	  U[0] = X[13]; U[1] =  X[19]; U[2] =  X[18];
	  V[0] = Y[13]; V[1] =  Y[19]; V[2] =  Y[18];


	A_mat[0][0] = x1[13];A_mat[0][1] = x1[19];A_mat[0][2] = x1[18];
	A_mat[1][0] = y1[13];A_mat[1][1] = y1[19];A_mat[1][2] = y1[18];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 32*/ 
	
	 U[0] = X[14]; U[1] =  X[13]; U[2] =  X[19];
	  V[0] = Y[14]; V[1] =  Y[13]; V[2] =  Y[19];


	A_mat[0][0] = x1[14];A_mat[0][1] = x1[13];A_mat[0][2] = x1[19];
	A_mat[1][0] = y1[14];A_mat[1][1] = y1[13];A_mat[1][2] = y1[19];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 33*/ 
	
	 U[0] = X[14]; U[1] =  X[20]; U[2] =  X[19];
	  V[0] = Y[14]; V[1] =  Y[20]; V[2] =  Y[19];


	A_mat[0][0] = x1[14];A_mat[0][1] = x1[20];A_mat[0][2] = x1[19];
	A_mat[1][0] = y1[14];A_mat[1][1] = y1[20];A_mat[1][2] = y1[19];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);
	
			/*triangle 34*/ 
	
	 U[0] = X[15]; U[1] =  X[23]; U[2] =  X[25];
	  V[0] = Y[15]; V[1] =  Y[23]; V[2] =  Y[25];


	A_mat[0][0] = x1[15];A_mat[0][1] = x1[23];A_mat[0][2] = x1[25];
	A_mat[1][0] = y1[15];A_mat[1][1] = y1[23];A_mat[1][2] = y1[25];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 35*/ 
	
	 U[0] = X[15]; U[1] =  X[16]; U[2] =  X[23];
	  V[0] = Y[15]; V[1] =  Y[16]; V[2] =  Y[23];


	A_mat[0][0] = x1[15];A_mat[0][1] = x1[16];A_mat[0][2] = x1[23];
	A_mat[1][0] = y1[15];A_mat[1][1] = y1[16];A_mat[1][2] = y1[23];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 36*/ 
	
	 U[0] = X[16]; U[1] =  X[17]; U[2] =  X[23];
	  V[0] = Y[16]; V[1] =  Y[17]; V[2] =  Y[23];


	A_mat[0][0] = x1[16];A_mat[0][1] = x1[17];A_mat[0][2] = x1[23];
	A_mat[1][0] = y1[16];A_mat[1][1] = y1[17];A_mat[1][2] = y1[23];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 37*/ 
	
	  U[0] = X[17]; U[1] =  X[21]; U[2] =  X[23];
	  V[0] = Y[17]; V[1] =  Y[21]; V[2] =  Y[23];


	A_mat[0][0] = x1[17];A_mat[0][1] = x1[21];A_mat[0][2] = x1[23];
	A_mat[1][0] = y1[17];A_mat[1][1] = y1[21];A_mat[1][2] = y1[23];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 38*/ 
	
	 U[0] = X[21]; U[1] =  X[23]; U[2] =  X[26];
	  V[0] = Y[21]; V[1] =  Y[23]; V[2] =  Y[26];


	A_mat[0][0] = x1[21];A_mat[0][1] = x1[23];A_mat[0][2] = x1[26];
	A_mat[1][0] = y1[21];A_mat[1][1] = y1[23];A_mat[1][2] = y1[26];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 39*/ 
	
	 U[0] = X[23]; U[1] =  X[26]; U[2] =  X[25];
	  V[0] = Y[23]; V[1] =  Y[26]; V[2] =  Y[25];


	A_mat[0][0] = x1[23];A_mat[0][1] = x1[26];A_mat[0][2] = x1[25];
	A_mat[1][0] = y1[23];A_mat[1][1] = y1[26];A_mat[1][2] = y1[25];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 40*/ 
	
	 U[0] = X[18]; U[1] =  X[17]; U[2] =  X[21];
	  V[0] = Y[18]; V[1] =  Y[17]; V[2] =  Y[21];


	A_mat[0][0] = x1[18];A_mat[0][1] = x1[17];A_mat[0][2] = x1[21];
	A_mat[1][0] = y1[18];A_mat[1][1] = y1[17];A_mat[1][2] = y1[21];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 41*/ 
	
	  U[0] = X[18]; U[1] =  X[22]; U[2] =  X[21];
	  V[0] = Y[18]; V[1] =  Y[22]; V[2] =  Y[21];


	A_mat[0][0] = x1[18];A_mat[0][1] = x1[22];A_mat[0][2] = x1[21];
	A_mat[1][0] = y1[18];A_mat[1][1] = y1[22];A_mat[1][2] = y1[21];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 42*/ 
	
	 U[0] = X[22]; U[1] =  X[21]; U[2] =  X[26];
	  V[0] = Y[22]; V[1] =  Y[21]; V[2] =  Y[26];


	A_mat[0][0] = x1[22];A_mat[0][1] = x1[21];A_mat[0][2] = x1[26];
	A_mat[1][0] = y1[22];A_mat[1][1] = y1[21];A_mat[1][2] = y1[26];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 43*/ 
	
	 U[0] = X[26]; U[1] =  X[25]; U[2] =  X[27];
	  V[0] = Y[26]; V[1] =  Y[25]; V[2] =  Y[27];


	A_mat[0][0] = x1[26];A_mat[0][1] = x1[25];A_mat[0][2] = x1[27];
	A_mat[1][0] = y1[26];A_mat[1][1] = y1[25];A_mat[1][2] = y1[27];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 44*/ 
	
	 U[0] = X[18]; U[1] =  X[22]; U[2] =  X[24];
	  V[0] = Y[18]; V[1] =  Y[22]; V[2] =  Y[24];


	A_mat[0][0] = x1[18];A_mat[0][1] = x1[22];A_mat[0][2] = x1[24];
	A_mat[1][0] = y1[18];A_mat[1][1] = y1[22];A_mat[1][2] = y1[24];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 45*/ 
	
	 U[0] = X[19]; U[1] =  X[18]; U[2] =  X[24];
	  V[0] = Y[19]; V[1] =  Y[18]; V[2] =  Y[24];


	A_mat[0][0] = x1[19];A_mat[0][1] = x1[18];A_mat[0][2] = x1[24];
	A_mat[1][0] = y1[19];A_mat[1][1] = y1[18];A_mat[1][2] = y1[24];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 46*/ 
	
	 U[0] = X[20]; U[1] =  X[19]; U[2] =  X[24];
	  V[0] = Y[20]; V[1] =  Y[19]; V[2] =  Y[24];


	A_mat[0][0] = x1[20];A_mat[0][1] = x1[19];A_mat[0][2] = x1[24];
	A_mat[1][0] = y1[20];A_mat[1][1] = y1[19];A_mat[1][2] = y1[24];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

				/*triangle 47*/ 
	
	  U[0] = X[20]; U[1] =  X[24]; U[2] =  X[27];
	  V[0] = Y[20]; V[1] =  Y[24]; V[2] =  Y[27];


	A_mat[0][0] = x1[20];A_mat[0][1] = x1[24];A_mat[0][2] = x1[27];
	A_mat[1][0] = y1[20];A_mat[1][1] = y1[24];A_mat[1][2] = y1[27];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	
	warp(dest,source,A_mat,U,V);

			/*triangle 48*/ 
	
	 U[0] = X[24]; U[1] =  X[26]; U[2] =  X[27];
	  V[0] = Y[24]; V[1] =  Y[26]; V[2] =  Y[27];


	A_mat[0][0] = x1[24];A_mat[0][1] = x1[26];A_mat[0][2] = x1[27];
	A_mat[1][0] = y1[24];A_mat[1][1] = y1[26];A_mat[1][2] = y1[27];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);

			/*triangle 49*/ 
	
	 U[0] = X[22]; U[1] =  X[24]; U[2] =  X[26];
	  V[0] = Y[22]; V[1] =  Y[24]; V[2] =  Y[26];


	A_mat[0][0] = x1[22];A_mat[0][1] = x1[24];A_mat[0][2] = x1[26];
	A_mat[1][0] = y1[22];A_mat[1][1] = y1[24];A_mat[1][2] = y1[26];
	A_mat[2][0] = 1;A_mat[2][1] = 1;A_mat[2][2] = 1;
	
	warp(dest,source,A_mat,U,V);



	return(0);
}