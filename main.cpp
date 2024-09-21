#include <SFML/Graphics.hpp>
#include "settings_screen.cpp"
using namespace sf; 

Color Background_Color = Color::Black;
int window_size_x = 1600;
int window_size_y = 900;

void titleWindow();
void playWindow();
void settingsWindow();
void exitWindow();

int main() {
	titleWindow();
}

void titleWindow() {
	TitleScreen title;
	RenderWindow window(VideoMode(window_size_x, window_size_y), "World Builder", Style::Close | Style::Resize);
	Event event;
	window.setFramerateLimit(30);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
			}
			title.update(window, &playWindow, &settingsWindow, &exitWindow);
			window.clear(Background_Color);
			title.render(window);
			window.display();
		}
	}
}

void playWindow() {
	cout << "Play";
}

void settingsWindow() {
	SettingsScreen settings;
	RenderWindow window(VideoMode(window_size_x, window_size_y), "World Builder", Style::Close | Style::Resize);
	Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
			}
			settings.update(window, &titleWindow, Background_Color, window_size_x, window_size_y);
			window.clear(Background_Color);
			settings.render(window);
			window.display();
		}
	}
}

void exitWindow() {
	cout << "Exit";
}
