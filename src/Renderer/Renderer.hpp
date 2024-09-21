#ifndef RENDERER_H
#define RENDERER_H

//#define USE_SDL
//#define USE_SFML
//#define USE_WINDOWSCONSOLE

#include <tuple>
#include <string>
#include <iostream>
#include <map>
#include "../Core/Vector2.hpp"
#include "Transform2D.hpp"

#ifdef USE_WINDOWSCONSOLE
#include <iomanip>
#include <windows.h>
#endif

#ifdef USE_SDL
#include "../LibSDL/SDL.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#endif

#ifdef USE_SFML
#include <SFML/Graphics.hpp>
#include <string>
#include <tuple>
#include <vector>
#endif
typedef enum FilterMode_s{
    nearestNeighbor,
    linear
    //bilinear
    //trilinear
    //anisotropic
}FilterMode;
typedef enum WrapMode_s{
    repeat,
    clamp
    //mirror
}WrapMode;
class Renderer
{
public:
    static void initialize();
    static void destroy();
    static void clear();
    static void display();
    static void loadTexture(std::string path);
    static void loadFont(std::string path);
    static void draw();
    static void draw(std::string imageName);
    static void draw(std::string imageName,Transform2D& transform,Vector2 normalizedOrigin=Vector2());
    static void drawRow(void *row, int size);
    static void drawText(std::string text, std::string fontName, int fontSize, Vector2 pos);
    static Vector2 getResolution();
    static std::map<std::string,std::string> imageFormats;
    static std::map<std::string,std::string> fontFormats;
#ifdef USE_WINDOWSCONSOLE
    static HANDLE buffer;
#endif
#ifdef USE_SDL
    static std::map<std::string, SDL_Texture*> images;
    static std::map<std::string, TTF_Font*> fonts;

    static SDL_Window *window;
    static SDL_Renderer *renderer;
#endif

#ifdef USE_SFML
    static sf::RenderWindow window;
    static std::map<std::string, sf::Texture> images;
    static std::map<std::string, sf::Font> fonts;
#endif
};

#endif