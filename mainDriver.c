/**
	Benjamin Braun
	PA1
	10-16-18
	CPSC-1070

	Creates images, headers, and pixels for storage and modification
	Calls functions to read in and modify image data
	Calls functions to output image data to new image file

**/


#include "defs.h"

// Creates struct instances, opens image file, calls parse functions,
// allocates memory for image, calls modification functions,
// calls output functions, closes image file
// argc - number of command line arguments
// argv[] - array of command line arguments
// Returns: nothing meaningful
int main(int argc, char * argv[]) {
	header_t header;
	image_t theImage;
	int userChoice;

	FILE *inFile;

	// open the input file specified on the command line
	inFile = fopen(argv[1],"rb");

	// also check to make sure it was successfully opened
	assert(inFile);


	// call the parseHeader function
	parseHeader(inFile, &header);


	// malloc space for the image
	theImage.pixels = malloc(header.rows * header.columns);


	// add header info to image structure
	theImage.dim = header;

	parseImage(inFile, &theImage, &header);


	printHeader(&header);

	// declare temp image for modification
	image_t tempImage;
	tempImage.pixels=(pixel_t*)malloc(header.rows*header.columns*sizeof(pixel_t));

	userChoice = printMenu();


	switch(userChoice) {
		case 1:
			printImage(&theImage, &header);
			break;
		case 2:
			mirror(&theImage, &header, &tempImage);
			printImage(&tempImage, &header);
			break;
		case 3:
			flipHoriz(&theImage, &header, &tempImage);
			printImage(&tempImage, &header);
			break;
		case 4:
			makePurple(&theImage, &header, &tempImage);
			printImage(&tempImage, &header);
			break;
		default:
			break;
	}


	fclose(inFile);

	free(theImage.pixels);
	free(tempImage.pixels);

	return 0;
}
