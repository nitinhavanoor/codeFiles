#include <iostream>
#include <vector>

using namespace std;

int *k_means(double **data, int n, int m, int k, double t, double **centroids);

int main(int argc, char *argv[])
{
	int i,j,k,temp1_int = 0, temp2_int = 0, temp3_int = 0,size1,size2,format;
	FILE *file;
	float temp1_float = 0.0,temp2_float = 0.0,temp3_float = 0.0;



	if (!(file=fopen("seg1.raw","rb"))) {
	for(i = 0 ; i < size2; i++)
	{
		for(j = 0; j < size1; j++)
			fread(Imagedata1[i][j], sizeof(unsigned char),3, file);
	for(i = 0 ; i < size2; i++)
	{
		for(j = 0; j < size1; j++)
			fread(Imagedata3[i][j], sizeof(unsigned char),3, file);
	for(i = 0 ; i < size2; i++)
	{
		for(j = 0; j < size1; j++)
			fread(Imagedata5[i][j], sizeof(unsigned char),3, file);
	{
		for(j = 0; j < size1; j++)
			fwrite(Imagedata2[i][j], sizeof(unsigned char), 3, file);			
	{
		for(j = 0; j < size1; j++)
			fwrite(Imagedata4[i][j], sizeof(unsigned char), 3, file);			
	{
		for(j = 0; j < size1; j++)
			fwrite(Imagedata6[i][j], sizeof(unsigned char), 3, file);			


	return(0);
}