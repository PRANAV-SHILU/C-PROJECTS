# C Programming Projects

A comprehensive collection of 8 C programming projects demonstrating fundamental to intermediate programming concepts, including games, utilities, and practical applications.

## 📋 Overview

This repository contains 8 well-structured C projects that progressively demonstrate various programming concepts such as control structures, functions, file handling, data structures, recursion, and algorithm implementation. Each project is self-contained in its own directory with fully functional source code.

**Author:** Pranav Shilu

## 🛠️ Technologies & Tools Used

- **Language:** C
- **Headers:** `stdio.h`, `stdlib.h`, `string.h`, `time.h`, `math.h`, `unistd.h`, `conio.h`
- **Compiler:** GCC (GNU Compiler Collection) or any C compiler
- **Platform:** Cross-platform (Windows/Linux/macOS) with conditional compilation for platform-specific features
- **Concepts Demonstrated:**
  - Control structures (loops, conditionals)
  - Functions and modular programming
  - Arrays and strings
  - Structures (structs)
  - File I/O (text and binary files)
  - Dynamic memory management
  - Recursion and backtracking
  - Random number generation
  - Time manipulation

## 📚 Projects

### 1. Number Guessing Game

**File:** [`1 Number Guessing Game/guessing_game.c`](1%20Number%20Guessing%20Game/guessing_game.c)

A simple yet engaging game where the player tries to guess a randomly generated number between 1 and 100.

**Features:**

- Random number generation using `srand()` and `rand()`
- Feedback system (higher/lower hints)
- Attempt counter
- User-friendly interface

**Concepts Covered:**

- Random number generation (`time.h`, `stdlib.h`)
- Do-while loops
- Conditional statements
- Basic input/output

**How to Run:**

```bash
gcc "1 Number Guessing Game/guessing_game.c" -o guessing_game
./guessing_game
```

---

### 2. Simple Calculator

**File:** [`2 Simple Calculator/calculator.c`](2%20Simple%20Calculator/calculator.c)

A menu-driven calculator supporting six basic arithmetic operations with error handling.

**Features:**

- Addition, subtraction, multiplication, division
- Modulus operation using `fmod()` for floating-point numbers
- Power calculation using `pow()`
- Division by zero error handling
- Continuous operation with menu loop
- Uses `NAN` (Not a Number) for invalid results

**Concepts Covered:**

- Mathematical functions (`math.h`)
- Switch-case statements
- Function modularity with `display_menu()`
- Error handling with `stderr`
- While loops for continuous execution

**How to Run:**

```bash
gcc "2 Simple Calculator/calculator.c" -o calculator -lm
./calculator
```

---

### 3. Digital Clock

**File:** [`3 Digital Clock/clock.c`](3%20Digital%20Clock/clock.c)

A real-time digital clock displaying current time and date with format options.

**Features:**

- Real-time clock updates every second
- 12-hour and 24-hour format options
- Current date display (Day, Date, Month, Year)
- Cross-platform screen clearing
- Uses system time functions

**Concepts Covered:**

- Time manipulation (`time.h`, `time_t`, `struct tm`)
- String formatting with `strftime()`
- System calls (`system()`)
- Conditional compilation (`#ifdef _WIN32`)
- Infinite loops with `sleep()`

**How to Run:**

```bash
gcc "3 Digital Clock/clock.c" -o clock
./clock
```

---

### 4. Progress Bar

**File:** [`4 Progress bar/progress_bar.c`](4%20Progress%20bar/progress_bar.c)

A terminal-based multi-task progress bar simulator displaying concurrent task completion.

**Features:**

- Simulates 5 concurrent tasks
- Visual progress bars with percentage
- Random completion rates for each task
- Real-time display updates
- Screen clearing for smooth animation

**Concepts Covered:**

- Structures (`typedef struct`)
- Arrays of structures
- For loops and nested loops
- Screen manipulation
- Progress visualization algorithms

**How to Run:**

```bash
gcc "4 Progress bar/progress_bar.c" -o progress_bar
./progress_bar
```

---

### 5. User Management System

**File:** [`5 User Management/user_management.c`](5%20User%20Management/user_management.c)

A secure user registration and login system with password masking functionality.

**Features:**

- User registration (up to 10 users)
- Secure login authentication
- Password masking during input (platform-specific)
- Username and password validation
- Cross-platform terminal control

**Concepts Covered:**

- Arrays of structures
- String manipulation (`strcmp()`, `strcspn()`, `fgets()`)
- Platform-specific programming (`conio.h` for Windows, `termios.h` for Unix)
- Security concepts (password masking)
- Function pointers and modular design

**How to Run:**

```bash
# Windows
gcc "5 User Management/user_management.c" -o user_management

# Linux/macOS
gcc "5 User Management/user_management.c" -o user_management
./user_management
```

---

### 6. Bank Management System

**File:** [`6 Bank Management System/bank.c`](6%20Bank%20Management%20System/bank.c)

A complete banking application with persistent storage using binary file operations.

**Features:**

