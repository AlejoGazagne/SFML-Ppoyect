#ifndef PERSONAJE1_H_ATAQUE_H
#define PERSONAJE1_H_ATAQUE_H
#include <SFML/Graphics.hpp>

#define VEL_ATAQUE 6.5

class Ataque {
private:
    sf::Sprite sp;
    int timeout;
public:
    void dibujar(sf::RenderWindow &w);
    Ataque(sf::Vector2f pos, const sf::Texture &tx);
    void simular();

    int getTimeout() const;
};


#endif //PERSONAJE1_H_ATAQUE_H
