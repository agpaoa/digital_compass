#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "board.h"
#include "LSM303D.h"
#include "ecompass.h"

int main(void)
{
	SystemCoreClockUpdate();
	Board_Init();
	printf("Initializing compass...\n");
	Compass_Init();
	//printf("Running compass test...\n");
	//Compass_Test();

	//setClosedPosition();

	while(1)
	{

		if(!isClosed())
			printf("Door is open\n");
		else
			printf("Door is closed\n");

	}

	return 1;
}
