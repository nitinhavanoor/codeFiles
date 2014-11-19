#include <iostream>
#include <stdio.h>
#include "GLOBVAR.h"


using namespace std;
int size = 256;
void main()
{
	deBlock input_image1("clock1.raw");
	deBlock input_image2("clock2.raw");
	deBlock input_image3("clock3.raw");
	deBlock input_image4("clock4.raw");
	deBlock input_image5("clock5.raw");
	
	deBlock output_image1 , output_image2 , output_image3 , output_image4 , output_image5 , output_image6 , output_image7 ,output_image8,
		output_image9 ,output_image10;

	output_image1.copy_image ( input_image1 );
	output_image1.deBlock_col( input_image1 );
	output_image1.deBlock_rows( input_image1 );
	output_image1.writeImage("clock1_smooth.raw");
	
	output_image2.copy_image ( input_image2 );
	output_image2.deBlock_col( input_image2 );
	output_image2.deBlock_rows( input_image2 );
	output_image2.writeImage("clock2_smooth.raw");

	output_image3.copy_image ( input_image3 );
	output_image3.deBlock_col( input_image3 );
	output_image2.deBlock_rows( input_image3 );
	output_image3.writeImage("clock3_smooth.raw");

	output_image4.copy_image ( input_image4 );
	output_image4.deBlock_col( input_image4 );
	output_image2.deBlock_rows( input_image4 );
	output_image4.writeImage("clock4_smooth.raw");

	output_image5.copy_image ( input_image5 );
	output_image5.deBlock_col( input_image5 );
	output_image2.deBlock_rows( input_image5 );
	output_image5.writeImage("clock5_smooth.raw");
	

	color input_image6("pepper1.raw");
	color input_image7("pepper2.raw");
	color input_image8("pepper3.raw");
	color input_image9("pepper4.raw");
	color input_image10("pepper5.raw");
	
	deBlock temp;
	for(int index = 0; index < 3; index++)
	{
		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				temp.data[index2][index3] = input_image6.data[index2][index3][index];
			}
		}
		
		output_image6.copy_image ( temp );
		output_image6.deBlock_col( temp );
		output_image6.deBlock_rows( temp );

		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				 input_image6.data[index2][index3][index] = output_image6.data[index2][index3];
			}
		}

	
	}
	input_image6.writeImage("pepper1_smooth.raw");



	for(int index = 0; index < 3; index++)
	{
		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				temp.data[index2][index3] = input_image7.data[index2][index3][index];
			}
		}
		
		output_image7.copy_image ( temp );
		output_image7.deBlock_col( temp );
		output_image7.deBlock_rows( temp );

		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				 input_image7.data[index2][index3][index] = output_image7.data[index2][index3];
			}
		}

	
	}
	input_image7.writeImage("pepper2_smooth.raw");



		for(int index = 0; index < 3; index++)
	{
		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				temp.data[index2][index3] = input_image8.data[index2][index3][index];
			}
		}
		
		output_image8.copy_image ( temp );
		output_image8.deBlock_col( temp );
		output_image8.deBlock_rows( temp );

		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				 input_image8.data[index2][index3][index] = output_image8.data[index2][index3];
			}
		}

	
	}
	input_image8.writeImage("pepper3_smooth.raw");



		for(int index = 0; index < 3; index++)
	{
		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				temp.data[index2][index3] = input_image9.data[index2][index3][index];
			}
		}
		
		output_image9.copy_image ( temp );
		output_image9.deBlock_col( temp );
		output_image9.deBlock_rows( temp );

		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				 input_image9.data[index2][index3][index] = output_image9.data[index2][index3];
			}
		}

	
	}
	input_image9.writeImage("pepper4_smooth.raw");


	for(int index = 0; index < 3; index++)
	{
		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				temp.data[index2][index3] = input_image10.data[index2][index3][index];
			}
		}
		
		output_image10.copy_image ( temp );
		output_image10.deBlock_col( temp );
		output_image10.deBlock_rows( temp );

		for(int index2 = 0; index2 < size; index2++)
		{
			for(int index3 = 0; index3 < size; index3++)
			{
				 input_image10.data[index2][index3][index] = output_image10.data[index2][index3];
			}
		}

	
	}
	input_image10.writeImage("pepper5_smooth.raw");
	
}