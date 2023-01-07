#include "map.h"

Map::Map() : Map(0, 0, 0, nullptr) {}

Map::Map(const Map& other)
    : width(other.width),
      height(other.height),
      max_moves(other.max_moves),
      map(other.map),
      player_init_pos(other.player_init_pos),
      num_boxes(other.num_boxes) {
  if (num_boxes > 0) {
    box_init_pos = new Vec[num_boxes];
    for (int i = 0; i < num_boxes; i++) {
      box_init_pos[i] = other.box_init_pos[i];
    }
  } else {
    box_init_pos = nullptr;
  }
}

Map::Map(int width, int height, int max_moves, const MapField* map)
    : width(width), height(height), max_moves(max_moves), map(map) {
  // zliczanie boxow i ustawianie pozycji gracza
  this->num_boxes = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (get_field(x, y) == BOX || get_field(x, y) == DEST_BOX) {
        num_boxes++;
      } else if (get_field(x, y) == PLAYER) {
        player_init_pos = Vec{x, y};
      }
    }
  }
  // alokacja tablicy boxow
  if (num_boxes > 0)
    box_init_pos = new Vec[num_boxes];
  else
    box_init_pos = nullptr;

  // dodawanie boxow do tablicy
  int box_index = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (get_field(x, y) == BOX || get_field(x, y) == DEST_BOX) {
        box_init_pos[box_index++] = Vec{x, y};
      }
    }
  }
}

Map::~Map() {
  if (num_boxes > 0)
    delete[] box_init_pos;
}

MapField Map::get_field(int x, int y) const {
  return map[y * width + x];
}

bool Map::is_wall(int x, int y) const {
  return get_field(x, y) == WALL;
}

bool Map::is_dest(int x, int y) const {
  return get_field(x, y) == DEST || get_field(x, y) == DEST_BOX;
}

int Map::get_width() const {
  return width;
}

int Map::get_height() const {
  return height;
}

int Map::get_max_moves() const {
  return max_moves;
}

Vec Map::get_init_player_pos() const {
  return player_init_pos;
}

int Map::get_num_boxes() const {
  return num_boxes;
}

Vec Map::get_init_box_pos(int box_index) const {
  return box_init_pos[box_index];
}

Map Map::get_stage1() {
  return Map{STAGE1_WIDTH, STAGE1_HEIGHT, STAGE1_MOVES, STAGE1};
}

Map Map::get_stage2() {
  return Map{STAGE2_WIDTH, STAGE2_HEIGHT, STAGE2_MOVES, STAGE2};
}

Map Map::get_stage3() {
  return Map{STAGE3_WIDTH, STAGE3_HEIGHT, STAGE3_MOVES, STAGE3};
}
