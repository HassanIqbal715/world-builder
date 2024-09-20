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


	void update(sf::Vector2f mousePos, sf::RenderWindow &window, void (*function)()) {
		BTN_STATE = IDLE;
		if (hover(mousePos)) {
			BTN_STATE = HOVER;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				BTN_STATE = PRESSED;
			}
		}

		switch (BTN_STATE) {
		case HOVER:
			shape.setFillColor(sf::Color::Cyan);
			break;

		case IDLE:
			shape.setFillColor(sf::Color::Black);
			break;

		case PRESSED:
			(*(function))();
			window.close();
			break;

		default:
			shape.setFillColor(sf::Color::Black);
			break;
		}
	}

	void render(sf::RenderWindow &window) {
		window.draw(shape);
		window.draw(text);
	}
};

class TitleScreen {
private:
	TitleButton playButton, settingsButton, exitButton;
	TitleText worldText, builderText;

public:
	TitleScreen() {
		playButton.setText("Play");
		settingsButton.setText("Settings");
		exitButton.setText("Exit");
		playButton.setPosition(sf::Vector2f(650, 450));
		settingsButton.setPosition(sf::Vector2f(650, 580));
		exitButton.setPosition(sf::Vector2f(650, 710));

		worldText.setText("World");
		worldText.setPosition(sf::Vector2f(665, 90));
		builderText.setText("Builder");
		builderText.setPosition(sf::Vector2f(632, 216));
	}

	void update(sf::RenderWindow &window, void(*play)(), void(*settings)(), void(*exit)()) {
		sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		playButton.update(mousePos, window, play);
		settingsButton.update(mousePos, window, settings);
		exitButton.update(mousePos, window, exit);
	}

	void render(sf::RenderWindow &window) {
		playButton.render(window);
		settingsButton.render(window);
		exitButton.render(window);
		worldText.render(window);
		builderText.render(window);
	}
};
