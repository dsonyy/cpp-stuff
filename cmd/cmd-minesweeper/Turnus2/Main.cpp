#include <iostream>

#include "DisplayCmd.h"
#include "DisplayAllegro.h"
#include "ControlAllegro.h"
#include "Engine.h"

int main(int argc, char ** argv)
{
	DisplayCmd display;
	//ControlAllegro control;
	Engine engine(&display/*, &control*/);


	engine.Init();

	return 0;

}
