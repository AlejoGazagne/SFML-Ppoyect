#include "Coin.h"

Coin::Coin(float x, float y){
    position.x = x;
    position.y = y;
    coin.setSize({20, 20});
    coin.setFillColor(sf::Color::Yellow);
    coin.setPosition(x, y);
}

void Coin::draw(sf::RenderWindow &window){
    window.draw(coin);
}

sf::Vector2f Coin::getPosition(){
    return coin.getPosition();
}
