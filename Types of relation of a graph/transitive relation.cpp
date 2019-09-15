#include <stdio.h>
#include <conio.h>
#include <string.h>
#define size 10

struct string 
{
	char name[10];	
};

struct edge
{
	string v1;
	string v2;
};


int main()
{
	
	
	int len;
	printf("Enter how many subset you want to enter= ");
	scanf("%d", &len);

 	edge edges[len];
 	edge same_vertex[len];
 	edge diff_vertex[len];

 	int same_vertex_count= 0;
 	int diff_vertex_count= 0;
	int flag= 0;  //------------------------>> condition for not repeating msg[i.e vertex not in the list ] <<-----------------------------
	int count= 1;
	int count1= 1;
	



	
//---------------------------------->> Taking input of element of subset <<---------------------------------------	
	printf("\n\n------| Enter element of  [%d] subset |-------\n", len); 
	for(int i= 0; i<len; i++)
	{	
		printf("\nEnter any two vertices of subset[%d]= \n", i+1); 
		scanf("%s %s", edges[i].v1.name, edges[i].v2.name);
	}
//----------------------------------------------------------------------------------------------------------------		




	 	
//---------------------------------------->> printing edges or subsetTable <<-------------------------------------
	printf("\n\n\n\n===============>> Edge Table <<================\n" ); 
	printf("             --------------------\n");
	printf("             | set[%d] | v1 | v2 |", len); 
	printf("\n             --------------------");
	for(int i= 0; i<len; i++)
	{	
		printf("\n             | set[%d] | %s  |  %s |",i, edges[i].v1.name, edges[i].v2.name);
	}
	printf("\n             --------------------\n");
	printf("\n\n\n");	
//------------------------------------------------------------------------------------------------------





	
//---------------------------->> Printing the subset of relation <<-----------------------------------------------
	printf("\n\n\n");	
	printf("================================================\n");
	printf("|         Subset of a Relation                 |");
	printf("\n================================================");
	printf("\n\n Relation = {");
	for(int i= 0; i<len; i++)
	{
		printf(" (%s,%s) " , edges[i].v1.name, edges[i].v2.name);
	}
	printf("}");
	
	printf("\n\n"); 
//----------------------------------------------------------------------------------------------------------------






//--//-------------------------------->> filtering the same_vertex and diff_vertex from the edges table
//  and storing them to same_vetex[] and diff_vertex[] <<-----------------------------------------------					
	for(int i= 0; i<len; i++)
	{
		if(strcmp(edges[i].v1.name, edges[i].v2.name)== 0)
		{
			strcpy(same_vertex[same_vertex_count].v1.name, edges[i].v1.name);
			strcpy(same_vertex[same_vertex_count].v2.name, edges[i].v1.name);
			
			same_vertex_count++;
			
		}
		else
		{
			strcpy(diff_vertex[diff_vertex_count].v1.name, edges[i].v1.name);
			strcpy(diff_vertex[diff_vertex_count].v2.name, edges[i].v2.name);
			
			diff_vertex_count++;
			
			
		}
	}
//----------------------------------------------------------------------------------------------------------------	





//-------------------->> printing the content of both array same_vertex[] and diff_vertex[] <<--------------------	
	printf("\n\n===========>> Same vertex[] <<====================\n");
	for(int i= 0; i< same_vertex_count; i++)
	{
		printf(" \n\tsame_vertex[%d]---> %s %s", i, same_vertex[i].v1.name, same_vertex[i].v2.name ); 	
	} 
	printf("\n=================================================="); 
	
	printf("\n\n\n===========>> diff vertex[]  <<===================\n");
	for(int i= 0; i< diff_vertex_count; i++)
	{
		printf(" \n\tdiff_vertex[%d]---> %s %s", i, diff_vertex[i].v1.name, diff_vertex[i].v2.name ); 	
	} 
	printf("\n==================================================\n"); 
//----------------------------------------------------------------------------------------------------------------




	
//=======================================>> Step 2 <<=============================================================
//---------------->> checking wheather the all the inputed edges have same vertex name or not i.e v1.name= v2.name
	if(same_vertex_count== len) 
	{
		
		printf("\n\nIt holds [transitive relation ].\n");
		printf("\n\n same_vertex_count= %d", same_vertex_count);
		goto bottom;
	}
//----------------------------------------------------------------------------------------------------------------




	
//-> checking weather all the edges don't have any common vertex or not e.g: edges[i].v2.name != edges[j].v1.name
	for(int i= 0; i<len; i++)	
	{
		for(int j= 0; j<len; j++)
		{
			if(i!= j)
			{
				if(strcmp(diff_vertex[i].v1.name, diff_vertex[j].v2.name)== 0)
				{
					flag= 1;		
				}
				else
				{
							
				}
			}
		}
	}
	
	if(flag== 0)
	{
		printf("\n\n\nIt holds [transitive relation].\n");
		goto bottom;
	}
	else
	{
		
	}
	
	
	for(int i= 0; i<len; i++)
	{
		if(strcmp(edges[i].v1.name, edges[i].v2.name) != 0 ) 		//------------------------------->> for discarding index of array edges[] of loop[i] which have same name of vertex v1 and v2
		{
			
			for(int j= 0; j<len; j++)
			{		
					if(i!= j)										//------------------------------->> because loop[i] and loop[j] should not point to same index of array edges[] 
					{	
						if(strcmp(edges[j].v1.name, edges[j].v2.name)!= 0) 		//------------------------>> once again discarding index of array edges[] 
						{												   		//------------------------>> of loop[j] which have same name of vertex v1 and v2
							if(strcmp(edges[i].v2.name, edges[j].v1.name)== 0) // checking wheather the ist rule of transitive relation is applicable or not to array 
							{												   // edges[] i.e // comparing the 2nd element of ist subset with the ist element of 2nd subset
								for(int c= 0; c<len; c++)                      
								{
									if(i!= c)
									{
										if(strcmp(edges[i].v1.name, edges[c].v1.name)==0 && strcmp(edges[j].v2.name, edges[c].v2.name)== 0 ) //  checking where the array edges[] consist transitive pair or not.
										{
											printf("\n\n It holds [transitive Relation]."); 
											goto bottom;
										}
										else
										{		
											count++;
											if(count== len)
												printf("\n\n It does not holds [transitive Relation]."); 
										}
									}
									
								}
							}
							
						}
					}
				
			}
			printf("\n\n");
		}
	}
//----------------------------------------------------------------------------------------------------------------





	
	bottom:
	/*	
		printf("\n\n Compiler has moved to bottom.");   ----------->> just for tracing code.
	*/

	getch();
	return 0;
}
