#ifndef PERSONAJE_H_VIDA_H
#define PERSONAJE_H_VIDA_H

#include "SFML/Graphics.hpp"

class Vida {
private:
    sf::Sprite sp_vida;
public:
    Vida(float x, float y, sf::Texture &tx_vida);
    void draw(sf::RenderWindow &window);
};


#endif //PERSONAJE_H_VIDA_H
