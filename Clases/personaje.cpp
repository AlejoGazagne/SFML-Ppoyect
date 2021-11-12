#include "personaje.h"
#include <cmath>
#include <iostream>

Personaje::Personaje(int x, int y, float ang, const sf::Texture &tx) : x(x), y(y), tx(tx) {
    oldPos.x = x;
    oldPos.y = y;
    speedX = 0;
    state = IDLE;
    anim.setTexture(tx);
    anim.setFila(6);
    anim.setColumna(8);
    anim.setFps(5);
    anim.setOrigin(anim.getGlobalBounds().width / 2, anim.getGlobalBounds().height / 2);
    anim.setRotation(ang);
    anim.setPosition(x, y);


}

void Personaje::dibujar(sf::RenderWindow &w) {
    anim.animate();
    w.draw(anim);
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
    oldPos = anim.getPosition();
    anim.move(0, -speedY);
    for (int ii = 0; ii < list.getSize(); ii++) {
        miRectangulo = list.get(ii);
        if (anim.getGlobalBounds().intersects(*miRectangulo)) {
            chocando = true;
            anim.setPosition(oldPos);
            if (state == JUMPING ) {
                state = FALLING;
            }else if(state == FALLING) {
                state = IDLE;
            }
            speedY = 0;
        }
    }

    // Para movimientos en X
    oldPos = anim.getPosition();
    anim.move(speedX, 0);
    speedX = 0;
    for (int ii = 0; ii < list.getSize(); ii++) {
        miRectangulo = list.get(ii);
        if (anim.getGlobalBounds().intersects(*miRectangulo)) {
            chocando = true;
            anim.setPosition(oldPos);
        }
    }
}

void Personaje::moverDerecha(float deltaTime) {
    speedX = 200 * deltaTime;
    ang = 0;
    anim.setScale(1, 1);
}

void Personaje::moverIzquierda(float deltaTime) {
    speedX = -200 * deltaTime;
    ang = 180;
    anim.setScale(-1, 1);
}

sf::Vector2f Personaje::getPos() const {
    return anim.getPosition();
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
