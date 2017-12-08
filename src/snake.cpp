#include "snake.h"
#include "WiimoteBtns.h"

/**
 * Initializes starting values for the game.
 */
void init() {
	srand(time(NULL));
	ended = false;
	curr.x = WIDTH / 2;
	curr.y = HEIGHT / 2;
	spawnFruit();
	score = 0;
	tailSize = 0;
	dir = INVALID;
	cout << "Press any of the keypad buttons to begin playing a new game!" << endl;
	cout << "Quit a game anytime by pressing the B button" << endl;
}

/**
 * Prints the horizontal top and bottom borders.
 */
void drawHorizontalBorder() {
	for (int i = 0; i < WIDTH + 2; i++) {
		cout << TOP_BORDER;
	}
	cout << endl;
}

/**
 * Draws the background board as well as the snake/fruit. The board is 
 * blank pixels, surrounded by borders. The board also tracks the snake
 * and the fruit.
 */
void render() {
	drawHorizontalBorder();
	for (int y = 0; y < HEIGHT + 1; y++) {
		cout << SIDE_BORDER;
		for (int x = 0; x < WIDTH + 1; x++) {
			if (y == curr.y && x == curr.x) {
				cout << SNAKE;
			}
			else if (y == fruit.y && x == fruit.x) {
				cout << FRUIT;
			} else {
				bool tailAtPosn = false;
				for (int i = 0; i < tailSize; i++) {
					if (tail[i].x == x && tail[i].y == y) {
						cout << SNAKE;
						tailAtPosn = true;
						break;
					}
				}
				if (!tailAtPosn) {
					cout << " ";
				}
			}
		}
		cout << SIDE_BORDER;
		cout << endl;
	}

	drawHorizontalBorder();
	cout << "SCORE : " << score << endl;
}

/**
 * Updates the position of the snake and manages the growing tail. Also handles 
 * game state to potentially terminate the game on the next tick.
 */
void update() {
	Posn prev = tail[0];
	Posn tmpPrev;

	tail[0] = curr;
	for (int i = 1; i < tailSize; i++) {
		tmpPrev = tail[i];
		tail[i] = prev;
		prev = tmpPrev;
	}

	switch (dir) {
		case LEFT:  curr.x--; break;
		case RIGHT: curr.x++; break;
		case UP:	curr.y--; break;
		case DOWN:	curr.y++; break;
		default:	break;
	}

	if (curr.x > WIDTH || curr.x < 0) {
		ended = true;
	}
	if (curr.y > HEIGHT || curr.y < 0) {
		ended = true;
	}

	for (int i = 0; i < tailSize; i++) {
		if (tail[i].x == curr.x && tail[i].y == curr.y) {
			ended = true;
			return;
		}
	}

	if (curr.x == fruit.x && curr.y == fruit.y) {
		score += SCORE_PER_FRUIT;
		spawnFruit();
		tail[tailSize].x = curr.x;
		tail[tailSize].y = curr.y;
		tailSize++;
	}
}

/**
 * Spawns the fruit at random coordinates.
 */
void spawnFruit() {
	fruit.x = rand() % WIDTH;
	fruit.y = rand() % HEIGHT;
}

WiimoteBtns::WiimoteBtns() {
	fd = open("/dev/input/event2", O_RDONLY);
	if (fd == -1) {
		cerr << "Error: Could not open event file\n";
		exit(1);
	}
}

WiimoteBtns::~WiimoteBtns() {
	close(fd);	
}

void WiimoteBtns::listen() {
	char buffer[32];
	read(fd, buffer, 32);

	if (buffer[12] == 0) {
		return;
	}

	switch (buffer[10]) {
		case 105: dir = LEFT; 	break;
		case 106: dir = RIGHT;	break;
		case 108: dir = DOWN;	break;
		case 103: dir = UP;		break;
		case 49: ended = true; break;
		default:	dir = INVALID;			break;
	}
	render();
	update();
}

int main() {
	WiimoteBtns *wb = new WiimoteBtns();
	init();
	while (!ended) {
		wb->listen();
	}
	delete wb;
	cout << "Your final score : " << score << endl;
	return 0;
}
