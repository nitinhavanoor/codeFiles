// The main warping function.
//input triangle coordinates
//output warpes triangle

#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>

using namespace cv;
using namespace std;

int warp(unsigned char*** dest, unsigned char*** source, double** A_mat, double U[], double V[])
{	
	double slope1,slope2,slope3;
	double Xj,Yi;
	int i,j,k,i1,j1;

	double a[3] = {0}, b[3] = {0}, result[9] = {0};

	double A_mat1[3][3] = {A_mat[0][0], A_mat[0][1], A_mat[0][2], A_mat[1][0], A_mat[1][1], A_mat[1][2], 1, 1, 1};

	Mat A(3,3,CV_64F,A_mat1);	

	Mat a_inv(3,3,CV_64F,result);

	invert(A,a_inv,DECOMP_SVD);

	
	
	for(i = 0; i < 3; i++)
	{
		a[i] = 0;
		for(j = 0; j < 3; j++)
		{
			a[i] += a_inv.at<double>(j,i) * U[j];
		}
	}
	for(i = 0; i < 3; i++)
	{
		b[i] = 0;
		for(j = 0; j < 3; j++)
		{
			b[i] += a_inv.at<double>(j,i) * V[j];
		}
	}


	int max = 0, min = 0, j_index1,j_index2,flag1 = 0, flag2 = 0, flag3 = 0;
	
	if(A_mat[1][0] > max)
		max = A_mat[1][0];
	if(A_mat[1][1] > A_mat[1][0])
		max = A_mat[1][1];
	if(A_mat[1][2] > A_mat[1][1])
		max = A_mat[1][2];

	 min = A_mat[1][0];
	if(A_mat[1][0] < min)
		min = A_mat[1][0];
	if(A_mat[1][1] < A_mat[1][0])
		min = A_mat[1][1];
	if(A_mat[1][2] < A_mat[1][1])
		min = A_mat[1][2];

	

	if(A_mat[1][0] == A_mat[1][1])
	{
		flag1 = 1;
		if(A_mat[0][0] != A_mat[0][2])
			slope1 = (A_mat[1][0] - A_mat[1][2])/(A_mat[0][0] - A_mat[0][2]);
		else
			slope1 = 0;

		if(A_mat[0][1] != A_mat[0][2])
			slope2 = (A_mat[1][1] - A_mat[1][2])/(A_mat[0][1] - A_mat[0][2]);
		else
			slope2 = 0;
		
	}
	else if(A_mat[1][1] == A_mat[1][2])
	{
		flag2 = 1;
		if(A_mat[0][0] != A_mat[0][1])
			slope1 = (A_mat[1][0] - A_mat[1][1])/(A_mat[0][0] - A_mat[0][1]);
		else
			slope1 = 0;

		if(A_mat[0][0] != A_mat[0][2])
			slope2 = (A_mat[1][0] - A_mat[1][2])/(A_mat[0][0] - A_mat[0][2]);
		else
			slope2 = 0;
	}
	else
	{
		flag3 = 1;

		if(A_mat[0][0] != A_mat[0][1])
			slope1 = (A_mat[1][0] - A_mat[1][1])/(A_mat[0][0] - A_mat[0][1]);
		else
			slope1 = 0;

		if(A_mat[0][0] != A_mat[0][2])
			slope2 = (A_mat[1][0] - A_mat[1][2])/(A_mat[0][0] - A_mat[0][2]);
		else
			slope2 = 0;

		if(A_mat[0][1] != A_mat[0][2])
			slope3 = (A_mat[1][1] - A_mat[1][2])/(A_mat[0][1] - A_mat[0][2]);
		else
			slope3 = 0;
	}
	int halt;
	if(flag3 == 1)
		halt = A_mat[1][1];
	else
		halt = max;

	
/*	cout << max << '\t' << min << '\n';*/
	

	for(i = min;i <= max; i++)
	{
		if(i < halt)
		{
			if(flag1 == 1)
			{
				j_index1 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
				j_index2 = ((i - A_mat[1][1])/slope2) + A_mat[0][1];

				if(slope1 == 0)
					j_index1 = A_mat[0][0];

				if(slope2 == 0)
					j_index2 = A_mat[1][2];

			}
			else if (flag2 == 1)
			{
				j_index1 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
				j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];

				if(slope1 == 0)
					j_index1 = A_mat[0][0];

				if(slope2 == 0)
					j_index2 = A_mat[1][2];
			}
			else if (flag3 == 1)
			{
				if(A_mat[0][0] <= A_mat[0][1])
				{
					if(abs(A_mat[0][0] - A_mat[0][1]) > abs(A_mat[0][0] - A_mat[0][2]))
					{
						j_index1 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
						j_index2 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
				

						if(slope1 == 0)
							j_index2 = A_mat[0][0];

						if(slope2 == 0)
							j_index1 = A_mat[0][0];
					}
					else
					{
						if((((A_mat[1][1] - A_mat[1][0])/slope2) + A_mat[0][0]) > A_mat[0][1])
						{
							j_index1 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
							j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
				

							if(slope1 == 0)
								j_index1 = A_mat[0][0];

							if(slope2 == 0)
								j_index2 = A_mat[0][0];
						}
						else
						{
							j_index1 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
							j_index2 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
				

							if(slope2 == 0)
								j_index1 = A_mat[0][0];

							if(slope1 == 0)
								j_index2 = A_mat[0][0];
						}
						
					}
				}
				else if(A_mat[0][0] > A_mat[0][1])
				{
					if(abs(A_mat[0][0] - A_mat[0][1]) > abs(A_mat[0][0] - A_mat[0][2]))
					{
						j_index1 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
						j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
				

						if(slope1 == 0)
							j_index1 = A_mat[0][0];

						if(slope2 == 0)
							j_index2 = A_mat[0][0];
					}
					else
					{
						if(A_mat[0][1] > A_mat[0][2])
						{
							if((((A_mat[1][1] - A_mat[1][0])/slope2) + A_mat[0][0]) < A_mat[0][1])
							{
								j_index1 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
								j_index2 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
				

								if(slope1 == 0)
									j_index2 = A_mat[0][0];

								if(slope2 == 0)
									j_index1 = A_mat[0][0];
							}
							else
							{
								
								j_index1 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
								j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
				

								if(slope2 == 0)
									j_index2 = A_mat[0][0];

								if(slope1 == 0)
									j_index1 = A_mat[0][0];
							}

							
						}
						else
						{
							j_index1 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
							j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
				

							if(slope2 == 0)
								j_index2 = A_mat[0][0];

							if(slope1 == 0)
								j_index1 = A_mat[0][0];
						}
					}
				}
			}



			/*cout << slope1  << '\t' << slope2 << '\t' << i << '\t' <<  j_index1 << '\t' << j_index2 << '\n';*/

		
				for(j = j_index1; j < j_index2; j++)
				{
					Xj = (double)j * a[0] + (double)i * a[1] + (double)a[2];
					Yi = (double)j * b[0] + (double)i * b[1] + (double)b[2];

					i1 = Yi;
					j1 = Xj;			

					for(k = 0; k < 3; k++)
						/*dest[i][j][k] = (unsigned char)255;*/dest[i][j][k] = source[i1][j1][k];

				}
	}
	else
	{
		if(flag1 == 1)
			{
				j_index1 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
				j_index2 = ((i - A_mat[1][1])/slope2) + A_mat[0][1];

				if(slope1 == 0)
					j_index1 = A_mat[0][0];

				if(slope2 == 0)
					j_index2 = A_mat[1][2];

			}
			else if (flag2 == 1)
			{
				j_index1 = ((i - A_mat[1][0])/slope1) + A_mat[0][0];
				j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];

				if(slope1 == 0)
					j_index1 = A_mat[0][0];

				if(slope2 == 0)
					j_index2 = A_mat[1][2];
			}
			else if (flag3 == 1)
			{
				if(A_mat[0][0] <= A_mat[0][1])
				{
					if(abs(A_mat[0][0] - A_mat[0][1]) > abs(A_mat[0][0] - A_mat[0][2]))
					{
						j_index1 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
						j_index2 = ((i - A_mat[1][1])/slope3) + A_mat[0][1];
				

						if(slope3 == 0)
							j_index2 = A_mat[0][1];

						if(slope2 == 0)
							j_index1 = A_mat[0][0];
					}
					else
					{
						if((((A_mat[1][1] - A_mat[1][0])/slope2) + A_mat[0][0]) > A_mat[0][1])
						{
							j_index1 = ((i - A_mat[1][1])/slope3) + A_mat[0][1];
							j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
				

							if(slope3 == 0)
								j_index1 = A_mat[0][1];

							if(slope2 == 0)
								j_index2 = A_mat[0][0];
						}
						else
						{
							j_index1 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
							j_index2 = ((i - A_mat[1][1])/slope3) + A_mat[0][1];
				

							if(slope2 == 0)
								j_index1 = A_mat[0][1];

							if(slope3 == 0)
								j_index2 = A_mat[0][0];
						}
					}
				}
				else if(A_mat[0][0] > A_mat[0][1])
				{
					if(abs(A_mat[0][0] - A_mat[0][1]) > abs(A_mat[0][0] - A_mat[0][2]))
					{
						j_index1 = ((i - A_mat[1][1])/slope3) + A_mat[0][1];
						j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
				

						if(slope3 == 0)
							j_index1 = A_mat[0][1];

						if(slope2 == 0)
							j_index2 = A_mat[0][0];
					}
					else
					{
						if(A_mat[0][1] > A_mat[0][2])
						{
							if((((A_mat[1][1] - A_mat[1][0])/slope2) + A_mat[0][0]) < A_mat[0][1])
							{
								j_index1 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
								j_index2 = ((i - A_mat[1][1])/slope3) + A_mat[0][1];
				

								if(slope3 == 0)
									j_index2 = A_mat[0][1];

								if(slope2 == 0)
									j_index1 = A_mat[0][0];
							}
							else
							{
								j_index1 = ((i - A_mat[1][1])/slope3) + A_mat[0][1];
								j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
				

								if(slope2 == 0)
									j_index2 = A_mat[0][1];

								if(slope3 == 0)
									j_index1 = A_mat[0][0];
							}
						}
						else
						{
							j_index1 = ((i - A_mat[1][1])/slope3) + A_mat[0][1];
							j_index2 = ((i - A_mat[1][0])/slope2) + A_mat[0][0];
				

							if(slope2 == 0)
								j_index2 = A_mat[0][1];

							if(slope3 == 0)
								j_index1 = A_mat[0][0];
						}
					}
				}
			}



			/*cout << flag1  << '\t' << flag2 << '\t' <<  j_index1 << '\t' << j_index2 << '\n';*/

			for(j = j_index1; j < j_index2; j++)
			{
				Xj = (double)j * a[0] + (double)i * a[1] + (double)a[2];
				Yi = (double)j * b[0] + (double)i * b[1] + (double)b[2];

				i1 = Yi;
				j1 = Xj;			

				for(k = 0; k < 3; k++)
					/*dest[i][j][k] = (unsigned char)255;*/dest[i][j][k] = source[i1][j1][k];
			}
	}
	}
	
	return(0);
}