#ifndef ENEMIGOS_H_COIN_H
#define ENEMIGOS_H_COIN_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "LinkedList.h"

class Coin {
public:
    Coin(sf::Vector2f size){
        coin.setSize(size);
        coin.setFillColor(sf::Color::Yellow);
    }
    void draw(sf::RenderWindow &window){
        window.draw(coin);
    }
    sf::Vector2f getPosition(){
        return coin.getPosition();
    }
    void setPos(sf::Vector2f newPos){
        coin.setPosition(newPos);
    }

private:
    sf::RectangleShape coin;
    int posx, posy;
};


#endif //ENEMIGOS_H_COIN_H
