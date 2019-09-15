#include <stdio.h>
#include <conio.h>
#define s 10
int main()
{
	int b_count, h_count; 	
	int a[s], b[s], help[s];
	int count= 0, sum= 0;
	
	int size;
	printf("Enter how many elements you want to enter= ");
	scanf("%d", &size);	
	printf("\n");
	for(int i= 0; i<size; i++)
	{
		printf(" Enter the value for a[%d]= ", i);
		scanf("%d", &a[i]); 
		b[i]= a[i];
		sum= sum + a[i];
		
	}
	
	sum= sum+1;
	for(int i= 0; i<size; i++)
	{
		help[i]= sum;
	}
	
	// ----------------->> printing the infinity value <<-------------
	for(int i= 0; i<size; i++)
	{
		b_count= 0;
		h_count= 0;
		for(int j= 0; j<size; j++)
		{
			if(a[i]== b[j])
			{
				b_count++;
			}
		}
		
		for(int c= 0; c<size; c++)
		{
			if(a[i]== help[c])
			{	
				h_count++;
			}						

		}
		
		if(b_count > 0 && h_count== 0)
		{
			help[count]= a[i];
			count++;
		}
	}
	
	
	printf("\n\n\n===============>> Printing the [User Input] value <<==================\n");
	
	for(int i= 0; i<size; i++)
	{
		printf("\n a[%d]= %d", i, a[i]);	
	} 
	
	
	size= count;   //------------------------------------>> initializing the size with count values 
	printf("\n\n=============>>  After filtering [Duplicated] elements <<=============== \n");
	for(int i= 0; i<size; i++)
	{
		a[i]= help[i];
		printf("\n a[%d]= %d", i, a[i]);	
	} 
	
	//====================>> sorting the data in asending form <<======================
	int temp;
	for(int i= 0; i<size; i++)
	{
		for(int j= i+1; j<size; j++)
		{
			if(a[i] > a[j])
			{
				temp= a[i];
				a[i]= a[j];
				a[j]= temp;
			}
		}
	}
	
	printf("\n\n --------->> After[sorting] the array elements  <<--------------------\n");
	for(int i= 0; i<size; i++)
	{
		printf("\n a[%d]= %d", i, a[i]);
	}
	
	//=======================================>> Main formulae <<===================================
	int key;
	printf("\n\n\nEnter the value that \n you want to search= ");
	scanf("%d", &key);
	
	
	
	int F_i= 0;
	int L_i= size-1;
	int mid_index, mid_val;
		
	
	char choice;
	int search_count= 0;
	int L_e_c= 0; 			// L_e_c means [Loop_Execution_count]
	int copy_mid_index;
	int flag= 0;
	
	printf("\n\n\n size= %d", size);
	mid_index= (F_i + L_i)/2;
	copy_mid_index= 0;
	
	int i= 0;
	while(1)
	{
		i++;
		search_count++;
		mid_index= (F_i + L_i)/2;
		mid_val= a[mid_index];
				
		printf("\n\n\nloop count ---> [%d]",i);
		/*
		printf("\n[mid_index]= %d",mid_index);
		printf("\n[copyied_mid_index]= %d",copy_mid_index);			
		*/
		if(mid_index== copy_mid_index)
		{
			printf("\n\nSorry! [%d] is not in the list.", key);
			printf("\nSearching time---> [%d]", search_count);
			break;
		}
		
		copy_mid_index= mid_index;	//--------------->> copying the content of mid_index
		
		
		
	
		if(mid_val== key)
		{
			printf("\n Found on its [%d] search.", search_count);
			printf("\n=================================================");
			printf("\n|\t\tElement has been found: \t|\n");
			printf("|\t\t\t\t\t\t|");
			printf("\n|\t\t   at a[%d]= %d\t\t\t|", mid_index, mid_val);
			printf("\n=================================================\n");
			printf("\n");
			break; 
		}
		
		if(mid_val < key)
		{
			flag= 1;
			F_i= mid_index + 1;
			
			if(F_i > (size-1) )
			{	
				printf("\nSorry! this item [%d] is not in the list.", key);
				break;
					
			}
			
			
		}
		//-------------------------> checking that wheather the value of mid_index got decrease or not <<-----------------
			
		if(mid_val > key)
		{
			flag= 0;
			L_i= mid_index - 1;
			
			if(L_i < 0 )
			{					
				printf("\nSorry! this item [%d] is not in the list.", key);
				break;
			}
			
			
		}

		
		//L_e_c++;
		//	printf(" Loop has been executed [%d] times.", L_e_c);
	}
	getch(); 
	return 0; 
}
