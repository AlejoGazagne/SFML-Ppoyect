#include "enemigos.h"

Enemigos::Enemigos(){
    tEnemy = new sf::Texture;
    sEnemy = new sf::Sprite;

    tEnemy->loadFromFile("assets/juntos.png");
    sEnemy->setTexture(*tEnemy);

    sEnemy->setOrigin(((float)sEnemy->getTexture()->getSize().x)/2,((float)sEnemy->getTexture()->getSize().y)/2);

}

sf::Sprite &Enemigos::getSprite() {
    return *sEnemy;
}

sf::Texture &Enemigos::getTexture() {
    return *tEnemy;
}

void Enemigos::dibujar(sf::RenderWindow &w) {
    w.draw(*sEnemy);
}