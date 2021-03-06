#include<stdio.h>
// Number of verticies in the graph
#define V 4

void printSolution(int colort[]);

/*A utility function to check if the current color assigntment is safe for vertex v*/

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
	return true;
}

/*A recursive utiltiy funtion to solve m coloring problem */

void graphColoring(bool graphColoring(bool graph[V][V], int m, int color[], int v)
{
	/* base case: If all vertuces are assigned a color then
	   return true */
	if (v == V) {
		printSolution(color);
		return;

	}

	/*Consider this vertex v and try different colors*/
	for (int c = 1; c <= m; c++)
	{
		/*Check if assignment of color c to v is fine*/
		if (isSafe(v, graph, m, color, v + 1))
		{
			color[v] = c;
			/*recur to assign color c doesnt lead to a solution the remove it*/
			graphColoring(graph, m, color, v + 1);

			/*If assigning color c doesnt lead to a solution then remove it*/
			color[v] = 0;
		}
	}
}

/*Utility function to print solution*/
void printSolution(int color[])
{
	printf(" Following are the assigned colors \n");
	for (int i = 0; i < V; i++)
		printf(" %d", color[i]; 
	print("\n");
}
//Driver program to test above function
int main()
{
	/*Create following graph and test wether it is 3 colorable
   (3)---(2)
	|   / |
	|  /  |
	| /   |
   (0)---(1)
     */
	bool graph[V][V] = { {0, 1, 1, 1},
	{1, 0, 1, 0},
	{1, 1, 0, 1},
	{1, 0, 1, 0},
	};
	int m = 3; // Number of colors

	int color[V];
	
	for (int i = 0; i < V; i++)
		color[i] = 0;
	graphColoring(graph, m, color, 0);
	return 0;
}


