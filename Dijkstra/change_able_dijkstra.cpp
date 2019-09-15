#include<stdio.h>
#include<string.h>
#include <conio.h>

int VerticesN;
struct string
{
	char name[100];
};

string unvisited[100], visited[100], startV;
int unvisitedN = 0, visitedN = 0;

struct edge
{
	string v1;
	string v2;
	int weight;
};

edge edges[100];
int EdgesN = 0;

struct minPath
{
	string Vertex;
	string Previos;
	int dist;
};
minPath minPaths[100];

void get_vertext_edges()
{
	int count;
	
	printf("Enter total num of [edges] beth [vertices] of [graph]= ");
	scanf("%d", &count);
    printf("Enter the source/starting vertext= ");
	scanf("%s", startV.name);
	printf("\n=========================================="); 
	for(int i= 0; i<count; i++)
	{
		printf("\nEnter two vertices= \n");
		scanf("\n%s %s", edges[EdgesN].v1.name, edges[EdgesN].v2.name);
		printf("Enter the [edge value] beth [%s] and [%s]= ",  edges[EdgesN].v1.name, edges[EdgesN].v2.name);
		scanf("%d",  &edges[EdgesN].weight);
		EdgesN++;
		printf("\n------------------------------------------");
	}
	
	
}
void printGraph()
{
	printf("\n\n------------OUR GRAPH-----------");
	printf("\nStarting Vertex is: %s", startV.name);
	printf("\nOur Edges: ");
	for(int i=0; i<EdgesN ; i++)
	{
		printf("\n%s %s %d", edges[i].v1.name, edges[i].v2.name, edges[i].weight);
	}
	printf("\n\n------------------------------");
}
int added(char name[])
{
	for(int i=0; i<unvisitedN; i++)
	{
		if(strcmp(name, unvisited[i].name)== 0)
		{
			return 1;
		}
	}
	return 0;
}
void getUnvisitedVertices()
{
	for(int i=0; i<EdgesN; i++)
	{
		if(!added(edges[i].v1.name))
		{
			strcpy(unvisited[unvisitedN].name , edges[i].v1.name);
			unvisitedN++;
			
		}
		if(!added(edges[i].v2.name))
		{
			strcpy(unvisited[unvisitedN].name , edges[i].v2.name);
			unvisitedN++;
		}
	}
	
	
}

void printVisit()
{
	printf("\nUnvisited: ");
	for(int i=0; i<unvisitedN; i++)
	{
		printf("  %s", unvisited[i].name);
	}
	printf("\nVisited: ");
	for(int i=0; i<visitedN; i++)
	{
		printf(" %s", visited[i].name);
	}	
}
void initializeMinPathTable()
{
	int initialDist = 1;
	for(int i=0; i< EdgesN; i++)
	{
		initialDist = initialDist + edges[i].weight;
	}
	for(int i=0; i<VerticesN; i++)
	{
		strcpy(minPaths[i].Vertex.name, unvisited[i].name);
		strcpy(minPaths[i].Previos.name, "null");
		if(strcmp(minPaths[i].Vertex.name , startV.name) == 0 )
		{
			minPaths[i].dist = 0;
		}
		else
		{
			minPaths[i].dist = initialDist;
		}
	}
}
void printMinPathTable()
{

	printf("\n\nMin Path Now:");
	for(int i=0; i<VerticesN; i++)
	{
		printf("\n%s   %d \t%s", minPaths[i].Vertex.name , minPaths[i].dist, minPaths[i].Previos.name);
	}
}


edgeWeight(char s1[], char s2[])
{
	for(int i=0; i< EdgesN; i++)
	{
		if(  strcmp(edges[i].v1.name, s1)==0 &&  strcmp(edges[i].v2.name, s2)==0)
		{
		
			return edges[i].weight;
		}
		if(  strcmp(edges[i].v2.name, s1)==0 &&  strcmp(edges[i].v1.name, s2)==0)
		{
			return edges[i].weight;
		}
	}
}
int unvisitedIndexInPath(char s[])
{
	for(int i=0; i<VerticesN; i++)
	{
		
		if(strcmp(s , minPaths[i].Vertex.name)==0)
		{
			return i;
		}
	}
}



