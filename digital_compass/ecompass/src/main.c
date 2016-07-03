#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "board.h"
#include "LSM303D.h"
#include "ecompass.h"
extern int16_t acc[3];
extern int16_t mag[3];
int main(void)
{
	SystemCoreClockUpdate();
	Board_Init();    // Initialize board
	Compass_Init();  // Initialize compass

	while(1)
	{
		currentHeading = getHeading();
		//int16_t *acc = getAcc();
		//int16_t *mag = getMag();
		printf("Heading: %d ", currentHeading);
		printf("Acc: %d %d %d ", acc[0], acc[1], acc[2]);
		printf("Mag: %d %d %d\n", mag[0], mag[1], mag[2]);

	}

	return 1;
}
