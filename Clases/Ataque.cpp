#include "Ataque.h"
#include "enemigos.h"
#include <cmath>
#include <iostream>

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
    sf::Vector2f *enemigo;
    //sf::Rect<float> enemigo;
    Enemigos *enem;
    sf::Sprite en;

    for(int ii = 0; ii < list.getSize(); ii++){
        miRectangulo = list.get(ii);
        en = enem->getSprite();
        sf::Rect<float> enemigo;

        for(list.iterInit(); !list.iterEnd(); list.iterNext()){
            miRectangulo = list.iterGet();

            if(sp.getGlobalBounds().intersects(*miRectangulo)){
                return true;
            }

            if(sp.getGlobalBounds().intersects(en.getGlobalBounds())){
            }
            for(enemy.iterInit(); !enemy.iterEnd(); enemy.iterNext()){
                enemigo = enemy.iterGet()->getSprite().getGlobalBounds();
                if (sp.getGlobalBounds().intersects(enemigo)) {
                    std::cout << "Choqué Enemigo" << std::endl;
                    // enemy.restarVida();
                    return true;
                }
            }
            return false;
        }
    }
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