- Create new bank accounts
- Deposit money
- Withdraw money with balance validation
- Balance inquiry
- Persistent data storage using binary files (`account.dat`)
- File pointer manipulation with `fseek()`

**Concepts Covered:**

- File handling (binary mode: `rb`, `wb`, `rb+`, `ab+`)
- Structures for account data
- File I/O functions (`fopen()`, `fclose()`, `fread()`, `fwrite()`)
- File seeking (`fseek()`, `SEEK_CUR`)
- Data persistence
- Menu-driven architecture

**How to Run:**

```bash
gcc "6 Bank Management System/bank.c" -o bank
./bank
```

**Note:** The program creates an `account.dat` file in the same directory to store account information.

---

### 7. Sudoku Solver

**File:** [`7 Sudoku Solver/sudoku.c`](7%20Sudoku%20Solver/sudoku.c)

An intelligent Sudoku puzzle solver using backtracking algorithm.

**Features:**

- Solves any valid 9x9 Sudoku puzzle
- Backtracking algorithm implementation
- Beautiful formatted puzzle display
- Pre-loaded sample puzzle
- Validates row, column, and 3x3 box constraints

**Concepts Covered:**

- Recursion and backtracking
- 2D arrays (9x9 matrix)
- Algorithm design
- Constraint satisfaction problems
- Nested loops and complex conditionals

**How to Run:**

```bash
gcc "7 Sudoku Solver/sudoku.c" -o sudoku
./sudoku
```

**Algorithm:**

1. Find empty cell
2. Try numbers 1-9
3. Check if number is valid (row, column, box)
4. Recursively solve next cell
5. Backtrack if no solution found

---

### 8. Tic-Tac-Toe

**File:** [`8 Tic-Tac-Toe/tic-tac-toe.c`](8%20Tic-Tac-Toe/tic-tac-toe.c)

An interactive Tic-Tac-Toe game with both multiplayer and AI opponent modes featuring two difficulty levels.

**Features:**

- **Two game modes:**
  - **Multiplayer:** Player X vs Player O (human vs human)
  - **Player vs Computer:** Human vs AI with two difficulty levels
- **Computer difficulty modes:**
  - **Human mode:** Basic AI (blocks immediate wins and attempts to win)
  - **God mode:** Advanced AI (unbeatable - uses strategic positioning)
- Score tracking across multiple games
- Random first player selection
- Beautiful board visualization
- Play-again functionality
- Input validation for all moves

**Concepts Covered:**

- Game logic and state management
- AI algorithm implementation
- Multiple functions and modular code
- Random number generation for game dynamics
- Structures for score tracking
- Advanced control flow
- Conditional game mode handling

**How to Run:**

```bash
gcc "8 Tic-Tac-Toe/tic-tac-toe.c" -o tictactoe -lm
./tictactoe
```

**Game Modes:**

- **Multiplayer:** Two players take turns as X and O
- **Computer (Human Mode):** AI blocks and wins but plays randomly otherwise
- **Computer (God Mode):** AI uses optimal strategy (nearly unbeatable)

**AI Strategy (God Mode):**

1. Check for immediate win
2. Block player's winning move
3. Play center if available
4. Play corners strategically
5. Play any available move

---

## 🚀 Getting Started

### Prerequisites

- A C compiler (GCC recommended)
- Terminal/Command Prompt
- Basic understanding of C programming

### Compilation

Each project can be compiled individually using:

```bash
gcc "project_folder/source_file.c" -o output_name
```

For projects using math functions (calculator, tic-tac-toe), include the math library:

```bash
gcc "project_folder/source_file.c" -o output_name -lm
```

## 📖 Learning Path

These projects are organized in increasing complexity:

1. **Beginner:** Number Guessing Game, Simple Calculator
2. **Intermediate:** Digital Clock, Progress Bar, User Management
3. **Advanced:** Bank Management System, Sudoku Solver, Tic-Tac-Toe

## 🔑 Key Takeaways

- **Modular Programming:** Breaking down problems into functions
- **Data Structures:** Using structs to organize related data
- **File Operations:** Reading and writing data persistently
- **Algorithms:** Implementing solving strategies (backtracking, game AI)
- **Cross-Platform Development:** Writing portable C code
- **Error Handling:** Managing edge cases and invalid inputs
- **User Experience:** Creating interactive and user-friendly terminal applications

## 📝 Notes

- Some projects use platform-specific code with `#ifdef` directives for Windows/Unix compatibility
- The Bank Management System creates a binary file (`account.dat`) in its directory
- Password masking in User Management works differently on Windows (using `conio.h`) vs Unix (using `termios.h`)
- Math library functions require the `-lm` flag during compilation

## 🤝 Contributing

Feel free to fork this repository and enhance any project. Suggestions for improvements:

- Add more game features
- Implement additional algorithms
- Enhance user interfaces
- Add more error handling
- Create unit tests

## 📄 License

These projects are created for educational purposes. Feel free to use and modify them for learning.

---

**Happy Coding! 🎉**

_Developed by Pranav Shilu_
