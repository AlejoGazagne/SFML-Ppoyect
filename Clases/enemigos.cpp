#include "enemigos.h"

Enemigos::Enemigos(){
    vidas = 3;
    tEnemy = new sf::Texture;
    sEnemy = new sf::Sprite;

    tEnemy->loadFromFile("assets/enemigo.png");
    sEnemy->setTexture(*tEnemy);

    sEnemy->setOrigin(((float)sEnemy->getTexture()->getSize().x)/2,((float)sEnemy->getTexture()->getSize().y)/2);

}
void Enemigos::mover(const float& dt, float y, float x, LinkedList<sf::Rect<float> *> list){
    float Posx = x;
    float Posy = y;

    oldPos.x = sEnemy->getPosition().x;
    oldPos.y = sEnemy->getPosition().y;

    if(this->getSprite().getPosition().x < x){
        this->sEnemy->move(1.f * this->movementSpeed * dt, 0.f * this->movementSpeed * dt);
    }
    if(this->getSprite().getPosition().x > x){
        this->sEnemy->move(-1.f * this->movementSpeed * dt, 0.f * this->movementSpeed * dt);
    }
    if(this->getSprite().getPosition().y < y - 8){
        this->sEnemy->move(0.f * this->movementSpeed * dt, 1.f * this->movementSpeed * dt);
    }
    if(this->getSprite().getPosition().y > y - 8){
        this->sEnemy->move(-0.f * this->movementSpeed * dt, -1.f * this->movementSpeed * dt);
    }

    sf::Rect<float> *miRectangulo;

    for(int ii = 0; ii < list.getSize(); ii++){
        miRectangulo = list.get(ii);
        if(sEnemy->getGlobalBounds().intersects(*miRectangulo)){
            sEnemy->setPosition(oldPos);
        }
    }

    Posx = x - this->sEnemy->getPosition().x;
    Posy = y - this->sEnemy->getPosition().y;

}

int Enemigos::getVidas(){
    return vidas;
}

int Enemigos::setVidas(int v) {
    vidas = vidas - v;
}

sf::Sprite &Enemigos::getSprite() {
    return *sEnemy;
}

sf::Texture &Enemigos::getTexture() {
    return *tEnemy;
}

/*void Enemigos::dibujar(sf::RenderWindow &w) {
    w.draw(*sEnemy);
}*/