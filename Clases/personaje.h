#ifndef PROYECTO_INFOII_PERSONAJE1_H
#define PROYECTO_INFOII_PERSONAJE1_H

#include <SFML/Graphics.hpp>
#include <queue>
#include <stack>
#include "LinkedList.h"
#include "Animator.h"
#include "Coin.h"
#include "Vida.h"

using namespace std;

enum estados {
    JUMPING,
    FALLING,
    IDLE,
    RUNNING,
};
class Personaje {
private:
    float gravityAcceleration = 9.8;
    int x, y;
    bool goingLeft;
    float speedY, speedX;
    estados state;
    Animator anim;
    sf::Vector2f oldPos;

    sf::Sprite sp;
    sf::Texture tx;
    /*// VIDA PERSONAJE
    Vida *vi;
    stack<Vida *> vida;
    sf::Font font;
    sf::Text life;
    sf::Text porVida;*/

public:
    Personaje(int x, int y, const sf::Texture &tx);

    sf::Texture &getTexture();

    void dibujar(sf::RenderWindow &w);

    void moverDerecha(float deltaTime);

    void moverIzquierda(float deltaTime);

    void move(float deltaTime);

    sf::Vector2f getPos() const;

    bool getLeft();

    void colisiones(LinkedList<sf::Rect<float> *> list, float deltaTime);

    void setSpeedvalue(float speedvalue);

    bool getJumping();

    // COINS
    bool isCollindingWhithCoin(Coin *coin){
        if(anim.getGlobalBounds().contains(coin->getPosition())){
            return true;
        }
        return false;
    }

};

#endif //PROYECTO_INFOII_PERSONAJE1_H