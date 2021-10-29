#include <SFML/Graphics.hpp>

class Animacion {
public:
    Animacion(sf::Texture * texture , sf::Vector2u imageCount,float switchTime );
    void Update(int row , float deltaTime);



public:
sf::IntRect uvRect;

private:
    sf::Vector2u Imagecount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;





};


