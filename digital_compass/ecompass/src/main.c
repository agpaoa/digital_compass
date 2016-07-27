#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "board.h"
#include "LSM303D.h"
#include "ecompass.h"

// Global Variables
// External
extern Accelerometer acc;
extern Magnetometer mag;

int main(void)
{
	SystemCoreClockUpdate();
	Board_Init();    // Initialize board
	Compass_Init();  // Initialize compass

	Compass comp;

	while(1)
	{
		readCompass(&comp);
		printf("Heading = %.1f ", comp.heading);
		printf("Pitch = %.1f ", comp.pitch);
		printf("Roll = %.1f\n", comp.roll);
	}

	return 1;
}
