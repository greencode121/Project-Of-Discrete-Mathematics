#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
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
	char A[size];
	char B[size];
	int count_A= 0;
	int count_B= 0;
	int sbq; //---------------->> i.e sbq stands for [sub set quantity ] <<----------------------------------
	
	
	printf("Enter the Total number of edge[i.e subset]= "); 
	scanf("%d", &sbq);
	printf("=============================================\n");
	if(sbq== 0)
	{
		printf("\n\n\n=====================================================\n");
		printf("\tI hold [Reflexive Relation ]\n");
		printf("=====================================================\n");
		exit(0);
	}
	
	
	 edge edges[sbq]; //-------------->> here if we "struct" keyword to create array of edges as: 
	//-------------->> struct edge edges[] then the result will be wrong for more than 5 subset





//---------------------------------->> Taking input of element of subset <<---------------------------------------
	printf("\n\n------| Enter element of  [%d] subset |-------\n", sbq); 
	for(int i= 0; i<sbq; i++)
	{	
		printf("\nEnter any two vertices of subset[%d]= \n", i+1); 
		scanf("%s %s", edges[i].v1.name, edges[i].v2.name);
	}
//----------------------------------------------------------------------------------------------------------------
	




//---------------------------------------->> printing edges or subsetTable <<-------------------------------------
	printf("\n\n\n\n=========>> Edge Table <<=========\n" ); 
	printf("      --------------------\n");
	printf("      | set[%d] | v1 | v2 |", sbq); 
	printf("\n      --------------------");
	for(int i= 0; i<sbq; i++)
	{	
		printf("\n      | set[%d] | %s  |  %s |",i, edges[i].v1.name, edges[i].v2.name);
	}
	printf("\n      --------------------\n");
//------------------------------------------------------------------------------------------------------





//------------------------------->> Filtering unique vertex from the edges <<-------------------------------------
	char *a, *b;
	for(int i= 0; i<sbq; i++)
	{
		a= edges[i].v1.name;
		b= edges[i].v2.name;
		
		B[count_B]= *a;
		count_B++;			
		B[count_B]= *b;
		count_B++;
	}

//----------------------------------------------------------------------------------------------------------------
	
	
	


//------------------------->> Now copying only the unique element into array A[] from array A[] <<----------------
	int flag= 0;
	int count_test= 0;
	
	for(int i= 0; i<count_B; i++)
	{
		for(int j= 0; j<=i; j++)
		{

			if(B[i]== A[j])
			{
				flag= 1;
				//printf("Dupbicated value [detected]");
				break;
	
			}
			
		}
		if(flag== 0)
		{
			A[count_A]= B[i];
			count_A++;
		}
		flag= 0; //---------------->> point to be remember (i.e here flag value need to be reset)
		
	}
//----------------------------------------------------------------------------------------------------------------

 



//---------------------------->> Printing the subset of relation <<-----------------------------------------------
	printf("\n\n\n");	
	printf("================================================\n");
	printf("|         Subset of a Relation                 |");
	printf("\n================================================");
	printf("\n\n Relation = {");
	for(int i= 0; i<sbq; i++)
	{
		printf(" (%s,%s) " , edges[i].v1.name, edges[i].v2.name);
	}
	printf("}");
	
	printf("\n\n"); 

	printf("================================================\n");
	printf("|       Printing Element of Set A              |");
	printf("\n================================================\n");
	printf("   A= {");
	for(int i= 0; i<count_A; i++)
	{
		printf("  %c  ", A[i]);	
	}	
	printf("}");
//----------------------------------------------------------------------------------------------------------------
	
	



//------------------------------------>> Printing the [cartisian Product] <<--------------------------------------
	printf("\n\n===========================================");
	printf("\n Printing [Cartisian Product] of Set A[]  |\n");
	printf("===========================================");
	for(int i= 0; i<count_A; i++)
	{
		printf("\n\t--------------\n");
		printf("\t");
		for(int j= 0; j<count_A; j++)
		{
			printf("| %c%c ", A[i],A[j]);
		}
		
	}	
	printf("\n\t--------------\n");
//----------------------------------------------------------------------------------------------------------------



	

//---------------------------------->> Main Mechanism <<---------------------------------------------------------
	char *c;
	char *d;
	int count= 0;
	
	for(int i= 0; i<sbq; i++)
	{
		for(int j= 0; j<count_A; j++)
		{
			c= edges[i].v1.name;
			d= edges[i].v2.name;
		
			if(*c== A[j] && *d== A[j])
			{
				count++;
			}
		}
	}
	
	
	if(count== 0)
	{
		printf("\n===============================================\n");
		printf("|         It holds [Irreflexive relation ]     |\n");
		printf("===============================================\n");
	}
	else
	{
		printf("\n==================================================\n");
		printf("| Sorry! it doesn't holds [Irreflexive relation] |\n");
		printf("==================================================\n");
	}
//----------------------------------------------------------------------------------------------------------------	

	getch(); 
	return 0; 
}
