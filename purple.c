/**
	Benjamin Braun
	PA1
	10-16-18
	CPSC-1070

	Converts image to grayscale
	Adds value to red and blue to create purple tint

**/

#include "defs.h"

// Averages r, g, and b values for each pixel to create grayscale
// Modifies r, g, and b values individually, allowing for color tint
// image - pointer to the image_t where the image data is stored
// header - pointer to the header_t where header data is stored
// tempImage - pointer to the new image_t where the modified data is stored
void makePurple(image_t * image, header_t * header, image_t * tempImage) {
	int i;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char gray;
	unsigned char p_gray;

	for(i=0; i<header->rows*header->columns; i++) {
		red = image->pixels[i].r;
		green = image->pixels[i].g;
		blue = image->pixels[i].b;

		// average the red, green, and blue values to make grayscale pixel
		gray = (red+green+blue) / 3;

		if(gray+35 > 255) {
			p_gray = 255;
		}
		else {
			p_gray = gray+35;
		}

		// modify rgb values, with red and blue getting higher values to make purple
		tempImage->pixels[i].r = p_gray;
		tempImage->pixels[i].g = gray;
		tempImage->pixels[i].b = p_gray;
	}
}
