#ifndef PERSONAJE_H_PUNTAJE_H
#define PERSONAJE_H_PUNTAJE_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include "../main.h"
#include "sstream"
using namespace std;

class Puntaje {
    string pantalla;
    sf::Text Olddata;
    sf::Font font;
    int timeout;
    sf::Texture textura;
    sf::Sprite imagen;
public:
    Puntaje();

    state draw(sf::RenderWindow &window);

};


#endif //PERSONAJE_H_PUNTAJE_H
