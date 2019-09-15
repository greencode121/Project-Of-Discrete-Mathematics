#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct arc
{
        char vertix1[100];
        char vertix2[100];
        float weight;
        struct arc * next;
}edge;
edge *initialEdgesHead = NULL;
edge *spanningTreeHead = NULL;
int numberOfEdges;

typedef struct state
{
        char name[100];
        struct state * next;
}states;
states *treesArray[70];
int statesNumber = 0;


void getGraph()
{
    char v1[100],v2[100];
	float weight;

	int count;
	printf("\n\nEnter total num of [edges] beth [vertices] of [graph]= ");
	scanf("%d", &count);
 
	edge *e1, *e2;
	for(int i= 1; i<=count; i++)
	{
     printf("\nEnter any two vertices= \n");
	 scanf("%s %s", v1, v2);
	 printf("\nEnter the weight beth [%s] and [%s]= ", v1, v2);
	 scanf("%f", &weight);   

     e1 = (edge *) malloc (sizeof(edge));
     e1 -> next = NULL;
     strcpy(e1->vertix1, v1);
     strcpy(e1->vertix2, v2);
     e1->weight = weight;
     if(initialEdgesHead == NULL)
     {
         initialEdgesHead = e1; 
     }
     else
     {
         for(e2 = initialEdgesHead; e2->next != NULL; e2 = e2->next);
         e2->next = e1;
     }  
    }
}
void displayTheSystem()
{
	edge *e;
	printf("\n\t===============================\n");
	printf("\t| vert-1  | vert-1 | weight   |");
	printf("\n\t-------------------------------\n");    
 	for(e = spanningTreeHead; e!=NULL; e=e->next)
     {
           printf("\t|    %s    |    %s    |    %0.0f    |",e->vertix1,e->vertix2,e->weight);
		   printf("\n\t-------------------------------\n");
     }

}
void createArrayOfInitialTrees()
{
     states *s;
     int b;
     edge *n;
     s = (states *) malloc (sizeof(states));
     s->next=NULL;
     strcpy(s->name,  initialEdgesHead->vertix1);
     treesArray[statesNumber] = s;
     statesNumber++;
     
     for(n=initialEdgesHead; n!= NULL; n=n->next)
     {
                             b = 1;
                             for(int i=0; i<statesNumber; i++)
                             {
                                  if(strcmp(n->vertix1, treesArray[i]->name) == 0)
                                  {
                                                        b = 0;
                                  }
                             }
                             if(b==1)
                             {
                                    s = (states *) malloc (sizeof(states));
                                    s->next=NULL;
                                    strcpy(s->name,  n->vertix1);
                                    treesArray[statesNumber] = s;
                                    statesNumber++;
                             }
                             
                             b = 1;
                             for(int i=0; i<statesNumber; i++)
                             {
                                  if(strcmp(n->vertix2, treesArray[i]->name) == 0)
                                  {
                                                        b = 0;
                                  }
                             }
                             if(b==1)
                             {
                                    s = (states *) malloc (sizeof(states));
                                    s->next=NULL;
                                    strcpy(s->name,  n->vertix2);
                                    treesArray[statesNumber] = s;
                                    statesNumber++;
                             }
     }
}
edge * lowestEdge()
{
     edge *n, *n1;
     float min;
     if(initialEdgesHead == NULL)
     {
        return NULL;
     }
     else
     {
         n1 = initialEdgesHead;
         min = initialEdgesHead->weight;
         for(n=initialEdgesHead; n!=NULL; n=n->next)
         {
             if( n->weight < min)
             {
                 n1 = n;
                 min = n->weight;
             }
         }
         return n1;
     }
}
void indexOfTheTwoTreesContainingV1andV2(char v1[100], char v2[100], int &i1, int &i2)
{
    //i1 will be the index of the list containing v1
    //i2 will be the index of the list containing v2
    states *s;
    for(int i=0; i<statesNumber; i++)
    {
            for(s=treesArray[i]; s!=NULL; s=s->next)
            {
                 if(strcmp(s->name,v1)==0)
                 {
                      i1 = i;
                 } 
                 if(strcmp(s->name,v2)==0)
                 {
                      i2 = i;
                 } 
            }
    }
}
void addTreeI2toI1(int i1,int i2)
{
     state *s;
     for(s=treesArray[i1]; s->next!=NULL; s=s->next);
     s->next = treesArray[i2];
     treesArray[i2] = NULL;
     
     
}
void addThisLowestWeithedEdgeToTheSpanningTree(char v1[100], char v2[100], float weight)
{
     edge *e = (edge *) malloc (sizeof(edge));
     e->next = NULL;
     strcpy(e->vertix1,v1);
     strcpy(e->vertix2, v2);
     e->weight = weight;
     edge *e1;
     if(spanningTreeHead == NULL)
     {
                         spanningTreeHead = e;
     }
     else
     {
         for(e1=spanningTreeHead; e1->next != NULL; e1=e1->next);
         e1->next = e;
     }
     
}
void deleteTheLowestEdgeFromTheInitialEdgesSet(edge *e)
{
     
     if(e == initialEdgesHead)
     {
          initialEdgesHead = initialEdgesHead->next;
          free(e);
     }
     else
     {
         edge *e1;
         for(e1=initialEdgesHead; e1->next != e; e1=e1->next);
         e1->next = e->next;
         free(e);
     }
}
void kruskal()
{
     

     if(initialEdgesHead == NULL)
     {
                         
                         return;
     }
     int boolean;
     edge *edgeWithLowestWeight = lowestEdge();
     
     int i1,i2;
     indexOfTheTwoTreesContainingV1andV2(edgeWithLowestWeight->vertix1, edgeWithLowestWeight->vertix2,i1,i2);
     if(i2 != i1)
     {
           addTreeI2toI1(i1,i2);
           addThisLowestWeithedEdgeToTheSpanningTree(edgeWithLowestWeight->vertix1, edgeWithLowestWeight->vertix2,edgeWithLowestWeight->weight);
           deleteTheLowestEdgeFromTheInitialEdgesSet(edgeWithLowestWeight);
     }
     else
     {
         deleteTheLowestEdgeFromTheInitialEdgesSet(edgeWithLowestWeight);
     }
     kruskal();
}
main()
{
      printf("\t\tKruskal's Algorithm");
      getGraph();
      createArrayOfInitialTrees();
      printf("\n\n\n==========| The Edges of Spanning Tree |===============\n\n"); 
	  kruskal();
	  printf("======================| OUTPUT |=======================\n\n"); 
	  displayTheSystem();	  	  
      getchar();
}
