#ifndef PROYECTO_INFOII_PERSONAJE1_H
#define PROYECTO_INFOII_PERSONAJE1_H

#include <SFML/Graphics.hpp>
#include "LinkedList.h"
#include "Animator.h"

enum estados {
    JUMPING,
    FALLING,
    IDLE,
    RUNNING,
};

class Personaje {
    float gravityAcceleration = 9.8;
    int x, y;
    bool goingLeft;
    float speedY, speedX;
    bool chocando;
    estados state;
    Animator anim;
public:
    bool isChocando() const;

private:
    sf::Vector2f oldPos;
    sf::Sprite sp;
    sf::Texture tx;

public:
    Personaje(int x, int y, float ang, const sf::Texture &tx);

    void dibujar(sf::RenderWindow &w);

    void moverDerecha(float deltaTime);

    void moverIzquierda(float deltaTime);

    void move(float deltaTime);

    //void gravity();
    sf::Vector2f getPos() const;

    bool getLeft();

    void colisiones(LinkedList<sf::Rect<float> *> list, float deltaTime);

    void setSpeedvalue(float speedvalue);

    bool getJumping();
};

#endif //PROYECTO_INFOII_PERSONAJE1_H