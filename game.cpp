#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;

enum TextureToPlace { GRASS, BOX, BOX_damaged, CROSS };

class PixelBox {
private:
	RectangleShape shape;
	RectangleShape hover_mask;

public:
	PixelBox() {
		shape.setSize(Vector2f(50, 50));
		shape.setFillColor(Color::Transparent);
		shape.setTexture(NULL);
		hover_mask.setSize(Vector2f(50, 50));
	}
	
	void setPosition(float x, float y) {
		shape.setPosition(Vector2f(x, y));
		hover_mask.setPosition(Vector2f(x, y));
	}
	
	void hover(Vector2f mousePos, TextureToPlace textureToPlace, Texture* textures) {
		hover_mask.setFillColor(Color::Transparent);
		if (shape.getGlobalBounds().contains(mousePos)) {
			hover_mask.setFillColor(Color{ 80, 80, 80, 100 });
			if (Mouse::isButtonPressed(Mouse::Left)) {
				shape.setFillColor(Color::White);
				if (textureToPlace == GRASS) {
					shape.setTexture(&textures[0]);
				}
				else if (textureToPlace == BOX) {
					shape.setTexture(&textures[1]);
				}
				else if (textureToPlace == BOX_damaged) {
					shape.setTexture(&textures[2]);
				}
				else if (textureToPlace == CROSS) {
					shape.setFillColor(Color::Transparent);
					shape.setTexture(NULL);
				}
			}
		}
	}

	void setTexture(Texture &texture) {
		shape.setTexture(&texture);
	}

	void render(RenderWindow& window) {
		window.draw(shape);
		window.draw(hover_mask);
	}
};

class TextureBox {
private:
	RectangleShape shape;
	Texture texture;
	TextureToPlace textureToPlace;

public:
	TextureBox() {
		shape.setSize(Vector2f(50,50));
		shape.setFillColor(Color::White);
	}

	void setTexture(Texture &texture) {
		shape.setTexture(&texture);
	}

	void setPosition(float x, float y) {
		shape.setPosition(Vector2f(x, y));
	}

	void update(Vector2f mousePos, TextureToPlace &textureToPlace) {
		if (shape.getGlobalBounds().contains(mousePos)) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				textureToPlace = this->textureToPlace;
			}
		}
	}

	void setTextureToPlace(TextureToPlace texture) {
		textureToPlace = texture;
	}

	void render(RenderWindow& window) {
		window.draw(shape);
	}
};

class Palette {
private:
	RectangleShape shape;
	TextureBox textureBoxes[4];
	Texture textures[4];

public:
	Palette() {
		shape.setSize(Vector2f(400, 900));
		shape.setPosition(Vector2f(1200, 0));
		shape.setFillColor(Color::Transparent);
		shape.setOutlineColor(Color::White);
		shape.setOutlineThickness(1);

		textures[0].loadFromFile("Textures/grass.jpg");
		textures[1].loadFromFile("Textures/Box.png");
		textures[2].loadFromFile("Textures/Box_damaged.png");
		textures[3].loadFromFile("Textures/redCross.png");

		textureBoxes[0].setTextureToPlace(GRASS);
		textureBoxes[1].setTextureToPlace(BOX);
		textureBoxes[2].setTextureToPlace(BOX_damaged);
		textureBoxes[3].setTextureToPlace(CROSS);

		for (int i = 0; i < 4; i++) {
			textureBoxes[i].setTexture(textures[i]);
			textureBoxes[i].setPosition(1200 + i * 50, 0);
		}
	}

	void update(RenderWindow& window, Vector2f mousePos, TextureToPlace &textureToPlace) {
		for (int i = 0; i < 4; i++) {
			textureBoxes[i].update(mousePos, textureToPlace);
		}
	}

	void render(RenderWindow& window) {
		window.draw(shape);
		for (int i = 0; i < 4; i++) {
			textureBoxes[i].render(window);
		}
	}
};

class PlayArea {
private:
	RectangleShape shape;
	PixelBox Boxes[16][16];

public:
	PlayArea() {
		shape.setSize(Vector2f(800, 800));
		shape.setPosition(Vector2f(332, 51));
		shape.setOutlineColor(Color::White);
		shape.setOutlineThickness(1);
		shape.setFillColor(Color::Transparent);
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				Boxes[i][j].setPosition(332 + j * 50, 51 + i * 50);
			}
		}
	}

	void update(RenderWindow& window, Vector2f mousePos, TextureToPlace textureToPlace, Texture* textures) {
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				Boxes[i][j].hover(mousePos, textureToPlace, textures);
			}
		}
	}

	RectangleShape getPlayArea() {
		return shape;
	}

	void render(RenderWindow& window) {
		window.draw(shape);
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				Boxes[i][j].render(window);
			}
		}
	}
};

class Play {
private:
	PlayArea playArea;
	Palette palette;
	TextureToPlace textureToPlace;
	Texture textures[4];

public:

	Play() {
		textures[0].loadFromFile("Textures/grass.jpg");
		textures[1].loadFromFile("Textures/Box.png");
		textures[2].loadFromFile("Textures/Box_damaged.png");
		textures[3].loadFromFile("Textures/redCross.png");
	}

	void update(RenderWindow& window) {
		Vector2f mousePos = static_cast<Vector2f>(Mouse::getPosition(window));
		playArea.update(window, mousePos, textureToPlace, textures);

		palette.update(window, mousePos, textureToPlace);
	}

	void render(RenderWindow& window) {
		playArea.render(window);
		palette.render(window);
	}
};
