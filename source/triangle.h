#pragma once

#include <3ds.h>
#include <sf2d.h>
#include <limits.h>

#define SCREEN_HEIGHT 240
#define TOP_WIDTH  400
#define BOT_WIDTH  320
#define ABS(x) ((x >= 0) ? x : -x)

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
} Triangle;

typedef struct
{
  long x, y;
  u32 color;
} Point;

long ContourX[SCREEN_HEIGHT][2];

/*
 * Code borrowed from here:
 * http://stackoverflow.com/questions/11139724/i-need-a-pixel-perfect-triangle-fill-algorithm-to-avoid-aliasing-artifacts
 * 
 * Scans a side of a triangle setting min X and max X in ContourX[][]
 * (using the Bresenham's line drawing algorithm).
 * I have no idea what is happening here.
 */
void scanLine(int x1, int y1, int x2, int y2);
void drawPoly(Point points[], int length);