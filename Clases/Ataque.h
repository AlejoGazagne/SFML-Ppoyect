#include <SFML/Graphics.hpp>

#ifndef PERSONAJE1_H_ATAQUE_H
#define PERSONAJE1_H_ATAQUE_H

#define VEL_ATAQUE 2.0

class Ataque {
private:
    sf::Sprite sp;
float angulo;
float velocidad;
public:

    void dibujar(sf::RenderWindow &w);

    Ataque(int x , int y , float angulo , const sf::Texture &tx);

    void simular();
};


#endif //PERSONAJE1_H_ATAQUE_H
