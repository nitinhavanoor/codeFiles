#ifndef _SCALAR_QUANT_
#define _SCALAR_QUANT_

extern int size;

class deBlock{

class color{
private:
	int index;

public:
	unsigned char ***data;
	
	color( const char*);
	~color();

	void writeImage(const char* name);

};

#endif