#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

using namespace std;

#define WIDTH 30
#define HEIGHT 30

#define TOP_BORDER '-'
#define SIDE_BORDER '|'
#define SNAKE 'o'
#define FRUIT 'x'

#define SCORE_PER_FRUIT 20

void init();
void drawHorizontalBorder();
void render();
void update();
void spawnFruit();

/**
 * A Posn is a cartesian coordinate. Valid Posns must be non-negative, and
 * smaller than the width/height constraints. 
 */
struct Posn {
	int x;
	int y;
};

/**
 * A Direction represents a movement of the snake on the gameboard. The 
 * snake may move in any of the four cardinal directions.
 */
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	INVALID
};

bool ended;

Posn curr;
Posn fruit;

int score;

Posn tail[200];
int tailSize;

Direction dir;

#endif
