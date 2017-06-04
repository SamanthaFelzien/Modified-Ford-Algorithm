// FELZIEN_HW8_EX12.cpp : Defines the entry point for the console application.
//
// FELZIEN_HW8_EX9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "modiFordAlgorithm.h"


using namespace std;

int main()
{
	int numVertices = 9;
	int numEdges = 12;
	struct Graph* graph = CreateGraph(numVertices, numEdges);

	// Edge a-b
	graph->edge[0].Source = 0;
	graph->edge[0].Destination = 1;
	graph->edge[0].Weight = 1;

	// Edge b-e
	graph->edge[1].Source = 1;
	graph->edge[1].Destination = 4;
	graph->edge[1].Weight = -5;

	// Edge e-f
	graph->edge[2].Source = 4;
	graph->edge[2].Destination = 5;
	graph->edge[2].Weight = 4;

	// Edge c-d
	graph->edge[3].Source = 2;
	graph->edge[3].Destination = 3;
	graph->edge[3].Weight = 1;

	// Edge c-g
	graph->edge[4].Source = 2;
	graph->edge[4].Destination = 6;
	graph->edge[4].Weight = 1;

	// Edge c-h
	graph->edge[5].Source = 2;
	graph->edge[5].Destination = 7;
	graph->edge[5].Weight = 1;

	// Edge d-e
	graph->edge[6].Source = 3;
	graph->edge[6].Destination = 4;
	graph->edge[6].Weight = 4;

	// Edge d-a
	graph->edge[7].Source = 3;
	graph->edge[7].Destination = 0;
	graph->edge[7].Weight = 2;

	// Edge d-i
	graph->edge[8].Source = 3;
	graph->edge[8].Destination = 8;
	graph->edge[8].Weight = 1;

	// Edge i-f
	graph->edge[9].Source = 8;
	graph->edge[9].Destination = 5;
	graph->edge[9].Weight = 1;

	// Edge h-g
	graph->edge[10].Source = 7;
	graph->edge[10].Destination = 6;
	graph->edge[10].Weight = -1;

	// Edge g-d
	graph->edge[11].Source = 6;
	graph->edge[11].Destination = 3;
	graph->edge[11].Weight = -1;


	fordAlgorithm(graph, 5);

	printf("Adjacency Matrix\n");
	printf("    A  B  C  D  E  F  G  H  I \n");
	printf("A   0  1  0  0  0  0  0  0  0\n");
	printf("B   0  0  0  0  1  0  0  0  0\n");
	printf("C   0  0  0  1  0  0  1  1  0\n");
	printf("D   1  0  0  0  1  0  0  0  1\n");
	printf("E   0  0  0  0  0  1  0  0  0\n");
	printf("F   0  0  0  0  0  0  0  0  0\n");
	printf("G   0  0  0  1  0  0  0  0  0\n");
	printf("H   0  0  0  0  0  0  1  0  0\n");
	printf("I   0  0  0  0  0  1  0  0  0\n");

	system("PAUSE");
	return 0;
}
