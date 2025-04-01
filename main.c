#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>

#include "task.h"

#define MAX_TASKS 100

struct Task *head = NULL;
char checkMark[4] = "\u2705";
char incomp[4] = "\u274c";

int mainMenu(int menuChoice)
{
    printf("\n(1): List Tasks\n(2): Add Task\n(3): Mark Task Completed\n(4): Delete Task\n(5): Save Task to File\n(6): Load Tasks from File\n(0): Exit\n");
    printf("Enter your selection: ");
    scanf("%d", &menuChoice);
    return menuChoice;
}

void addTask(Task *tasks, int *count);

void listTasks() {
    struct Task *current = head;
    char* desc;
    char* comp;
    
    printf("\n");
    while (current->next != NULL) {
        int id = current->id;
        desc = strcpy(current->description, desc);
        if (current->completed == 0){
            comp = incomp;
        }
        else {
            comp = checkMark;
        }
        printf("%s %d - %s\n", comp, id, desc);
        current = current->next;
    }
    int id = current->id;
    desc = strcpy(current->description, desc);

    if (current->completed == 0){
        comp = incomp;
    }
    else {
        comp = checkMark;
    }
    printf("%s %d - %s\n", comp, id, desc);
}

void completeTask(Task *tasks, int id, int count);

void deleteTask(Task *tasks, int *count, int id);

void saveTasks(Task *tasks, int count);

void loadTasks(const char* fileName) {
    FILE *tasks = fopen(fileName, "r");
    if (!tasks) {
        printf("Error: User Info Not Found\n");
        return;
    }
    
    struct Task *current = NULL;
    char line[250];

    // Skip first line with labels
    if (fgets(line, sizeof(line), tasks) == NULL) {
        fclose(tasks);
        return;
    }

    int numTasks = 0;

    //Iterate through each line of file and populate the Tasks Linked List
    while (fgets(line, sizeof(line),  tasks) != NULL) {
        numTasks++;
        struct Task *taskObj = malloc(sizeof(struct Task));
        char *token = strtok(line, ",");
        if (token) {
            taskObj->id = atoi(token);
            token = strtok(NULL, ",");

            if (token) {
                strcpy(taskObj->description, token);
                token = strtok(NULL, ",");

                if (token) {
                    taskObj->completed = atoi(token);
                    token = strtok(NULL, ",");
                
                    if (head == NULL) {
                        head = taskObj;
                        current = taskObj;
                    }
                    else {
                        current->next = taskObj;
                        current = taskObj;
                    }
                }   
            }
        }
    }
    printf("\nUser Info loaded...\n");
}


int main() {
    setlocale(LC_ALL, "en_US.UTF-8"); // Sets the locale to U.S. English with UTF-8 encoding
    // Load user tasks (Implement multiple users later)
    loadTasks("tasks.csv");
    
    int menuChoice;
    while (menuChoice != 0)
    {
        menuChoice = mainMenu(menuChoice);
        if (menuChoice == 1) {
            listTasks();
        }
    }

    return 0;
}