void dijkstra(char vName[])
{
	//------------------------------------->> Part 1 <<-------------------------------------------
	printf("\n\n\n ....... reducing from [%s].......", vName);
	string vName_unvisited_neighbour[100];
	int N= 0;
	
	for(int i= 0; i<EdgesN; i++)
	{
		if(strcmp(vName, edges[i].v1.name)== 0)	
		{
			strcpy(vName_unvisited_neighbour[N].name, edges[i].v2.name);
			N++;
		}
		if(strcmp(vName, edges[i].v2.name)== 0)
		{
			strcpy(vName_unvisited_neighbour[N].name, edges[i].v1.name);
			N++;
		}
	}
	
	
	//------------------------------------->> Part 2 <<----------------------------------------------
	// here we will remove those vertices from the vName_unvisited_neighbour[ ] which are already visited (i.e source vertex)
	// and does not present inside unvisited[] array --
	// Means our main goal is to remove those neighbour vertices which are already visited and only to keep those unvisited 
	// neighbour by removing the already visited neighbour vertices.
	
	string help[100];
	int x= 0;
	
	for(int i= 0; i<N; i++)
	{
		for(int j= 0; j<unvisitedN; j++)
		{
			if(strcmp(vName_unvisited_neighbour[i].name, unvisited[j].name)== 0)	
			{
				strcpy(help[x].name, vName_unvisited_neighbour[i].name);
				x++;
			}
		}
	}
	

	
	
	//=======================================>> Part 3 <<=====================================================
	// Now as we have filtered only those pure unvisited neighbour vertices from vName_unvisited_neighbour[]
	// and kept inside help[] by removing already visited neighbuor vertices from vName_unvisited_neighbour. 
	// now finally after filteration again we need to move it into the vName_unvisited_neighbour[] array.
	
	N= x;
	for(int i= 0; i< N; i++)
	{
		strcpy(vName_unvisited_neighbour[i].name, help[i].name);
	}
	
	//------------>> now printing the pure unvisited_neighbour_vertices <<------------------
	printf("\nThe set of unvisited neighbour of %s are: ", vName);
	
	for(int i= 0; i<N; i++)
	{
		printf(" %s", vName_unvisited_neighbour[i].name); 
	}
	
	//=======================================>> Part 4 <<=====================================================
	// In this part we need to replace the previous distance value with new least distance value 
	// also we need to replace the previous vertices name with current source vertex name
	// For that at first we need to find the least dist of source vertex 
	
	int vNameDist;
	for(int i= 0; i< VerticesN; i++)
	{
		if(strcmp(vName, minPaths[i].Vertex.name)== 0)
		{
			vNameDist= minPaths[i].dist;	
		}
	}
	
	int weight, distPlusWeight;
	
	for(int i= 0; i<N; i++)
	{
		weight= edgeWeight(vName, vName_unvisited_neighbour[i].name);
		distPlusWeight= vNameDist + weight;
		
		for(int j= 0; j< VerticesN; j++)
		{
			if(strcmp(vName_unvisited_neighbour[i].name, minPaths[j].Vertex.name)== 0)
			{
				if(minPaths[j].dist > distPlusWeight)	
				{
					minPaths[j].dist= distPlusWeight;
					strcpy(minPaths[j].Previos.name, vName);
					
				}	
			}
			
		}
		
	}
	printMinPathTable();
	//=======================================>> Part 5 <<=====================================================
	//Now in this part: we need to move the visited_vertex from unvisited[] array to visited[] array 
		
	strcpy(visited[visitedN].name, vName);
	visitedN++;
	string help1[100];
	int x1= 0;
	
	for(int i= 0; i< unvisitedN; i++)
	{
		if(strcmp(vName, unvisited[i].name)!= 0)
		{
			strcpy(help1[x1].name, unvisited[i].name);
			x1++;
		}
	}
	
	unvisitedN= x1;
	
	for(int i= 0; i<unvisitedN; i++)
	{
		strcpy(unvisited[i].name, help1[i].name);
	}
	
	printVisit();
	//=======================================>> Part 6 <<=======================================================================
	// Here again we need to call the dijkstra( ) function but by passing the pure_unvisited_vertex that have the least distance. 
	
	// means the unvisited vertex which is filtered from the visited vertex/source which is stored inside unvisted[] array.
	
	if(unvisitedN > 0)
	{
		int min_dist, i2, index;
		
		index= unvisitedIndexInPath(unvisited[0].name);
		min_dist= minPaths[index].dist;
		
		for(int i= 0; i< unvisitedN; i++)
		{
			i2= unvisitedIndexInPath(unvisited[i].name);
			if(min_dist > minPaths[i2].dist)
			{
				index= i2;
				min_dist= minPaths[index].dist;
			}
		}
		dijkstra(minPaths[index].Vertex.name);
	}
	
	
}

int main()
{
	get_vertext_edges();
	printGraph();
	getUnvisitedVertices();
	VerticesN = unvisitedN;
	printVisit();
	initializeMinPathTable();
	printMinPathTable();
	dijkstra(startV.name);
	
	getch(); 
	return 0;	
}
