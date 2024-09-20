#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;


class TitleButton {
private:
	sf::Text text;
	sf::Font font;
	sf::RectangleShape shape;

public:
	TitleButton() {
		font.loadFromFile("Fonts/font.ttf");
		text.setFont(font);
		shape.setSize(sf::Vector2f(300, 100));
		shape.setOutlineThickness(2.0f);
	}
};

class TitleScreen {

};
