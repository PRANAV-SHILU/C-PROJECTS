# C Headers Reference Guide

A comprehensive reference for all C standard library headers used in this project collection. Click on any header below to expand and view detailed documentation.

## 📚 Headers Overview

This collection uses 7 standard C headers to implement various functionalities:

| Header     | Primary Purpose            | Projects Using It |
| ---------- | -------------------------- | ----------------- |
| `stdio.h`  | Input/Output operations    | All projects      |
| `stdlib.h` | General utilities & memory | 6 projects        |
| `time.h`   | Time and date operations   | 5 projects        |
| `string.h` | String manipulation        | 3 projects        |
| `math.h`   | Mathematical functions     | 2 projects        |
| `unistd.h` | POSIX system calls         | 3 projects        |
| `conio.h`  | Console I/O (Windows)      | 1 project         |

---

<details>
<summary><strong>📄 stdio.h — Standard Input/Output</strong></summary>
<br>

**Description:** The fundamental header for all input/output operations in C, providing formatted I/O, file stream handling, and console interaction.

**Include:** `#include <stdio.h>`

### Functions Used in Projects

#### Console I/O Functions

**`printf()`**

- **Purpose:** Prints formatted output to stdout (console)
- **Syntax:** `int printf(const char *format, ...);`
- **Used in:** All 8 projects
- **Example:**
  ```c
  printf("Welcome to the game!\n");
  printf("Score: %d\n", score);
  ```

**`scanf()`**

- **Purpose:** Reads formatted input from stdin (console)
- **Syntax:** `int scanf(const char *format, ...);`
- **Used in:** All projects except Sudoku Solver
- **Example:**
  ```c
  int choice;
  scanf("%d", &choice);
  ```

**`getchar()`**

- **Purpose:** Reads a single character from stdin
- **Syntax:** `int getchar(void);`
- **Used in:** User Management, Bank Management
- **Example:**
  ```c
  char c = getchar(); // Read one character
  ```

**`putchar()`**

- **Purpose:** Writes a single character to stdout
- **Syntax:** `int putchar(int char);`
- **Used in:** User Management (for password masking)
- **Example:**
  ```c
  putchar('*'); // Display asterisk for password
  ```

**`fgets()`**

- **Purpose:** Reads a line of text from input stream (safer than `gets()`)
- **Syntax:** `char *fgets(char *str, int n, FILE *stream);`
- **Used in:** User Management, Bank Management
- **Example:**
  ```c
  char name[50];
  fgets(name, sizeof(name), stdin);
  ```

#### File I/O Functions

**`fopen()`**

- **Purpose:** Opens a file and returns a file pointer
- **Syntax:** `FILE *fopen(const char *filename, const char *mode);`
- **Modes:** `"r"` (read), `"w"` (write), `"a"` (append), `"rb"` (read binary), `"wb"` (write binary), `"rb+"` (read/write binary), `"ab+"` (append/read binary)
- **Used in:** Bank Management System
- **Example:**
  ```c
  FILE *file = fopen("account.dat", "rb+");
  if (file == NULL) {
      printf("Error opening file!\n");
  }
  ```

**`fclose()`**

- **Purpose:** Closes an open file stream
- **Syntax:** `int fclose(FILE *stream);`
- **Used in:** Bank Management System
- **Example:**
  ```c
  fclose(file);
  ```

**`fread()`**

- **Purpose:** Reads data from a binary file
- **Syntax:** `size_t fread(void *ptr, size_t size, size_t count, FILE *stream);`
- **Used in:** Bank Management System
- **Example:**
  ```c
  Account acc;
  fread(&acc, sizeof(acc), 1, file);
  ```

**`fwrite()`**

- **Purpose:** Writes data to a binary file
- **Syntax:** `size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);`
- **Used in:** Bank Management System
- **Example:**
  ```c
  fwrite(&acc, sizeof(acc), 1, file);
  ```

**`fseek()`**

- **Purpose:** Moves the file pointer to a specific location
- **Syntax:** `int fseek(FILE *stream, long offset, int origin);`
- **Origins:** `SEEK_SET` (beginning), `SEEK_CUR` (current), `SEEK_END` (end)
- **Used in:** Bank Management System
- **Example:**
  ```c
  // Move back one record to update it
  fseek(file, -(long)sizeof(acc), SEEK_CUR);
  ```

**`fprintf()`**

