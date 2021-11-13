#ifndef PERSONAJE1_H_ATAQUE_H
#define PERSONAJE1_H_ATAQUE_H
#include <SFML/Graphics.hpp>
#include "LinkedList.h"

#define VEL_ATAQUE 18

class Ataque {
private:
    int posx;
    int posy;
    sf::Sprite sp;
    int timeout;
    bool left;
public:
    bool dibujar(sf::RenderWindow &w, LinkedList<sf::Rect<float> *> list);
    Ataque(sf::Vector2f pos, bool left, const sf::Texture &tx);
    void simular();
    int getTimeout() const;
};


#endif //PERSONAJE1_H_ATAQUE_H
