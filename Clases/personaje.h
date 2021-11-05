#ifndef PROYECTO_INFOII_PERSONAJE1_H
#define PROYECTO_INFOII_PERSONAJE1_H

#include <SFML/Graphics.hpp>
#include "LinkedList.h"

class Personaje {
    float gravityAcceleration = 9.8;
    int x, y;
    int velx, vely;
    float ang;
    float speedvalue;
    bool chocando;
public:
    bool isChocando() const;

private:
    sf::Vector2f oldPos;
    sf::Sprite sp;
    sf::Texture tx;

public:
    Personaje(int x, int y,float ang, const sf::Texture &tx);
    void dibujar(sf::RenderWindow &w);
    void moverDerecha(float deltaTime);
    void moverIzquierda(float deltaTime);
    void saltar(float deltaTime);
    //void gravity();
    sf::Vector2f getPos() const;
    float getAng();
    void colisiones(LinkedList<sf::Rect<float> *> list);
    void setSpeedvalue(float speedvalue);

};

#endif //PROYECTO_INFOII_PERSONAJE1_H