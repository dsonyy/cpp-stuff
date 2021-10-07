#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

const int WIDTH = 1900;
const int HEIGHT = 1000;

sf::RenderWindow window;
bool running;
bool keys[sf::Keyboard::KeyCount] = {};

struct Arrow {
  enum { LEN = 15 };
  float x;
  float y;
  float angle;
};

std::vector<Arrow> arrows;

void handle_input();
void update();
void redraw();

int main(int argc, char** argv) {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8.0;
  window.create(sf::VideoMode(WIDTH, HEIGHT), "Arrows",
                sf::Style::Close | sf::Style::Titlebar, settings);
  window.setMouseCursorVisible(true);
  window.setFramerateLimit(60);
  running = true;

  for (float i = Arrow::LEN; i <= WIDTH - Arrow::LEN; i += Arrow::LEN + 1) {
    for (float j = Arrow::LEN; j <= HEIGHT - Arrow::LEN; j += Arrow::LEN + 1) {
      arrows.push_back(Arrow{i, j, 0});
    }
  }
  std::sort(arrows.begin(), arrows.end(), [](const Arrow& a, const Arrow& b) {
    return std::pow(a.x, 2) + std::pow(a.y, 2) >
           std::pow(b.x, 2) + std::pow(b.y, 2);
  });

  std::getchar();

  sf::Font font;
  if (!font.loadFromFile("resources/typed.ttf"))
    return EXIT_FAILURE;
  sf::Text text("", font, 15);
  text.setFillColor(sf::Color(255, 255, 255, 255));
  text.setPosition(10, 10);

  while (running) {
    handle_input();
    update();
    redraw();

    window.draw(text);
    window.display();
  }

  return 0;
}

void handle_input() {
  sf::Event event;

  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      running = false;
    } else if (event.type == sf::Event::KeyPressed &&
               event.key.code != sf::Keyboard::Key::Unknown) {
      keys[event.key.code] = true;
    } else if (event.type == sf::Event::KeyReleased &&
               event.key.code != sf::Keyboard::Key::Unknown) {
      keys[event.key.code] = false;
    } else if (event.type == sf::Event::MouseMoved) {
    } else if (event.type == sf::Event::MouseButtonPressed) {
    } else if (event.type == sf::Event::MouseButtonReleased) {
    } else if (event.type == sf::Event::MouseWheelMoved) {
    }
  }
}

void update() {
  float cnt = 0;
  for (auto& arrow : arrows) {
    cnt++;
    arrow.angle += cnt / 300;
    if (arrow.angle >= 360.0)
      arrow.angle -= 360.0;
  }
}

void redraw() {
  sf::RectangleShape line;
  line.setSize(sf::Vector2f(2, Arrow::LEN));
  line.setOrigin(sf::Vector2f(1, Arrow::LEN / 2));

  window.clear(sf::Color::Black);

  for (const auto& arrow : arrows) {
    line.setPosition(arrow.x, arrow.y);
    line.setRotation(arrow.angle);

    sf::Uint8 c = sf::Uint8(255 / 360.0 * (int(arrow.angle * 2) % 360));
    if (int(arrow.angle) % 360 >= 180) {
      c = 255 - c;
    }
    line.setFillColor(sf::Color(c, c, c));
    window.draw(line);
  }
}
