#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int v;
    int e;
    int adj[100][100];
} Graph;

typedef struct {
    int size;
    int set[100];
} VertexCover;

void init_graph(Graph *G, int v, int e) {
    G->v = v;
    G->e = e;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            G->adj[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {
    G->adj[u][v] = 1;
    G->adj[v][u] = 1;
}

VertexCover vertex_cover_2approx(Graph *G) {
    VertexCover cover;
    bool visited[100] = { false };

    for (int i = 0; i < G->v; i++) {
        if (!visited[i]) {
            for (int j = 0; j < G->v; j++) {
                if (G->adj[i][j] && !visited[j]) {
                    visited[i] = true;
                    visited[j] = true;
                    cover.set[cover.size++] = i;
                    cover.set[cover.size++] = j;
                    break;
                }
            }
        }
    }

    return cover;
}

int main() {
    Graph G;
    int v, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    init_graph(&G, v, e);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    VertexCover cover = vertex_cover_2approx(&G);

    printf("Vertex cover of size %d: ", cover.size);
    for (int i = 0; i < cover.size; i++) {
        printf("%d ", cover.set[i]);
    }
    printf("\n");

    printf("Edges removed:\n");
    for (int i = 0; i < cover.size; i++) {
        for (int j = i + 1; j < cover.size; j++) {
            if (G.adj[cover.set[i]][cover.set[j]] == 1) {
                printf("(%d, %d)\n", cover.set[i], cover.set[j]);
            }
        }
    }

    return 0;
}
