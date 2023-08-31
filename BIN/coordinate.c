#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_POINTS 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX_POINTS];

void initializeParent(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    parent[u] = v;
}

int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int minCostConnectPoints(Point points[], int n) {
    Edge edges[MAX_POINTS * MAX_POINTS];
    int edgeCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges[edgeCount].u = i;
            edges[edgeCount].v = j;
            edges[edgeCount].weight = manhattanDistance(points[i], points[j]);
            edgeCount++;
        }
    }

    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    int cost = 0;
    initializeParent(n);

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            unionSets(u, v);
            cost += edges[i].weight;
        }
    }

    return cost;
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point points[MAX_POINTS];
    printf("Enter the coordinates of each point:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    int result = minCostConnectPoints(points, n);
    printf("Minimum cost to connect all points: %d\n", result);

    return 0;
}
