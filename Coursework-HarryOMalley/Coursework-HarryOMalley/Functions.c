#define _CRT_SECURE_NO_WARNINGS

#include "Functions.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
int arrayGraph[Height][Width][3], siny = Height / 2, repeat = 1, harmonic;
double doublesiny = Height / 2, harmonicY, amplitude;
void drawAxis(void), clearGraph(void);
int repeatChecker(void), fileOutput(void);

void drawAxis(void)
{
	int i, j;
	for (i = 0; i < Height; i++)
	{
		arrayGraph[i][1][RED] = 255;
		arrayGraph[i][1][GREEN] = 255;
		arrayGraph[i][1][BLUE] = 255;
	}

	for (j = 0; j < Width; j++)
	{
		arrayGraph[(Height / 2) - 1][j][RED] = 255;
		arrayGraph[(Height / 2) - 1][j][GREEN] = 255;
		arrayGraph[(Height / 2) - 1][j][BLUE] = 255;
	}

	// Drawing the ticks at the end of Axis
	
	// Y Axis
	arrayGraph[0][1][RED] = 255;
	arrayGraph[0][1][GREEN] = 255;
	arrayGraph[0][1][BLUE] = 255;
	arrayGraph[1][2][RED] = 255;
	arrayGraph[1][2][GREEN] = 255;
	arrayGraph[1][2][BLUE] = 255;
	arrayGraph[1][0][RED] = 255;
	arrayGraph[1][0][GREEN] = 255;
	arrayGraph[1][0][BLUE] = 255;
	// X Axis
	arrayGraph[Height / 2][Width - 2][RED] = 255;
	arrayGraph[Height / 2][Width - 2][GREEN] = 255;
	arrayGraph[Height / 2][Width - 2][BLUE] = 255;
	arrayGraph[(Height / 2) - 1][Width - 1][RED] = 255;
	arrayGraph[(Height / 2) - 1][Width - 1][GREEN] = 255;
	arrayGraph[(Height / 2) - 1][Width - 1][BLUE] = 255;
	arrayGraph[(Height / 2) - 2][Width - 2][RED] = 255;
	arrayGraph[(Height / 2) - 2][Width - 2][GREEN] = 255;
	arrayGraph[(Height / 2) - 2][Width - 2][BLUE] = 255;
	for (j = 0; j < Height; j++)
	{
		arrayGraph[j][0][RED] = 255;
		arrayGraph[j][0][GREEN] = 255;
		arrayGraph[j][0][BLUE] = 255;
	}


}
void clearGraph(void)
{
	int i, j;
	for (i = 0; i < Height; i++) //Black Background
	{
		for (j = 0; j < Width; j++)
		{
			arrayGraph[i][j][RED] = 0;
			arrayGraph[i][j][GREEN] = 0;
			arrayGraph[i][j][BLUE] = 0;
		}
	}

}
int fileOutput(void)
{
	int i, j;
	FILE *graphOut = NULL;
	printf("Default name is Graph.ppm, would you like to use a different name? (Y/N): ");
	char defaultName, filename[100] = "";
	scanf(" %c", &defaultName);
	if (defaultName == 'y' || defaultName == 'Y')
	{
		printf("\nPlease enter the filename you would like to use (including .ppm): ");
		scanf(" %s", &filename);
		graphOut = fopen(filename, "w");
	}
	else if (defaultName == 'n' || defaultName == 'N')
	{
		graphOut = fopen("Graph.ppm", "w");
		printf("Using default filename...\n");
	}
	else
		return 0;
	printf("Outputting to file...\n");
	fprintf(graphOut, "P3\n# %s\n%d %d\n255\n", filename, Width, Height);
	for (i = 0; i < Height; i++)
	{
		for (j = 0; j < Width; j++)
		{
			fprintf(graphOut, "%d %d %d ", arrayGraph[i][j][RED], arrayGraph[i][j][GREEN], arrayGraph[i][j][BLUE]);
		}
		fprintf(graphOut, "\n");

	}

}
int repeatChecker(void)
{
	char repeatInput;
	printf("\nWould you like to run again?	(Y/N): ");
	scanf(" %c", &repeatInput);
	if (repeatInput == 'y' || repeatInput == 'Y')
		return(1);
	else if (repeatInput == 'n' || repeatInput == 'N')
	{
		printf("\n\n\n\t\tThank you for using the Square Wave Harmonic Generator.");
		Sleep(1000);
		return(0);
	}
	else
	{
		printf("Invalid character entered.");
		return(2);
	}
}

struct colours randomColour()
{
	struct colours RGB;
	RGB.red = rand() % 256; //Random Colour generator, runs with each iteration of harmonics
	RGB.green = rand() % 256;
	RGB.blue = rand() % 256;
	return RGB;
}