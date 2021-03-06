/* dancing leds 
	to start from left: mask = 0x80; mask >>= 1
	to start from right: mask = 1; mask <<= 1

	1) fill from right
	2) clear from left
	3) fill from left
	4) clear from right

	5) fill from right
	6) clear from right
	7) fill from left
	8) clear from left

	9) single digit from right
	10) single digit from left
	11) single digit from left
	12) single digit from right
	13) single digit from left (3x)
	14) single digit from right (3x)
*/

#include <stdio.h>

int main(void)
{
	int i;
	int j;
	int k;
	unsigned char test;
	unsigned char mask;
	
	test = 0;
	mask = 1;
	j = 0;

//	printf("\n1) fill from right\n");
	for(i = 0;i < 8;i++)
	{
		test |= mask;
		mask <<= 1;
		printf("0x%x, ",test);
	}
	j += i;

	mask = 0x80;

//	printf("\n2) clear from left\n");
	for(i = 0;i < 8;i++)
	{
		test &= ~mask;
		mask >>= 1;
		printf("0x%x, ",test);
	}
	j += i;

//	printf("\n3) fill from left\n");

	mask = 0x80;
	for(i = 0;i < 8;i++)
	{
		test |= mask;
		mask >>= 1;
		printf("0x%x, ",test);
	}
	j += i;
//	printf("\n4) clear from right\n");
	mask = 1;

	for(i = 0;i < 8;i++)
	{
		test &= ~mask;
		mask <<= 1;
		printf("0x%x, ",test);
	}
	j += i;

/*
	5) fill from right
	6) clear from right
	7) fill from left
	8) clear from left
*/
	mask = 1;
//	printf("\n5) fill from right\n");
	for(i = 0;i < 8;i++)
	{
		test |= mask;
		mask <<= 1;
		printf("0x%x, ",test);
	}
	j += i;
	mask = 1;

//	printf("\n6) clear from right\n");
	for(i = 0;i < 8;i++)
	{
		test &= ~mask;
		mask <<= 1;
		printf("0x%x, ",test);
	}
	j += i;

//	printf("\n7) fill from left\n");
	mask = 0x80;
	for(i = 0;i < 8;i++)
	{
		test |= mask;
		mask >>= 1;
		printf("0x%x, ",test);
	}
	j += i;

//	printf("\n8) clear from left\n");
	mask = 0x80;

	for(i = 0;i < 8;i++)
	{
		test &= ~mask;
		mask >>= 1;
		printf("0x%x, ",test);
	}
	j += i;


	test = 0;
	mask = 1;

//	printf("\nsingle digit from right\n");
	for(i = 0;i < 7;i++)
	{
		test |= mask;
		mask <<= 1;
		printf("0x%x, ",test);
		test = 0;
	}
	j += i;

//	printf("\nsingle digit from left\n");
	mask = 0x80;
	test = 0;
	for(i = 0;i < 8;i++)
	{
		test |= mask;
		mask >>= 1;
		printf("0x%x, ",test);
		test = 0;
	}
	j += i;

	mask = 0x80;
	test = 0;
//	printf("\nsingle digit from left\n");
	for(i = 0;i < 7;i++)
	{
		test |= mask;
		mask >>= 1;
		printf("0x%x, ",test);
		test = 0;
	}
	j += i;

//	printf("\nsingle digit from right\n");
	mask = 1;
	test = 0;
	for(i = 0;i < 8;i++)
	{
		test |= mask;
		mask <<= 1;
		printf("0x%x, ",test);
		test = 0;
	}
	j += i;

//	printf("\nsingle digit from left (3x)\n");
	for(k = 0;k < 3;k++)
	{
		mask = 0x80;
		test = 0;
		for(i = 0;i < 8;i++)
		{
			test |= mask;
			mask >>= 1;
			printf("0x%x, ",test);
			test = 0;
		}
		j += i;
	}

//	printf("\nsingle digit from right (3x)\n");
	for(k = 0;k < 3;k++)
	{
		mask = 1;
		test = 0;
		for(i = 0;i < 8;i++)
		{
			test |= mask;
			mask <<= 1;
			printf("0x%x, ",test);
			test = 0;
		}
		j += i;
	}

	test = 0;
	printf("0x%x, ",test);
	mask = 1;
	printf("\n");
	j++;

	printf("\n");		
	printf("total: %d\n\n",j);
}
