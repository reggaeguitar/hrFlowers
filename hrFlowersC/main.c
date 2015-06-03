#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp_desc(const void * a, const void * b)
{
	int * aPtr = (int*)a;
	int * bPtr = (int*)b;
	return *bPtr - *aPtr;
}

int main()
{
	int flowersNeeded, numFriends;
	scanf("%d %d", &flowersNeeded, &numFriends);
	getchar();
	int flowerCosts[100];
	memset(flowerCosts, 0, sizeof(flowerCosts));
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