#ifndef PROYECTO_INFOII_PERSONAJE1_H
#define PROYECTO_INFOII_PERSONAJE1_H

#include <SFML/Graphics.hpp>
////////////sadasdasdasda
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

#endif //PROYECTO_INFOII_PERSONAJE1_H
