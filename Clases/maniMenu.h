#ifndef MAIN_CPP_MANIMENU_H
#define MAIN_CPP_MANIMENU_H

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4

class maniMenu {

public:
    maniMenu(float width, float height);
    ~maniMenu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {return selectedItemIndex;}
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Texture texture1;
    sf::Sprite image1;
};


#endif //MAIN_CPP_MANIMENU_H
