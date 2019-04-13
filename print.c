/**
	Benjamin Braun
	PA1
	10-16-18
	CPSC-1070

	Prints image data to the newly created image file (output redirection)

**/

#include "defs.h"

// Prints header data (format, dimensions, color mode)
// dimensions - pointer to the dimensions of the image
void printHeader(header_t * dimensions) {
	printf("P6\n");
	printf("%d  %d\n", dimensions->columns, dimensions->rows);
	printf("255\n");
}

// Prints pixel data (rgb for each pixel)
// image - pointer to the image_t where the pixel data is stored
// header - pointer to the header_t where the header data is stored
void printImage(image_t * image, header_t * header) {
	int i;
	for(i=0; i<=header->columns*header->rows; i++) {
		unsigned char red = image->pixels[i].r;
		unsigned char green = image->pixels[i].g;
		unsigned char blue = image->pixels[i].b;
		printf("%c%c%c", red, green, blue);
	}
}
