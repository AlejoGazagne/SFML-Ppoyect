#ifndef PROYECTO_INFOII_PERSONAJE1_H
#define PROYECTO_INFOII_PERSONAJE1_H

#include <SFML/Graphics.hpp>


class Personaje {
    int x, y;
    int velx, vely;
    sf::Sprite sp;
    sf::Texture tx;
public:
    Personaje(int x, int y, const sf::Texture &tx);
    void dibujar(sf::RenderWindow &w);
    void moverDerecha();
    void moverIzquierda();

    sf::Vector2f getPos() const;

};

#endif //PROYECTO_INFOII_PERSONAJE1_H