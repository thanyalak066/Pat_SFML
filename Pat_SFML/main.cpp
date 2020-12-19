#pragma warning(push, 0)
#pragma warning(pop)
#pragma warning(disable : 26812)
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "Player.h"
#include "Collider.h"
#include <time.h>
#include "PLatform.h"
#include "hitboxComponent.h"
#include "Bullet.h"
#include "Enemy.h"
#include <string.h>
#include <sstream>
#include "menu.h"
#include "Highscore.h"
#include <stdlib.h>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "bulletEnemy.h"
#include "Boss.h"
using namespace std;

char nameplayer[10] = " ";//hightscore
int check = 0;//hightscore
int looptestname = 0;//hightscore
sf::Text textname;//hightscore

sf::Text hightscname, hightscscore;
std::stringstream Hscorename, Hscorescore;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "63011078 GAME_SFML", sf::Style::Close);//| sf::Style::Resize

    //texture
    sf::Texture bullet;
    sf::Texture enemyBull;
    sf::Texture enemyTexture;
    sf::Texture playHP;
    sf::Texture indexMenu;
    sf::Texture Boss1;
    sf::Texture endMenu;
    sf::Texture menuSetname;
    sf::Texture mainMenu;
    sf::Texture topScore;
    sf::Texture howTo;
    sf::Texture Died;
    sf::Texture win;
    sf::Texture boss11;
    sf::Texture plays;

    sf::Music music;
    //sound
    /*if (!music.openFromFile("C:/Users/Asarawoot114/source/repos/SFML_104/SFML_104/sound.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }
    music.setVolume(50.0f);
    music.setLoop(true);
    music.play();*/

    sf::SoundBuffer title;
    title.loadFromFile("sound/title.wav");
    sf::Sound titles;
    titles.setVolume(60);
    titles.setBuffer(title);

    sf::SoundBuffer button;
    button.loadFromFile("sound/button.wav");
    sf::Sound buttons;
    buttons.setVolume(60);
    buttons.setBuffer(button);

    sf::SoundBuffer playerShoot;
    playerShoot.loadFromFile("sound/playerShoot.wav");
    sf::Sound playerShoots;
    playerShoots.setVolume(60);
    playerShoots.setBuffer(playerShoot);

    plays.loadFromFile("charactor/gg.png");
    Player player(&plays, sf::Vector2u(4, 3), 0.1f, 350.0f, 300.0f);

    //bullet player
    sf::Vector2f pos;
    bullet.loadFromFile("bullets/bullet1.png");
    Bullet bulletPlayer(&bullet, sf::Vector2u(4, 1), 0.1f, 1500.f, pos, sf::Vector2f(30.0f, 8.75f), 1.0f);

    int bul = 0;
    int bul1 = 0;

    enemyBull.loadFromFile("bullets/bulletEnemy.png");
    bulletEnemy bulletE(&enemyBull, sf::Vector2u(1, 1), 0.1f, 500.0f, sf::Vector2f(-100, -100), sf::Vector2f(50.0f, 31.0f), 0.3f);
    
    //enemy
    enemyTexture.loadFromFile("enemy/enemy12.png");
    //Enemy enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f);
    
    //boss
    boss11.loadFromFile("boss/boss.png");
    Boss boss(&boss11, sf::Vector2u(4, 1), 0.8f, 300.0f, 300.0f, sf::Vector2f(13716.0f, 50.0f));

    //hitbox
    HitboxComponent hitboxPlayer(0, 0, sf::Vector2f(46.f, 88.f), player.GetPosition());

    //HitboxComponent hitboxEnemy(0, 0, sf::Vector2f(50.0f, 75.0f), enemy.GetPosition());

    std::vector<PLatform> platforms;
    std::vector<Enemy> enemys;


    //enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(700.0f, 200.0f)));

    //random position enemy
    srand(time(NULL));
    for (int i = 0; i < 40; i++)
    {
        float r = ((rand() % 5300) + 800); // value > 1000 but < 13400
        enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f((float)r, 50.0f)));
        printf("%.2f\n", r);
    }

    /*platforms.push_back(PLatform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));*/
    // enemy vector
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(700.0f, 200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(750.0f, 200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(900.0f, 200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(1200.0f, 200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(1400.0f, 200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(2000.0f, 200.0f)));

    //map1
    sf::Texture mapTexture1;
    mapTexture1.loadFromFile("maps/bgvenia.png");
    sf::RectangleShape map1(sf::Vector2f(6630.0f, 720.0f));
    map1.setPosition(0.0f, 0.0f);
    map1.setTexture(&mapTexture1);

    //warp point
    sf::RectangleShape warpPoint(sf::Vector2f(1.0f, 720.0f));
    //warpPoint.setFillColor(sf::Color::Red);
    warpPoint.setPosition(sf::Vector2f(6629.0f, 200.0f));

    ////warp point
    //sf::RectangleShape warpPoint(sf::Vector2f(200.0f, 200.0f));
    //warpPoint.setFillColor(sf::Color::Red);
    //warpPoint.setPosition(sf::Vector2f(14025.0f, 300.0f));

    //state
    int state = 1;

    //Index Menu
    Menu menu(window.getSize().x, window.getSize().y);
    /*indexMenu.loadFromFile("background/mainMenu.png");
    sf::RectangleShape menuIndex(sf::Vector2f(1080.0f, 720.0f));
    menuIndex.setTexture(&indexMenu);
    menuIndex.setPosition(sf::Vector2f(0.0f, 0.0f));*/
    int cheeckongame = 0;
    int howToPlay = 0;
    int highScore = 0;
    int diedddddd = 0;

    mainMenu.loadFromFile("background/mainMenu.png");
    sf::RectangleShape mainMenuState(sf::Vector2f(1080.0f, 720.0f));
    mainMenuState.setPosition(0.0f, 0.0f);
    mainMenuState.setTexture(&mainMenu);

    //end menu
    endMenu.loadFromFile("background/end.png");
    sf::RectangleShape end(sf::Vector2f(1080.0f, 720.0f));
    end.setPosition(sf::Vector2f(0.0f, 0.0f));
    end.setTexture(&endMenu);

    //top score
    topScore.loadFromFile("background/topScore.png");
    sf::RectangleShape topScoreShow(sf::Vector2f(1080.0f, 720.0f));
    topScoreShow.setPosition(0.0f, 0.0f);
    topScoreShow.setTexture(&topScore);

    //how to play
    howTo.loadFromFile("background/howtoplay.png");
    sf::RectangleShape howToPlays(sf::Vector2f(1080.0f, 720.0f));
    howToPlays.setPosition(sf::Vector2f(0.0f, 0.0f));
    howToPlays.setTexture(&howTo);

    //Died
    Died.loadFromFile("background/diedd.png");
    sf::RectangleShape diedd(sf::Vector2f(1080.0f, 720.0f));
    diedd.setPosition(sf::Vector2f(0.0f, 0.0f));
    diedd.setTexture(&Died);

    //Died
    win.loadFromFile("background/winnn.png");
    sf::RectangleShape winn(sf::Vector2f(1080.0f, 720.0f));
    winn.setPosition(sf::Vector2f(0.0f, 0.0f));
    winn.setTexture(&win);

    //View
    sf::View view;

    //Show time
    sf::Clock clocks;
    sf::Time time;
    std::ostringstream showtime;
    sf::Font font;
    font.loadFromFile("font/font.ttf");
    sf::Text lbltime;
    lbltime.setString(showtime.str());
    lbltime.setCharacterSize(30);
    lbltime.setFont(font);
    lbltime.setFillColor(sf::Color::Green);

    showtime.str(" ");
    showtime << "Time : ";
    //lbltime.setPosition(view.getCenter().x + 280, view.getCenter().y - 320);

    //point
    int score = 0;
    sf::Text showScore;
    showScore.setCharacterSize(30);
    showScore.setFont(font);
    showScore.setFillColor(sf::Color::White);

    Hscorename = updatescore(0, score, nameplayer);//hightscore
    Hscorescore = updatescore(1, score, nameplayer);//hightscore
    hightscname.setString(Hscorename.str());//hightscore
    hightscscore.setString(Hscorescore.str());//hightscore

    //player name
    hightscname.setFont(font);
    hightscname.setFillColor(sf::Color::White);
    hightscname.setCharacterSize(45);
    hightscname.setPosition(150, 250);

    //score -> number
    hightscscore.setFont(font);
    hightscscore.setFillColor(sf::Color::White);
    hightscscore.setCharacterSize(45);
    hightscscore.setPosition(600, 250);

    //input
    textname.setFont(font);
    textname.setCharacterSize(60);
    textname.setFillColor(sf::Color::White);
    textname.setPosition(370, 300);

    menuSetname.loadFromFile("background/bg_setname.png");
    sf::RectangleShape setName(sf::Vector2f(1080.0f, 720.0f));
    setName.setTexture(&menuSetname);
    setName.setPosition(0.0f, 0.0f);

    //showScore.setPosition(view.getCenter().x + -10, view.getCenter().y - 320);


    bool faceright = true;
    float deltaTime = 0.0f;
    sf::Clock clock;
    bool stop = false;
    int pselect = 0;

    //bool isFiring = false;

    while (window.isOpen())
    {
        while (stop == true)
        {
            sf::Text paused("Paused", font, 60);
            sf::Text resume("Resume", font, 40);
            sf::Text exit("Exit", font, 40);

            window.clear();
            window.setView(view);

            view.setCenter(sf::Vector2f(-1000.0f, 1800.0f));
            paused.setPosition(view.getCenter().x - 50, view.getCenter().y - 300.0f);
            resume.setPosition(view.getCenter().x - 50, view.getCenter().y + 200.0f);
            exit.setPosition(view.getCenter().x - 50, view.getCenter().y + 250.0f);

            if (pselect == 0)
            {
                resume.setFillColor(sf::Color::Red);
                exit.setFillColor(sf::Color::White);
            }
            if (pselect == 1)
            {
                exit.setFillColor(sf::Color::Red);
                resume.setFillColor(sf::Color::White);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                pselect = 0;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                pselect = 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && pselect == 0 && diedddddd == 0)
            {
                stop = false;
                cheeckongame = 9;
            }
            window.draw(paused);
            window.draw(resume);
            window.draw(exit);
            window.display();


        }
        if (stop == false)
        {

            pos = player.GetPosition();
            if (cheeckongame == 1) {
                time = clocks.getElapsedTime();
                //time = sf::seconds((int)time.asSeconds() % 60);
                showtime << (int)time.asSeconds() / 60 << " : " << (int)time.asSeconds() % 60;
            }

            //std::cout << bulletPlayer.cooldown(deltaTime, bul) << std::endl;
            //std::cout << ammunition << std::endl;

            deltaTime = clock.restart().asSeconds();
            if (deltaTime > 1.0f / 20.0f)
                deltaTime = 1.0f / 20.0f;

            sf::Event evnt;
            while (window.pollEvent(evnt))
            {

                if (cheeckongame == 3) // menu add user
                {
                    // user added
                    if (evnt.type == sf::Event::TextEntered)
                    {
                        if (evnt.text.unicode == 27)
                        {
                            cheeckongame = 0; // esc
                        }
                        if (evnt.text.unicode == 13)
                        {
                            if (looptestname > 0)
                            {
                                cheeckongame = 2; // enter
                                printf("enter\n");

                            }
                            else if (looptestname >= 0)
                            {
                                looptestname--;
                            }


                        }
                        if (evnt.text.unicode == 8) // back space
                        {
                            if (looptestname > 0)
                            {
                                looptestname--;
                                nameplayer[looptestname] = '\0';
                            }

                        }
                        else
                        {
                            if (looptestname < 8)
                            {
                                printf("%c\n", evnt.text.unicode);
                                nameplayer[looptestname] = evnt.text.unicode;
                                looptestname++;
                            }

                        }
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                    {
                        cheeckongame = 1;
                    }
                }



                switch (evnt.type)
                {

                    // Menu
                case sf::Event::KeyReleased:
                    switch (evnt.key.code) {
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break;
                    case sf::Keyboard::Return:
                        switch (menu.GetPressedItem())
                        {
                        case 0:
                            if (cheeckongame == 0)
                            {
                                cheeckongame = 3; // check for into game
                                break;
                            }

                        case 1:
                            //std::cout << "2" << std::endl;
                            howToPlay = 1;
                            break;
                        case 2:
                            highScore = 1;
                            break;
                        case 3:
                            window.close();
                            break;
                        }
                    }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
                    /*case sf::Event::Resized:
                        ResizeView(window, view);
                        break;*/

                case sf::Event::TextEntered:
                    if (evnt.text.unicode < 128)
                    {
                        char show = evnt.text.unicode;
                        //std::cout << show << std::endl;  // Show input Keyboards
                    }
                }

            }
            //hitbox
            hitboxPlayer.Update(player.GetPosition(), -25.f, -45.f);

            sf::Vector2f direction;
            player.Update(deltaTime, direction); // player = class name ,Update = function name , (deltaTime) = parameter  
            player.iframeTimer(deltaTime, direction);
            if (player.GetHp() <= 0)
            {

                diedddddd = 1;
            }
            for (int i = 0; i < enemys.size(); i++)
            {
                if (abs(enemys[i].GetPosition().x - player.GetPosition().x) > 500.0f)
                {
                    enemys[i].Update(deltaTime, direction, 2);
                }
                if (enemys[i].GetPosition().x >= player.GetPosition().x && abs(enemys[i].GetPosition().x - player.GetPosition().x) <= 500.0f)
                {
                    enemys[i].Update(deltaTime, direction, 1);
                }
                if (enemys[i].GetPosition().x < player.GetPosition().x && abs(enemys[i].GetPosition().x - player.GetPosition().x) <= 500.0f)
                {
                    enemys[i].Update(deltaTime, direction, 0);
                }
                if (enemys[i].GetCollider1().hit(player.GetCollider(), direction))
                {
                    player.damaged(5);
                }
            }

            //boss
            boss.Update(deltaTime, direction);
            //boss
            for (PLatform& platform : platforms)
            {    //Boss
                if (platform.GetCollider().CheckCollision(boss.GetCollider2(), direction, 1.0f))
                    boss.OnCollision2(direction);
            }

            if (boss.GetPosition().x - player.GetPosition().x <= 750.0f && boss.GetPosition().x - player.GetPosition().x > 0 && abs(boss.GetPosition().y - player.GetPosition().y < 150.0f))
            {
                bulletE.attackL(boss.GetPosition());
            }
            bulletE.updateL(deltaTime);
            if (abs(bulletE.GetPosition().x - view.getCenter().x) >= 750.0f)
            {
                bulletE.ready();
                bulletE.setPosition();
            }
            if (bulletPlayer.GetCollider().CheckCollision(boss.GetCollider2(), direction, 1.0f))
            {
                bul = 0;
                bulletPlayer.ready();
                bulletPlayer.setPosition(pos);
                boss.updateHP(1);
            }
            if (boss.getHP() <= 0 && boss.GetPosition().x < 29000)
            {
                boss.setPos(32000.0f, 100.0f);
                score += 40;
            }
            if (bulletE.GetCollider().hit(player.GetCollider(), direction))
            {
                player.damaged(15);
            }

            for (PLatform& platform : platforms)
            {    //player
                if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
                    player.OnCollision(direction);
            }


            //enemy map 1
            for (int i = 0; i < enemys.size(); i++)
            {
                for (PLatform& platform : platforms)
                {   //enemy
                    if (platform.GetCollider().CheckCollision(enemys[i].GetCollider1(), direction, 1.0f))
                        enemys[i].OnCollision1(direction);
                }
                if (bulletPlayer.GetCollider().CheckCollision(enemys[i].GetCollider1(), direction, 1.0f))
                {
                    bul = 0;
                    bulletPlayer.ready();
                    bulletPlayer.setPosition(pos);
                    enemys[i].updateHP(1);
                }
                if (enemys[i].getHP() <= 0 && enemys[i].GetPosition().x < 29000)
                {
                    enemys[i].setPos(32000.0f, 100.0f);
                    score += 5;
                }

            }

            view.setCenter(sf::Vector2f(player.GetPosition()));
            view.setSize(sf::Vector2f(1080.0f, 720.0f));

            // state 1
            if (player.GetPosition().x >= 0 && player.GetPosition().x < 6630.0f)
            {
                state = 1;

                if (view.getCenter().x - 540.0f <= 0.0f)
                {
                    if (view.getCenter().y - 360.0f <= 0.0f)
                    {
                        view.setCenter(sf::Vector2f(540.0f, 360.0f));
                    }
                    if (view.getCenter().y + 360.0f >= 720.0f)
                    {
                        view.setCenter(sf::Vector2f(540.0f, 360.0f));
                    }
                }
                if (view.getCenter().x + 540.0f >= 6630.0f)
                {
                    if (view.getCenter().y - 360.0f <= 0.0f)
                    {
                        view.setCenter(sf::Vector2f(6090.0f, 360.0f));
                    }
                    if (view.getCenter().y + 360.0f >= 720.0f)
                    {
                        view.setCenter(sf::Vector2f(6090.0f, 360.0f));
                    }
                }
                if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 6630.0f)
                {
                    if (view.getCenter().y - 360.0f <= 0.0f)
                    {
                        view.setCenter(sf::Vector2f(player.GetPosition().x, 360.0f));
                    }
                    if (view.getCenter().y + 360.0f >= 720.0f)
                    {
                        view.setCenter(sf::Vector2f(player.GetPosition().x, 360.0f));
                    }
                }
            }



            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                faceright = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                faceright = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && cheeckongame == 2)
            {
                //cheeckongame = 5;
                stop = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletPlayer.cooldown(deltaTime, bul) >= 0.4f)
            {
                playerShoots.play();
                if (faceright == true)
                {

                    bul = 1;
                    bulletPlayer.attackR(pos);
                }
                if (faceright == false)
                {
                    bul = -1;
                    bulletPlayer.attackL(pos);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            {
                player.setPosition(13000.0f, 100.0f);
            }

            //Show time
            lbltime.setString(showtime.str());

            showtime.str(" ");
            showtime << " Time  :  ";
            lbltime.setPosition(view.getCenter().x + 280, view.getCenter().y - 320);

            //show score
            showScore.setPosition(view.getCenter().x - 10, view.getCenter().y - 320);
            showScore.setString("score : " + std::to_string(score));

            window.clear();

            if (cheeckongame == 0)
            {
                // Menu
                window.draw(mainMenuState);
                menu.draw(window);
                //Stop.draw(window);
            }

            if (cheeckongame == 1)
            {
                for (PLatform& platform : platforms)
                    platform.Draw(window);

                

                //time
                window.draw(lbltime);

                //score
                window.draw(showScore);

                //boss
                boss.Draw(window);
                bulletE.draw(window);

                //enemy
                for (int i = 0; i < enemys.size(); i++)
                {
                    enemys[i].Draw(window);
                }

                window.setView(view);


                // state 1
                if (hitboxPlayer.checkIntersect(warpPoint.getGlobalBounds()))
                {
                    player.stateChange(window);
                }

                if (boss.getHP() <= 0 && boss.GetPosition().x > 8000)
                {
                    window.draw(warpPoint);
                    cheeckongame = 8;
                    //end game
                    if (hitboxPlayer.checkIntersect(warpPoint.getGlobalBounds()))
                    {
                        state = 3;
                    }
                }
                //map1
                window.draw(map1);
                player.Draw(window);


                if (bul == 1)
                {
                    bulletPlayer.updateR(deltaTime);

                    bulletPlayer.draw(window);
                }
                if (bul == -1)
                {
                    bulletPlayer.updateL(deltaTime);

                    bulletPlayer.draw(window);

                }
                if (abs(bulletPlayer.GetPosition().x - player.GetPosition().x) >= 1000.0f)
                {

                    bul = 0;
                    bulletPlayer.ready();
                    bulletPlayer.setPosition(pos);
                }

            }
            if (cheeckongame == 3)
            {
                howToPlay = 0;
                textname.setString(nameplayer);
                window.draw(setName);
                window.draw(textname);
            }
            if (cheeckongame == 2 && check == 0) // end
            {
                check = 1;
                howToPlay = 0;
                Hscorename = updatescore(0, score, nameplayer);//hightscore
                Hscorescore = updatescore(1, score, nameplayer);//hightscore

                hightscname.setString(Hscorename.str());
                hightscscore.setString(Hscorescore.str());
            }
            if (pselect == 3 && cheeckongame == 9)
            {
                window.draw(diedd);//hightscore
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    highScore = 1;
                    pselect = 0;
                }
            }
            if (cheeckongame == 8)
            {
                window.draw(winn);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && highScore == 0)
                {
                    window.clear();

                    howToPlay = 0;
                    highScore = 1;
                    diedddddd = 0;
                    cheeckongame = 0;
                    player.HPre();
                }
            }
            if (check == 1)
            {
                window.draw(end);//hightscore
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    cheeckongame = 0;
                    check = 0;
                }
            }
            if (howToPlay == 1)
            {
                window.draw(howToPlays);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    cheeckongame = 0;
                    howToPlay = 0;
                }
            }
            if (highScore == 1)
            {
                //back from show score
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    cheeckongame = 0;
                    highScore = 0;
                    howToPlay = 0;
                }

                window.draw(topScoreShow);
                hightscname.setString(Hscorename.str());
                hightscscore.setString(Hscorescore.str());
                // window.draw(menuIndex);
                window.draw(hightscname);
                window.draw(hightscscore);

            }
            if (cheeckongame == 1)
            {
                player.drawbar(view.getCenter(), window, view.getCenter());
                howToPlay = 0;
            }
           
            if (diedddddd == 1 && highScore == 0)
            {

                if (diedddddd == 1)
                {
                    player.setPosition(100.0f, 100.0f);
                    window.draw(diedd);
                    //gameEnds.play();
                }

                //check = 0;

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
                {
                    window.clear();

                    howToPlay = 0;
                    highScore = 1;
                    diedddddd = 0;
                    cheeckongame = 0;
                    player.HPre();
                    //highScore = 0;
                }
            }
            printf("%d\n", cheeckongame);
            window.display();
        }
    }
}