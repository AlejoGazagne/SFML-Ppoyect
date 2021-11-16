#include "Coin.h"
Coin::Coin(sf::Vector2f size){
    coin.setSize(size);
    coin.setFillColor(sf::Color::Yellow);
}
void Coin::draw(sf::RenderWindow &window){
    window.draw(coin);
}
sf::Vector2f Coin::getPosition(){
    return coin.getPosition();
}
/*void Coin::setPos(sf::Vector2f newPos){
    coin.setPosition(newPos);
}*/