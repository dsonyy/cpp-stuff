#ifndef _MAP_H_
#define _MAP_H_

#include "maps.h"
#include "vec.h"

class Map {
 public:
  Map();
  Map(const Map& other);
  Map(int width, int height, int max_moves, const MapField* map);
  ~Map();

  // gettery
  MapField get_field(int x, int y) const;
  bool is_wall(int x, int y) const;
  bool is_dest(int x, int y) const;
  int get_width() const;
  int get_height() const;
  int get_max_moves() const;
  Vec get_init_player_pos() const;
  int get_num_boxes() const;
  Vec get_init_box_pos(int box_index) const;

  // predefiniowane poziomy
  static Map get_stage1();
  static Map get_stage2();
  static Map get_stage3();

 private:
  int width;
  int height;
  int max_moves;
  int num_boxes;
  Vec player_init_pos;
  Vec* box_init_pos;
  const MapField* map;
};
#endif