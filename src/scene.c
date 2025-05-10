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
static SDL_Texture *scene11Texture;
static SDL_Texture *sceneTexture;
static SDL_Rect r;
int drawRect = 0;

int sceneCounter = 0;

int history[MAX_HISTORY];
int history_top = 0;

void push_scene(int oldScene) {
    if (history_top < MAX_HISTORY) {
        history[history_top++] = oldScene;
    }
}

int pop_scene(void) {
    if (history_top > 0) {
        return history[--history_top];
    }
    else {
        return 0;
    }
}

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
    scene11Texture = loadTexture("gfx/mouthEyeScene.png");

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
    struct Clickable c0_1 = {340, 260, 760, 650};
    struct Clickable c0_2 = {660, 540, 240, 120};
    struct Clickable c0_3 = {400, 280, 260, 140};
    struct Clickable c0_4 = {100, 20, 660, 580};

    struct Clickable c1_1 = {360, 240, 530, 480};
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
            
            if (app.mouse.x > c0_1.xmin && app.mouse.x < c0_1.xmax && app.mouse.y > c0_1.ymin && app.mouse.y < c0_1.ymax)
            {
                if (DEBUG)
                {
                    drawRect = 1;
                    r.x = c0_1.xmin;
                    r.y = c0_1.ymin;
                    r.w = c0_1.xmax-c0_1.xmin;
                    r.h = c0_1.ymax-c0_1.ymin;
                }

                if (app.mouse.button[SDL_BUTTON_LEFT])
                {
                    push_scene(sceneCounter);
                    sceneCounter = 1;
                }
            }
            else if (app.mouse.x > c0_2.xmin && app.mouse.x < c0_2.xmax && app.mouse.y > c0_2.ymin && app.mouse.y < c0_2.ymax)
            {
                if (DEBUG)
                {
                    drawRect = 1;
                    r.x = c0_2.xmin;
                    r.y = c0_2.ymin;
                    r.w = c0_2.xmax-c0_2.xmin;
                    r.h = c0_2.ymax-c0_2.ymin;
                }

                if (app.mouse.button[SDL_BUTTON_LEFT])
                {
                    sceneCounter = 2;
                }
            }
            else if (app.mouse.x > c0_3.xmin && app.mouse.x < c0_3.xmax && app.mouse.y > c0_3.ymin && app.mouse.y < c0_3.ymax)
            {
                if (DEBUG)
                {
                    drawRect = 1;
                    r.x = c0_3.xmin;
                    r.y = c0_3.ymin;
                    r.w = c0_3.xmax-c0_3.xmin;
                    r.h = c0_3.ymax-c0_3.ymin;
                }

                if (app.mouse.button[SDL_BUTTON_LEFT])
                {
                    sceneCounter = 3;
                }
            }
            else if (app.mouse.x > c0_4.xmin && app.mouse.x < c0_4.xmax && app.mouse.y > c0_4.ymin && app.mouse.y < c0_4.ymax)
            {
                if (DEBUG)
                {
                    drawRect = 1;
                    r.x = c0_4.xmin;
                    r.y = c0_4.ymin;
                    r.w = c0_4.xmax-c0_4.xmin;
                    r.h = c0_4.ymax-c0_4.ymin;
                }

                if (app.mouse.button[SDL_BUTTON_LEFT])
                {
                    sceneCounter = 4;
                }
            }
            else
            {
                drawRect = 0;
            }
            break;
        case 1:
            sceneTexture = scene1Texture;
            if (app.mouse.x > c1_1.xmin && app.mouse.x < c1_1.xmax && app.mouse.y > c1_1.ymin && app.mouse.y < c1_1.ymax)
            {
                if (DEBUG)
                {
                    drawRect = 1;
                    r.x = c1_1.xmin;
                    r.y = c1_1.ymin;
                    r.w = c1_1.xmax-c1_1.xmin;
                    r.h = c1_1.ymax-c1_1.ymin;
                }

                if (app.mouse.button[SDL_BUTTON_LEFT])
                {
                    push_scene(sceneCounter);
                    sceneCounter = 11;
                }
            }
            else
            {
                drawRect = 0;
            }
            break;
        case 2:
            sceneTexture = scene2Texture;
            drawRect = 0;
            break;
        case 3:
            sceneTexture = scene3Texture;
            drawRect = 0;
            break;
        case 4:
            if (nRandonNumber <=5)
            {
                sceneTexture = scene4Texture;
            } else
            {
                sceneTexture = scene4Texture2;
            }
            drawRect = 0;
            break;
        case 11:
            sceneTexture = scene11Texture;
            drawRect = 0;
            break;
        default:
            sceneTexture = startTexture;
            sceneCounter = 0;


    }

    if (app.mouse.button[SDL_BUTTON_RIGHT])
    {
        SDL_RenderClear(app.renderer);
        sceneCounter = pop_scene();
        SDL_Delay(100);
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