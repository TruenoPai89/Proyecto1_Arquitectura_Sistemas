#ifndef WIFICOLLECTOR_COLLECT_H
#define WIFICOLLECTOR_COLLECT_H

struct wificollector_collect {
    int celda;
    char texto[];
};
extern struct wificollector_collect collectors[21];

void wificollector_collect();
#endif //WIFICOLLECTOR_COLLECT_H
