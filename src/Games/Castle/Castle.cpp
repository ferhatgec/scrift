/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include <iostream>
#include <curses.h>
#include <stdlib.h>

#include "Castle.hpp"

int main() {
  setlocale(LC_ALL, "");

  FCastle *termo = new FCastle();
  termo->start();
  
	  
  delete termo; 
  return 0;
}

void FCastle::start() {
  char key;

  while(1) {
    timer = (timer >= TIMER_RANGE ? 0 : timer + 1);
    key = getch();

    switch(key) {
      case ' ':
        if (debounceTimer != 0)
          break;

        switch(gameState) {
          case GAME_STARTED:
            jump();
            if (bushPos < 28 && bushPos > 6) {
              score.passed++;
            }
            break;
          case GAME_AI:
          case GAME_OVER:
            startGame();
            break;
        }

        break;
      case 'q':
        return;
    }

    draw();
    refresh();

    if (key != -1) {
      debounceTimer = TIMER_RANGE;
    } else {
      debounceTimer = (debounceTimer == 0 ? 0 : debounceTimer - 1);
    }
  }
}

void FCastle::draw() {
  clear();

  attron(COLOR_PAIR(2));
    drawTerrain();
    drawBush();
  attroff(COLOR_PAIR(2));

  attron(COLOR_PAIR(3));
    drawDino();
  attron(COLOR_PAIR(3));
  drawScore();

  switch(gameState) {
    case GAME_AI:
      aiGame();
      break;
    case GAME_OVER:
      gameOver();
      aiGame();
      break;
    case GAME_STARTED:
      score.time++;
      break;
  }
}

void FCastle::jump() {
  isJump = true;
  jumpTimer = TIMER_RANGE * 2.4;
}

void FCastle::gameOver() {
  mvprintw((winSize.y / 2) - 1, (winSize.x / 2) - 4, "GAME OVER : :(");
}

void FCastle::aiGame() {
  mvprintw(winSize.y / 2, (winSize.x / 2) - (20 / 2), "Press SPACE to start ");

  if (bushPos < 23 && bushPos > 10 && !isJump) {
    jump();
  }
}

void FCastle::startGame() {
  gameState = GAME_STARTED;
  score = { 0, 0 };
  bushPos = -10;
}

void FCastle::drawScore() {
  attron(COLOR_PAIR(5));
  
  if(score.passed >= 10) 
  {
  	mvprintw(2, 2, "Wow! Nice!: %04d x %08d", score.passed, score.time);
  }
  else if(score.passed >= 50)
  {
  	mvprintw(3, 3, "Cool!: %04d x %08d", score.passed, score.time);
  }
  else if(score.passed >= 100)
  {
  	mvprintw(4, 4, "Mr. Castle! What's up?: %04d x %08d", score.passed, score.time);
  }
  else if(score.passed >= 200)
  {
  	mvprintw(1, 1, "What the.... Castle!: %04d x %08d", score.passed, score.time);
  }
  else if(score.passed >= 400)
  {
  	mvprintw(1, 1, "President... Castle.: %04d x %08d", score.passed, score.time);
  }
  else if(score.passed >= 800)
  {
  	mvprintw(1, 1, "Hahaha! Good joke, Castle.: %04d x %08d", score.passed, score.time);
  }
  else if(score.passed >= 2000)
  {
  	mvprintw(1, 1, "Help me! President... Castle.: %04d x %08d", score.passed, score.time);
  }
  else if(score.passed >= 4000)
  {
  	mvprintw(1, 1, "Really?: %04d x %08d", score.passed, score.time);
  }
  
  mvprintw(1, 1, "Your Score: %04d x %08d", score.passed, score.time);
	
  attroff(COLOR_PAIR(5));
}

void FCastle::drawBush() {
  bushPos -= 3;

  if (bushPos <= -5) {
    srand(timer);
    bushPos = winSize.x + (rand() % (winSize.x));
  }

  if (bushPos <= (winSize.x - 5)) {
    int y = winSize.y - 1;

    mvprintw(y - 4, bushPos, "▄█ █▄");
    mvprintw(y - 3, bushPos, "██ ██");
    mvprintw(y - 2, bushPos + 1, "███");
    mvprintw(y - 1, bushPos + 1, "███");
  }

  if (bushPos <= 23 && bushPos <= 6 && !isJump) {
    gameState = GAME_OVER;
  }
}

void FCastle::drawTerrain() {
  int i;

  for (i = 0; i < winSize.x; i++) {
    mvprintw(winSize.y - 1, i, "█");

    if (i == 3 && !isJump) {
      i = 23;
    }
  }
}

void FCastle::drawDino() {
  Point pos = { 5,  winSize.y - 12 };

  if (isJump) {
    pos.y -= 4;
    jumpTimer--;

    if (jumpTimer <= 0) {
      isJump = false;
    }
  }

  mvprintw(  pos.y, pos.x, "   ███ ██ ███    ");
  mvprintw(++pos.y, pos.x, "   ██████████ ");
  mvprintw(++pos.y, pos.x, "   ██████████		");
  mvprintw(++pos.y, pos.x, "   ██ ████ ██   	");
  mvprintw(++pos.y, pos.x, "   ██████████   ");
  mvprintw(++pos.y, pos.x, "   ██ ████ ██   ");
  mvprintw(++pos.y, pos.x, "   ██      ██     ");
  mvprintw(++pos.y, pos.x, "   ██████████     ");
  mvprintw(++pos.y, pos.x, "   ██████████     ");
  
  if (isJump) {
    mvprintw(++pos.y, pos.x, "   ██▄   ██▄");
  } else {
    if (timer < (TIMER_RANGE / 2)) {
      mvprintw(++pos.y, pos.x, "   ██    ██▄   ");
      mvprintw(++pos.y, pos.x, "   █▄▄      ");
    } else {
      mvprintw(++pos.y, pos.x, "    ██▄ ██  ");
      mvprintw(++pos.y, pos.x, "         █▄▄  ");
    }
  }
}

void FCastle::clear() {
  int i;

  if (!emptyLine) {
    emptyLine = new char[winSize.x];

    for (i = 0; i < winSize.x; i++) {
      emptyLine[i] = ' ';
    }
  }

  for (i = 0; i <= winSize.y; i++) {
    mvprintw(i, 0, "%s", emptyLine);
  }
}

FCastle::FCastle() {
  startCurses();
  bushPos = -10;
  gameState = GAME_AI;
}

FCastle::~FCastle() {
  delete emptyLine;
  stopCurses();
}

void FCastle::startCurses() {
  initscr();
  start_color();
  noecho();
  cbreak();
  curs_set(false);

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);

  getmaxyx(stdscr, winSize.y, winSize.x);
  keypad(stdscr, true);
  timeout(FPS_TIMEOUT);
}

void FCastle::stopCurses() {
  endwin();
}
