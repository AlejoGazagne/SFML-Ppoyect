#ifndef PERSONAJE_H_VIDA_H
#define PERSONAJE_H_VIDA_H
#include "SFML/Graphics.hpp"

class Vida {
private:
    sf::Vector2f pos;
    sf::Texture *tx_vida;
    sf::Sprite *sp_vida;
public:
    Vida(float x, float y);
    ~Vida();
    void draw(sf::RenderWindow &window);
    sf::Sprite &getSprite ();
    sf::Texture &getTexture ();
    void setPos(float x, float y);
};




#endif //PERSONAJE_H_VIDA_H
