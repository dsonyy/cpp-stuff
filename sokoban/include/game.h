#ifndef _GAME_H_
#define _GAME_H_

#include "map.h"
#include "vec.h"

enum MoveDirection {
  UP,
  RIGHT,
  DOWN,
  LEFT,
};

struct HistoryState {
  int player_moves_left;
  int box_on_dest_left;
  Vec player_pos;
  Vec* box_pos;
};

const int HISTORY_SIZE = 20;

class Game {
 public:
  Game();
  Game(const Map& map);
  ~Game();

  void move_player(MoveDirection direction);
  void undo();
  void redo();
  bool is_success() const;
  bool is_running() const;
  MapField get_map_field(int x, int y) const;
  int get_map_width() const;
  int get_map_height() const;
  int get_player_moves_left() const;
  int get_box_on_dest_left() const;

 private:
  static Vec direction_to_vec(MoveDirection direction);
  bool check_in_bounds(Vec pos) const;
  int get_box_index_at(Vec pos) const;
  void update_history();

  int player_moves_left;
  int box_on_dest_left;
  bool running;
  Map map;
  Vec player_pos;
  Vec* box_pos;
  HistoryState history[HISTORY_SIZE];
  int history_index;
  int history_length;
};

#endif
