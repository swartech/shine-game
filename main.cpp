
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
#include "gameObject.h"
#include "Player.h"
#include "Chaser.h"
#include "Tile.h"
#include "LightOrb.h"
#include "level.h"

using namespace std;

#ifndef __APPLE__
string resourcePath() {
   return "";
}
#endif


const int WIDTH = 800;
const int HEIGHT = 640;

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Shine!");
    //window.setFramerateLimit(30);
    window.setVerticalSyncEnabled(true);
    
    //Declare Player
    sf:: Texture playerTexture;
    playerTexture.loadFromFile(resourcePath() + "player.png");
    Player player(playerTexture, sf::Vector2f(WIDTH/2, HEIGHT/2), sf::Vector2f(5, 0), 1, true, true);
    //Chaser chaser();

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
    background.scale(10, 10);
    
    // Load a sprite to display
    sf::Texture lightOrbTexture;
    if (!lightOrbTexture.loadFromFile(resourcePath() + "lightOrb.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite lightOrbSprite(lightOrbTexture);
    
    // Load a sprite to display
    sf::Texture blockTexture;
    if (!blockTexture.loadFromFile(resourcePath() + "block.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite blockSprite(blockTexture);

    //move the player sprite to the centre of the screen ... ish
    player.sprite.move(player.position);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
    //if (!font.loadFromFile("sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setColor(sf::Color::Black);
    
    vector<GameObject> gameObjects;
    
    Level level(resourcePath() + "levelTest.png", lightOrbSprite, blockSprite);
    cout << level.tilemap.size();
    
    for (int i = 0; i < level.tilemap.size(); ++i)
    {
        gameObjects.push_back(level.tilemap[i]);
    }
    cout << gameObjects.size();
    

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

    float scrollX = player.velocity.x + 0.5;
    
    sf::Sprite overlay;

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
        if(background.getGlobalBounds().width - (WIDTH / 2) > view.getCenter().x)
        {
            view.move(scrollX, 0);
            window.setView(view);
        }
        
        // Draw the background
        window.draw(background);
        
        for (int i = 0; i < gameObjects.size(); ++i)
        {
            //cout << gameObjects[i].sprite.getGlobalBounds().top << "\n";
            window.draw(gameObjects[i].sprite);
        }

        // Draw the player
        if(background.getGlobalBounds().width - (WIDTH / 2) > view.getCenter().x)
        {
            player.sprite.move(player.velocity.x, 0);
            window.draw(player.sprite);
        }
        
        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }

    //return EXIT_SUCCESS;

    return 0;
}
