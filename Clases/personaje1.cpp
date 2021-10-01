#include "personaje1.h"

Personaje1::Personaje1(int x, int y, const sf::Texture &tx) : x(x), y(y), tx(tx) {
    velx = 0;
    vely = 0;
    sp.setTexture(tx);
    sp.setPosition(x, y);
}

void Personaje1::dibujar(sf::RenderWindow &w) {
    w.draw(sp);
}

void Personaje1::moverDerecha(){
    sp.move(5, 0);
}

void Personaje1::moverIzquierda(){
    sp.move(-5, 0);
}

