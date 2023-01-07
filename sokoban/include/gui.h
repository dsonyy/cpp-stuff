#ifndef _GUI_H_
#define _GUI_H_

#include <cstdlib>
#include <iostream>
#include "game.h"
#include "inputs.h"

const int VIEW_WIDTH = 80;
const int VIEW_HEIGHT = 22;

class GUI {
 public:
  GUI();

  MenuInput run_menu(int success_stages);
  GameInput run_game(const Game& game);

 private:
  static void clear_screen();

  Vec view_offset;
};

#endif