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
    sf::FloatRect getGlobalBounds(){
        return coin.getGlobalBounds();
    }
    void setPos(sf::Vector2f newPos){
        posx = newPos.x;
        posy = newPos.y;
        coin.setPosition(newPos);
    }

private:
    sf::RectangleShape coin;
    int posx, posy;
};


#endif //ENEMIGOS_H_COIN_H
