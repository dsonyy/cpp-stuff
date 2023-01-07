#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "hsv2rgb.h"

using namespace std;
using namespace sf;

int w = 640;
int h = 480;
bool painting = false;
vector<Color> palette(256);                            // fire palette
Image buffer;                                          // pixel buffer
vector<vector<size_t>> fire(w, vector<size_t>(h, 0));  // fire buffer
set<pair<unsigned, unsigned>> sources;                 // fire sources
double alpha = 4.4;

void handle_input(RenderWindow& window, const Event& ev) {
  if (ev.type == Event::Closed) {
    // window close
    window.close();
  } else if (ev.type == Event::Resized) {
    // window resize
    w = ev.size.width;
    h = ev.size.height;
    FloatRect visibleArea(0, 0, w, h);
    window.setView(sf::View(visibleArea));
  } else if (ev.type == Event::MouseButtonPressed) {
    painting = true;
  } else if (ev.type == Event::MouseButtonReleased) {
    painting = false;
  } else if (ev.type == Event::KeyPressed) {
    if (ev.key.code == Keyboard::P) {
      // save screenshot
      Texture texture;
      texture.create(window.getSize().x, window.getSize().y);
      texture.update(window);
      texture.copyToImage().saveToFile("screenshots/" +
                                       to_string(time(nullptr)) + ".png");

    } else if (ev.key.code == Keyboard::Down) {
      alpha += 0.01;
    } else if (ev.key.code == Keyboard::Up) {
      alpha = max(1.0, alpha - 0.01);
    }
    cout << "alpha = " << alpha << endl;
  }

  if (painting) {
    auto mouse = Mouse::getPosition(window);
    if (mouse.x >= 0 && mouse.x < w && mouse.y >= 0 && mouse.y < h)
      sources.insert({mouse.x, mouse.y});
  }
}

void init_palette(vector<Color>& palette) {
  int sz = palette.size();
  for (int i = 0; i < sz; ++i) {
    auto hue = 60.0 / double(sz) * double(i);
    auto sat = 1.0;
    auto val = min(1.0, 0.1 + double(i) / double(sz) * 3);

    auto color = hsv2rgb({hue, sat, val});
    palette[i] = Color(color.r * 255, color.g * 255, color.b * 255);
  }
}

size_t merge_colors(const vector<vector<size_t>>& fire,
                    const vector<Vector2i>& coords) {
  size_t val = 0;
  for (auto coord : coords) {
    val += fire[coord.x % fire.size()][coord.y % fire[0].size()];
  }
  return min(palette.size() - 1, max(size_t(0), size_t(double(val) / alpha)));
}

void update(RenderWindow& window) {
  // set random value to fire sources
  for (auto source : sources)
    fire[source.first][source.second] = rand() % palette.size();

  // calculate higher lines of the fire
  // NOTE: interesting if you change the order of the loops
  for (int j = 0; j < h - 1; j++)
    for (int i = 0; i < w; i++) {
      fire[i][j] = merge_colors(
          fire, {{i + 1, j + 1}, {i, j + 1}, {i - 1, j + 1}, {i, j + 2}});
    }

  // print fire
  for (int i = 0; i < fire.size(); i++)
    for (int j = 0; j < fire[i].size(); j++)
      buffer.setPixel(i, j, palette[fire[i][j]]);

  // print palette
  for (int i = 0; i < min(palette.size(), size_t(w)); ++i)
    for (int j = 0; j < 5; j++)
      buffer.setPixel(i, j, palette[i]);

  // make pixel buffer printable
  Texture texture;
  texture.loadFromImage(buffer);
  Sprite sprite(texture);

  // print and display the scene
  window.clear(Color::Black);
  window.draw(sprite);
  window.display();
}

int main(int argc, char** argv) {
  // create window
  RenderWindow window(VideoMode(w, h), "Fire", Style::Close,
                      ContextSettings(0U, 0U, 1.0));
  window.setFramerateLimit(30);

  // init stuff
  buffer.create(w, h, Color::Black);
  init_palette(palette);
  // set window bottom line as fire source
  for (int i = 0; i < w; i++)
    sources.insert({i, h - 1});

  // main loop
  update(window);
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      handle_input(window, event);
    }
    update(window);
  }
  return 0;
}
