# C Headers — Quick Reference

Short, practical descriptions of common C headers and their key functions.

## stdio.h

- Description: Standard input/output — formatted I/O, file streams, and error reporting.
- Major functions: `printf`, `scanf`, `fprintf`, `fscanf`, `fopen`, `fclose`, `fread`, `fwrite`, `fseek`, `ftell`, `perror`, `puts`, `fflush`.

## conio.h

- Description: Console I/O for DOS/Windows compilers (non-standard): direct keyboard and screen control.
- Major functions: `getch`, `clrscr`, `textcolor`.

## string.h

- Description: String and memory utilities — copying, concatenation, comparison, search, and block operations.
- Major functions: `strcpy`, `strcat`, `strlen`, `strcmp`.

## math.h

- Description: Mathematical functions and constants for floating-point computations.
- Major functions: `sin`, `cos`, `tan`, `asin`, `acos`, `atan`, `pow`, `sqrt`, `exp`, `log`, `log10`, `ceil`, `floor`.

## time.h

- Description: Time and date utilities — timestamps, conversions, formatting, and elapsed-time measurement.
- Major functions: `time`, `clock`, `difftime`, `mktime`, `strftime`, `localtime`.
- Common types: `time_t`, `struct tm *`.

## stdlib.h

- Description: General utilities — dynamic memory, process control, conversions, sorting/searching, and RNG.
- Major functions: `malloc`, `calloc`, `realloc`, `free`, `exit`, `atexit`, `system`, `abs`, `rand`, `srand`.

## unistd.h

- Description: POSIX system API for Unix-like systems — low-level I/O, process and filesystem calls for terminal.
- Major functions/syscalls: `read`, `write`, `close`, `sleep`.
