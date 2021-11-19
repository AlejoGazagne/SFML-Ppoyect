#ifndef MAIN_CPP_ENEMIGOS_H
#define MAIN_CPP_ENEMIGOS_H

#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "LinkedList.h"

class Enemigos {
private:
    int movementSpeed = 45;
    int vidas;
    sf::Vector2f oldPos;
    sf::Texture *tEnemy;
    sf::Sprite *sEnemy;
public:
    Enemigos();
    sf::Sprite &getSprite ();
    sf::Texture &getTexture ();
    void dibujar(sf::RenderWindow &w);
    void mover(const float& dt, float y, float x, LinkedList<sf::Rect<float> *> list);
    int getVidas();
    int setVidas(int v);

    //void colision(LinkedList<sf::Rect<float> *> list, float deltaTime);

};


#endif //MAIN_CPP_ENEMIGOS_H
