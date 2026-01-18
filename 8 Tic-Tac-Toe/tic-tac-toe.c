/**
 * The code implements a Tic-Tac-Toe game where the player can play against the computer in different
 * difficulty modes.
 * 
 * @return The code provided is a Tic-Tac-Toe game implemented in C. The main function initializes the
 * game by setting the difficulty level, then enters a loop to play the game and prompt the user if
 * they want to play again. The play_game function handles the game logic, alternating between player
 * and computer moves until a win or draw condition is met. The player_move and computer_move functions
 * handle the respective
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define X 'X'
#define O 'O'

int difficulty;
void input_difficulty();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE]);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);

typedef struct
{
  int player;
  int computer;
  int draw;
} Score;

Score score = {0, 0, 0};

int main()
{
  srand(time(NULL));
  int choice;
  input_difficulty();

  do
  {
    play_game();
    printf("\nPlay again? (1 for yes, 0 for no): ");
    scanf("%d", &choice);
  } while (choice == 1);

  printf("Thank you for playing!\n\n");

  return 0;
}

void play_game()
{
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  char current_player = rand() % 2 == 0 ? X : O;

  while (1)
  {
    print_board(board);
    if (current_player == X)
    {
      player_move(board);
      print_board(board);

      if (check_win(board, X))
      {
        score.player++;
        print_board(board);
        printf("Congratulations! You have won!\n");
        break;
      }
      current_player = O;
    }
    else
    {
      computer_move(board);
      print_board(board);
      if (check_win(board, O))
      {
        score.computer++;
        print_board(board);
        printf("Computer has won! But you played well! Try again!\n");
        break;
      }
      current_player = X;
    }

    if (check_draw(board))
    {
      score.draw++;
      printf("It's a draw!\n");
      break;
    }
  }
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col)
{
  return !(row < 0 || col < 0 || row > 2 || col > 2 || board[row][col] != ' ');
}

void player_move(char board[BOARD_SIZE][BOARD_SIZE])
{
  int count = 0, x, y;
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      if (board[i][j] == ' ')
      {
        count++;
        x = i;
        y = j;
      }
    }
  }

  if (count == 1)
  {
    board[x][y] = X;
    return;
  }

  int row, col;
  do
  {
    printf("\nPlayer X's turn,\nEnter row and column (1-3): ");
    scanf("%d %d", &row, &col);

    row--;
    col--;

  } while (!is_valid_move(board, row, col));

  board[row][col] = X;
}

void computer_move(char board[BOARD_SIZE][BOARD_SIZE])
{

  // 1. play for imidiate win
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      if (board[i][j] == ' ')
      {
        board[i][j] = O;
        if (check_win(board, O))
          return;
        board[i][j] = ' ';
      }
    }
  }
  // 2. block player's imidiate win
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      if (board[i][j] == ' ')
      {
        board[i][j] = X;
        if (check_win(board, X))
        {
          board[i][j] = O;
          return;
        }
        board[i][j] = ' ';
      }
    }
  }

  // God mode moves
  if (difficulty == 2)
  {
    // 3. Play center
    if (board[1][1] == ' ')
    {
      board[1][1] = O;
      return;
    }
    // 4. Play corners
    for (int i = 0; i < BOARD_SIZE; i += 2)
    {
      for (int j = 0; j < BOARD_SIZE; j += 2)
      {
        if (board[i][j] == ' ')
        {
          board[i][j] = O;
          return;
        }
      }
    }
  }

  // 5. Play first available move
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      if (board[i][j] == ' ')
      {
        board[i][j] = O;
        return;
      }
    }
  }
}

//  for multiplayer game, used 'computer_move' name for not to change code in
//  other funcitons
/*
void computer_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;
    do
    {
        printf("\nPlayer O's turn,\nEnter row and column (1-3): ");
        scanf("%d %d", &row, &col);

        row--;
        col--;

    } while (!is_valid_move(board, row, col));

    board[row][col] = O;
}
*/

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    // check rows
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
      return 1;
    // check columns
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
      return 1;
  }
  // check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    return 1;
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    return 1;
  return 0;
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE])
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      if (board[i][j] == ' ')
        return 0;
    }
  }
  return 1;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
  clear_screen();
  printf("Score - Player X: %d, Computer O: %d, Draw: %d\n", score.player,
         score.computer, score.draw);

  printf("Tic-Tac-Toe - ");
  if (difficulty == 1)
    printf(" Human mode\n");
  else
    printf(" God mode\n");

  for (int i = 0; i < BOARD_SIZE; i++)
  {
    printf("\n");
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      printf(" %c ", board[i][j]);
      if (j < BOARD_SIZE - 1)
        printf("|");
    }
    if (i < BOARD_SIZE - 1)
      printf("\n---+---+---");
  }
  printf("\n\n");
}

void input_difficulty()
{
  while (1)
  {
    printf("\nWelcome to Tic-Tac-Toe\n");
    printf("1. Human (standard)");
    printf("\n2. God (impossible)");
    printf("\nEnter your choice: ");
    scanf("%d", &difficulty);

    if (difficulty != 1 && difficulty != 2)
      printf("Invalid choice! Please try again\n");
    else
      break;
  }
}

void clear_screen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}