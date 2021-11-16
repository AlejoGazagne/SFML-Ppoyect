#include "SFML/Graphics.hpp"

#ifndef PERSONAJE_H_VIDA_H
#define PERSONAJE_H_VIDA_H


class Vida {

public:
    Vida();
    ~Vida();

    void draw(sf::RenderWindow &window);

private:
    int max_vidas = 4;
    std::string Vidas; //lo que va a mostrar
    sf::Font font;
    sf::Text vida[2];
    sf::Texture texture1;
    sf::Sprite image1;
};




#endif //PERSONAJE_H_VIDA_H
