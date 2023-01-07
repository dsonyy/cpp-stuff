#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int W = 1280;
int H = 720;

float theta = 1.0f;
float alpha = 0.3f;
int n = 4;
int k = 2;
float leaves_sz = 50.0f;

void add_leaves(vector<CircleShape>& shapes, Vector2f pos, float size) {
  auto sz = size / n;
  CircleShape leaf(sz);
  leaf.setFillColor(Color(rand() % 50, rand() % 100 + 155, rand() % 50, 60));
  leaf.setPosition(pos);
  leaf.setOrigin(sz, sz);
  shapes.push_back(leaf);
}

void add_tree(VertexArray& pts,
              vector<CircleShape>& leaves,
              Vector2f pos,
              Vector2f dir,
              int n) {
  if (n <= 0)
    return;
  if (n == 1) {
    add_leaves(leaves, pos + dir, leaves_sz);
  }

  pts.append(Vertex(pos, Color::Black));
  pts.append(Vertex(pos + dir, Color::Black));

  vector<float> angles(k, 0);
  for (int i = 0; i < k / 2; i++) {
    angles[i] = theta * (i + 1) - (k % 2 == 0 ? theta / 2 : 0);
    angles[k - i - 1] = -theta * (i + 1) + (k % 2 == 0 ? theta / 2 : 0);
  }
  for (auto angle : angles) {
    auto a = Vector2f(alpha * (dir.x * cos(angle) - dir.y * sin(angle)),
                      alpha * (dir.x * sin(angle) + dir.y * cos(angle)));
    add_tree(pts, leaves, pos + dir, a, n - 1);
  }
}

void update(RenderWindow& window) {
  srand(0);
  window.clear(Color::White);
  VertexArray pts(Lines);
  vector<CircleShape> leaves;
  add_tree(pts, leaves, Vector2f(W / 2, H), Vector2f(0, -H / 2), n);
  for (auto leaf : leaves)
    window.draw(leaf);
  window.draw(pts);
  window.display();
}

int main() {
  ContextSettings settings;
  settings.antialiasingLevel = 1.0;
  RenderWindow window(VideoMode(W, H), "Fractals", Style::Default, settings);
  // window.setFramerateLimit(30);

  update(window);
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      else if (event.type == Event::Resized) {
        W = event.size.width;
        H = event.size.height;
        FloatRect visibleArea(0, 0, W, H);
        window.setView(sf::View(visibleArea));
      } else if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)
          theta += 0.01f;
        else if (event.key.code == Keyboard::Down)
          theta -= 0.01f;
        else if (event.key.code == Keyboard::Left)
          alpha -= 0.01f;
        else if (event.key.code == Keyboard::Right)
          alpha += 0.01f;
        else if (event.key.code == Keyboard::W)
          n++;
        else if (event.key.code == Keyboard::S)
          n--;
        else if (event.key.code == Keyboard::A)
          k = max(0, k - 1);
        else if (event.key.code == Keyboard::D)
          k++;
        else if (event.key.code == Keyboard::Q)
          leaves_sz -= 0.1f;
        else if (event.key.code == Keyboard::E)
          leaves_sz += 0.1f;
        else if (event.key.code == Keyboard::Space) {
          Texture texture;
          texture.create(window.getSize().x, window.getSize().y);
          texture.update(window);
          texture.copyToImage().saveToFile(to_string(time(nullptr)) + ".png");
        }
      }
      update(window);
    }
  }
  return 0;
}
