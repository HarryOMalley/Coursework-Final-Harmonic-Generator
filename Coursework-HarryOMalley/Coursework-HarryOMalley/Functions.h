
#include <stdio.h>

#define Width 2560
#define Height 1440
#define RED 0
#define BLUE 1
#define GREEN 2

extern int arrayGraph[Height][Width][3], siny, repeat, harmonic;
extern double doublesiny, harmonicY, amplitude;
extern void drawAxis(void), clearGraph(void);
extern int repeatChecker(void), fileOutput(void);
extern struct colours randomColour();
struct colours
{
	int red;
	int green;
	int blue;
};