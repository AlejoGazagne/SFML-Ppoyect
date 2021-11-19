#ifndef ENEMIGOS_H_COIN_H
#define ENEMIGOS_H_COIN_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "LinkedList.h"

class Coin {
public:
    Coin(float x, float y);
    void draw(sf::RenderWindow &window);
    sf::Vector2f getPosition();
private:
    sf::RectangleShape coin;
    sf::Vector2f position;
};

#endif //ENEMIGOS_H_COIN_H