- **Purpose:** Prints formatted output to a file stream (including stderr)
- **Syntax:** `int fprintf(FILE *stream, const char *format, ...);`
- **Used in:** Simple Calculator, Bank Management
- **Example:**
  ```c
  fprintf(stderr, "Error! Division by zero.\n");
  ```

**`fflush()`**

- **Purpose:** Flushes the output buffer of a stream
- **Syntax:** `int fflush(FILE *stream);`
- **Used in:** User Management (to ensure password prompt displays)
- **Example:**
  ```c
  printf("Enter password: ");
  fflush(stdout);
  ```

</details>

---

<details>
<summary><strong>🔧 stdlib.h — Standard Library Utilities</strong></summary>
<br>

**Description:** Provides general-purpose functions including memory allocation, process control, random number generation, and type conversions.

**Include:** `#include <stdlib.h>`

### Functions Used in Projects

**`rand()`**

- **Purpose:** Generates a pseudo-random integer between 0 and `RAND_MAX`
- **Syntax:** `int rand(void);`
- **Used in:** Number Guessing Game, Progress Bar, Tic-Tac-Toe
- **Example:**
  ```c
  int random = rand() % 100 + 1; // Random number 1-100
  ```

**`srand()`**

- **Purpose:** Seeds the random number generator
- **Syntax:** `void srand(unsigned int seed);`
- **Used in:** Number Guessing Game, Progress Bar, Tic-Tac-Toe
- **Example:**
  ```c
  srand(time(NULL)); // Seed with current time
  ```

**`system()`**

- **Purpose:** Executes a system command
- **Syntax:** `int system(const char *command);`
- **Used in:** Digital Clock, Progress Bar, Tic-Tac-Toe (for screen clearing)
- **Example:**
  ```c
  #ifdef _WIN32
      system("cls");  // Windows
  #else
      system("clear"); // Unix/Linux
  #endif
  ```

**`exit()`**

- **Purpose:** Terminates the program with a status code
- **Syntax:** `void exit(int status);`
- **Note:** Not directly used in current projects, but important for error handling

**Memory Management Functions**

- `malloc()`, `calloc()`, `realloc()`, `free()` — Not used in current projects, but essential for dynamic memory allocation

</details>

---

<details>
<summary><strong>⏰ time.h — Time and Date Functions</strong></summary>
<br>

**Description:** Provides functions for time manipulation, date formatting, and measuring time intervals.

**Include:** `#include <time.h>`

### Types and Functions Used

**`time_t`**

- **Purpose:** Data type to store calendar time (usually seconds since Unix epoch)
- **Used in:** Number Guessing Game, Digital Clock, Progress Bar, Tic-Tac-Toe
- **Example:**
  ```c
  time_t raw_time;
  ```

**`struct tm`**

- **Purpose:** Structure containing broken-down time components (year, month, day, hour, etc.)
- **Used in:** Digital Clock
- **Members:** `tm_year`, `tm_mon`, `tm_mday`, `tm_hour`, `tm_min`, `tm_sec`, `tm_wday`, etc.

**`time()`**

- **Purpose:** Returns current calendar time
- **Syntax:** `time_t time(time_t *timer);`
- **Used in:** All projects using random numbers or time display
- **Example:**
  ```c
  srand(time(NULL)); // For random seeding
  time_t raw_time;
  time(&raw_time); // Get current time
  ```

**`localtime()`**

- **Purpose:** Converts `time_t` to local time as `struct tm`
- **Syntax:** `struct tm *localtime(const time_t *timer);`
- **Used in:** Digital Clock
- **Example:**
  ```c
  time_t raw_time;
  time(&raw_time);
  struct tm *current_time = localtime(&raw_time);
  ```

**`strftime()`**

- **Purpose:** Formats date and time into a string
- **Syntax:** `size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr);`
- **Used in:** Digital Clock
- **Common formats:** `%H` (hour 24), `%I` (hour 12), `%M` (minute), `%S` (second), `%p` (AM/PM), `%A` (day name), `%B` (month name), `%Y` (year)
- **Example:**
  ```c
  char buffer[50];
  strftime(buffer, 50, "%H:%M:%S", current_time); // 14:30:45
  strftime(buffer, 50, "%I:%M:%S %p", current_time); // 02:30:45 PM
  strftime(buffer, 100, "%A %d %B %Y", current_time); // Monday 23 January 2026
  ```

</details>

---

