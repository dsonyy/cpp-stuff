#include "app.h"

App::App(GUI& gui)
    : gui(gui),
      showing_menu(true),
      running(true),
      game(nullptr),
      success_stages(1) {}

void App::update() {
  if (showing_menu) {
    update_menu();
  } else {
    update_game();
    if (!game->is_running()) {
      if (game->is_success()) {
        success_stages++;
      }
      delete game;
      showing_menu = true;
    }
  }
}

bool App::is_running() {
  return running;
}

void App::update_menu() {
  switch (gui.run_menu(success_stages)) {
    case START_STAGE1:
      game = new Game(Map::get_stage1());
      break;
    case START_STAGE2:
      game = new Game(Map::get_stage2());
      break;
    case START_STAGE3:
      game = new Game(Map::get_stage3());
      break;
    case EXIT:
      running = false;
      break;
  }
  showing_menu = false;
}

void App::update_game() {
  switch (gui.run_game(*game)) {
    case MOVE_UP:
      game->move_player(UP);
      break;
    case MOVE_RIGHT:
      game->move_player(RIGHT);
      break;
    case MOVE_DOWN:
      game->move_player(DOWN);
      break;
    case MOVE_LEFT:
      game->move_player(LEFT);
      break;
    case VIEW_UP:
    case VIEW_RIGHT:
    case VIEW_DOWN:
    case VIEW_LEFT:
      break;
    case MENU:
      showing_menu = true;
      break;
    case UNDO:
      game->undo();
      break;
    case REDO:
      game->redo();
      break;
  }
}