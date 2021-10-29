#ifndef PROYECTO_INFOII_PERSONAJE1_H
#define PROYECTO_INFOII_PERSONAJE1_H

#include <SFML/Graphics.hpp>
#include "LinkedList.h"

class Personaje {
    int x, y;
    int velx, vely;
    float ang;
    sf::Vector2f oldPos;
    sf::Sprite sp;
    sf::Texture tx;

public:
    Personaje(int x, int y,float ang, const sf::Texture &tx);
    void dibujar(sf::RenderWindow &w);
    void moverDerecha();
    void moverIzquierda();
    void saltar();
    void gravity();
    sf::Vector2f getPos() const;
    float getAng();
    void colisiones(LinkedList<sf::Rect<float> *> list);

};

#endif //PROYECTO_INFOII_PERSONAJE1_H