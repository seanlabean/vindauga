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
//static SDL_Texture *text_texture;
static SDL_Rect r;
int drawRect = 0;
TTF_Font *font;

SDL_Surface *text;
// Set color to white
SDL_Color color = { 255, 255, 255 };

int sceneCounter = 0;
char sceneText[100];

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

    font = TTF_OpenFont("font/Roboto-Regular.ttf", 20);
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
            strcpy(sceneText,"Welcome to Vindauga. Left-click to delve deeper, right-click to step back.");
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
            strcpy(sceneText,"( As she turns to face you, she smiles lightly. )");
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
            strcpy(sceneText,"'Hey, kid. Having fun yet?' ( Wisps of smoke curl around the brim of his hat. )");
            drawRect = 0;
            break;
        case 11:
            sceneTexture = scene11Texture;
            strcpy(sceneText,"bleh.");
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
        SDL_Delay(150);
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

    // text = TTF_RenderText_Solid( font, "Hello World!", color );

    // text_texture = SDL_CreateTextureFromSurface( app.renderer, text );
    
    // SDL_Rect dest2 = { 0, 0, text->w, text->h };
    
    // SDL_RenderCopy( app.renderer, text_texture, NULL, &dest2 );
    // SDL_FreeSurface(text);
    // SDL_DestroyTexture(text_texture);

    //this opens a font style and sets a size
    // TTF_Font* Sans = TTF_OpenFont("font/Heyam.ttf", 24);

    // this is the color in rgb format,
    // maxing out all would give you the color white,
    // and it will be your text's color
    SDL_Color White = {255, 255, 255};

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    SDL_Surface* surfaceMessage =
        TTF_RenderText_Solid(font, sceneText, White); 

    // now you can convert it into a texture
    SDL_Texture* Message = SDL_CreateTextureFromSurface(app.renderer, surfaceMessage);

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 20;  //controls the rect's x coordinate 
    Message_rect.y = SCREEN_HEIGHT - 100; // controls the rect's y coordinte
    Message_rect.w = surfaceMessage->w; // controls the width of the rect
    Message_rect.h = surfaceMessage->h; // controls the height of the rect

    // (0,0) is on the top left of the window/screen,
    // think a rect as the text's box,
    // that way it would be very simple to understand

    // Now since it's a texture, you have to put RenderCopy
    // in your game loop area, the area where the whole code executes

    // you put the renderer's name first, the Message,
    // the crop size (you can ignore this if you don't want
    // to dabble with cropping), and the rect which is the size
    // and coordinate of your texture
    SDL_RenderCopy(app.renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);

    if (drawRect == 1)
    {
        SDL_SetRenderDrawColor( app.renderer, 255, 0, 0, 255 );

        // Render rect
        SDL_RenderDrawRect( app.renderer, &r );

        // Render the rect to the screen - This causes previously rendered sceneTexture to flicker onto screen briefly for some reason. - SCL
        //SDL_RenderPresent(app.renderer);
    }
}