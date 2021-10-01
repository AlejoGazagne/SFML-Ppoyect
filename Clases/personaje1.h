#ifndef PROYECTO_INFOII_PERSONAJE1_H
#define PROYECTO_INFOII_PERSONAJE1_H

#include <SFML/Graphics.hpp>

class Personaje1 {
    int x, y;
    int velx, vely;
    sf::Sprite sp;
    sf::Texture tx;
public:
    Personaje1(int x, int y, const sf::Texture &tx);
    void dibujar(sf::RenderWindow &w);
    void moverDerecha();
    void moverIzquierda();

};

#endif //PROYECTO_INFOII_PERSONAJE1_H