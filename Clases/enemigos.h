#ifndef MAIN_CPP_ENEMIGOS_H
#define MAIN_CPP_ENEMIGOS_H

#include <SFML/Graphics.hpp>
#include <stack>
#include "LinkedList.h"

class Enemigos {
private:
    float gravityAcceleration = 9.8;
    int x, y;
    float speedY, speedX;
    sf::Vector2f oldPos;
    sf::Sprite sp;
    sf::Texture tx;
public:
    Enemigos(const sf::Texture &tx, std::stack<sf::Vector2<float> * > enemigos);

    void dibujar(sf::RenderWindow &w);

    void colision(LinkedList<sf::Rect<float> *> list, float deltaTime);


};


#endif //MAIN_CPP_ENEMIGOS_H
