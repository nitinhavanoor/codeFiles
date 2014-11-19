#ifndef _SCALAR_QUANT_
#define _SCALAR_QUANT_

extern int size;

class deBlock{private:	int index;	const char* determineFilterMode( int *);	bool smoothFilter( int ** );	bool defaultFilter( int ** );	int minimum( int, int, int);	int clip( int, int, int);public:	unsigned char **data;	deBlock(const char * name);	deBlock();	~deBlock();	void copy_image( deBlock );	void deBlock_rows( deBlock inp);	void deBlock_col( deBlock inp);		void writeImage(const char *name);};

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