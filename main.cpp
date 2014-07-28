
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
#include <algorithm>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "gameObject.h"
#include "Player.h"
#include "Chaser.h"
#include "Tile.h"
#include "LightOrb.h"
#include "level.h"
#include "Chaser.h"

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
    playerTexture.loadFromFile(resourcePath() + "playerSheet.png");
    sf::Sprite playerSprite(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 128));
    Player player(playerTexture, playerSprite, sf::Vector2f(WIDTH/2, HEIGHT/2), sf::Vector2f(5, 0), true, true);
    
    
    sf:: Texture chaserTexture;
    chaserTexture.loadFromFile(resourcePath() + "Chaser.png");
    sf::Sprite chaserSprite(chaserTexture);
    Chaser chaser(chaserSprite, sf::Vector2f(-WIDTH, 0), sf::Vector2f(5.4, 0));

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
    texture.setSmooth(true);
    sf::Sprite background(texture);
    background.scale(10, 10);
    
    //overlay
    sf::Texture overlayTexture;
    if (!overlayTexture.loadFromFile(resourcePath() + "overlay.png")) {
        return EXIT_FAILURE;
    }
    overlayTexture.setSmooth(true);
    sf::Sprite overlay(overlayTexture);
    overlay.scale(10, 10);
    
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
    
    
    for (int i = 0; i < level.tilemap.size(); ++i)
    {
        gameObjects.push_back(level.tilemap[i]);
    }
    
    std::sort(gameObjects.begin(), gameObjects.end(), GameObject::compareDepth);
    
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "music.ogg")) {
    //if (!music.openFromFile("nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();


    //scrolling view
    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));    float scrollX = player.velocity.x + 0.2;

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
            window.draw(gameObjects[i].sprite);
        }

        // draw overlay
        
        window.draw(overlay);
        
        // Draw the player and the chaser
        if(background.getGlobalBounds().width - (WIDTH / 2) > view.getCenter().x)
        {
            player.update();//sprite.move(player.velocity.x, 0);
            chaser.update();//sprite.move(chaser.velocity.x, 0);
        }
//        else
//        {
//            music.stop();
//        }
        window.draw(player.sprite);
        
        window.draw(chaser.sprite);

        // Update the window
        window.display();
    }

    //return EXIT_SUCCESS;

    return 0;
}
