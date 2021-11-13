#include "personaje.h"
#include <cmath>
#include <iostream>

Personaje::Personaje(int x, int y, const sf::Texture &tx) : x(x), y(y), tx(tx) {
    oldPos.x = x;
    oldPos.y = y;
    speedX = 0;
    state = IDLE;
    anim.setTexture(tx);
    anim.setFila(6);
    anim.setColumna(8);
    anim.setFps(5);
    anim.setOrigin(anim.getGlobalBounds().width / 2, anim.getGlobalBounds().height / 2);
    anim.setPosition(x, y);

}

void Personaje::dibujar(sf::RenderWindow &w) {
    if (state == RUNNING)
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

    if (!tx_Vida.loadFromFile("assets/heart.png")) {
        cout << "No se pudo cargar juntos.png" << endl;
    }
    image_Vida.setTexture(tx_Vida);
    int h = 10;
    for(int ii = 0; ii < 4;ii++){
        image_Vida.setPosition(h, 20);
        w.draw(image_Vida);
        h = h + 40;
    }

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
            anim.setPosition(oldPos);
            if (state == JUMPING) {
                state = FALLING;
            } else if (state == FALLING) {
                state = IDLE;
            }
            speedY = 0;
        }
    }

    // Para movimientos en X
    oldPos = anim.getPosition();
    if(state != JUMPING && state!= FALLING){
        if(speedX!=0)
            state = RUNNING;
        else
            state = IDLE;
    }
    anim.move(speedX, 0);
    speedX = 0;
    for (int ii = 0; ii < list.getSize(); ii++) {
        miRectangulo = list.get(ii);
        if (anim.getGlobalBounds().intersects(*miRectangulo)) {
            anim.setPosition(oldPos);
        }
    }
}

void Personaje::moverDerecha(float deltaTime) {
    speedX = 200 * deltaTime;
    goingLeft = false;
    anim.setScale(1, 1);
}

void Personaje::moverIzquierda(float deltaTime) {
    speedX = -200 * deltaTime;
    goingLeft = true;
    anim.setScale(-1, 1);
}

sf::Vector2f Personaje::getPos() const {
    return anim.getPosition();
}

bool Personaje::getLeft() {
    return goingLeft;
}

void Personaje::setSpeedvalue(float speedvalue) {
    Personaje::speedY = speedvalue;
    state = JUMPING;
}

void Personaje::move(float deltaTime) {
}

bool Personaje::getJumping() {
    return state == JUMPING;
}
