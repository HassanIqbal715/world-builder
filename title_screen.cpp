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
		text.setCharacterSize(40);
		text.setFillColor(sf::Color::White);
		shape.setSize(sf::Vector2f(300, 100));
		shape.setOutlineThickness(2.0f);
		shape.setFillColor(sf::Color::Black);
		shape.setOutlineColor(sf::Color::White);
	}

	void setPosition(sf::Vector2f pos) {
		shape.setPosition(pos);
		text.setPosition(sf::Vector2f(pos.x + 150, pos.y + shape.getLocalBounds().getSize().y/3));
	}

	void setText(string textString) {
		text.setString(textString);
		auto center = text.getLocalBounds().getSize() / 2.f;
		text.setOrigin(center);
	}

	void render(sf::RenderWindow &window) {
		window.draw(shape);
		window.draw(text);
	}
};

class TitleScreen {

};
