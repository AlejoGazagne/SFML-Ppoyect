#include "Ataque.h"
#include <cmath>

Ataque::Ataque(sf::Vector2f pos, bool left, const sf::Texture &tx) {
<<<<<<< HEAD
    posx = sp.getPosition().x;
    posy = sp.getPosition().y;
    sp.setOrigin(sp.getGlobalBounds().width /2, sp.getGlobalBounds().height/2 );
    this->left = left;
    if (left)
        sp.scale(-1, 1);
    sp.setPosition(pos.x, pos.y-7);
=======
    sp.setOrigin(sp.getGlobalBounds().width / 2, sp.getGlobalBounds().height / 2);
    this->left = left;
    if (left)
        sp.scale(-1, 1);
    sp.setPosition(pos.x, pos.y);
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5
    sp.setTexture(tx);
    timeout = 200;
}

<<<<<<< HEAD
/*bool colisiones(LinkedList<sf::Rect<float> *> list, int posx){
    sf::Rect<float> *miRectangulo;

    for(int ii = 0; ii < list.getSize(); ii++){
        miRectangulo = list.get(ii);
        if(posx == miRectangulo){
            return true;
        }
    }
    return false;
}*/

bool Ataque::dibujar(sf::RenderWindow &w, LinkedList<sf::Rect<float> *> list) {
=======
void Ataque::dibujar(sf::RenderWindow &w) {
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5
    w.draw(sp);
    sf::Rect<float> *miRectangulo;

    for(int ii = 0; ii < list.getSize(); ii++){
        miRectangulo = list.get(ii);
        if(sp.getGlobalBounds().intersects(*miRectangulo)){
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

int Ataque::getTimeout() const {
    return timeout;
}
