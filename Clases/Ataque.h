#ifndef PERSONAJE1_H_ATAQUE_H
#define PERSONAJE1_H_ATAQUE_H
#include <SFML/Graphics.hpp>

#define VEL_ATAQUE 18

class Ataque {
private:
    sf::Sprite sp;
    int timeout;
    bool left;
public:
    void dibujar(sf::RenderWindow &w);
    Ataque(sf::Vector2f pos, bool left, const sf::Texture &tx);
    void simular();
    int getTimeout() const;
};


#endif //PERSONAJE1_H_ATAQUE_H
