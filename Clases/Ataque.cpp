#include "Ataque.h"
#include <cmath>

Ataque::Ataque(sf::Vector2f pos, bool left, const sf::Texture &tx) {
    sp.setOrigin(sp.getGlobalBounds().width / 2, sp.getGlobalBounds().height / 2);
    this->left = left;
    if (left)
        sp.scale(-1, 1);
    sp.setPosition(pos.x, pos.y);
    sp.setTexture(tx);
    timeout = 200;
}

void Ataque::dibujar(sf::RenderWindow &w) {
    w.draw(sp);
}

void Ataque::simular() {
    sf::Vector2f newPos = sp.getPosition();
    if (left)
        newPos.x = sp.getPosition().x + -VEL_ATAQUE;
    else
        newPos.x = sp.getPosition().x + VEL_ATAQUE;
    sp.setPosition(newPos);
    timeout--;
}

int Ataque::getTimeout() const {
    return timeout;
}
