#include <cmath>
#include <iostream>
#include "enemigos.h"
#include "Ataque.h"

Ataque::Ataque(sf::Vector2f pos, bool left, const sf::Texture &tx) {
    //posx = sp.getPosition().x;
    //posy = sp.getPosition().y;
    sp.setOrigin(sp.getGlobalBounds().width /2, sp.getGlobalBounds().height/2 );
    this->left = left;
    if (left)
        sp.scale(-1, 1);
    sp.setPosition(pos.x, pos.y-7);
    sp.setTexture(tx);
    timeout = 200;
}

bool Ataque::dibujar(sf::RenderWindow &w, LinkedList<sf::Rect<float> *> list, LinkedList<Enemigos*> enemy) {
    w.draw(sp);
    sf::Rect<float> *miRectangulo;
    sf::Rect<float> enemigo;

    for(list.iterInit(); !list.iterEnd(); list.iterNext()){
        miRectangulo = list.iterGet();

        if(sp.getGlobalBounds().intersects(*miRectangulo)){
            return true;
        }
    }
    for(int ii = 0; ii < enemy.getSize();ii++){
        enemigo = enemy.get(ii)->getSprite().getGlobalBounds();
        if (sp.getGlobalBounds().intersects(enemigo)) {
            //std::cout << "Choqué Enemigo" << std::endl;
            enemy.get(ii)->setVidas(1);
            //enemy.restarVida();
            return true;
        }
    }
    return false;
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

/*int Ataque::getTimeout() const {
    return timeout;
}*/