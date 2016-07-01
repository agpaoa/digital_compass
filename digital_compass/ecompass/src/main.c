#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "board.h"
#include "LSM303D.h"
#include "ecompass.h"

int main(void)
{
	SystemCoreClockUpdate();
	Board_Init();    // Initialize board
	Compass_Init();  // Initialize compass

	while(1)
	{
		currentHeading = getHeading();
		printf("Heading: %d\n", currentHeading);
	}

	return 1;
}
