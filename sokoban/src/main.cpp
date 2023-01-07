#include "app.h"

int main(int argc, char** argv) {
  GUI gui = GUI();
  App app = App(gui);

  while (app.is_running()) {
    app.update();
  }

  return 0;
}