#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Box {
private: 
	RectangleShape shape;
	Text text;
	Font font;
	float shapeWidth;
	float shapeHeight;

public:
	Box() {
		shapeWidth = 470;
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

	void setText(string textString) {
		text.setString(textString);
		auto center = text.getLocalBounds().getSize() / 2.f;
		text.setOrigin(center);
	}

	void setPosition(float x, float y) {
		shape.setPosition(Vector2f(x, y));
		text.setPosition(Vector2f(x + shapeWidth/2, y + shape.getLocalBounds().getSize().y / 3));
	}

	void setSize(float width, float height) {
		shape.setSize(Vector2f(width, height));
	}

	void setOutlineThickness(float thickness) {
		shape.setOutlineThickness(thickness);
	}

	void render(RenderWindow& window) {
		window.draw(shape);
		window.draw(text);
	}
};
