/**
	Benjamin Braun
	PA1
	10-16-18
	CPSC-1070

	Prints a selection menu for the user
	Scans for user input

**/

#include "defs.h"

// Prints options for the user to choose from
// Scans for user input and returns it
// Returns: user's selection input
int printMenu() {
  int userChoice;
  fprintf(stderr,"\n1. original image");
  fprintf(stderr,"\n2. mirror image");
  fprintf(stderr,"\n3. upside down image");
  fprintf(stderr,"\n4. colorize purple");

  fprintf(stderr,"\n\nMENU CHOICE:   ");
  fscanf(stdin,"%d", &userChoice);

  return(userChoice);
}