<details>
<summary><strong>📝 string.h — String Manipulation</strong></summary>
<br>

**Description:** Provides functions for string operations, memory manipulation, and character array handling.

**Include:** `#include <string.h>`

### Functions Used in Projects

**`strcmp()`**

- **Purpose:** Compares two strings lexicographically
- **Syntax:** `int strcmp(const char *str1, const char *str2);`
- **Returns:** 0 if equal, negative if str1 < str2, positive if str1 > str2
- **Used in:** User Management System (password verification)
- **Example:**
  ```c
  if (strcmp(username, users[i].username) == 0) {
      // Strings are equal
  }
  ```

**`strcspn()`**

- **Purpose:** Finds the length of the initial segment not containing specified characters
- **Syntax:** `size_t strcspn(const char *str1, const char *str2);`
- **Used in:** User Management, Bank Management (removing newline from `fgets()`)
- **Example:**
  ```c
  char name[50];
  fgets(name, sizeof(name), stdin);
  int index = strcspn(name, "\n");
  name[index] = '\0'; // Remove newline
  ```

**Other Common Functions (Listed but not used in current projects):**

- `strcpy()` — Copy strings
- `strcat()` — Concatenate strings
- `strlen()` — Get string length

</details>

---

<details>
<summary><strong>🔢 math.h — Mathematical Functions</strong></summary>
<br>

**Description:** Provides mathematical functions for floating-point computations and constants.

**Include:** `#include <math.h>`

**Compilation Note:** Requires linking with math library: `gcc file.c -o output -lm`

### Functions and Constants Used

**`pow()`**

- **Purpose:** Calculates power (base^exponent)
- **Syntax:** `double pow(double base, double exponent);`
- **Used in:** Simple Calculator
- **Example:**
  ```c
  double result = pow(2.0, 3.0); // 2^3 = 8.0
  ```

**`fmod()`**

- **Purpose:** Calculates floating-point remainder (modulus for doubles)
- **Syntax:** `double fmod(double x, double y);`
- **Used in:** Simple Calculator (modulus of floating-point numbers)
- **Example:**
  ```c
  double result = fmod(7.5, 2.5); // 0.0
  ```

**`isnan()`**

- **Purpose:** Checks if a value is NaN (Not a Number)
- **Syntax:** `int isnan(double x);`
- **Used in:** Simple Calculator (error checking)
- **Example:**
  ```c
  if (!isnan(result)) {
      printf("Result: %.2lf\n", result);
  }
  ```

**`NAN`**

- **Purpose:** Constant representing "Not a Number"
- **Used in:** Simple Calculator (error return value)
- **Example:**
  ```c
  if (divisor == 0) {
      result = NAN; // Indicate error
  }
  ```

**Other Functions (Not used in current projects):**

- Trigonometric: `sin()`, `cos()`, `tan()`, `asin()`, `acos()`, `atan()`
- Logarithmic: `log()`, `log10()`, `exp()`
- Rounding: `ceil()`, `floor()`, `round()`
- Other: `sqrt()`, `abs()`, `fabs()`

</details>

---

<details>
<summary><strong>🐧 unistd.h — POSIX System Calls</strong></summary>
<br>

**Description:** POSIX standard header providing access to OS system calls. Available on Unix/Linux/macOS, not standard on Windows.

**Include:** `#include <unistd.h>`

**Platform:** Unix/Linux/macOS (use `_sleep()` or `Sleep()` on Windows)

### Functions Used in Projects

**`sleep()`**

- **Purpose:** Suspends program execution for specified seconds
- **Syntax:** `unsigned int sleep(unsigned int seconds);`
- **Used in:** Digital Clock, Progress Bar
- **Example:**
  ```c
  sleep(1); // Pause for 1 second
  ```

**Terminal Control (Used in User Management for password masking):**

**`tcgetattr()`**

- **Purpose:** Gets terminal attributes
- **Syntax:** `int tcgetattr(int fd, struct termios *termios_p);`
- **Used in:** User Management (Unix/Linux password masking)

**`tcsetattr()`**

- **Purpose:** Sets terminal attributes
- **Syntax:** `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);`
- **Used in:** User Management (Unix/Linux password masking)

**Example (Password Masking on Unix):**

