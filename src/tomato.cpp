#include <vector>
#include <thread>
#include <chrono>  
#include "SFML/Graphics.hpp"
#include "tomatoplant.h"
#include "cucumberplant.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include <sstream>


void simulateoneday(plantbase &plant){
    plant.grow(1);
}

int main(int argc, char const *argv[])
{
    lemonbalm my_plant;
    float sidebranchlength1 = 0.;
    float sidebranchlength2 = 0.;
    float sidebranchlength3 = 0.;
    float sidebranchlength4 = 0.;
    float sidebranchlength5 = 0.;
    float sidebranchlength6 = 0.;
    float sidebranchlength7 = 0.;
    float sidebranchlength8 = 0.;
    float sidebranchlength9 = 0.;
    float sidebranchlength10 = 0.;
    float sidebranchlength11 = 0.;
    
    float stalklength = 0;
    sf::RectangleShape tomatostalk {sf::Vector2f{5.0, stalklength}};
    tomatostalk.setFillColor (sf::Color{0,255,0});
    tomatostalk.setPosition(400, 600); 

    sf::RectangleShape sidestalk1 {sf::Vector2f{sidebranchlength1, 5.0}};
    sidestalk1.setFillColor (sf::Color{0,255,0});
    sidestalk1.setPosition(400, 555);

    sf::RectangleShape sidestalk2 {sf::Vector2f{sidebranchlength2, 5.0}};
    sidestalk2.setFillColor (sf::Color{0,255,0});
    sidestalk2.setPosition(400, 525);

    sf::RectangleShape sidestalk3 {sf::Vector2f{sidebranchlength3, 5.0}};
    sidestalk3.setFillColor (sf::Color{0,255,0});
    sidestalk3.setPosition(400, 500);

    sf::RectangleShape sidestalk4 {sf::Vector2f{sidebranchlength4, 5.0}};
    sidestalk4.setFillColor (sf::Color{0,255,0});
    sidestalk4.setPosition(400, 470);

    sf::RectangleShape sidestalk5 {sf::Vector2f{sidebranchlength5, 5.0}};
    sidestalk5.setFillColor (sf::Color{0,255,0});
    sidestalk5.setPosition(400, 430); 

    sf::RectangleShape sidestalk6 {sf::Vector2f{sidebranchlength6, 5.0}};
    sidestalk6.setFillColor (sf::Color{0,255,0});
    sidestalk6.setPosition(400, 410); 

    sf::RectangleShape sidestalk7 {sf::Vector2f{sidebranchlength7, 5.0}};
    sidestalk7.setFillColor (sf::Color{0,255,0});
    sidestalk7.setPosition(400, 400); 

    sf::RectangleShape sidestalk8 {sf::Vector2f{sidebranchlength8, 5.0}};
    sidestalk8.setFillColor (sf::Color{0,255,0});
    sidestalk8.setPosition(400, 370); 

    sf::RectangleShape sidestalk9 {sf::Vector2f{sidebranchlength9, 5.0}};
    sidestalk9.setFillColor (sf::Color{0,255,0});
    sidestalk9.setPosition(400, 345); 

    sf::RectangleShape sidestalk10 {sf::Vector2f{sidebranchlength10, 5.0}};
    sidestalk10.setFillColor (sf::Color{0,255,0});
    sidestalk10.setPosition(400, 320); 

    sf::RectangleShape sidestalk11 {sf::Vector2f{sidebranchlength11, 5.0}};
    sidestalk11.setFillColor (sf::Color{0,255,0});
    sidestalk11.setPosition(400, 300); 
        // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);


    
    sf::Clock deltaClock;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("my greenhouse");
        bool mybutton = ImGui::Button("wait a day");
        bool pick_tomato = ImGui::Button("pick tomato");
        bool N = ImGui::Button("fertelize N");
        bool P = ImGui::Button("fertelize P");
        bool K = ImGui::Button("fertelize K");
        bool water = ImGui::Button("water 1 liter");
        if (mybutton == true)
        {
           simulateoneday(my_plant);
        }
        if (N == true)
        {
            my_plant.plantsoil.Fertilize_NPK(1,0,0);
        }
        if (P == true)
        {
            my_plant.plantsoil.Fertilize_NPK(0,1,0);
        }
        if (K == true)
        {
            my_plant.plantsoil.Fertilize_NPK(0,0,1);
        }
        if (water == true)
        {
            my_plant.plantsoil.water_plant(1);
        }
        
        stalklength = 0 - my_plant.getheight();
        tomatostalk.setSize(sf::Vector2f{5., stalklength});
        ImGui::End();
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        // draw everything here...

        window.draw(tomatostalk);
        if (stalklength  < -50)
        {
            window.draw(sidestalk1);
            sidestalk1.setSize(sf::Vector2f{sidebranchlength1, 5.});
            sidebranchlength1 = (stalklength + 50) / 2;
        }
         if (stalklength  < -100)
        {
            window.draw(sidestalk2);
            sidestalk2.setSize(sf::Vector2f{sidebranchlength2, 5.});
            sidebranchlength2 = -(stalklength + 100) / 2;
        }
        if (stalklength  < -140)
        {
            window.draw(sidestalk3);
            sidestalk3.setSize(sf::Vector2f{sidebranchlength3, 5.});
            sidebranchlength3 = (stalklength + 100) / 2;
        }
         if (stalklength  < -160)
        {
            window.draw(sidestalk4);
            sidestalk4.setSize(sf::Vector2f{sidebranchlength4, 5.});
            sidebranchlength4 = -(stalklength + 150) / 2;
        }
          if (stalklength  < -190)
        {
            window.draw(sidestalk5);
            sidestalk5.setSize(sf::Vector2f{sidebranchlength5, 5.});
            sidebranchlength5 = (stalklength + 130) / 2;
        }
          if (stalklength  < -190)
        {
            window.draw(sidestalk6);
            sidestalk6.setSize(sf::Vector2f{sidebranchlength6, 5.});
            sidebranchlength6 = -(stalklength + 190) / 2;
        }
          if (stalklength  < -210)
        {
            window.draw(sidestalk7);
            sidestalk7.setSize(sf::Vector2f{sidebranchlength7, 5.});
            sidebranchlength7 = (stalklength + 210) / 2;
        }
          if (stalklength  < -235)
        {
            window.draw(sidestalk8);
            sidestalk8.setSize(sf::Vector2f{sidebranchlength8, 5.});
            sidebranchlength8 = -(stalklength + 230) / 2;
        }
          if (stalklength  < -255)
        {
            window.draw(sidestalk9);
            sidestalk9.setSize(sf::Vector2f{sidebranchlength9, 5.});
            sidebranchlength9 = (stalklength + 250) / 2;
        }
          if (stalklength  < -280)
        {
            window.draw(sidestalk10);
            sidestalk10.setSize(sf::Vector2f{sidebranchlength10, 5.});
            sidebranchlength10 = -(stalklength + 280) / 2;
        }
          if (stalklength  < -310)
        {
            window.draw(sidestalk11);
            sidestalk11.setSize(sf::Vector2f{sidebranchlength11, 5.});
            sidebranchlength11 = (stalklength + 300) / 2;
        }
        // window.draw(...);
        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }
    return 0;
}
