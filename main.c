#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "task.h"

int mainMenu(int menuChoice)
{
    printf("\n(1): List Tasks\n(2): Add Task\n(3): Mark Task Completed\n(4): Delete Task\n(5): Save Task to File\n(6): Load Tasks from File\n(0): Exit\n");
    printf("Enter your selection: ");
    scanf("%d", &menuChoice);
    return menuChoice;
}

void addTask(Task *tasks, int *count)

void listTasks(Task *tasks, int count)

void completeTask(Task *tasks, int id, int count)

void deleteTask(Task *tasks, int *count, int id)

void saveTasks(Task *tasks, int count)

void loadTasks(Task *tasks, int *count)


int main(){
    
    int menuChoice;
    while (menuChoice != 0)
    {
        menuChoice = mainMenu(menuChoice);
    }

    return 0;
}