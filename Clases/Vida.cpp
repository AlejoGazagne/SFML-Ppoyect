#include <iostream>
#include "Vida.h"
#include "SFML/Graphics.hpp"

Vida::Vida(float x, float y) {
    pos.x = x;
    pos.y = y;

    tx_vida = new sf::Texture;
    sp_vida = new sf::Sprite;

    tx_vida->loadFromFile("assets/heart.png");
    sp_vida->setTexture(*tx_vida);
}
Vida::~Vida() {

}
void Vida::draw(sf::RenderWindow &window) {
    for(int ii = 0; ii < 2; ii++){
        window.draw(*sp_vida);
    }
}
sf::Sprite &Vida::getSprite() {
    return *sp_vida;
}

sf::Texture &Vida::getTexture() {
    return *tx_vida;
}
void Vida::setPos(float x, float y){
    pos.x = x;
    pos.y = y;
    sp_vida->setPosition(x, y);
}