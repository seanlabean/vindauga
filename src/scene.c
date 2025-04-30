#include "common.h"
#include "draw.h"
#include "sound.h"

extern App app;
extern StoryBoard storyboard;

static void draw(void);
static void logic(void);
static void doScene(void);
static void drawScene(void);

static SDL_Texture *startTexture;
static SDL_Texture *startTexture2;
static SDL_Texture *scene1Texture;
static SDL_Texture *scene2Texture;
static SDL_Texture *scene3Texture;
static SDL_Texture *scene4Texture;
static SDL_Texture *scene4Texture2;
static SDL_Texture *sceneTexture;
static SDL_Rect r;
int drawRect = 0;

int sceneCounter = 0;

void initScene(void)
{
    app.delegate.logic = logic;
    app.delegate.draw = draw;

    startTexture = loadTexture("gfx/startScene.png");
    startTexture2 = loadTexture("gfx/startScene2.png");
    scene1Texture = loadTexture("gfx/girlScene.png");
    scene2Texture = loadTexture("gfx/starScene.png");
    scene3Texture = loadTexture("gfx/stationScene.png");
    scene4Texture = loadTexture("gfx/cowboy1.png");
    scene4Texture2 = loadTexture("gfx/cowboy2.png");

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", "music/welcome.ogg");
	loadMusic("music/welcome.ogg");

	playMusic(1);
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "playing music");
}

static void draw(void)
{
    drawScene();
}

static void logic(void)
{
    doScene();
}

static void doScene(void)
{
    srand(time(NULL));
    int nRandonNumber = rand()%((10+1)-1) + 1;
    switch (sceneCounter)
    {
        case 0:

            if (nRandonNumber <= 5)
            {
                sceneTexture = startTexture;
            } else
            {
                sceneTexture = startTexture2;
            }
            int xmax = 340; int xmin = 280; int ymax = 760; int ymin = 650;
            if (app.mouse.x > xmin && app.mouse.x < xmax && app.mouse.y > ymin && app.mouse.y < ymax)
            {
                if (DEBUG)
                {
                    drawRect = 1;
                    r.x = xmin;
                    r.y = ymin;
                    r.w = xmax-xmin;
                    r.h = ymax-ymin;
                }

                if (app.mouse.button[SDL_BUTTON_LEFT])
                {
                    sceneCounter = 1;
                }
            }
            else if (app.mouse.x > SCREEN_WIDTH/1.5 && app.mouse.x < SCREEN_WIDTH && app.mouse.y < SCREEN_HEIGHT/3 && app.mouse.button[SDL_BUTTON_LEFT])
            {
                sceneCounter = 2;
            }
            else if (app.mouse.x > SCREEN_WIDTH/2.5 && app.mouse.x < SCREEN_WIDTH/1.75 && app.mouse.y < SCREEN_HEIGHT/2.5 && app.mouse.button[SDL_BUTTON_LEFT])
            {
                sceneCounter = 3;
            }
            else if (app.mouse.x < 100 && app.mouse.y < 650 && app.mouse.y > 550 && app.mouse.button[SDL_BUTTON_LEFT])
            {
                sceneCounter = 4;
            } 
            else
            {
                drawRect = 0;
            }
            break;
        case 1:
            sceneTexture = scene1Texture;
            drawRect = 0;
            break;
        case 2:
            sceneTexture = scene2Texture;
            break;
        case 3:
            sceneTexture = scene3Texture;
            break;
        case 4:
            if (nRandonNumber <=5)
            {
                sceneTexture = scene4Texture;
            } else
            {
                sceneTexture = scene4Texture2;
            }
            break;
        default:
            sceneTexture = startTexture;
            sceneCounter = 0;


    }

    if (app.mouse.button[SDL_BUTTON_RIGHT])
    {
        SDL_RenderClear(app.renderer);
        sceneTexture = startTexture;
        sceneCounter = 0;
    }
}

static void drawScene(void)
{
    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.w = SCREEN_WIDTH;
    dest.h = SCREEN_WIDTH; //SCREEN_HEIGHT/2;

    SDL_RenderCopy(app.renderer, sceneTexture, NULL, &dest);

    if (drawRect == 1)
    {
        SDL_SetRenderDrawColor( app.renderer, 255, 0, 0, 255 );

        // Render rect
        SDL_RenderDrawRect( app.renderer, &r );

        // Render the rect to the screen - This causes previously rendered sceneTexture to flicker onto screen briefly for some reason. - SCL
        //SDL_RenderPresent(app.renderer);
    }

}