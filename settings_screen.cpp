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
	BUTTON_STATE BTN_STATE;
	Color idleColor;

public:
	settingsButton() {
		shapeWidth = 50;
		shapeHeight = 50;
		shape.setSize(Vector2f(shapeWidth, shapeHeight));
	}

	void setButtonColor(sf::Color color) {
		shape.setFillColor(color);
		idleColor = color;
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

	void setSize(float width, float height) {
		shapeWidth = width;
		shapeHeight = height;
		shape.setSize(Vector2f(shapeWidth, shapeHeight));
	}

	bool hover(Vector2f mousePos) {
		if (shape.getGlobalBounds().contains(mousePos))
			return true;
	}

	void Click(Vector2f mousePos) {
		BTN_STATE = IDLE;
		if (hover(mousePos)) {
			BTN_STATE = HOVER;
			if (Mouse::isButtonPressed(Mouse::Left)) {
				BTN_STATE = PRESSED;
			}
		}
	}

	void updateBackgroundColor(Vector2f mousePos, Color &backgroundColor, Color color) {
		Click(mousePos);
		if (BTN_STATE == PRESSED) {
			backgroundColor = color;
		}
	}

	void render(RenderWindow &window) {
		window.draw(shape);
		window.draw(text);
	}
};

class SettingsScreen {
private:
	TitleButton backButton;
	Color bgPinkClr, bgOrangeClr, bgYellowClr, bgGreenClr, bgBlueClr, bgPurpleClr, bgWhiteClr, bgBlackClr;
	settingsButton bgPink, bgOrange, bgYellow, bgGreen, bgBlue, bgPurple, bgWhite, bgBlack;
	settingsButton textRed, textOrange, textYellow, textGreen, textBlue, textPurple, textWhite, textBlack;
	Box backgroundColorBox;

public:
	SettingsScreen() {
		backButton.setText("Back");
		backButton.setPosition(Vector2f(66, 774));
		backgroundColorBox.setText("Background Color");
		backgroundColorBox.setPosition(102, 91);

		bgPinkClr = Color{ 255, 165, 165 };
		bgOrangeClr = Color{ 255, 192, 70 };
		bgYellowClr = Color{ 252, 255, 121 };
		bgGreenClr = Color{ 127, 255, 132 };
		bgBlueClr = Color{ 165, 201, 255 };
		bgPurpleClr = Color{ 199, 165, 255 };
		bgWhiteClr = Color{ 255, 255, 255 };
		bgBlackClr = Color{ 0, 0, 0 };

		bgPink.setButtonColor(bgPinkClr);
		bgOrange.setButtonColor(bgOrangeClr);
		bgYellow.setButtonColor(bgYellowClr);
		bgGreen.setButtonColor(bgGreenClr);
		bgBlue.setButtonColor(bgBlueClr);
		bgPurple.setButtonColor(bgPurpleClr);
		bgWhite.setButtonColor(bgWhiteClr);
		bgBlack.setButtonColor(bgBlackClr);

		bgPink.setPosition(600, 116);
		bgOrange.setPosition(678, 116);
		bgYellow.setPosition(756, 116);
		bgGreen.setPosition(834, 116);
		bgBlue.setPosition(912, 116);
		bgPurple.setPosition(990, 116);
		bgWhite.setPosition(1068, 116);
		bgBlack.setPosition(1146, 116);
	}

	void update(RenderWindow &window, void(*titleScreen)(), Color &backgroundColor) {
		Vector2f mousePos = static_cast<Vector2f>(Mouse::getPosition(window));
		backButton.update(mousePos, window, titleScreen);

		bgPink.updateBackgroundColor(mousePos, backgroundColor, bgPinkClr);
		bgOrange.updateBackgroundColor(mousePos, backgroundColor, bgOrangeClr);
		bgYellow.updateBackgroundColor(mousePos, backgroundColor, bgYellowClr);
		bgGreen.updateBackgroundColor(mousePos, backgroundColor, bgGreenClr);
		bgBlue.updateBackgroundColor(mousePos, backgroundColor, bgBlueClr);
		bgPurple.updateBackgroundColor(mousePos, backgroundColor, bgPurpleClr);
		bgWhite.updateBackgroundColor(mousePos, backgroundColor, bgWhiteClr);
		bgBlack.updateBackgroundColor(mousePos, backgroundColor, bgBlackClr);
	}

	void render(RenderWindow &window) {
		backButton.render(window);
		backgroundColorBox.render(window);
		bgPink.render(window);
		bgOrange.render(window);
		bgYellow.render(window);
		bgGreen.render(window);
		bgBlue.render(window);
		bgPurple.render(window);
		bgWhite.render(window);
		bgBlack.render(window);
	}
};
