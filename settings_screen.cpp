#include<SFML/Graphics.hpp>
#include "title_screen.cpp"
#include "functions.cpp"

using namespace sf;

class settingsButton {
private:
	RectangleShape shape;
	Text text;
	int shapeWidth;
	int shapeHeight;

public:
	settingsButton() {
		shapeWidth = 28;
		shapeHeight = 28;
		shape.setSize(Vector2f(shapeWidth, shapeHeight));
	}

	void setButtonColor(sf::Color color) {
		shape.setFillColor(color);
	}

	void setOutlineThickness(float thickness) {
		shape.setOutlineThickness(thickness);
	}

	void setOutlineColor(sf::Color color) {
		shape.setOutlineColor(color);
	}

	void setPosition(float x, float y) {
		shape.setPosition(Vector2f(x, y));
	}
};

class SettingsScreen {
private:
	TitleButton backButton;
	Box backgroundColorButton;

public:
	SettingsScreen() {
		backButton.setText("Back");
		backButton.setPosition(Vector2f(66, 774));
		backgroundColorButton.setText("Background Color");
		backgroundColorButton.setPosition(102, 91);
	}

	void update(RenderWindow &window, void(*titleScreen)()) {
		Vector2f mousePos = static_cast<Vector2f>(Mouse::getPosition(window));
		backButton.update(mousePos, window, titleScreen);
	}

	void render(RenderWindow &window) {
		backButton.render(window);
		backgroundColorButton.render(window);
	}
};
