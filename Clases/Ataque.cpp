#include "Ataque.h"
#include <cmath>

Ataque::Ataque(sf::Vector2f pos, float ang, const sf::Texture &tx){
    sp.setRotation(ang);
    sp.setPosition(pos.x, pos.y);
    sp.setTexture(tx);
    timeout = 200;
}
void Ataque :: dibujar(sf::RenderWindow &w) {
    w.draw(sp);
}
void Ataque::simular() {
    sf::Vector2f newPos;
    newPos.x = sp.getPosition().x + VEL_ATAQUE * cos(sp.getRotation()/360 * M_PI * 2);
    newPos.y = sp.getPosition().y + VEL_ATAQUE * sin(sp.getRotation()/ 360 * M_PI * 2);
    sp.setPosition(newPos);
    timeout--;
}

int Ataque::getTimeout() const {
    return timeout;
}
