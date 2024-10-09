#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.cpp"
using namespace std;
using namespace sf;

enum BUTTON_STATE {IDLE, HOVER, PRESSED};

class TitleText {
private:
	Text text;
	Font font;

public:
	TitleText() {
		font.loadFromFile("Fonts/font.ttf");
		text.setFont(font);
		text.setCharacterSize(100);
		text.setFillColor(Color::White);
	}

	void setText(string textString) {
		text.setString(textString);
	}

	void setPosition(Vector2f pos) {
		text.setPosition(pos);
	}

	void render(RenderWindow &window) {
		window.draw(text);
	}
};

class TitleButton {
private:
	Text text;
	Font font;
	RectangleShape shape;
	BUTTON_STATE BTN_STATE;
	float shapeWidth;
	float shapeHeight;

public:
	TitleButton() {
		shapeWidth = 300;
		shapeHeight = 100;
		font.loadFromFile("Fonts/font.ttf");
		text.setFont(font);
		text.setCharacterSize(40);
		text.setFillColor(Color::White);
		shape.setSize(Vector2f(shapeWidth, shapeHeight));
		shape.setOutlineThickness(2.0f);
		shape.setFillColor(Color::Black);
		shape.setOutlineColor(Color::White);
	}

	void setPosition(Vector2f pos) {
		shape.setPosition(pos);
		text.setPosition(Vector2f(pos.x + shapeWidth/2, pos.y + shape.getLocalBounds().getSize().y/3));
	}

	void setText(string textString) {
		text.setString(textString);
		auto center = text.getLocalBounds().getSize() / 2.f;
		text.setOrigin(center);
	}

	void setSize(float width, float height) {
		shape.setSize(Vector2f(width, height));
		shapeWidth = width;
		shapeHeight = height;
	}

	bool hover(Vector2f mousePos) {
		if (shape.getGlobalBounds().contains(mousePos))
			return true;
	}


	void update(Vector2f mousePos, RenderWindow &window, void (*function)(RenderWindow&)) {
		BTN_STATE = IDLE;
		if (hover(mousePos)) {
			BTN_STATE = HOVER;
			if (Mouse::isButtonPressed(Mouse::Left)) {
				BTN_STATE = PRESSED;
			}
		}

		switch (BTN_STATE) {
		case HOVER:
			shape.setFillColor(Color{80, 80, 80});
			break;

		case IDLE:
			shape.setFillColor(Color::Black);
			break;

		case PRESSED:
			(*(function))(window);
			break;

		default:
			shape.setFillColor(Color::Black);
			break;
		}
	}

	void render(RenderWindow &window) {
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
		playButton.setPosition(Vector2f(650, 450));
		settingsButton.setPosition(Vector2f(650, 580));
		exitButton.setPosition(Vector2f(650, 710));

		worldText.setText("World");
		worldText.setPosition(Vector2f(665, 90));
		builderText.setText("Builder");
		builderText.setPosition(Vector2f(632, 216));
	}

	void update(RenderWindow &window, void(*play)(RenderWindow&), void(*settings)(RenderWindow&), void(*exit)(RenderWindow&)) {
		Vector2f mousePos = static_cast<Vector2f>(Mouse::getPosition(window));

		playButton.update(mousePos, window, play);
		settingsButton.update(mousePos, window, settings);
		exitButton.update(mousePos, window, exit);
	}

	void render(RenderWindow &window) {
		playButton.render(window);
		settingsButton.render(window);
		exitButton.render(window);
		worldText.render(window);
		builderText.render(window);
	}
};
