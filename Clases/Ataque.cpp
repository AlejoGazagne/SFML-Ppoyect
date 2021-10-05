//
// Created by lauty on 5/10/2021.
//

#include "Ataque.h"
#include <math.h>

Ataque::Ataque(int x , int y , float angulo , const sf::Texture &tx) : angulo(angulo) {

sp.setTexture(tx);
sp.setPosition(x,y);
sp.rotate(angulo);
}
void Ataque :: dibujar(sf::RenderWindow &w) {
    w.draw(sp);
}
void Ataque::simular() {
    angulo=0;
    sf::Vector2f newPos;
    newPos.x = sp.getPosition().x * VEL_ATAQUE * cos(sp.getRotation()/360 * M_PI * 2);
    newPos.y = sp.getPosition().y * VEL_ATAQUE * sin(sp.getRotation()/ 360 * M_PI * 2);
    sp.setPosition(newPos);
}