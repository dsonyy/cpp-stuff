# Snake

It's a simple clone of popular snake games. The program was created using high-level graphic library called SFML.
You control your snake using arrows. The snake is growing up all the time. It also speed up when you eat apples.

The game was tested only using Visual Studio for Windows but the code should also works on other systems
supported by SFML.

## Installation

This guide describes installation for SFML with Visual C++ 15 (2017). While you are reading this, it is possible that newer versions
are available.

Be sure that SFML and Visual C++ Compiler have to match 100%, Otherwise there will be lots of errors.


### What do you need:
- Visual Studio, with v141 platform toolset and Windows SDK 10.0.15063.0 (read below)
- SFML 32-bit, compatible with v141 (Visual C++ 15 (2017))


### Download Links:
- SFML: https://www.sfml-dev.org
- Visual Studio: https://www.visualstudio.com/


### Prepare Visual Studio:
- Make sure that you have installed VS2017 (v141) platform toolset in your Visual Studio.
- Make sure that you have installed Windows SDK 10.0.15063.0 in your Visual Studio.

To check it go to Visual Studio Installer -> Individual Components 
to find (and install) above components. 

In my case there wasn't proper Windows SDK version
so I downloaded it manually from here: https://developer.microsoft.com/en-us/windows/downloads/sdk-archive


### Prepare project with SFML:
1. Download project.
2. Get SFML 32-bit from link above.
3. Copy unpacked SFML archive to the main project directory.
4. Be sure that SFML folder is named just 'SFML' not 'SFML-X.X.X' etc.


### Compiling and running:
If you successfully install SFML, open .sln file and build project in Debug or Release mode.

If you cannot compile project and there are lots of unresolved symbol errors or another strange things, something is wrong
and you should check again versions of platform toolsets, windows SDK and SFML.

In Debug mode (with dynamic linking) you have to copy dlls from SFML/bin to the folder with exe file.
Release mode uses static linking so you don't have to do that.

If you want to run this application on a computer without Visual C++ 2017 Runtime packages, 
you have to provide msvcp140.dll and vcruntime140.dll aside an EXE application.

### References:
 - SFML with Visual Studio installation guide: https://www.sfml-dev.org/tutorials/2.5/start-vc.php

