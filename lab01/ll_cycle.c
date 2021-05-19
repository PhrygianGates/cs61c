#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    node *tortoise, *hare;
    tortoise = hare = head;
    while (1) {
        if (hare == NULL || hare->next == NULL) {
            return 0;
        }
        hare = hare->next->next;
        tortoise = tortoise->next;
        if (hare == tortoise) {
            return 1;
        }
    }
    return 0;
}