#include "common.h"

#include "input.h"

extern App app;

static void doMouseButtonUp(SDL_MouseButtonEvent *event)
{
	app.mouse.button[event->button] = 0;
}

static void doMouseButtonDown(SDL_MouseButtonEvent *event)
{
	app.mouse.button[event->button] = 1;
}


void doInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_MOUSEBUTTONDOWN:
				doMouseButtonDown(&event.button);
				break;

			case SDL_MOUSEBUTTONUP:
				doMouseButtonUp(&event.button);
				break;

			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}

	SDL_GetMouseState(&app.mouse.x, &app.mouse.y);

}
