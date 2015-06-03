#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp_desc(const void * aPtr, const void * bPtr)
{
	int a = *(int*)aPtr;
	int b = *(int*)bPtr;
	return b - a;
}

int main()
{
	int flowersNeeded, numFriends;
	scanf("%d %d", &flowersNeeded, &numFriends);
	int flowerCosts[100];
	for (int i = 0; i < flowersNeeded; ++i)
	{
		scanf("%d", &flowerCosts[i]);
	}
	qsort(flowerCosts, flowersNeeded, sizeof(int), comp_desc);
	int flowersBought = 0;
	int moneySpent = 0;
	int multiplier = 1;
	for (int i = 0; i < flowersNeeded; ++i)
	{
		moneySpent += flowerCosts[i] * multiplier;
		++flowersBought;
		multiplier = (flowersBought / numFriends) + 1;
	}
	printf("%d\n", moneySpent);
	return 0;
}