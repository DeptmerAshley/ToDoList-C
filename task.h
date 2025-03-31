#ifndef TASK_H
#define TASK_H

typedef struct Task {
    int id;
    char description[256];
    int completed; // 0 = incomplete, 1 = complete

    struct Task *next;
} Task;

#endif