#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

const int WIDTH = 1920 * 1;
const int HEIGHT = 1080 * 1;

sf::RenderWindow window;
bool running;
bool keys[sf::Keyboard::KeyCount] = {};
bool mouse = false;
float G = 0;

struct object {
  float r = 4;
  float x = 0;
  float y = 0;
  float vx = 0;
  float vy = 0;
  sf::Color color = sf::Color::White;
  bool alive = true;
};

std::vector<object> objects;
object hand;

void handle_input();
void update();
void redraw();
void applyForces(object&, object&);

int main(int argc, char** argv) {
  window.create(sf::VideoMode(WIDTH, HEIGHT), "Gravity",
                sf::Style::Close | sf::Style::Titlebar);
  window.setMouseCursorVisible(false);
  window.setFramerateLimit(60);
  running = true;

  sf::Font font;
  if (!font.loadFromFile("resources/typed.ttf"))
    return EXIT_FAILURE;
  sf::Text text("", font, 15);
  text.setFillColor(sf::Color(255, 255, 255, 255));
  text.setPosition(10, 10);

  objects.push_back(object{10, -100, 0, 0, 0, sf::Color::Red});
  objects.push_back(object{10, 100, 0, 0, 0, sf::Color::Blue});

  while (running) {
    handle_input();
    update();
    redraw();

    text.setString(std::to_string(G));
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
      hand.x = event.mouseMove.x - WIDTH / 2;
      hand.y = event.mouseMove.y - HEIGHT / 2;
    } else if (event.type == sf::Event::MouseButtonPressed) {
      mouse = true;
    } else if (event.type == sf::Event::MouseButtonReleased) {
      if (hand.r > 0) {
        objects.push_back(hand);
        hand = {};
      }
      mouse = false;
    } else if (event.type == sf::Event::MouseWheelMoved) {
      G += event.mouseWheel.delta * 0.5;
    }
  }
}

void update() {
  if (mouse) {
    hand.r += 0.5;
  }

  for (auto i = 0; i < objects.size(); i++) {
    if (!objects[i].alive)
      continue;

    for (auto j = i + 1; j < objects.size(); j++) {
      if (!objects[j].alive)
        continue;

      float dist2 = std::pow(objects[i].x - objects[j].x, 2) +
                    std::pow(objects[i].y - objects[j].y, 2);
      if (dist2 < objects[i].r) {
        objects[j].alive = false;
        objects[i].r += objects[j].r;
        objects[i].vx += objects[j].vx;
        objects[i].vy += objects[j].vy;
        continue;
      } else if (dist2 < objects[j].r) {
        objects[i].alive = false;
        objects[j].r += objects[i].r;
        objects[j].vx += objects[i].vx;
        objects[j].vy += objects[i].vy;
        continue;
      }

      applyForces(objects[i], objects[j]);
    }

    if (objects[i].x - objects[i].r > WIDTH / 2 ||
        objects[i].x + objects[i].r < -WIDTH / 2 ||
        objects[i].y - objects[i].r > HEIGHT / 2 ||
        objects[i].y + objects[i].r < -HEIGHT / 2) {
      objects[i].alive = false;
    }
  }

  for (auto& o : objects) {
    o.x += o.vx;
    o.y += o.vy;
  }
}

void redraw() {
  window.clear(sf::Color::Black);

  sf::CircleShape circle;
  circle.setRadius(hand.r);
  circle.setPosition(hand.x + WIDTH / 2, hand.y + HEIGHT / 2);
  circle.setOrigin(hand.r, hand.r);
  circle.setFillColor(sf::Color(255, 255, 255, 128));
  window.draw(circle);

  for (const auto& o : objects) {
    if (!o.alive)
      continue;
    sf::CircleShape circle;
    circle.setRadius(o.r);
    circle.setPosition(o.x + WIDTH / 2, o.y + HEIGHT / 2);
    circle.setOrigin(o.r, o.r);
    circle.setFillColor(o.color);

    window.draw(circle);
  }
}

void applyForces(object& a, object& b) {
  // calculate the distance from a to b
  float dist2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  float dist = std::sqrt(dist2);

  // calculate the scalar force value for a and b
  float aVal = G * b.r / dist2;
  float bVal = G * a.r / dist2;

  // calculate normalized direction vector of the force (a -> b)
  float x = (b.x - a.x) / dist;
  float y = (b.y - a.y) / dist;

  // apply forces
  a.vx += x * aVal;
  a.vy += y * aVal;
  b.vx += -x * bVal;
  b.vy += -y * bVal;
}