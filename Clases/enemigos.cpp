#include "enemigos.h"

Enemigos::Enemigos(const sf::Texture &tx, std::stack<sf::Vector2<float> * > enemigos) : x(x), y(y), tx(tx) {
    oldPos.x = x;
    oldPos.y = y;
    sp.setTexture(tx);
    sp.setOrigin(sp.getGlobalBounds().width/2, sp.getGlobalBounds().height/2);
    sp.setPosition(x, y);
}

void Enemigos::dibujar(sf::RenderWindow &w) {
    w.draw(sp);

}

void Enemigos::colision(LinkedList<sf::Rect<float> *> list, float deltaTime) {
    sf::Rect<float> *miRectangulo;

    // Para movimientos en Y
    speedY -= gravityAcceleration * deltaTime;
    oldPos = sp.getPosition();
    sp.move(0, -speedY);
    for (int ii = 0; ii < list.getSize(); ii++) {
        miRectangulo = list.get(ii);
        if (sp.getGlobalBounds().intersects(*miRectangulo)) {
            sp.setPosition(oldPos);
            /*if (state == JUMPING) {
                state = FALLING;
            } else if (state == FALLING) {
                state = IDLE;
            }*/
            speedY = 0;
        }
    }

    // Para movimientos en X
    oldPos = sp.getPosition();
    /*if(state != JUMPING && state!= FALLING){
        if(speedX!=0)
            state = RUNNING;
        else
            state = IDLE;
    }*/
    sp.move(speedX, 0);
    speedX = 0;
    for (int ii = 0; ii < list.getSize(); ii++) {
        miRectangulo = list.get(ii);
        if (sp.getGlobalBounds().intersects(*miRectangulo)) {
            sp.setPosition(oldPos);
        }
    }
}