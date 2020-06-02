/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef CASTLE_HPP
#define CASTLE_HPP

#define FPS_TIMEOUT 60
#define TIMER_RANGE 4

enum GAME_STATE_TABLE {
  GAME_STARTED,
  GAME_OVER,
  GAME_AI
};

struct Point {
  int x;
  int y;
};

struct Score {
  int time;
  int passed;
};

class FCastle {
  public:
    FCastle();
    ~FCastle();

    void start();

  private:
    Point winSize;
    Score score;
    char *emptyLine;
    char timer;
    char debounceTimer;
    char jumpTimer;
    bool isJump;
    int bushPos;
    char gameState;

    void startCurses();
    void stopCurses();
    void draw();
    void drawDino();
    void drawTerrain();
    void drawBush();
    void drawScore();
    void clear();

    void gameOver();
    void aiGame();
    void startGame();

    void jump();
};

#endif // CASTLE_HPP
