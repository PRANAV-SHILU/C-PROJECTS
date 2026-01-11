#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

const int MAX_TASKS = 5;
const int BAR_LENGTH = 50;

typedef struct
{
    int id;
    int progress;
    int step;
} Task;

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_bar(Task task)
{
    int bars_to_show = (task.progress * BAR_LENGTH) / 100;
    
    printf("Task %d:  [", task.id);

    for (int i = 0; i < BAR_LENGTH; i++)
    {
        if (i < bars_to_show)
            printf("=");
        else
            printf(" ");
    }

    printf("] %d%%\n", task.progress);
}

int main()
{
    int i, tasks_incomplete = 1; // flag : 1-continue,  0-stop
    Task task[MAX_TASKS];
    srand(time(NULL));

    // initialization
    for (i = 0; i < MAX_TASKS; i++)
    {
        task[i].id = i + 1;
        task[i].progress = 0;
        task[i].step = rand() % 20 + 1; // Random step between 1 and 10
    }

    while (tasks_incomplete)
    {
        tasks_incomplete = 0;
        clear_screen(); // clears the terminal

        for (i = 0; i < MAX_TASKS; i++)
        {
            task[i].progress += task[i].step;
            if (task[i].progress > 100)
                task[i].progress = 100;
            else if (task[i].progress < 100)
                tasks_incomplete = 1;
            print_bar(task[i]);
        }

        sleep(1); // sleep for 1 second
    }

    printf("\nAll tasks completed!\n\n");
    return 0;
}
