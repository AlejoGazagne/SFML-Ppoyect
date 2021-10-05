#include "personaje.h"

Personaje::Personaje(int x, int y, const sf::Texture &tx) : x(x), y(y), tx(tx) {
    velx = 0;
    vely = 0;
    sp.setTexture(tx);
    sp.setPosition(x, y);
}

void Personaje::dibujar(sf::RenderWindow &w) {
    w.draw(sp);
}

void Personaje::moverDerecha(){
    sp.move(5, 0);
}

void Personaje::moverIzquierda(){
    sp.move(-5, 0);
}

sf::Vector2f Personaje::getPos() const {
    return sp.getPosition();
}

