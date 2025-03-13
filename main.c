#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "task.h"

#define MAX_TASKS 100

int mainMenu(int menuChoice)
{
    printf("\n(1): List Tasks\n(2): Add Task\n(3): Mark Task Completed\n(4): Delete Task\n(5): Save Task to File\n(6): Load Tasks from File\n(0): Exit\n");
    printf("Enter your selection: ");
    scanf("%d", &menuChoice);
    return menuChoice;
}

void addTask(Task *tasks, int *count);

void listTasks(Task *tasks, int count);

void completeTask(Task *tasks, int id, int count);

void deleteTask(Task *tasks, int *count, int id);

void saveTasks(Task *tasks, int count);

Task* loadTasks(Task* userTaskList)  // (Task *tasks, int *count)
{
    FILE* userTasks = fopen("tasks.txt", "r");
    if (userTasks == NULL)
    {
        printf("Cannot locate user information\nExiting...\n");
        return 0;
    }
    userTaskList = malloc(MAX_TASKS * sizeof(Task));
}


int main(){
    
    // int userStartUp = loadTasks();
    // if (userStartUp == 0)
    // {
    //     return 1;
    // }

    Task* userTaskList;
    userTaskList = loadTasks(userTaskList);

    int menuChoice;
    while (menuChoice != 0)
    {
        menuChoice = mainMenu(menuChoice);
    }

    return 0;
}