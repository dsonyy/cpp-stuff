#include "gui.h"

GUI::GUI() : view_offset{0, 0} {}

MenuInput GUI::run_menu(int success_stages) {
  clear_screen();
  std::cout << "\n"
            << "  #####  ####### #    # ####### ######     #    #     #\n"
            << " #     # #     # #   #  #     # #     #   # #   ##    #\n"
            << " #       #     # #  #   #     # #     #  #   #  # #   #\n"
            << "  #####  #     # ###    #     # ######  #     # #  #  #\n"
            << "       # #     # #  #   #     # #     # ####### #   # #\n"
            << " #     # #     # #   #  #     # #     # #     # #    ##\n"
            << "  #####  ####### #    # ####### ######  #     # #     #\n"
            << "\n"
            << "\n\n"
            << " ===== Menu Główne =====\n";
  for (int i = 1; i <= success_stages; i++) {
    std::cout << " " << i << " - Poziom " << i << std::endl;
  }
  std::cout << " q - Wyjście\n" << std::endl;

  char input;
  std::cin >> input;
  do {
    switch (input) {
      case '1':
        return START_STAGE1;
      case '2':
        return START_STAGE2;
      case '3':
        return START_STAGE3;
      case 'q':
        return EXIT;
      default:
        std::cout << "Niepoprawne polecenie." << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> input;
    }
  } while (true);
}

GameInput GUI::run_game(const Game& game) {
  clear_screen();
  std::cout << "Pozostalo ruchow: " << game.get_player_moves_left()
            << std::endl;
  std::cout << "Pozostalo skrzyn: " << game.get_box_on_dest_left() << std::endl;

  for (int j = 0; j < VIEW_HEIGHT; j++) {
    for (int i = 0; i < VIEW_WIDTH; i++) {
      int x = i / 2 + view_offset.x;
      int y = j / 2 + view_offset.y;

      if (x >= game.get_map_width() || y >= game.get_map_height() || x < 0 ||
          y < 0) {
        std::cout << ' ';
      } else {
        switch (game.get_map_field(x, y)) {
          case WALL:
            std::cout << "\u2588";
            break;
          case EMPTY:
            std::cout << " ";
            break;
          case BOX:
            std::cout << "O";  //"\u2593";
            break;
          case DEST:
            std::cout << "+";
            break;
          case PLAYER:
            std::cout << "@";  //"\u2592";
            break;
          case DEST_BOX:
            std::cout << "X";
            break;
          default:
            std::cout << "?";
            break;
        }
      }
    }
    std::cout << std::endl;
  }

  char input;
  std::cin >> input;
  do {
    switch (input) {
      case 'w':
      case 'W':
        return MOVE_UP;
      case 'd':
      case 'D':
        return MOVE_RIGHT;
      case 's':
      case 'S':
        return MOVE_DOWN;
      case 'a':
      case 'A':
        return MOVE_LEFT;
      case 'i':
      case 'I':
        view_offset.y++;
        return VIEW_UP;
      case 'l':
      case 'L':
        view_offset.x--;
        return VIEW_RIGHT;
      case 'k':
      case 'K':
        view_offset.y--;
        return VIEW_DOWN;
      case 'j':
      case 'J':
        view_offset.x++;
        return VIEW_LEFT;
      case 'q':
      case 'Q':
        return MENU;
      case 'u':
      case 'U':
        return UNDO;
      case 'r':
      case 'R':
        return REDO;
      default:
        std::cout << "Niepoprawne polecenie." << std::endl;
        std::cin >> input;
    }
  } while (true);
}

void GUI::clear_screen() {
  system("clear");
}