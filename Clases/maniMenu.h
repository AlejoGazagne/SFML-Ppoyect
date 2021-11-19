#ifndef MAIN_CPP_MANIMENU_H
#define MAIN_CPP_MANIMENU_H

#include "SFML/Graphics.hpp"
#include "../main.h"
#include <string>

#define MAX_NUMBER_OF_ITEMS 3

class maniMenu {

public:
    maniMenu(float width, float height);
    state events(sf::Event e);
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();

private:
    state selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Texture texture1;
    sf::Sprite image1;
};


#endif //MAIN_CPP_MANIMENU_H
