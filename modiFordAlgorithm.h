
#include <iostream>


using namespace std;


#ifndef MODIFORDALGORITHM
#define MODIFORDALGORITHM
/***********************************************/

struct Edge
{
	int Source;
	int Destination;
	int Weight;
};

struct Graph
{
	int NumVertices;
	int NumEdges;
	struct Edge* edge;
};

static struct Graph* CreateGraph(int numVertices, int numEdges)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->NumVertices = numVertices;
	graph->NumEdges = numEdges;
	graph->edge = (struct Edge*)malloc(graph->NumEdges * sizeof(struct Edge));

	return graph;
}

static void Print(int distance[], int count)
{
	printf("Vertex   Distance to source\n");

	for (int i = 0; i < count; ++i)
		printf("%d\t %d\n", i, distance[i]);
}

static void fordAlgorithm(struct Graph* graph, int source)
{
	int numVertices = graph->NumVertices;
	int numEdges = graph->NumEdges;
	int* distance = (int*)malloc(sizeof(int) * numVertices);

	for (int i = 0; i < numVertices; i++)
		distance[i] = INT_MAX;

	distance[source] = 0;

	for (int i = 1; i <= numVertices - 1; ++i)
	{
		for (int j = 0; j < numEdges; ++j)
		{
			int u = graph->edge[j].Source;
			int v = graph->edge[j].Destination;
			int weight = graph->edge[j].Weight;

			if (distance[v] == INT_MAX && distance[u] == INT_MAX  && distance[v] > (distance[u] + weight)) {
				distance[v] = distance[u] + weight; 
			}
		}
	}

	

	for (int i = 0; i < numEdges; ++i)
	{
		int u = graph->edge[i].Source;
		int v = graph->edge[i].Destination;
		int weight = graph->edge[i].Weight;

		if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
			printf("Graph contains negative weight cycle.");
	}
	
	Print(distance, numVertices);
}
#endif
