#ifndef PERSONAJE_H_GAMEOVER_H
#define PERSONAJE_H_GAMEOVER_H

#include <SFML/Graphics.hpp>
#include "../main.h"
#include "sstream"
using namespace std;

class GameOver {
    string pantalla;
    sf::Text Olddata;
    sf::Font font;
public:
    GameOver();

    state events(sf::Event event);

    void draw(sf::RenderWindow &window);
};


#endif //PERSONAJE_H_GAMEOVER_H