```c
struct termios old_props, new_props;
tcgetattr(STDIN_FILENO, &old_props);
new_props = old_props;
new_props.c_lflag &= ~(ECHO | ICANON); // Disable echo
tcsetattr(STDIN_FILENO, TCSANOW, &new_props);
// Read password...
tcsetattr(STDIN_FILENO, TCSANOW, &old_props); // Restore
```

</details>

---

<details>
<summary><strong>💻 conio.h — Console I/O (Windows)</strong></summary>
<br>

**Description:** Non-standard header for DOS/Windows console I/O operations. Provides direct keyboard input and screen control.

**Include:** `#include <conio.h>`

**Platform:** Windows only (MinGW, Turbo C, etc.)

### Functions Used in Projects

**`_getch()` / `getch()`**

- **Purpose:** Reads a character from keyboard without echoing to screen
- **Syntax:** `int _getch(void);` (modern) or `int getch(void);` (older)
- **Used in:** User Management System (Windows password masking)
- **Returns:** ASCII value of key pressed (including special keys)
- **Example:**
  ```c
  char password[30];
  int i = 0;
  int ch;
  while ((ch = _getch()) != '\r') { // '\r' is Enter key
      if (ch == 8 || ch == 127) { // Backspace or Delete
          if (i > 0) {
              i--;
              printf("\b \b"); // Erase * from screen
          }
      } else {
          password[i++] = (char)ch;
          putchar('*'); // Show * instead of character
      }
  }
  password[i] = '\0';
  ```

**Special Key Codes:**

- `8` or `\b` — Backspace
- `127` — Delete
- `13` or `\r` — Enter (carriage return)
- `27` — Escape

**Other Functions (Not used in current projects):**

- `clrscr()` — Clear screen (use `system("cls")` instead)
- `textcolor()` — Set text color
- `gotoxy()` — Move cursor to position

</details>

---

## 🔍 Quick Reference Table

### Most Frequently Used Functions

| Function             | Header   | Purpose                  | Projects Count |
| -------------------- | -------- | ------------------------ | -------------- |
| `printf()`           | stdio.h  | Display output           | 8/8            |
| `scanf()`            | stdio.h  | Read input               | 7/8            |
| `time()`             | time.h   | Get current time         | 5/8            |
| `srand()`            | stdlib.h | Seed random generator    | 3/8            |
| `rand()`             | stdlib.h | Generate random number   | 3/8            |
| `system()`           | stdlib.h | Execute system command   | 3/8            |
| `strcmp()`           | string.h | Compare strings          | 2/8            |
| `strcspn()`          | string.h | Find character in string | 2/8            |
| `fopen()`            | stdio.h  | Open file                | 1/8            |
| `fread()`/`fwrite()` | stdio.h  | Read/Write binary files  | 1/8            |

---

## 💡 Usage Tips

### File I/O Best Practices

```c
FILE *file = fopen("data.txt", "r");
if (file == NULL) {
    fprintf(stderr, "Error: Cannot open file\n");
    return 1;
}
// ... use file ...
fclose(file); // Always close files
```

### Random Number Generation

```c
srand(time(NULL)); // Seed once at program start
int num = rand() % 100 + 1; // Random between 1-100
```

### String Input Safety

```c
char name[50];
fgets(name, sizeof(name), stdin); // Safer than gets()
name[strcspn(name, "\n")] = '\0'; // Remove newline
```

### Cross-Platform Code

```c
#ifdef _WIN32
    #include <conio.h>
    system("cls");
#else
    #include <unistd.h>
    system("clear");
#endif
```

---

## 📌 Important Notes

1. **Math Library Compilation:** When using `math.h`, compile with `-lm` flag:

   ```bash
   gcc calculator.c -o calculator -lm
   ```

2. **Platform-Specific Headers:**
   - `conio.h` — Windows only
   - `unistd.h` — Unix/Linux/macOS only
   - Use conditional compilation (`#ifdef`) for cross-platform code

3. **File Modes:**
   - Text mode: `"r"`, `"w"`, `"a"`
   - Binary mode: `"rb"`, `"wb"`, `"ab"`, `"rb+"`, `"ab+"`

4. **Buffer Safety:**
   - Always use `fgets()` instead of `gets()` (deprecated/unsafe)
   - Check return values of file operations
   - Use `sizeof()` for buffer size limits

---

**For more details, refer to the [C Standard Library Documentation](https://en.cppreference.com/w/c) or use `man function_name` in Unix terminal.**

_This reference guide covers all headers and functions used in the 8 C projects in this repository._
