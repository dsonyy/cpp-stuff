#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <thread>
#include <algorithm>

bool quit = false;

// Box rotation variables
float rotation[4] = {};
sf::Mutex rotationMutex;

void input() {
    float tempRotation[4] = {};

    while (!quit) {
        std::cin >> tempRotation[0] >> tempRotation[1] >> tempRotation[2] >> tempRotation[3];

        rotationMutex.lock();
        rotation[0] = tempRotation[0];
        rotation[1] = tempRotation[1];
        rotation[2] = tempRotation[2];
        rotation[3] = tempRotation[3];
        rotationMutex.unlock();
    }
}

void createCuboid(GLfloat* c, GLfloat x, GLfloat y, GLfloat z) {
    const size_t len = 5 * 3 * 2 * 6;
    GLfloat v[len] = {
        -x, -y, -z,  0, 0,
        -x,  y, -z,  1, 0,
        -x, -y,  z,  0, 1,
        -x, -y,  z,  0, 1,
        -x,  y, -z,  1, 0,
        -x,  y,  z,  1, 1,

         x, -y, -z,  0, 0,
         x,  y, -z,  1, 0,
         x, -y,  z,  0, 1,
         x, -y,  z,  0, 1,
         x,  y, -z,  1, 0,
         x,  y,  z,  1, 1,

        -x, -y, -z,  0, 0,
         x, -y, -z,  1, 0,
        -x, -y,  z,  0, 1,
        -x, -y,  z,  0, 1,
         x, -y, -z,  1, 0,
         x, -y,  z,  1, 1,

        -x,  y, -z,  0, 0,
         x,  y, -z,  1, 0,
        -x,  y,  z,  0, 1,
        -x,  y,  z,  0, 1,
         x,  y, -z,  1, 0,
         x,  y,  z,  1, 1,

        -x, -y, -z,  0, 0,
         x, -y, -z,  1, 0,
        -x,  y, -z,  0, 1,
        -x,  y, -z,  0, 1,
         x, -y, -z,  1, 0,
         x,  y, -z,  1, 1,

        -x, -y,  z,  0, 0,
         x, -y,  z,  1, 0,
        -x,  y,  z,  0, 1,
        -x,  y,  z,  0, 1,
         x,  y,  z,  1, 1,
         x, -y,  z,  1, 0,
    }; 

    std::copy(v, v + len, c);
}

int main()
{
    // Run the thread responsible for reading input
    auto inputThread = std::thread(&input);

    // Define a 3D cube (6 faces made of 2 triangles composed by 3 vertices)
    GLfloat cube[5 * 3 * 2 * 6];
    createCuboid(cube, 15, 25, 30);

    // Request a 24-bits depth buffer when creating the window
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(600, 600), "Angle Visualization", sf::Style::Close | sf::Style::Titlebar, contextSettings);
    window.setVerticalSyncEnabled(true);

    // Create some text to draw on top of our OpenGL object
    sf::Font font;
    if (!font.loadFromFile("resources/typed.ttf"))
        return EXIT_FAILURE;
    sf::Text text("", font, 15);
    text.setFillColor(sf::Color(0, 0, 0, 255));
    text.setPosition(10, 10);

    // Load a texture to apply to our 3D cube
    sf::Texture texture;
    if (!texture.loadFromFile("resources/texture.jpg"))
        return EXIT_FAILURE;

    // Attempt to generate a mipmap for our cube texture
    // We don't check the return value here since
    // mipmapping is purely optional in this example
    texture.generateMipmap();

    // Make the window the active window for OpenGL calls
    window.setActive(true);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(1.f);

    // Disable lighting
    glDisable(GL_LIGHTING);

    // Configure the viewport (the same size as the window)
    glViewport(0, 0, window.getSize().x, window.getSize().y);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

    // Bind the texture
    glEnable(GL_TEXTURE_2D);
    sf::Texture::bind(&texture);

    // Enable position and texture coordinates vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cube);
    glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), cube + 3);

    // Disable normal and color vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    // Make the window no longer the active window for OpenGL calls
    window.setActive(false);

    // Create a clock for measuring the time elapsed
    sf::Clock clock;

    // Start game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: quit
            if (event.type == sf::Event::Closed)
            {
                quit = true;
                window.close();
            }

            // Escape key: quit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                quit = true;
                window.close();
            }

            // Adjust the viewport when the window is resized
            if (event.type == sf::Event::Resized)
            {
                // Make the window the active window for OpenGL calls
                window.setActive(true);

                glViewport(0, 0, event.size.width, event.size.height);

                // Make the window no longer the active window for OpenGL calls
                window.setActive(false);
            }
        }

        // Draw the background
        window.pushGLStates();
        window.clear(sf::Color::White);
        window.popGLStates();

        // Make the window the active window for OpenGL calls
        window.setActive(true);

        // Clear the depth buffer
        glClear(GL_DEPTH_BUFFER_BIT);

        // Apply some transformations
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0, 0, -100.f);
        rotationMutex.lock();
        glRotatef(rotation[0], rotation[1], rotation[2], rotation[3]);

        // Update text
        text.setString(
            "qw:\t" + std::to_string(rotation[0]) +
            "\nqx:\t" + std::to_string(rotation[1]) +
            "\nqy:\t" + std::to_string(rotation[2]) +
            "\nqz:\t" + std::to_string(rotation[3]));
        rotationMutex.unlock();

        // Draw the cube
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Make the window no longer the active window for OpenGL calls
        window.setActive(false);

        // Draw some text on top of our OpenGL object
        window.pushGLStates();
        window.draw(text);
        window.popGLStates();

        // Finally, display the rendered frame on screen
        window.display();
    }

    // Join the thread which waits for input
    inputThread.join();

    return EXIT_SUCCESS;
}
