#include "maniMenu.h"

maniMenu::maniMenu(float width, float height) {
    if (!font.loadFromFile("assets/letra.ttf")) {
        //handle error
    }
    if (!texture1.loadFromFile("assets/menu.png")) {
        //handle error;
    }
    image1.setTexture(texture1);

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].getCharacterSize();
    menu[0].setString("Jugar");
    menu[0].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 0.5));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].getCharacterSize();
    menu[1].setString("Puntajes");
    menu[1].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].getCharacterSize();
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.5));

    selectedItemIndex = JUEGO;

}


void maniMenu::draw(sf::RenderWindow &window) {
    for (auto &ii : menu) {
        ii.setFillColor(sf::Color::Black);
    }
    switch (selectedItemIndex) {
        case JUEGO:
            menu[0].setFillColor(sf::Color::Red);
            break;
        case TABLE:
            menu[1].setFillColor(sf::Color::Red);
            break;
        case EXIT:
            menu[2].setFillColor(sf::Color::Red);
            break;
    }

    window.clear();
    window.draw(image1);

    for (const auto &ii : menu) {
        window.draw(ii);
    }
    window.display();
}

void maniMenu::MoveUp() {
    switch (selectedItemIndex) {
        case TABLE:
            selectedItemIndex = JUEGO;
            break;
        case EXIT:
            selectedItemIndex = TABLE;
            break;
        default:
            break;
    }
}

void maniMenu::MoveDown() {
    switch (selectedItemIndex) {
        case JUEGO:
            selectedItemIndex = TABLE;
            break;
        case TABLE:
            selectedItemIndex = EXIT;
            break;
        default:
            break;
    }
}

state maniMenu::events(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyReleased:
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    MoveUp();
                    break;
                case sf::Keyboard::Down:
                    MoveDown();
                    break;
                case sf::Keyboard::Return:
                    // ver que paso
                    return selectedItemIndex;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    return MENU;
}