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
	int flag= 0;
	int count= 1;





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
	





//-------------------------------->> filtering the same_vertex and diff_vertex from the edges table
//  and storing them to same_vetex[] and diff_vertex[] <<---------------------------------------------------------				
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
	printf("\n\n===========>> Same vertex[] <<=================\n");
	for(int i= 0; i< same_vertex_count; i++)
	{
		printf(" \n\tsame_vertex[%d]---> %s %s", i, same_vertex[i].v1.name, same_vertex[i].v2.name ); 	
	} 
	printf("\n==============================================="); 
	
	printf("\n\n\n===========>> diff vertex[]  <<================\n");
	for(int i= 0; i< diff_vertex_count; i++)
	{
		printf(" \n\tdiff_vertex[%d]---> %s %s", i, diff_vertex[i].v1.name, diff_vertex[i].v2.name ); 	
	} 
	printf("\n===============================================\n"); 
//----------------------------------------------------------------------------------------------------------------
	
	
	
	
//===========================>> Main login for checking the transitive pair <<====================================
	if(same_vertex_count>0)
	{
		printf("\n==================================================\n");
		printf("| Sorry! it doesn't holds [Asymmetric relation] |\n");
		printf("==================================================\n");
	}
	else
	{
		for(int i= 0; i<len; i++)
		{
			for(int j= 0; j<len; j++)
			{
				if(i!= j)
				{
					if(strcmp(diff_vertex[i].v1.name, diff_vertex[j].v2.name)== 0 && 
					   strcmp(diff_vertex[i].v2.name, diff_vertex[j].v1.name)== 0)
					{
						flag= 1;
					}
					else
					{
					
					}
				}
			}
		}
		//----------------->> checking wheather the flag value is changed or not 
		//----------------->> if flag value is changed to 1 i.e flag= 1 then it doesnot hold symmetric relation
		//----------------->> if flag value doesn't changed to 1  means remain same i.e flag= 0 then it hold 
		//----------------->> symmetric relation
	
		
		if(flag== 1)
		{
			printf("\n==================================================\n");
			printf("| Sorry! it doesn't holds [Asymmetric relation] |\n");
			printf("==================================================\n");
		}
		else
		{
			printf("\n===============================================\n");
			printf("|      It holds [Asymmetric relation ]        |\n");
			printf("===============================================\n");
		}	
	
	}
//----------------------------------------------------------------------------------------------------------------

	
	
	getch();
	return 0;
}
