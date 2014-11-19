#include <iostream>
#include "init.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;void readFile(FileParameters* file1)
{
	int temp_int2 = 0;

	ifstream file;
	file.open (file1->file_name, ios::binary );

		file.seekg (0, ios::end);
	temp_int2  = file.tellg();
	file.seekg (0, ios::beg);


	char *text_data1 = new char [temp_int2 ];

	file.read(text_data1, temp_int2 );
	
	file1->file_data = (unsigned char *)text_data1;
	file1->length = temp_int2;

	file.close();
}/*void writeFile(FileParameters* file1, string output_file_name)
{
	int temp_int2 = 0;

	ofstream file;
	file.open (output_file_name, ios::binary );

		


	
	file << file1->compression_data;

	
	file.close();
	
}*/void writeFile(FileParameters* file, char* output_file_name , int size)
{
	FILE *file1;	if (!(file1 = fopen(output_file_name,"wb"))) {	cout << "Cannot open file: " << endl;	exit(1);	}		fwrite(file->compression_data , sizeof(char), size, file1);	fclose(file1);	
}


