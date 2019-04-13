/**
	Benjamin Braun
	PA1
	10-16-18
	CPSC-1070

	Read image into memory for processing

**/

#include "defs.h"

// Reads header of input image, storing dimensions and information
// inputFile - pointer to the image being parsed
// dimensions - pointer to where the dimensions should be stored
void parseHeader(FILE * inputFile, header_t * dimensions) {
	char format[2];  // for the P6 image format
	int maxPix;      // for the maximum pixel value of 255

	// fscanf statements to read in the header information
	fscanf(inputFile,"%c%c ",&format[0],&format[1]);
	fscanf(inputFile,"%d %d\n",&dimensions->columns,&dimensions->rows);
	fscanf(inputFile,"%d\n",&maxPix);

	// make sure that format is P6 and max rgb value is 255
	if(format[0] != 'P' || format[1] != '6' || maxPix != 255) {
		fprintf(stderr, "Invalid image format, must be P6 and 255.");
		exit(1);
	}
}

// Reads pixel data from input image, storing it in an image_t
// inputFile - pointer to the image being parsed
// image - pointer to the image_t where the pixel data will be stored
// header - pointer to the dimensional data parsed from image header
void parseImage(FILE * inputFile, image_t * image, header_t * header) {

	image->pixels=(pixel_t*)malloc(header->rows*header->columns*sizeof(pixel_t));

	// now read in the pixel data
	fread(image->pixels, 3 * header->rows, header->columns, inputFile);
}
