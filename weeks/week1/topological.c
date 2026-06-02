#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;
void topologicalSort(int n){
    int i, j, count = 0;
    for(i = 0; i < n; i++){
        indegree[i] = 0;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(graph[i][j] == 1){
                indegree[j]++;
            }
        }
    }
    for(i = 0; i < n; i++){
        if(indegree[i] == 0){
            queue[rear++] = i;
        }
    }
    printf("Topological Ordering: ");
    while(front < rear){
        int vertex = queue[front++];
        printf("%d ", vertex);
        count++;
        for(i = 0; i < n; i++){
            if(graph[vertex][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0){
                    queue[rear++] = i;
                }
            }
        }
    }
    if(count != n){
        printf("\nGraph contains a cycle. Topological ordering not possible.");
    }
}
int main(){
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    topologicalSort(n);
    return 0;
}