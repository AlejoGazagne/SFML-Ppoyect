#include "personaje.h"
#include <cmath>
#include <iostream>

Personaje::Personaje(int x, int y, float ang, const sf::Texture &tx) : x(x), y(y), tx(tx) {
    oldPos.x = x;
    oldPos.y = y;
    speedX = 0;
    state = IDLE;
    sp.setTexture(tx);
    sp.setOrigin(sp.getGlobalBounds().width / 2, sp.getGlobalBounds().height / 2);
    sp.setRotation(ang);
    sp.setPosition(x, y);
}

void Personaje::dibujar(sf::RenderWindow &w) {
    w.draw(sp);
#ifdef DEBUG
    sf::RectangleShape cuadrado({sp.getGlobalBounds().width, sp.getGlobalBounds().height});
    cuadrado.setPosition({sp.getGlobalBounds().left, sp.getGlobalBounds().top});
    cuadrado.setOutlineColor(sf::Color::Green);
    cuadrado.setOutlineThickness(2);
    cuadrado.setFillColor(sf::Color::Transparent);
    w.draw(cuadrado);
#endif
}

void Personaje::colisiones(LinkedList<sf::Rect<float> *> list, float deltaTime) {
    sf::Rect<float> *miRectangulo;

    // Para movimientos en Y
    speedY -= gravityAcceleration * deltaTime;
    oldPos = sp.getPosition();
    sp.move(0, -speedY);
    for (int ii = 0; ii < list.getSize(); ii++) {
        miRectangulo = list.get(ii);
        if (sp.getGlobalBounds().intersects(*miRectangulo)) {
            chocando = true;
            sp.setPosition(oldPos);
            if (state == JUMPING ) {
                state = FALLING;
            }else if(state == FALLING) {
                state = IDLE;
            }
            speedY = 0;
        }
    }

    // Para movimientos en X
    oldPos = sp.getPosition();
    sp.move(speedX, 0);
    speedX = 0;
    for (int ii = 0; ii < list.getSize(); ii++) {
        miRectangulo = list.get(ii);
        if (sp.getGlobalBounds().intersects(*miRectangulo)) {
            chocando = true;
            sp.setPosition(oldPos);
        }
    }
}

void Personaje::moverDerecha(float deltaTime) {
    speedX = 200 * deltaTime;
    ang = 0;
    sp.setScale(1, 1);
}

void Personaje::moverIzquierda(float deltaTime) {
    speedX = -200 * deltaTime;
    ang = 180;
    sp.setScale(-1, 1);
}

sf::Vector2f Personaje::getPos() const {
    return sp.getPosition();
}

float Personaje::getAng() {
    return ang;
}

void Personaje::setSpeedvalue(float speedvalue) {
    Personaje::speedY = speedvalue;
    state = JUMPING;
}

bool Personaje::isChocando() const {
    return chocando;
}

void Personaje::move(float deltaTime) {
}

bool Personaje::getJumping() {
    return state == JUMPING;
}
