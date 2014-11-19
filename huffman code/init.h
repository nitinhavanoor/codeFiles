
using namespace std;


/*Classes declarations */

class FileParameters
{
	public:
		char* file_name;
		unsigned char* file_data;
		long int length;	/* bytes*/
		unsigned char* compression_data;
};


/* declarations*/
void QMcoder( FileParameters *file);

/* file IO */
void readFile(FileParameters* file1);
void writeFile(FileParameters* file1, char* output_file_name , int size);

void renormalize( unsigned int *A , unsigned short int *C, bool *carry);
