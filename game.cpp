#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class PixelBox {
private:
	RectangleShape shape;
	RectangleShape hover_mask;
	Texture texture;

public:
	PixelBox() {
		shape.setSize(Vector2f(50, 50));
		shape.setFillColor(Color::Transparent);
		hover_mask.setSize(Vector2f(50, 50));
		texture.loadFromFile("Textures/grass.jpg");
	}
	
	void setPosition(float x, float y) {
		shape.setPosition(Vector2f(x, y));
		hover_mask.setPosition(Vector2f(x, y));
	}

	void hover(Vector2f mousePos) {
		hover_mask.setFillColor(Color::Transparent);
		if (shape.getGlobalBounds().contains(mousePos)) {
			hover_mask.setFillColor(Color{ 80, 80, 80, 100 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				shape.setTexture(&texture);
				shape.setFillColor(Color::White);
			}
		}
	}

	void render(RenderWindow& window) {
		window.draw(shape);
		window.draw(hover_mask);
	}
};

class Palette {

};

class PlayArea {
private:
	RectangleShape shape;
	PixelBox boxes[16][16];

public:
	PlayArea() {

	}
};

class game {

};
