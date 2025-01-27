#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>


enum Choice { ROCK, PAPER, SCISSORS };

class RockPaperScissorsGame {
public:
    RockPaperScissorsGame() : window(sf::VideoMode(400, 300), "Rock Paper Scissors Game") {
        setupUI();
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (event.type == sf::Event::MouseButtonPressed) {
                    handleMouseClick(event.mouseButton.x);
                }
            }

            window.clear();
            window.draw(title);
            window.draw(choicesText);
            window.draw(resultText);
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text title;
    sf::Text choicesText;
    sf::Text resultText;
    Choice playerChoice;
    Choice computerChoice;

    void setupUI() {
        if (!font.loadFromFile("Poppins.ttf")) { // Replace with the actual path
            std::cerr << "Failed to load font!" << std::endl;
            return;
        }

        title.setFont(font);
        title.setString("Rock Paper Scissors Game");
        title.setCharacterSize(26);
        title.setPosition(30, 20);

        choicesText.setFont(font);
        choicesText.setCharacterSize(25);
        choicesText.setPosition(45, 155);  // Adjust the position as needed
        choicesText.setString("Rock             Paper         Scissors");

        resultText.setFont(font);
        resultText.setCharacterSize(20);
        resultText.setPosition(30, 200);  // Adjust the position as needed

        updateChoicesText();
    }

    void handleMouseClick(int mouseX) {
        if (mouseX < 150) {
            playerChoice = ROCK;
        } else if (mouseX < 250) {
            playerChoice = PAPER;
        } else {
            playerChoice = SCISSORS;
        }

        determineWinner();
    }

    void determineWinner() {
        computerChoice = static_cast<Choice>(std::rand() % 3);

        std::string result = "It's a tie!";
        if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
            (playerChoice == PAPER && computerChoice == ROCK) ||
            (playerChoice == SCISSORS && computerChoice == PAPER)) {
            result = "You win!";
        } else if ((computerChoice == ROCK && playerChoice == SCISSORS) ||
                   (computerChoice == PAPER && playerChoice == ROCK) ||
                   (computerChoice == SCISSORS && playerChoice == PAPER)) {
            result = "Computer wins!";
        }

        resultText.setString("Result: " + result + "\nYou chose: " + choiceToString(playerChoice) +
                             "\nComputer chose: " + choiceToString(computerChoice));

        std::cout << "You chose " << choiceToString(playerChoice) << "\nComputer chose " << choiceToString(computerChoice) << "\n\n" << result << std::endl;

        updateChoicesText();
    }

    std::string choiceToString(Choice choice) {
        switch (choice) {
        case ROCK:
            return "Rock";
        case PAPER:
            return "Paper";
        case SCISSORS:
            return "Scissors";
        }
        return "";
    }

    void updateChoicesText() {
        // Update the text based on the selected choices if needed
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    RockPaperScissorsGame game;
    game.run();

    return 0;
}
