# Dijkstra-s-Algorithm-C-Program-
Skills shown: Algorithms, C Programming, Data Structures
#include <stdio.h>
#define INF 9999
#define V 5

void dijkstra(int graph[V][V], int start) {
    int dist[V], visited[V], count, mindist, next, i, j;
    for(i=0;i<V;i++){ dist[i]=INF; visited[i]=0; }
    dist[start]=0;

    for(count=0;count<V-1;count++) {
        mindist=INF;
        for(i=0;i<V;i++)
            if(!visited[i] && dist[i]<mindist) {
                mindist=dist[i];
                next=i;
            }
        visited[next]=1;
        for(i=0;i<V;i++)
            if(!visited[i] && mindist+graph[next][i]<dist[i])
                dist[i]=mindist+graph[next][i];
    }

    printf("Vertex\tDistance\n");
    for(i=0;i<V;i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int graph[V][V]={{0,6,INF,1,INF},{6,0,5,2,2},{INF,5,0,INF,5},{1,2,INF,0,1},{INF,2,5,1,0}};
    dijkstra(graph,0);
    return 0;
}
