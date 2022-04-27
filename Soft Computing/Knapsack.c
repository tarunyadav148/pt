
#include <stdio.h>


int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
}


int knapSack(int W, int wt[], int val[], int n)
{
	
	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	else
		return max(
			val[n - 1]
				+ knapSack(W - wt[n - 1],
						wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
}

void InsertWeight(int *wt, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter Weight of bag%d: \n", i+1);
		scanf("%d",&wt[i]);
	}
	
	
}

void InsertValue(int *val, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter Value of bag%d: \n", i+1);
		scanf("%d",&val[i]);
	}
	
}

int main()
{
	// int val[] = { 60, 100, 120 };
	// int wt[] = { 10, 20, 30 };
	int val[100], wt[100];
	int n;
	printf("Enter number of elements to be inserted\n");
	scanf("%d",&n);
	// for (int i = 0; i < n; i++)
	// {
	// 	printf("Enter Value of bag%d: \n", i+1);
		
	// 	scanf("%d",&val[i]);
	// }
	// for (int i = 0; i < n; i++)
	// {
	// 	printf("Enter Weight of bag%d: \n", i+1);
	
	// 	scanf("%d",&wt[i]);
		
	// }
     InsertValue(val, n);
   	 InsertWeight(wt, n);
    
	int W ;
	printf("Enter the maximum capacity of knapsack: \n");
	scanf("%d",&W);
	// int n = sizeof(val) / sizeof(val[0]);
	printf("Total value of total maximum weight that could be stored is: %d", knapSack(W, wt, val, n));
	return 0;
}

