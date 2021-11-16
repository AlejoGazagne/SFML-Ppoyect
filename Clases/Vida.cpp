#include <iostream>
#include "Vida.h"
#include "SFML/Graphics.hpp"

Vida::Vida() {
    if (!font.loadFromFile("assets/letra.ttf")) {
    }
    vida[0].setFont(font);
    vida[0].setColor(sf::Color::Red);
    vida[0].setString("Vida:");
    vida[0].setPosition(sf::Vector2f(30,30));

    std::string Vidas = "4";

    vida[1].setFont(font);
    vida[1].setColor(sf::Color::Red);
    vida[1].setString(Vidas);
    vida[1].setPosition(sf::Vector2f(30,40));

}
Vida::~Vida() {

}
void Vida::draw(sf::RenderWindow &window) {

    for(int ii = 0; ii < 2; ii++){
        window.draw(vida[ii]);
    }
}