/**
	Benjamin Braun
	PA1
	10-16-18
	CPSC-1070

	Creates a mirror image (vertical flip) version of an image

**/

#include "defs.h"

// Creates a version of image_t containing a vertical reflection
// down the middle of an image
// image - pointer to the image_t where the image data is stored
// header - pointer to the header_t where header data is stored
// tempImage - pointer to the new image_t where the modified data is stored
void mirror(image_t * image, header_t * header, image_t * tempImage) {
	int x,y;
	int rows = header->rows;
	int cols = header->columns;


	for(y=0; y<rows; y++) {
		for(x=1; x<=cols; x++) {
			tempImage->pixels[(cols*y)+x] = image->pixels[(cols*(y+1))-x-1];
		}
	}
}
