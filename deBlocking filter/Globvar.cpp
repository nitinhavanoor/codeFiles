#include <iostream>S
#include "Globvar.h"
#include < math.h>

using namespace std;

const int QP = 17;
const double C1_by_C3 = 0.2706;
const int T_one = 2;
const int T_two = 6;
const int bk[9] = { 1 , 1, 2 , 2 , 4 , 2 , 2 , 1 , 1};
int count2 = 0, count1 = 0;
deBlock::deBlock(const char* name)
	for(int index1 = 0 ; index1 < size; index1++)
		fread(data[index1], sizeof(unsigned char),size, file);

	for(int index = 0 ; index < size; index++)
		fwrite(data[index], sizeof(unsigned char),size, file);


	if (!(file=fopen(name,"rb"))) {
	for(int i = 0 ; i < size; i++)
	{
		for(int j = 0; j < size; j++)
			fread(data[i][j], sizeof(unsigned char),3, file);
	{
		for(int j = 0; j < size; j++)
			fwrite(data[i][j], sizeof(unsigned char), 3, file);			