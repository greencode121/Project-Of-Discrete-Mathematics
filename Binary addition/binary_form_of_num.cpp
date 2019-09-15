#include <stdio.h>
#include <conio.h>
#define size 10

int a[size];
int b[size];
int c[size];

int main()
{
	int a[size];
	int b[size];
	int c[size];

	int num1;
	int num2;
	int count1= 0;
	int count2= 0;
	int sum= 0; 
	
	

	printf("Enter the First number= ");
	scanf("%d", &num1);
	printf("Enter the First number= ");
	scanf("%d", &num2);
		
	
	//---------------------------------------->> Binary form of [num1] <<-----------------------------------------------
	while(num1>=1)
	{
		if(num1%2== 0)	
		{
			a[count1]= 0;
		}
		else
		{
			a[count1]= 1;
		}
		
		num1= num1/2;
		count1++;
	}
		
	printf("\n\n\n"); 
	printf("====>>| [Binary Form] of [%d] |<<=====\n\n", num1); 
	for(int i= (count1-1); i>=0; i--)
	{
		printf(" \na[%d]= %d", i, a[i]);
	}
	printf("\n The value of [count1]= %d", count1); 
	//---------------------------------------------------------------------------------------------------------------------
	
	//---------------------------------------->> Binary form of [num1] <<-----------------------------------------------
	while(num2>=1)
	{
		if(num2%2== 0)	
		{
			b[count2]= 0;
		}
		else
		{
			b[count2]= 1;
		}
		
		num2= num2/2;
		count2++;
	}
	
	
	printf("\n\n\n"); 
	printf("====>>| [Binary Form] of [%d] |<<=====\n\n", num2); 
	for(int i= (count2-1); i>=0; i--)
	{
		printf(" \nb[%d]= %d", i, b[i]);
	}
	printf("\n The value of [count2]= %d", count2); 
	//---------------------------------------------------------------------------------------------------------------------
	
	
	
	if(count1>count2)
	{
		for(int i= count2; i<count1; i++)
		{
			b[i]= 0;	
		}
	}	
	printf("\n\n\n"); 
	int carry= 0;
//	for(int i= count1; i>=0; i--)
	for(int i= 0; i<(count1); i++)
	{
		int e= a[i] + b[i];	
		
		printf("\n a[%d]= %d & b[%d]= %d", i, a[i], i, b[i]);
		 	
		e= e+carry;
		carry= 0;
		if(e== 1)
		{
			c[i]= 1;
			carry= 0;
		}
		else if(e== 0)
		{
			c[i]= 0;
			carry= 0;
		}
		else if(e== 2)
		{
			c[i]= 0;
			carry= 1;
		}
		else if(e== 3)
		{
			c[i]= 1;
			carry= 1;
		}
		else
		{
			
		}
		
		
	}
	
	if(carry== 1)
	{
		c[count1]= carry;
	}
	
	printf("\n\n\n");
	printf("\n--->|Result for Binary Addition|<-----\n"); 
	for(int i= (count1); i>=0 ; i--)
	{
		printf("\n \tc[%d]---> [%d] ",i, c[i]); 	
	}	
	
	
	
	
	
	
			
	getch(); 
	return 0; 
}
