/**
	Benjamin Braun
	PA1
	10-16-18
	CPSC-1070

	Creates a horizontally flipped version of the image

**/

#include "defs.h"

// Creates a modified version of the image that has been
// reflected across the horizontal center line
// image - pointer to the image_t where the image data is stored
// header - pointer to the header_t where header data is stored
// tempImage - pointer to the new image_t where the modified data is stored
void flipHoriz(image_t * image, header_t * header, image_t * tempImage) {
	int x,y;
	int rows = header->rows;
	int cols = header->columns;

	for(y=0; y<cols; y++) {
		for(x=0; x<rows; x++) {
			tempImage->pixels[(cols*x)+y] = image->pixels[((cols*rows)-(cols*x))-(cols-y)];
		}
	}
}
