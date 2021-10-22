#include "personaje.h"
#include <cmath>
#include <iostream>

Personaje::Personaje(int x, int y, float ang, const sf::Texture &tx) : x(x), y(y), tx(tx) {
    //ang = 0;
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
    cuadrado.setOutlineColor(sf::Color::Green);
    cuadrado.setOutlineThickness(2);
    cuadrado.setFillColor(sf::Color::Transparent);
    w.draw(cuadrado);
}

void Personaje::moverDerecha(){
    sp.move(5, 0);
    ang = 0;
    sp.setScale(1,1);
}

void Personaje::moverIzquierda(){
    sp.move(-5, 0);
    ang = 180;
    sp.setScale(-1,1);
}

sf::Vector2f Personaje::getPos() const {
    return sp.getPosition();
}

float Personaje::getAng(){
    return ang;
}

void Personaje::updateAttack() {
    if(this->attackCooldown < this->attackcooldownMax)
        this->attackCooldown += 1.f;
}

void Personaje::update() {
    this->updateAttack();
}

const bool Personaje::canAttack() {
    if(this->attackCooldown >= this->attackcooldownMax){
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Personaje::initVariables() {
    this->attackcooldownMax = 10.f;
    this->attackCooldown = this->attackcooldownMax;
}

