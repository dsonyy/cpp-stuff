#include "game.h"

Game::Game()
    : player_moves_left(0),
      box_on_dest_left(0),
      player_pos({0, 0}),
      box_pos(nullptr),
      running(true),
      history_index(0),
      history_length(0) {}

Game::Game(const Map& map)
    : map(map), running(true), history_index(0), history_length(0) {
  player_moves_left = map.get_max_moves();
  player_pos = map.get_init_player_pos();

  box_on_dest_left = 0;
  if (map.get_num_boxes() > 0) {
    box_pos = new Vec[map.get_num_boxes()];
    for (int i = 0; i < map.get_num_boxes(); i++) {
      box_pos[i] = map.get_init_box_pos(i);
      if (!map.is_dest(box_pos[i].x, box_pos[i].y))
        box_on_dest_left++;
    }
  } else {
    box_pos = nullptr;
  }

  update_history();
}

Game::~Game() {
  if (box_pos != nullptr) {
    delete[] box_pos;
  }

  // TODO zwolnic historie
}

void Game::move_player(MoveDirection direction) {
  Vec move = direction_to_vec(direction);
  Vec new_player_pos = {player_pos.x + move.x, player_pos.y + move.y};

  // sprawdzamy czy nie wyjdzie poza mape
  if (!check_in_bounds(new_player_pos))
    return;

  // sprawdzamy czy nie wejdzie w sciane
  if (map.is_wall(new_player_pos.x, new_player_pos.y))
    return;

  // sprawdzamy czy wejdzie w skrzynke
  int box_index = get_box_index_at(new_player_pos);
  if (box_index == -1) {
    player_pos = new_player_pos;
    player_moves_left--;
    update_history();
    if (player_moves_left <= 0)
      running = false;
    return;
  }

  Vec new_box_pos = {new_player_pos.x + move.x, new_player_pos.y + move.y};
  // sprawdzamy czy skrzynka nie wejdzie w sciane
  if (map.is_wall(new_box_pos.x, new_box_pos.y))
    return;

  // sprawdzamy czy skrzynka nie wyjdzie poza mape
  if (!check_in_bounds(new_box_pos))
    return;

  // sprawdzamy czy skrzynka nie wejdzie w inna skrzynke
  if (get_box_index_at(new_box_pos) != -1)
    return;

  // sprawdzamy czy skrzynka wyjdzie z miejsca docelowego
  if (map.is_dest(new_player_pos.x, new_player_pos.y))
    box_on_dest_left++;

  // sprawdzamy czy skrzynka wejdzie na miejsce docelowe
  if (map.is_dest(new_box_pos.x, new_box_pos.y))
    box_on_dest_left--;

  player_pos = new_player_pos;
  player_moves_left--;
  box_pos[box_index] = new_box_pos;
  update_history();

  if (is_success())
    running = false;
}

bool Game::is_success() const {
  return box_on_dest_left == 0 && player_moves_left >= 0;
}

bool Game::is_running() const {
  return running;
}

MapField Game::get_map_field(int x, int y) const {
  if (x == player_pos.x && y == player_pos.y) {
    return PLAYER;
  }

  int box_index = get_box_index_at(Vec{x, y});
  if (box_index != -1) {
    if (map.is_dest(x, y))
      return DEST_BOX;
    return BOX;
  }

  if (map.is_wall(x, y))
    return WALL;
  if (map.is_dest(x, y))
    return DEST;
  return EMPTY;
}

int Game::get_map_width() const {
  return map.get_width();
}

int Game::get_map_height() const {
  return map.get_height();
}

int Game::get_player_moves_left() const {
  return player_moves_left;
}

int Game::get_box_on_dest_left() const {
  return box_on_dest_left;
}

bool Game::check_in_bounds(Vec pos) const {
  return pos.x >= 0 && pos.y >= 0 && pos.x < map.get_width() &&
         pos.y < map.get_height();
}

int Game::get_box_index_at(Vec pos) const {
  for (int i = 0; i < map.get_num_boxes(); i++) {
    if (box_pos[i].x == pos.x && box_pos[i].y == pos.y) {
      return i;
    }
  }
  return -1;
}

Vec Game::direction_to_vec(MoveDirection direction) {
  switch (direction) {
    case UP:
      return Vec{0, -1};
    case RIGHT:
      return Vec{1, 0};
    case DOWN:
      return Vec{0, 1};
    case LEFT:
      return Vec{-1, 0};
    default:
      return Vec{0, 0};
  }
}

void Game::update_history() {
  if (history_index == HISTORY_SIZE) {
    delete[] history[0].box_pos;

    for (int i = 0; i < HISTORY_SIZE - 1; i++) {
      history[i] = history[i + 1];
    }

    history_index--;
  }

  history[history_index].player_pos = player_pos;
  history[history_index].player_moves_left = player_moves_left;
  history[history_index].box_on_dest_left = box_on_dest_left;
  history[history_index].box_pos = new Vec[map.get_num_boxes()];
  for (int i = 0; i < map.get_num_boxes(); i++) {
    history[history_index].box_pos[i] = box_pos[i];
  }
  history_index++;
  history_length = history_index;
}

void Game::undo() {
  if (history_index <= 1)
    return;

  history_index -= 2;
  player_pos = history[history_index].player_pos;
  player_moves_left = history[history_index].player_moves_left;
  box_on_dest_left = history[history_index].box_on_dest_left;
  for (int i = 0; i < map.get_num_boxes(); i++) {
    box_pos[i] = history[history_index].box_pos[i];
  }
  history_index++;
}

void Game::redo() {
  if (history_index >= history_length)
    return;

  player_pos = history[history_index].player_pos;
  player_moves_left = history[history_index].player_moves_left;
  box_on_dest_left = history[history_index].box_on_dest_left;
  for (int i = 0; i < map.get_num_boxes(); i++) {
    box_pos[i] = history[history_index].box_pos[i];
  }

  history_index++;
}