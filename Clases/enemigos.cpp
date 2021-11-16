#include "enemigos.h"

Enemigos::Enemigos(){
    tEnemy = new sf::Texture;
    sEnemy = new sf::Sprite;

    tEnemy->loadFromFile("assets/enemigo.png");
    sEnemy->setTexture(*tEnemy);

    sEnemy->setOrigin(((float)sEnemy->getTexture()->getSize().x)/2,((float)sEnemy->getTexture()->getSize().y)/2);

}
void Enemigos::mover(const float& dt, float y, float x){
    float posX;
    float posY;
    float angle;

    if(this->getSprite().getPosition().x < x){
        this->sEnemy->move(1.f * this->movementSpeed * dt, 0.f * this->movementSpeed * dt);
    }
    if(this->getSprite().getPosition().x > x){
        this->sEnemy->move(-1.f * this->movementSpeed * dt, 0.f * this->movementSpeed * dt);
    }
    if(this->getSprite().getPosition().y < y){
        this->sEnemy->move(0.f * this->movementSpeed * dt, 1.f * this->movementSpeed * dt);
    }
    if(this->getSprite().getPosition().y > y){
        this->sEnemy->move(-0.f * this->movementSpeed * dt, -1.f * this->movementSpeed * dt);
    }

    posX = x - this->sEnemy->getPosition().x;
    posY = y - this->sEnemy->getPosition().y;
    //angle = -atan2(posX,posY) * 180 / 3.14159;

    this->sEnemy->setRotation(angle);
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