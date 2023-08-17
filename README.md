# C/C++ stuff

## Recent projects

- **Fire** - Oldskool fire effect in SFML:

  <img src="fire/screenshots/1673106951.png" width=300> <img src="fire/screenshots/1673106956.png" width=300>

- **Fractal Trees** - just playing with fractals, recursion and SFML:

  <img src="fractal-trees/gallery/1673055665.png" width=300><img src="fractal-trees/gallery/1673055776.png" width=300><img src="fractal-trees/gallery/1673055846.png" width=300>

- **Gravity** - experiments with gravity and forces. [Youtube video](https://www.youtube.com/watch?v=3KXJqj0l5hY). Collisions are not implemented because I'm too lazy.

  Requires SFML 2.

- **Angle visualization** - a small program which visualizes quaternion rotations in real time. It waits for a stream of floating point numbers on _stdin_. Each group of 4 floats represents a single quaternion (_qw, qx, qy, qz_). The program creates an additional thread which renders OpenGL window with a box, which will be rotated if new input is received.

  Requires SFML 2.

  <img width=300 src="docs/angle.png">

- **IO Benchmark** - results:

  ```
  1) scanf:                                   648147us
  2) out-of-the-box cin:                      2640799us
  3) getline:                                 1873624us
  4) sync_with_stdio(false) cin:              1519344us
  5) sync_with_stdio(false) + cin.tie(0) cin: 1468933us
  ```

- **Yet Another Sokoban** - can be found in `sokoban` directory.

## Old projects

C++ was the first programming language which I started to learn. I uploaded here some of my old projects and exercises which survived on my computer. I think most of them were created in 2016-2018. A few were also reviewed and fixed by me later.

- **Stephen Prata - C++ Primer Plus [Polish Edition]** - my completed exercises and examples from the book.

  <img src="stephen-prata-book/book.jpg" width=200>

- **Command line** projects:

  - _Self-playing checkers_,
  - _Roguelike cave generator_,  
    <img width=500 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cave.png">
  - _Mathematic clock_,  
    <img width=500 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli17.png">
  - _Sokoban_,
  - miscellaneous (coloring console, arrows support, GUIs),
  - <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli0.png">  
    <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli2.png">  
    <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli3.png">  
    <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli4.png">  
    <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli16.png">  
    <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli14.png">  
    <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli18.png">  
  - _Ent simulator_ - an unfinished game where you are a tree,  
    <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli12.png">
  - _Hellmine_ - an unfinished roguelike game,  
    <img width="400" src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli8.png">
  - _Fireworks_ - an unfinished game where you need to click on the fireworks,  
    <img width="400" src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli9.png">
  - _Spider_ - an unfinished game where you are a spider and need to eat flies,  
    <img width="400" src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli15.png">
  - Yet another unfinished game:  
    <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli10.png">  
    <img width=400 src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli11.png">
    

- **SFML** projects:
  - _Snake_,
  - _Not Only Circles_ - renders circle from 1px height image,  
    ![](https://raw.githubusercontent.com/dsonyy/cpp-stuff/master/sfml-stuff/not-only-circles/screenshots/1.png)
    ![](https://raw.githubusercontent.com/dsonyy/cpp-stuff/master/sfml-stuff/not-only-circles/screenshots/3.png)
    ![](https://raw.githubusercontent.com/dsonyy/cpp-stuff/master/sfml-stuff/not-only-circles/screenshots/4.png)
- **Allegro** projects:
  - _Astro_,  
    <img width="400" src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/astro.png">
  - _Left Side Attack_,  
    <img width="400" src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/left.png">
  - miscellaneous (user input, rendering primitives)
- miscellaneous:
  - _Higher lower_,  
    <img width="300" src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli7.png">
  - _Name generator_,  
    <img width="300" src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli13.png">
  - _Temperature converter_.  
    <img width="300" src="https://raw.githubusercontent.com/dsonyy/cpp-learning/screenshots/cli6.png">
