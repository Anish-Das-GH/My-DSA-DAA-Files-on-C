#include <stdio.h>
void main()
{
	int i = 0, j = 0, temp = 0, dmax = 0, k = 0, tp = 0, n = 0;
	printf("Enter number of jobs: ");
	scanf("%d", &n);
	int job[n], profit[n], deadline[n];
	printf("Enter the job ID ,profit and their dedline:\n");
	for (i = 0; i < n; i++)
		scanf("%d %d %d", &job[i], &profit[i], &deadline[i]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (profit[j] < profit[j + 1])
			{
				temp = profit[j + 1];
				profit[j + 1] = profit[j];
				profit[j] = temp;

				temp = job[j + 1];
				job[j + 1] = job[j];
				job[j] = temp;

				temp = deadline[j + 1];
				deadline[j + 1] = deadline[j];
				deadline[j] = temp;
			}
		}
	}
	printf("Sorting job based on profit are:\nJob:\t");
	for (i = 0; i < n; i++)
		printf("\t%d", job[i]);
	printf("\nProfit:\t");
	for (i = 0; i < n; i++)
		printf("\t%d", profit[i]);
	printf("\nDeadline:");
	for (i = 0; i < n; i++)
		printf("\t%d", deadline[i]);

	for (i = 0; i < n; i++)
	{
		if (deadline[i] > dmax)
			dmax = deadline[i];
	}
	int timeslot[dmax];
	for (i = 0; i < dmax; i++)
		timeslot[i] = -1;
	for (i = 0; i < n; i++)
	{
		k = deadline[i];
		while (k >= 0)
		{
			if (timeslot[k] == -1)
			{
				timeslot[k] = job[i];
				tp += profit[i];
				break;
			}
			k -= 1;
		}
	}
	printf("\nJob vector are :");
	for (i = 0; i < dmax; i++)
		printf("%d ", timeslot[i]);
	printf("\nMax. Profit: %d", tp);
}
