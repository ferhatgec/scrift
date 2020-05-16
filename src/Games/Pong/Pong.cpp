/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include <ncurses.h>
#include <string.h>
#include <unistd.h>

#define DELAY 27000

typedef struct paddle {
	int x;
	int y;   
	int len;
	int score;
} paddle_t;

typedef struct ball {
	/* ball variables */
	int x;
	int y;
	int next_x;
	int next_y;
	int x_vel;
	int y_vel;
} ball_t;

typedef struct dimensions {
	int x;
	int y;
} dimensions_t;

void draw_ball(ball_t *input);
void draw_paddle(paddle_t *paddle);
void draw_score(paddle_t *inpt_paddle, dimensions_t *wall);
void paddle_collisions(ball_t *inpt_ball, paddle_t *inpt_paddle);
void paddle_pos(paddle_t *pddl, dimensions_t *wall, char dir);

int wall_collisions(ball_t *usr_ball, dimensions_t *walls);
int kbdhit();

int main(int argc, char **argv)
{
	/* initialize curses */
	initscr();
	noecho();
	curs_set(0);

	dimensions_t walls = { 0 };
	getmaxyx(stdscr, walls.y, walls.x); /* get dimensions */

	/* set the paddle variables */
	paddle_t usr_paddle = { 0 };

	usr_paddle.x = 5;
	usr_paddle.y = 11;
	usr_paddle.len = walls.y / 4; usr_paddle.score = 0; 

	/* set the ball */
	ball_t usr_ball = { 0 };

	usr_ball.x = walls.x / 2;
	usr_ball.y = walls.y / 2;
	usr_ball.next_x = 0;
	usr_ball.next_y = 0;
	usr_ball.x_vel = 1;
	usr_ball.y_vel = 1;

	/* we actually have to store the user's keypress somewhere... */
	int keypress = 0;
	int run = 1;
	nodelay(stdscr, TRUE);
	scrollok(stdscr, TRUE);

	while (run) {
		while (kbdhit()) {
			getmaxyx(stdscr, walls.y, walls.x);
			clear(); /* clear screen of all printed chars */

			draw_ball(&usr_ball);
			draw_paddle(&usr_paddle);
			draw_score(&usr_paddle, &walls);
			refresh(); /* draw to term */
			usleep(DELAY);

			/* set next positions */
			usr_ball.next_x = usr_ball.x + usr_ball.x_vel;
			usr_ball.next_y = usr_ball.y + usr_ball.y_vel;

			/* check for collisions */
			paddle_collisions(&usr_ball, &usr_paddle);
			if (wall_collisions(&usr_ball, &walls)) {
				run = 0;
				break;
			}
		}

		/* we fell out, get the key press */
		keypress = getch();


		switch (keypress) {
		case 'j':
		case 'k':
			paddle_pos(&usr_paddle, &walls, keypress);
			break;

		case 'p': 
			mvprintw(1, 0, "PAUSE - press any key to resume");
			while (getch() == ERR) {
				usleep(DELAY * 7);
			}
			break;

		case 'q':
			run = 0;
			break;

		}
	}

	endwin();

	printf("GAME OVER\nFinal Score: %d\n", usr_paddle.score);

	return 0;
}


void paddle_pos(paddle_t *pddl, dimensions_t *wall, char dir)
{
	if (dir == 'j') { /* moving down */
		if (pddl->y + pddl->len + 1 <= wall->y)
			pddl->y++;
	} else {          /* moving up (must be 'k') */
		if (pddl->y - 1 >= 0)
			pddl->y--;

	}

	return;
}


int wall_collisions(ball_t *usr_ball, dimensions_t *walls)
{
	/* check if we're supposed to leave quick */
	if (usr_ball->next_x < 0) {
		return 1;
	}

	/* check for X */
	if (usr_ball->next_x >= walls->x) {
		usr_ball->x_vel *= -1;
	} else {
		usr_ball->x += usr_ball->x_vel;
	}

	/* check for Y */
	if (usr_ball->next_y >= walls->y || usr_ball->next_y < 0) {
		usr_ball->y_vel *= -1;
	} else {
		usr_ball->y += usr_ball->y_vel;
	}

	return 0;
}


void paddle_collisions(ball_t *inpt_ball, paddle_t *inpt_paddle)
{

	if (inpt_ball->next_x == inpt_paddle->x) {
		if (inpt_paddle->y <= inpt_ball->y &&
			inpt_ball->y <= 
			inpt_paddle->y + inpt_paddle->len) {

			inpt_paddle->score++;
			inpt_ball->x_vel *= -1;
		}
	}

	return;
}


void draw_ball(ball_t *input)
{
	mvprintw(input->y, input->x, "O");
	return;
}

void draw_paddle(paddle_t *paddle)
{
	int i;

	for (i = 0; i < paddle->len; i++)
		mvprintw(paddle->y + i, paddle->x, "|");

	return;
}

void draw_score(paddle_t *inpt_paddle, dimensions_t *wall)
{
	mvprintw(0, wall->x / 2 - 7, "Score: %d", inpt_paddle->score);

	return;
}

int kbdhit()
{
	int key = getch();

	if (key != ERR) {
		ungetch(key);
		return 0;
	} else {
		return 1;
	}
}
