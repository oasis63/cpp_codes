#include<bits/stdc++.h>
using namespace std;


typedef struct node{
    int value;
    node* next;

}node;


node* newNode(int val){
    node* n;
    n=new node;
    n->value = val;
    n->next = NULL;
    return n;
}

typedef struct Graph{
    int v;  // number of vertices of the Graph
    node* *arr;  // arr of linkedList  .. arr of pointers
}Graph;

Graph* createGraph(int vert){
    Graph* graph = new Graph;
    graph->v = vert;

    // array of adjacency list

    graph->arr = new node*[graph->v];

   //node* arr[5];   // array of node pointer

   for(int i=0;i<vert;i++){
    //arr[i]=NULL;
    graph->arr[i]=NULL;
   }

  return graph;

}

// add an edge to an undirected graph

Graph* addEdge(Graph* graph,int src,int dest){

    node* sourceNode = newNode(src);
    node* destNode = newNode(dest);

    // inserting at the begining of the list 
    destNode->next=graph->arr[src];
    graph->arr[src] = destNode;


    sourceNode->next = graph->arr[dest];
    graph->arr[dest] = sourceNode;

    return graph;

}

void printGraph(Graph *graph){

    for(int i=0;i<graph->v;i++){

        printf("\n Adjacency list of vertex %d\n head ", i);

        while(graph->arr[i]!=NULL){
            cout<<"-> "<<graph->arr[i]->value;
            graph->arr[i] = graph->arr[i]->next;
        }
        cout<<endl;
    }
}



int main(){

    // create the graph given in above fugure
    int V = 5;
    Graph* graph = createGraph(V);
    graph = addEdge(graph, 0, 1);
    graph = addEdge(graph, 0, 4);
    graph = addEdge(graph, 1, 2);
    graph = addEdge(graph, 1, 3);
    graph = addEdge(graph, 1, 4);
    graph = addEdge(graph, 2, 3);
    graph = addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;


}

