#include <iostream>S
#include "Globvar.h"
#include < math.h>

using namespace std;

const int QP = 17;const double C2_by_C3 = 0.6533;
const double C1_by_C3 = 0.2706;
const int T_one = 2;
const int T_two = 6;
const int bk[9] = { 1 , 1, 2 , 2 , 4 , 2 , 2 , 1 , 1};
int count2 = 0, count1 = 0;
deBlock::deBlock(const char* name){	FILE *file;		data = new unsigned char* [size];	for(int index1 = 0; index1 < size; index1++)		data[index1] = new unsigned char [size];		if (!(file=fopen(name,"rb"))) {		cout << "Cannot open file: " <<endl;		exit(1);	}
	for(int index1 = 0 ; index1 < size; index1++)
		fread(data[index1], sizeof(unsigned char),size, file);	fclose(file);
}deBlock::deBlock(){	FILE *file;		data = new unsigned char* [size];	for(int index1 = 0; index1 < size; index1++)		data[index1] = new unsigned char [size];	for(int index1 = 0; index1 < size; index1++)	{		for(int index2 = 0; index2 < size; index2++)			data[index1][index2] = (unsigned char)0;	}}deBlock::~deBlock(){	}void deBlock::copy_image( deBlock inp){	for(int index1 = 0; index1 < size; index1++)	{		for(int index2 = 0; index2 < size; index2++)			data[index1][index2] = inp.data[index1][index2];	}}void deBlock::writeImage(const char *name){	FILE *file;			if (!(file=fopen(name,"wb"))) {		cout << "Cannot open file: " <<endl;		exit(1);	}
	for(int index = 0 ; index < size; index++)
		fwrite(data[index], sizeof(unsigned char),size, file);	fclose(file);}void deBlock::deBlock_col( deBlock inp){	const char* mode;	int *v;	v = new int [10];		for(int index1 = 0; index1 < size - 7; index1+= 8)	{		for(int index2 = 0; index2 < size - 7; index2+= 8)		{			for(int index3 = 0; index3 < 8; index3++)			{				for(int index4 = 0; index4 < 10; index4++)				{					v[index4] = (int)inp.data[index1 + index3][index2 + index4 + 3];				}									mode = determineFilterMode( v );						if( !(strcmp(mode , "smooth")))			{				smoothFilter( &v );							}			else			{								defaultFilter( &v );			}						for(int index4 = 0; index4 < 10; index4++)			{					data[index1 + index3][index2 + index4 + 3] = (unsigned char)v[index4];			}										}					}		 	}		}void deBlock::deBlock_rows( deBlock inp){	deBlock temp;	for(int index1 = 0; index1 < size; index1++)	{		for(int index2 = 0; index2 < size; index2++)		{			temp.data[index2][index1] = data[index1][index2];		}	}	deBlock_col( temp );	for(int index1 = 0; index1 < size; index1++)	{		for(int index2 = 0; index2 < size; index2++)		{			 temp.data[index2][index1] = data[index1][index2];		}	}	for(int index1 = 0; index1 < size; index1++)	{		for(int index2 = 0; index2 < size; index2++)		{			 data[index1][index2] = temp.data[index1][index2];		}	}}const char* deBlock::determineFilterMode( int *v ){	int F = 0;	int temp = 0;	for(int index1 = 0; index1 < 9; index1++)	{		temp = 0;		temp = v[index1] - v [index1 + 1];		if(abs(temp) <= T_one)			F += 1;		else			F = F;	}	if(F >= T_two)		return("smooth");	else		return("default");}bool deBlock::smoothFilter( int **v){	int max = 0, min = 0;	int p[18];	max = (*v)[0];	for(int index1 = 0; index1 < 10; index1++)	{		if((*v)[index1] > max)			max = (*v)[index1];	}	min = (*v)[0];	for(int index1 = 0; index1 < 10; index1++)	{		if((*v)[index1] < min)			min = (*v)[index1];	}			if( abs(max - min) > (2 * QP))	{		count2++;		return(false);	}		else	{		if( abs((*v)[1] - (*v)[0]) < QP)			p[4] = (*v)[0];		else			p[4] = (*v)[1];		if( abs((*v)[9] - (*v)[8]) < QP)			p[13] = (*v)[9];		else			p[13] = (*v)[8];				for(int index1 = 0; index1 < 18; index1++)		{			if(index1 < 5)				p[index1] = p[4];			else if((index1 >= 5) && (index1 <= 12))				p[index1] = (*v)[index1 - 4];			else				p[index1] = p[13];		}		for(int index1 = 1; index1 < 9 ; index1++)		{						(*v)[index1] = 0;			for(int index2 = 0; index2 < 9; index2++)			{				(*v)[index1] += (bk[index2] * p[index1 + index2]);			}			(*v)[index1] /= 16;		}		return(true);	}	}bool deBlock::defaultFilter( int **v ){		int S0[4] = {(*v)[1], (*v)[2], (*v)[3], (*v)[4]};	int S1[4] = {(*v)[3], (*v)[4], (*v)[5], (*v)[6]};	int S2[4] = {(*v)[5], (*v)[6], (*v)[7], (*v)[8]};	int a30 , a31 , a32;	a30 = (C1_by_C3 * (*v)[1]) - (C2_by_C3 * (*v)[2])  + (C2_by_C3 * (*v)[3])  - (C1_by_C3 * (*v)[4]);	a31 = (C1_by_C3 * (*v)[3]) - (C2_by_C3 * (*v)[4])  + (C2_by_C3 * (*v)[5])  - (C1_by_C3 * (*v)[6]);	a32 = (C1_by_C3 * (*v)[5]) - (C2_by_C3 * (*v)[6])  + (C2_by_C3 * (*v)[7])  - (C1_by_C3 * (*v)[8]);		if(abs(a31) > QP)	{		count1++;		return(false);	}	else	{		int a31_prime;		if(abs(a31) != 0)		{			a31_prime = a31 * minimum(abs(a30) , abs(a31) , abs(a32)) / abs(a31);		}		else		{			a31_prime = 0;		}		int d = clip((C2_by_C3 * (a31_prime - a31)) , 0 , ((*v)[4] - (*v)[5]) / 2);		(*v)[4] = (*v)[4] - d;		(*v)[5] = (*v)[5] + d;		return(true);	}}int deBlock::minimum( int a, int b, int c){	if(a < b)	{		if(a < c)			return(a);		else			return(c);	}	else	{		if(b < c)			return(b);		else			return(c);	}}int deBlock::clip( int a, int b, int c){	if((a > b) && (a < c))		return(a);	else	{		return(c / 2);	}}color::color( const char* name){		FILE* file;		data = new unsigned char** [size];	for(int i = 0; i < size; i++)	{		data[i] = new unsigned char* [size];					}		for(int i = 0; i < size; i++)	{		for(int j = 0; j < size; j++)		{			data[i][j] = new unsigned char [3];			}	}


	if (!(file=fopen(name,"rb"))) {		cout << "Cannot open file: " <<endl;		exit(1);	}
	for(int i = 0 ; i < size; i++)
	{
		for(int j = 0; j < size; j++)
			fread(data[i][j], sizeof(unsigned char),3, file);	}	fclose(file);}color::~color(){}void color::writeImage(const char* name){	FILE *file;		if (!(file=fopen(name,"wb"))) {		cout << "Cannot open file: "  << endl;		exit(1);	}	for(int i = 0 ; i < size; i++)
	{
		for(int j = 0; j < size; j++)
			fwrite(data[i][j], sizeof(unsigned char), 3, file);				}		fclose(file);}