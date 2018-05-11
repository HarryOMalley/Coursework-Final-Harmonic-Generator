#define _CRT_SECURE_NO_WARNINGS

/* Coursework Due 11th December, Harry O'Malley and Rebecca Neill*/

#include "Functions.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

main()
{
	do
	{
		int x, i, j, harmonics;
		amplitude = (Height / 2.8);
		srand((unsigned int)time(NULL));
		
		clearGraph(); // makes all values of array = 0

		printf("\n\t************** Square wave Harmonic Generator V1.5 **************\n\n\n"); // Welcome message
		printf("\tPlease enter the number of Harmonics you would like to generate: ");
		scanf(" %d", &harmonics);

		for (i = 1; i < harmonics + 1; i++)
		{
			struct colours RGB = randomColour();
			int redColour = RGB.red;
			int greenColour = RGB.green;
			int blueColour = RGB.blue;
			printf("%d ", i);

			for (x = 0; x < Width; x++) /* For Loop for each value of x, W-3 to prevent graph overlapping axis ticks */
			{
				float multiplier = 1.0;
				siny = Height / 2;
				doublesiny = Height / 2;
				for (j = 0; j < i; j++)
				{
					/* harmonicY is for plotting each fundamental harmonic prior to addition
					doublesiny is after addition of harmonics (both kept as double to prevent rounding errors) */
					
					harmonicY = (amplitude * -sin((multiplier * x * 3.14159) / (Width / 4)) / multiplier);
					doublesiny = doublesiny + harmonicY;
					harmonicY += (Height / 2);
					multiplier += 2.0;
				}
				
				siny = (int)doublesiny; /*Used to prevent rounding errors in the long calculation above*/
				harmonic = (int)harmonicY;
				
				arrayGraph[harmonic - 1][x + 1][RED] = 255;
				arrayGraph[harmonic - 1][x + 1][GREEN] = 0;
				arrayGraph[harmonic - 1][x + 1][BLUE] = 0;
				arrayGraph[siny - 1][x + 1][RED] = redColour;
				arrayGraph[siny - 1][x + 1][GREEN] = greenColour;
				arrayGraph[siny - 1][x + 1][BLUE] = blueColour;
			}
		}

		drawAxis();
		printf("\nArray Completed\n");
		do
			fileOutput();
		while (fileOutput == 0);
		printf("Operation Complete. %d Harmonics printed.", harmonics);

		do
			repeat = repeatChecker();
		while (repeat == 2);

	} while (repeat == 1);
}