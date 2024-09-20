#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;

enum BUTTON_STATE {IDLE, HOVER, PRESSED};

class TitleText {
private:
	sf::Text text;
	sf::Font font;

public:
	TitleText() {
		font.loadFromFile("Fonts/font.ttf");
		text.setFont(font);
		text.setCharacterSize(100);
		text.setFillColor(sf::Color::White);
	}

	void setText(string textString) {
		text.setString(textString);
	}

	void setPosition(sf::Vector2f pos) {
		text.setPosition(pos);
	}

	void render(sf::RenderWindow &window) {
		window.draw(text);
	}
};

class TitleButton {
private:
	sf::Text text;
	sf::Font font;
	sf::RectangleShape shape;
	BUTTON_STATE BTN_STATE;

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

	bool hover(sf::Vector2f mousePos) {
		if (shape.getGlobalBounds().contains(mousePos))
			return true;
	}

	void update(sf::Vector2f mousePos) {
		BTN_STATE = IDLE;
		if (hover(mousePos)) {
			BTN_STATE = HOVER;
		}

		switch (BTN_STATE) {
		case HOVER:
			shape.setFillColor(sf::Color::Cyan);
			break;

		case IDLE:
			shape.setFillColor(sf::Color::Black);
			break;

		default:
			shape.setFillColor(sf::Color::Black);
		}
	}

	void render(sf::RenderWindow &window) {
		window.draw(shape);
		window.draw(text);
	}
};

class TitleScreen {

};
