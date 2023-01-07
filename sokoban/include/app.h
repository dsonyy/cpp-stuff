#ifndef _APP_H_
#define _APP_H_

#include "game.h"
#include "gui.h"
#include "inputs.h"

class App {
 public:
  App(GUI& gui);

  void update();
  bool is_running();

 private:
  void update_menu();
  void update_game();

  GUI gui;
  Game* game;
  bool showing_menu;
  bool running;
  int success_stages;
};

#endif