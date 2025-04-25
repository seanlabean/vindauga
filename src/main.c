#include "common.h"

#include "draw.h"
#include "init.h"
#include "input.h"
#include "main.h"
#include "scene.h"
#include "sound.h"

App app;

int main(int argc, char *argv[])
{
	memset(&app, 0, sizeof(App));

	initSDL();

	atexit(cleanup);

	initSounds();

	initScene();

	while (1)
	{
		prepareScene();

		doInput();

		app.delegate.logic();

		app.delegate.draw();

		presentScene();

		SDL_Delay(16);
	}

	return 0;
}
