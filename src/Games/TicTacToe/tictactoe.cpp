/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#include <climits>
#include <iostream>
#include "tictactoe.h"
#include "../../../include/src/Scrift.hpp"
#include "../../../include/src/Syntax/Colors.hpp"
#include "../../../include/src/synflang.hpp"

using namespace std;


tictactoe::tictactoe (){
  for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
	    array[i][j] = '-';
	    }
    }
}

//play the x,y move on theh table
bool tictactoe::play (int x, int y, char c){
  if (array[x][y] == '-'){
      if (c == 'X' || c == 'O'){
        array[x][y] = c;
        return true;
	    }else{
	        return false;
	    }
    }else{
      return false;
    }
}


char tictactoe::checkwin (){
    int i;
    int j;
    for (i = 0; i < 3; i++){
        if (array[i][0] == array[i][1] && array[i][0] == array[i][2]){
	        return array[i][0];
	    }
    }
    for (j = 0; j < 3; j++){
        if (array[0][j] == array[1][j] && array[1][j] == array[2][j]){
	    return array[0][j];
	    }
    }
    if (array[0][0] == array[1][1] && array[1][1] == array[2][2]){
      return array[1][1];
    }
    if (array[2][0] == array[1][1] && array[1][1] == array[0][2]){
      return array[1][1];
    }
    //else return '-'
    return '-';
}

//print the table
void tictactoe::print (){
  int i, j;
  cout << "   1  2  3 \n";
  for (i = 0; i < 3; i++){
      cout<< i+1<<"  ";
    for (j = 0; j < 3; j++){
	    cout << array[i][j]<<"  ";
	}
    cout << "\n";
  }
  cout << "\n";
}

char tictactoe::swap (char inp){
  char pl;
  if (inp == 'X'){
      pl = 'O';
    }else{
      pl = 'X';
    }
  return pl;
}


void tictactoe::play (){
  int i, x, y, tmp;
  char inp='X', win;

  for (i = 0; i < 9; i++){
      cout << "\n";
      print ();
      //change player turn
      inp = swap (inp);
      //ask player to enter values x,y
      do{
        cout << "Plays the player with symbol " << inp << " \n \n";
        cout << "Choose in which LINE from 1 to 3 to insert your symbol "<< inp <<" \n";
        if(std::cin.get() == 'q') {
        	BOLD_RED_COLOR
                printlnf("Goodbye!");
                slashn
                BLACK_COLOR
                exit(EXIT_SUCCESS);
        } 
        //validating the input not being a character
        while (!(std::cin >> tmp)){
            std::cin.clear(); // clear the error flags
            std::cin.ignore(INT_MAX, '\n'); // discard the row
            std::cout << "Invalid input! Try again: \n ---";
        }
        x=tmp-1;
        cout << "Choose in which COLUMN from 1 to 3 to insert your symbol "<< inp <<" \n";
        //validating the input not being a character
        while (!(std::cin >> tmp)){
            std::cin.clear(); // clear the error flags
            std::cin.ignore(INT_MAX, '\n'); // discard the row
            std::cout << "Invalid input! Try again: \n ---";
        }
        y=tmp-1;
        if (!play (x, y, inp)){
            cout << "\n ********-- WARNING --******** \n This cell on table is not empty. \n";
            inp = swap (inp);
            continue;
        }
      }while (x < 0 || x >= 3 || y < 0 || y >= 3);
    //check if a player wins
    win = checkwin ();
    if (win != '-'){
      cout << "\n" << " **** CONGRATULATIONS *** \n \n THE WINNER IS PLAYER: " << win << "\n \n";
      print ();
      break;
    }else if (i == 9-1){
      cout << "DRAW - No winner found! \n \n";
    }
  }
}

