/**
 * The program displays the current time and date in either 24-hour or 12-hour format based on user
 * input, refreshing every second.
 *
 * @param buffer The `buffer` parameter in the `fill_time` and `fill_date` functions is a character
 * array where the formatted time or date string will be stored. It is used to hold the output of the
 * `strftime` function which converts the time or date into a string based on the specified format.
 *
 * @param format The `format` parameter in this code is used to determine whether the time should be
 * displayed in 24-hour format or 12-hour format. The user is prompted to choose between these two
 * options at the beginning of the program by calling the `input_format()` function. The choice made by
 * the user
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void fill_time(char *buffer, int format)
{
    time_t raw_time;         // time_t is a data tipe to store raw time
    struct tm *current_time; // it is inbuilt structure to store local time

    time(&raw_time);                     // it gives you global time
    current_time = localtime(&raw_time); // this converts global time into local timezone

    if (format == 1)
        strftime(buffer, 50, "%H:%M:%S", current_time);
    else
        strftime(buffer, 50, "%I:%M:%S %p", current_time); // this gives you stringify time to display, argument - (char[],size,formate,struct tm *)
}

void fill_date(char *buffer)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);

    strftime(buffer, 100, "%A %d %B %Y", current_time);
}

int input_format()
{
    int format;
    printf("\nChoose the time formate: ");
    printf("\n1. 24 hour formate");
    printf("\n2. 12 hour formate (default)");
    printf("\nMake a choice (1/2): ");
    scanf("%d", &format);
    return format;
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    int format;
    char time[50], date[100];
    format = input_format();

    while (1)
    {
        clear_screen();

        fill_time(time, format);
        fill_date(date);
        printf("\nCurrent time  = %s", time);
        printf("\nCurrent date  = %s", date);

        sleep(1);
    }

    return 0;
}