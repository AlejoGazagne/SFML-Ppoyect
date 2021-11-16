#include "maniMenu.h"

maniMenu::maniMenu(float width, float height){
    if(!font.loadFromFile("assets/letra.ttf")){
        //handle error
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].getCharacterSize();
    menu[0].setString("Jugar");
    menu[0].setPosition(sf::Vector2f(width/5, height /(MAX_NUMBER_OF_ITEMS +1)*0.5));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].getCharacterSize();
    menu[1].setString("Puntajes");
    menu[1].setPosition(sf::Vector2f(width/5, height /(MAX_NUMBER_OF_ITEMS +1)*1));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].getCharacterSize();
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/5, height /(MAX_NUMBER_OF_ITEMS +1)*1.5));

    selectedItemIndex = 0;

}

maniMenu::~maniMenu(){

}

void maniMenu::draw(sf::RenderWindow &window) {
    if (!texture1.loadFromFile("assets/menu.png")) {
        //handle error;
    }
    image1.setTexture(texture1);
    window.draw(image1);

    for(int ii = 0; ii < MAX_NUMBER_OF_ITEMS; ii++){
        window.draw(menu[ii]);
    }
}

void maniMenu::MoveUp() {
    if(selectedItemIndex - 1 >= 0){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void maniMenu::MoveDown() {
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}