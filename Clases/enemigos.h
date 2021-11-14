#ifndef MAIN_CPP_ENEMIGOS_H
#define MAIN_CPP_ENEMIGOS_H

#include <SFML/Graphics.hpp>
#include "LinkedList.h"

class Enemigos {
private:
    float gravityAcceleration = 9.8;
    int x, y;
    float speedY, speedX;
    sf::Vector2f oldPos;

    sf::Texture *tEnemy;
    sf::Sprite *sEnemy;
public:
    Enemigos();

    sf::Sprite &getSprite ();
    sf::Texture &getTexture ();
    void dibujar(sf::RenderWindow &w);

    void colision(LinkedList<sf::Rect<float> *> list, float deltaTime);


};


#endif //MAIN_CPP_ENEMIGOS_H
