#include <iostream>
#include "Vida.h"
#include "SFML/Graphics.hpp"

Vida::Vida(float x, float y, sf::Texture &tx_vida) {
    sp_vida.setTexture(tx_vida);
    sp_vida.setPosition(x,y);
}

void Vida::draw(sf::RenderWindow &window) {
        window.draw(sp_vida);
}