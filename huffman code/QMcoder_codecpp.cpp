#include <iostream>
#include "init.h"
#include "QMheader.h"
#include <vector>

const int code_table[46][3] = {0x59EB,  1, 4,
0x5522,  1, 1,
0x504F,  1, 1,
0x4B85,  1, 1,
0x4639,  1, 1,
0x415E,  1, 1,
0x3C3D,  1, 1,
0x375E,  1, 1,
0x32B4,  1, 2,
0x2E17,  1, 1,
0x299A,  1, 2,
0x2516,  1, 1,
0x1EDF,  1, 1,
0x1AA9,  1, 2,
0x174E,  1, 1,
0x1424,  1, 2,
0x119C,  1, 1,
0x0F6B,  1, 2,
0x0D51,  1, 2,
0x0BB6,  1, 1,
0x0A40,  1, 2,
0x0861,  1, 2,
0x0706,  1, 2,
0x05CD,  1, 2,
0x04DE,  1, 1,
0x040F,  1, 2,
0x0363,  1, 2,
0x02D4,  1, 2,
0x025C,  1, 2,
0x01F8,  1, 2,
0x01A4,  1, 2,
0x0160,  1, 2,
0x0125,  1, 2,
0x00F6,  1, 2,
0x00CB,  1, 2,
0x00AB,  1, 1,
0x008F,  1, 2,
0x0068,  1, 2,
0x004E,  1, 2,
0x003B,  1, 2,
0x002C,  1, 2,
0x001A,  1, 3,
0x000D,  1, 2,
0x0006,  1, 2,
0x0003,  1, 2,
0x0001,  0, 1};

vector <unsigned char> code_data;


void QMcoder( FileParameters *file)
{
	int index, state;
	unsigned short int C, Qe;
	unsigned int A;
	bool carry;
	unsigned char LPS = 1, MPS = 0 , temp1;

	unsigned char temp[10] = {1 , 1, 0 , 0, 0, 1, 0, 0, 1, 0};

	A = 0x10000;
	C = 0x0000;
	state = 10; 
	Qe = code_table[10][0];

	int mask , bit;
	unsigned char data_bit;
	index = 0;

	
	while(index < file->length)
	{
		mask = 0x80;
		for(bit = 0; bit < 8; bit++)
		{
			data_bit = file->file_data[index] & (unsigned char)mask;
			data_bit >>= (7 - bit);
			mask >>= 1;

			if(data_bit == MPS)
			{
				A = A - Qe;
			
				if(A < 0x8000)
				{
				
					if( A < Qe)
					{
						if( (C + A) > 0xffff) {carry = true;}

						C += A;
						A = Qe;
					}
					state += code_table[state][1]; 
					Qe = code_table[state][0];

					renormalize( &A , &C , &carry );
				}
			
			}
			else
			{
				A = A - Qe;
				if(A >= Qe)
				{
						if( (C + A) > 0xffff) {carry = true;}

						C += A;
						A = Qe;
				}

			
				if(state == 0)
				{
					temp1 = LPS;
					LPS = MPS;
					MPS = temp1;
					continue;
				}
				state -= code_table[state][2];	
				Qe = code_table[state][0];
			


				renormalize( &A , &C , &carry );
			}
		}
		index++;
	}
	
	
		cout << code_data.size() << '\n';

}

void renormalize( unsigned int *A , unsigned short int *C, bool *carry)
{
	int len = 0 , temp;

	if(*carry == true)
	{
		len = code_data.size();
		code_data.resize(len + 1);
		code_data[len] = 1;
		*carry = false;
	}
	while(*A < 0x8000)
	{
		
		*A <<= 1;

		temp = 0x8000;
		temp = temp & *C;
		temp >>= 15;
		len = code_data.size();
		code_data.resize(len + 1);
		code_data[len] = temp;

		*C <<= 1;

		
	}

}
