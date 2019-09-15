#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int D, d, q, r;
	int big_num;
		
	int num1, num2;
	printf("Enter any two number= \n");
	scanf("%d %d", &num1, &num2);

	D= num1;
	d= num2;
	
	
	
	r= D%d;
	q= D/d;
	printf("\n=========================================\n");
	printf("|--->| GCD as a linear Comination |<----|\n");
	printf("=========================================\n");
	printf("\n\t  ------------------");
	while(r> 0) 
	{
		D= d;
		d= r;
		r= D%d;
		q= D/d;
		
	} 
	printf("\n\t  ------------------");
	printf("\n\n ");

	if(num1>num2)
	{
		big_num= num1;
	}
	else
	{
		big_num= num2;
	}

	for(int i= 0; i<big_num; i++)
	{
		for(int j= 0; j<big_num; j++)
		{
			int e= num1*i;
			int f= num2*j;
			
			if((e-f)== d)
			{
				printf("\n\n\n=========================================\n"); 
				printf("|\t\t OUTPUT \t\t|");
				printf("\n=========================================\n");
				printf("|\t   %d= %d*%d - %d*%d\t\t|", d, num1, i, num2, j);
				printf("\n-----------------------------------------\n");
				exit(0);
			}
		}
	}


	
	getch();
	return 0; 
}
