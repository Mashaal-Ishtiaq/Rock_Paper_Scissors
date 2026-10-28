
# Rock Paper Scissors — GUI

A desktop version of the classic Rock Paper Scissors game, built with Python and Tkinter.

## Overview

Play Rock Paper Scissors against the computer through a simple graphical interface. Choose a move, see the round result, and track your score as you play.

## Features

- Interactive Rock, Paper, and Scissors buttons
- Random computer choices
- Automatic winner determination
- Separate scores for the player, computer, and ties
- Color-coded results
- Quit button to close the game

## Technology Stack

- **Language:** Python
- **GUI:** Tkinter
- **Randomization:** Python's built-in `random` module

## Prerequisites

- Python 3.8 or later
- Tkinter support

On some Linux distributions, Tkinter may need to be installed separately:

```bash
sudo apt update
sudo apt install python3-tk
```

## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/Mashaal-Ishtiaq/rock_paper_scissors_gui.git
```

### 2. Navigate to the project directory

```bash
cd rock_paper_scissors_gui
```

### 3. Run the game

```bash
python rock_paper_scissors.py
```

On Linux, you can also use:

```bash
python3 rock_paper_scissors.py
```

## How to Play

1. Launch the application.
2. Click **Rock**, **Paper**, or **Scissors**.
3. View the computer's choice and the round result.
4. Track the player, computer, and tie scores.
5. Click **Quit** when you're finished.

## Game Rules

| Player's move | Beats |
|---|---|
| Rock | Scissors |
| Paper | Rock |
| Scissors | Paper |

Matching choices result in a tie.

## Project Structure

```text
rock_paper_scissors_gui/
└── rock_paper_scissors.py
```

## Limitations

- The game is designed for local, single-player use.
- Scores are maintained during the current session and are not saved between runs.
- The application requires a graphical desktop environment.

## Future Improvements

- Add a reset-score button.
- Add keyboard controls.
- Introduce configurable rounds and a best-of series.
- Add automated tests for the game logic.

## License

No license is currently documented. Check the repository's licensing before redistributing or reusing this project.
