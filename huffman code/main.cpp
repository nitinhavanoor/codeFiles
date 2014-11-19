#include <iostream>
#include "init.h" 

void main()
{
	FileParameters data;

	data.file_name = "image.dat";

	readFile( &data);
	cout << "image: ";
	QMcoder( &data );



}