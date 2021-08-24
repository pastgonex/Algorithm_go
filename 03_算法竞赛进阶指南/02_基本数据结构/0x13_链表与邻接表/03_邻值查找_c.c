#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX 0x3F3F3F3F
#define N 100005

typedef struct Node {
    int val;
    int idx;
    struct Node* prev;
    struct Node* next;
} Node, *pNode;

int cmp(const void* lhs, const void* rhs) {
    return ((const Node*)lhs)->val - ((const Node*)rhs)->val;
}

Node nodes[N];
pNode p[N];
int ans[N * 2];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &nodes[i].val);
        nodes[i].idx = i;
        nodes[i].prev = nodes[i].next = NULL;
    }

    qsort(nodes, n, sizeof(Node), cmp);

    for (int i = 0; i < n; ++i) {
        nodes[i].prev = (i - 1 >= 0 ? &nodes[i - 1] : NULL);
        nodes[i].next = (i + 1 < n ? &nodes[i + 1] : NULL);
        p[nodes[i].idx] = &nodes[i];
    }

    for (int i = n - 1, j = 0, ldiff, rdiff; i >= 1; --i) {
        pNode prev = p[i]->prev, next = p[i]->next;
        ldiff = prev ? p[i]->val - prev->val : MAX;
        rdiff = next ? next->val - p[i]->val : MAX;
        if (ldiff <= rdiff) {
            ans[2 * (i - 1)] = ldiff;
            ans[2 * (i - 1) + 1] = prev->idx + 1;
        }
        else {
            ans[2 * (i - 1)] = rdiff;
            ans[2 * (i - 1) + 1] = next->idx + 1;
        }

        if (prev) { prev->next = next; }
        if (next) { next->prev = prev; }
        p[i]->prev = p[i]->next = NULL;
    }

    for (int i = 0; i < n - 1; ++i) {
        printf("%d %d\n", ans[2 * i], ans[2 * i + 1]);
    }
    return 0;
}