/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */


#ifndef TICTACTOE_H
#define TICTACTOE_H

using namespace std;

class tictactoe{
public:
  tictactoe ();
  bool play (int x, int y, char c);
  char checkwin ();
  void print ();
  char swap (char inp);
  void play ();

private:
  char array[3][3];
};
#endif 
