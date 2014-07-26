
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

using namespace std;

#ifndef __APPLE__
string resourcePath() {
   return "";
}
#endif


const int WIDTH = 800;
const int HEIGHT = 600;

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Shine!");
    window.setFramerateLimit(30);

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
    //if (!icon.loadFromFile("icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "background.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite background(texture);

    // Load a sprite to display
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile(resourcePath() + "player.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite playerSprite(playerTexture);
    playerSprite.scale(sf::Vector2f(0.5f, 0.5f));

    //move the player sprite to the centre of the screen ... ish
    playerSprite.move(WIDTH/2, HEIGHT/2);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
    //if (!font.loadFromFile("sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
    //if (!music.openFromFile("nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();


    //scrolling view
    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));

    float scrollX = 10;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        //scroll the view
        view.move(scrollX, 0);
        window.setView(view);

        // Draw the background
        window.draw(background);

        // Draw the player
        playerSprite.move(scrollX, 0);
        window.draw(playerSprite);

        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }

    //return EXIT_SUCCESS;

    return 0;
}
