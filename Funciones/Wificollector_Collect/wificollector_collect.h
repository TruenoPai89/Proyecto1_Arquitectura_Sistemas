#ifndef WIFICOLLECTOR_COLLECT_H
#define WIFICOLLECTOR_COLLECT_H

#define SIZE 1000

struct wificollector_collect {
    int celda;
    char texto[SIZE];
};
extern struct wificollector_collect collectors[21];

void wificollector_collect();
#endif //WIFICOLLECTOR_COLLECT_H
