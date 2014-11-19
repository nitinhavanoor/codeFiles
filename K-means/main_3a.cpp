#include <iostream>
#include <vector>

using namespace std;

int *k_means(double **data, int n, int m, int k, double t, double **centroids);

int main(int argc, char *argv[])
{
	int i,j,k,temp1_int = 0, temp2_int = 0, temp3_int = 0,size1,size2,format;
	FILE *file;
	float temp1_float = 0.0,temp2_float = 0.0,temp3_float = 0.0;


	unsigned char ***Imagedata1,***Imagedata2,***Imagedata3,***Imagedata4,***Imagedata5,***Imagedata6;			size1 = 481;	size2 = 321;		Imagedata1 = new unsigned char** [size2];	Imagedata2 = new unsigned char** [size2];	Imagedata3 = new unsigned char** [size2];	Imagedata4 = new unsigned char** [size2];	Imagedata5 = new unsigned char** [size2];	Imagedata6 = new unsigned char** [size2];				for(i = 0; i < size2; i++)	{		Imagedata1[i] = new unsigned char* [size1];			Imagedata2[i] = new unsigned char* [size1];			Imagedata3[i] = new unsigned char* [size1];			Imagedata4[i] = new unsigned char* [size1];			Imagedata5[i] = new unsigned char* [size1];			Imagedata6[i] = new unsigned char* [size1];		}		for(i = 0; i < size2; i++)	{		for(j = 0; j < size1; j++)		{			Imagedata1[i][j] = new unsigned char [3];				Imagedata2[i][j] = new unsigned char [3];				Imagedata3[i][j] = new unsigned char [3];				Imagedata4[i][j] = new unsigned char [3];				Imagedata5[i][j] = new unsigned char [3];				Imagedata6[i][j] = new unsigned char [3];						}	}
	if (!(file=fopen("seg1.raw","rb"))) {		cout << "Cannot open file: " <<endl;		exit(1);	}
	for(i = 0 ; i < size2; i++)
	{
		for(j = 0; j < size1; j++)
			fread(Imagedata1[i][j], sizeof(unsigned char),3, file);	}	fclose(file);	if (!(file=fopen("seg2.raw","rb"))) {		cout << "Cannot open file: " <<endl;		exit(1);	}
	for(i = 0 ; i < size2; i++)
	{
		for(j = 0; j < size1; j++)
			fread(Imagedata3[i][j], sizeof(unsigned char),3, file);	}	fclose(file);		if (!(file=fopen("seg3.raw","rb"))) {		cout << "Cannot open file: " <<endl;		exit(1);	}
	for(i = 0 ; i < size2; i++)
	{
		for(j = 0; j < size1; j++)
			fread(Imagedata5[i][j], sizeof(unsigned char),3, file);	}	fclose(file);		int clusters,clusters1,clusters2;	double **data_points,**data_points1,**data_points2;	data_points = new double* [size1 * size2];	data_points1 = new double* [size1 * size2];	data_points2 = new double* [size1 * size2];	for(i = 0; i < (size1 * size2); i++)	{		data_points[i] = new double [3];		data_points1[i] = new double [3];		data_points2[i] = new double [3];	}		for(i = 0; i < size2; i++)	{		for(j = 0; j < size1; j++)		{			data_points[(i * size1) + j][0] = (double)Imagedata1[i][j][0];			data_points[(i * size1) + j][1] = (double)Imagedata1[i][j][1];			data_points[(i * size1) + j][2] = (double)Imagedata1[i][j][2];			data_points1[(i * size1) + j][0] = (double)Imagedata3[i][j][0];			data_points1[(i * size1) + j][1] = (double)Imagedata3[i][j][1];			data_points1[(i * size1) + j][2] = (double)Imagedata3[i][j][2];			data_points2[(i * size1) + j][0] = (double)Imagedata5[i][j][0];			data_points2[(i * size1) + j][1] = (double)Imagedata5[i][j][1];			data_points2[(i * size1) + j][2] = (double)Imagedata5[i][j][2];		}	}	cout << "working";	clusters = 4;	clusters1 = 6;	clusters2 = 12;	double **centroids,**centroids1,**centroids2;	centroids = new double* [clusters];	centroids1 = new double* [clusters1];	centroids2 = new double* [clusters2];	for(i = 0; i < clusters; i++)		centroids[i] = new double [3];	for(i = 0; i < clusters1; i++)		centroids1[i] = new double [3];	for(i = 0; i < clusters2; i++)		centroids2[i] = new double [3];	for(i = 0; i < clusters; i++)	{		for(j = 0; j < 3; j++)			centroids[i][j] = 0.0;	}	for(i = 0; i < clusters1; i++)	{		for(j = 0; j < 3; j++)			centroids1[i][j] = 0.0;	}	for(i = 0; i < clusters2; i++)	{		for(j = 0; j < 3; j++)			centroids2[i][j] = 0.0;	}	int* labels = k_means(data_points, (size1 * size2), 3, clusters, 0.0001, centroids);	int* labels1 = k_means(data_points1, (size1 * size2), 3, clusters1, 0.0001, centroids1);	int* labels2 = k_means(data_points2, (size1 * size2), 3, clusters2, 0.0001, centroids2);	cout << "working1";			for(i = 0; i < size2; i++)	{		for(j = 0; j < size1; j++)		{						Imagedata2[i][j][0] = centroids[labels[(i * size1) + j]][0];			Imagedata2[i][j][1] = centroids[labels[(i * size1) + j]][1];			Imagedata2[i][j][2] = centroids[labels[(i * size1) + j]][2];			Imagedata4[i][j][0] = centroids1[labels1[(i * size1) + j]][0];			Imagedata4[i][j][1] = centroids1[labels1[(i * size1) + j]][1];			Imagedata4[i][j][2] = centroids1[labels1[(i * size1) + j]][2];			Imagedata6[i][j][0] = centroids2[labels2[(i * size1) + j]][0];			Imagedata6[i][j][1] = centroids2[labels2[(i * size1) + j]][1];			Imagedata6[i][j][2] = centroids2[labels2[(i * size1) + j]][2];					}	}		if (!(file=fopen("output1.raw","wb"))) {		cout << "Cannot open file: "  << endl;		exit(1);	}	for(i = 0 ; i < size2; i++)
	{
		for(j = 0; j < size1; j++)
			fwrite(Imagedata2[i][j], sizeof(unsigned char), 3, file);				}		fclose(file);	if (!(file=fopen("output2.raw","wb"))) {		cout << "Cannot open file: "  << endl;		exit(1);	}	for(i = 0 ; i < size2; i++)
	{
		for(j = 0; j < size1; j++)
			fwrite(Imagedata4[i][j], sizeof(unsigned char), 3, file);				}		fclose(file);		if (!(file=fopen("output3.raw","wb"))) {		cout << "Cannot open file: "  << endl;		exit(1);	}	for(i = 0 ; i < size2; i++)
	{
		for(j = 0; j < size1; j++)
			fwrite(Imagedata6[i][j], sizeof(unsigned char), 3, file);				}		fclose(file);	for(i = 0; i < size2; i++)	{		delete [] Imagedata1[i];		delete [] Imagedata2[i];		delete [] Imagedata3[i];		delete [] Imagedata4[i];		delete [] Imagedata5[i];		delete [] Imagedata6[i];	}	


	return(0);
}