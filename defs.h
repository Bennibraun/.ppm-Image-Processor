/**
	Benjamin Braun
	PA1
	10-16-18
	CPSC-1070

	Include statements
	Structure definitions
	Function prototypes

**/

#include "stdio.h"
#include "stdlib.h"
#include "assert.h"


typedef struct {
	int rows, columns;
} header_t;

typedef struct {
	unsigned char r, g, b;
} pixel_t;

typedef struct {
	header_t dim;
	pixel_t * pixels;
} image_t;



// function prototypes
void parseHeader(FILE * inputFile, header_t * dimensions);
void parseImage(FILE * inputFile, image_t * image, header_t * header);
int printMenu();
void printImage(image_t * image, header_t * header);
void printHeader(header_t * dimensions);
void mirror(image_t * image, header_t * header, image_t * tempImage);
void flipHoriz(image_t * image, header_t * header, image_t * tempImage);
void makePurple(image_t * image, header_t * header, image_t * tempImage);
