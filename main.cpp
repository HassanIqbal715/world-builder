#include <SFML/Graphics.hpp>
#include "settings_screen.cpp"
using namespace sf; 

Color Background_Color = Color::Black;
int window_size_x = 1600;
int window_size_y = 900;

void titleWindow(RenderWindow&);
void playWindow(RenderWindow&);
void settingsWindow(RenderWindow& window);
void exitWindow(RenderWindow& window);

int main() {
	RenderWindow window(VideoMode(window_size_x, window_size_y), "World Builder", Style::Close | Style::Resize);
	window.setFramerateLimit(30);
	titleWindow(window);
}

void titleWindow(RenderWindow& window) {
	window.clear();
	TitleScreen title;
	Event event;
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

void playWindow(RenderWindow& window) {
	cout << "Play";
	window.clear(Background_Color);
	window.setFramerateLimit(60);
	Play play;
	Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
			}
			play.update(window);
			window.clear(Background_Color); 
			play.render(window);
			window.display();
		}
	}
}

void settingsWindow(RenderWindow& window) {
	window.clear();
	SettingsScreen settings;
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

void exitWindow(RenderWindow& window) {
	cout << "Exit";
	window.close(); 
}
