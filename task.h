#ifndef TASK_H
#define TASK_H

typedef struct {
    int id;
    char description[256];
    int completed; // 0 = incomplete, 1 = complete
} Task;

#endif