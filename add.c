#include <stdio.h>

int main()
{
	int a, b, sum;

	printf("\nEnter 2 numbers: ");
	scanf("%d %d", &a, &b);
	sum = a + b;

	printf("\n%d + %d = %d\n", a, b, sum);

	return 0;
}
