#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // ================= WINDOW =================
    sf::RenderWindow window(sf::VideoMode({ 900u, 500u }), "Slot Machine");

    // ================= FONT =================
    sf::Font font;
    font.openFromFile("C:/Windows/Fonts/arial.ttf");

    // ================= MONEY =================
    int balance = 0;
    const int spinCost = 200;

    // ================= FRUITS TEXT =================
    std::vector<std::string> fruitNames = { "Cherry", "Lemon", "Bell", "777" };
    std::vector<sf::Text> slotText;
    for (int i = 0; i < 3; i++)
    {
        sf::Text t(font);             // SFML 3: конструктор с font
        t.setString(fruitNames[i]);
        t.setCharacterSize(40);
        t.setFillColor(sf::Color::White);
        slotText.push_back(t);
    }

    slotText[0].setPosition(sf::Vector2f{ 150.f, 200.f });
    slotText[1].setPosition(sf::Vector2f{ 400.f, 200.f });
    slotText[2].setPosition(sf::Vector2f{ 650.f, 200.f });

    // ================= LINES =================
    sf::RectangleShape line1(sf::Vector2f{ 2.f, 500.f });
    sf::RectangleShape line2(sf::Vector2f{ 2.f, 500.f });
    line1.setPosition(sf::Vector2f{ 300.f, 0.f });
    line2.setPosition(sf::Vector2f{ 600.f, 0.f });
    line1.setFillColor(sf::Color::White);
    line2.setFillColor(sf::Color::White);

    // ================= SCOREBOARD =================
    sf::Text scoreText(font);
    scoreText.setString("Balance: 0$");
    scoreText.setCharacterSize(22);
    scoreText.setFillColor(sf::Color{ 150, 255, 0 });
    scoreText.setPosition(sf::Vector2f{ 700.f, 20.f });

    sf::Text resultText(font);
    resultText.setString("");
    resultText.setCharacterSize(26);
    resultText.setPosition(sf::Vector2f{ 350.f, 50.f });

    // ================= INTRO SCREEN =================
    bool intro = true;
    sf::Text introText(font);
    introText.setString(
        "Welcome to the Slot Machine!\n"
        "Press SPACE to start.\n"
        "Spin costs 200$.\n"
        "777 = 10000$\n"
        "3 same fruits = 1000$\n"
        "= shows total balance"
    );
    introText.setCharacterSize(22);
    introText.setFillColor(sf::Color::White);
    introText.setPosition(sf::Vector2f{ 100.f, 150.f });

    // ================= MAIN LOOP =================
    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::KeyPressed>())
            {
                auto key = event->getIf<sf::Event::KeyPressed>();

                if (intro && key->code == sf::Keyboard::Key::Space)
                    intro = false;

                else if (!intro)
                {
                    if (key->code == sf::Keyboard::Key::Space)
                    {
                        balance -= spinCost;

                        int r1 = rand() % 4;
                        int r2 = rand() % 4;
                        int r3 = rand() % 4;

                        slotText[0].setString(fruitNames[r1]);
                        slotText[1].setString(fruitNames[r2]);
                        slotText[2].setString(fruitNames[r3]);

                        if (r1 == 3 && r2 == 3 && r3 == 3)
                        {
                            balance += 10000;
                            resultText.setString("JACKPOT 777!");
                            resultText.setFillColor(sf::Color(255, 165, 0));
                        }
                        else if (r1 == r2 && r2 == r3)
                        {
                            balance += 1000;
                            resultText.setString("YOU WIN!");
                            resultText.setFillColor(sf::Color(255, 165, 0));
                        }
                        else
                        {
                            resultText.setString("YOU LOSE");
                            resultText.setFillColor(sf::Color::Red);
                        }

                        scoreText.setString("Balance: " + std::to_string(balance) + "$");
                    }

                    if (key->code == sf::Keyboard::Key::Equal)
                    {
                        resultText.setString("TOTAL: " + std::to_string(balance) + "$");
                        resultText.setFillColor(sf::Color::White);
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        if (intro)
            window.draw(introText);
        else
        {
            window.draw(line1);
            window.draw(line2);

            for (auto& t : slotText)
                window.draw(t);

            window.draw(scoreText);
            window.draw(resultText);
        }

        window.display();
    }

    return 0;
}
