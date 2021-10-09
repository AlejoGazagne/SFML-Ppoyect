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

