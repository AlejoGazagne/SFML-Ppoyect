#ifndef PROYECTO_INFOII_PERSONAJE1_H
#define PROYECTO_INFOII_PERSONAJE1_H

#include <SFML/Graphics.hpp>
#include <queue>
#include "LinkedList.h"
#include "Animator.h"
#include "Coin.h"

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
    // Vidas
    queue<int> vida;
    sf::Texture tx_Vida;
    sf::Sprite image_Vida;

public:
    Personaje(int x, int y, const sf::Texture &tx);
    int vidas;

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
        if(anim.getGlobalBounds().intersects(coin->getGlobalBounds())){
            return true;
        }
        return false;
    }

    //FUNCION VIDA
    //FUNCIONES DE VIDA

    void Setvidas(int value){
        vidas += value;
    }
    int Getvidas(){
        return vidas;
    }

//Mostrar vidas
    void Mostrar(sf::RenderWindow &window ){

        window.setVerticalSyncEnabled(true);

        sf::Text texto;
        sf::String cadena;
        cadena = "La vida es:";

        texto.setString(cadena);
        texto.setCharacterSize(40);
        texto.setPosition(400,300);
        texto.rotate(20);

        window.draw(texto);
        window.display();

    }





};

#endif //PROYECTO_INFOII_PERSONAJE1_H