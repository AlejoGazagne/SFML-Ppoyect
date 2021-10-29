#include "personaje.h"
#include <cmath>
#include <iostream>

Personaje::Personaje(int x, int y, float ang, const sf::Texture &tx) : x(x), y(y), tx(tx) {
    oldPos.x = x;
    oldPos.y = y;
    velx = 0;
    vely = 0;
    sp.setTexture(tx);
    sp.setOrigin(sp.getGlobalBounds().width/2, sp.getGlobalBounds().height/2);
    sp.setRotation(ang);
    sp.setPosition(x, y);
}

void Personaje::dibujar(sf::RenderWindow &w) {
    w.draw(sp);
    sf::RectangleShape cuadrado({sp.getGlobalBounds().width, sp.getGlobalBounds().height});
    cuadrado.setPosition({sp.getGlobalBounds().left, sp.getGlobalBounds().top});
    cuadrado.setOutlineColor(sf::Color::Transparent);
    cuadrado.setOutlineThickness(2);
    cuadrado.setFillColor(sf::Color::Transparent);
    w.draw(cuadrado);
}

void Personaje::colisiones(LinkedList<sf::Rect<float> *> list){
    sf::Rect<float> *miRectangulo;

    for(int ii = 0; ii < list.getSize(); ii++){
        miRectangulo = list.get(ii);
        if(sp.getGlobalBounds().intersects(*miRectangulo)){
            sp.setPosition(oldPos);
        }
    }

}

void Personaje::moverDerecha(){
    oldPos = sp.getPosition();
    sp.move(5, 0);
    ang = 0;
    sp.setScale(1,1);

}

void Personaje::moverIzquierda(){
    oldPos = sp.getPosition();
    sp.move(-5, 0);
    ang = 180;
    sp.setScale(-1,1);
}

void Personaje::saltar(){
    oldPos = sp.getPosition();
    sp.move(0, -10);

}
void Personaje::gravity() {
    oldPos = sp.getPosition();
    sp.move(0,10);
}

sf::Vector2f Personaje::getPos() const {
    return sp.getPosition();
}

float Personaje::getAng(){
    return ang;
}
