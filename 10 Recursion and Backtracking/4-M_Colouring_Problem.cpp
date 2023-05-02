#include<bits/stdc++.h>
using namespace std;

// only ? O(N^M) : O(N)
bool isSafe(int node, int colorArray[], bool graph[101][101], int n, int col){
    
    for(int i=0; i<n; i++){

        if(i != node && graph[i][node] == 1 && colorArray[i] == col) 
            return false;
    }

    return true;
}

bool helper(int node, int colorArray[], int m, int n, bool graph[101][101]) {

    if(node == n) return true;

    for(int col=1; col<=m; col++){

        if(isSafe(node, colorArray, graph, n, col)){

            colorArray[node] = col;

            if(helper(node + 1, colorArray, m, n, graph)) return true;

            colorArray[node] = 0; // backtracking
        }
    }

    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int n){
  
    int colorArray[n] = {0};

    return helper(0, colorArray, m, n, graph);
}

int main(){

    int n = 4; // nodes
    int m = 3; // max colors can be used

    bool graph[101][101];

    memset(graph, false, sizeof(graph));

    // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
    graph[0][1] = 1; graph[1][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][0] = 1; graph[0][3] = 1;
    graph[0][2] = 1; graph[2][0] = 1;

    if(graphColoring(graph, m, n)) cout<<"Possible";
    else cout<<"Not possible";

    return 0;
}