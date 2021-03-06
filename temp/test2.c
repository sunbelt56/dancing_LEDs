/* dancing leds 
	to start from left: mask = 0x80; mask >>= 1
	to start from right: mask = 1; mask <<= 1

	fill from right
	single digit from left (reverse)
	single digit from right (reverse)
	single digit from right (reverse)
	single digit from left (reverse)
	single digit from left (reverse 3x)
	single digit from right (reverse 3x)
	clear from left
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

//	printf("fill from right\n");
	for(i = 0;i < 8;i++)
	{
		test |= mask;
		mask <<= 1;
		printf("0x%x, ",test);
	}
	j += i;

	mask = 0x80;
//	printf("\nsingle digit from left (reverse)\n");

	for(i = 0;i < 7;i++)
	{
		test &= ~mask;
		mask >>= 1;
		printf("0x%x, ",test);
		test = 0xff;
	}
	j += i;
	mask = 1;
//	printf("\nsingle digit from right (reverse)\n");

	for(i = 0;i < 8;i++)
	{
		test &= ~mask;
		mask <<= 1;
		printf("0x%x, ",test);
		test = 0xff;
	}
	j += i;

//	printf("\nsingle digit from right (reverse)\n");

	mask = 1;
	for(i = 0;i < 7;i++)
	{
		test &= ~mask;
		mask <<= 1;
		printf("0x%x, ",test);
		test = 0xff;
	}
	j += i;
	mask = 0x80;
//	printf("\nsingle digit from left (reverse)\n");

	for(i = 0;i < 8;i++)
	{
		test &= ~mask;
		mask >>= 1;
		printf("0x%x, ",test);
		test = 0xff;
	}
	j += i;
	test = 0xff;
	printf("0x%x, ",test);
	j++;

//	printf("\nsingle digit from left (reverse 3x)\n");
	for(k = 0;k < 3;k++)
	{
		mask = 0x80;
		for(i = 0;i < 8;i++)
		{
			test &= ~mask;
			mask >>= 1;
			printf("0x%x, ",test);
			test = 0xff;
		}
		printf("\n");
		j += i;
	}

//	printf("\nsingle digit from right (reverse 3x)\n");
	for(k = 0;k < 3;k++)
	{
		mask = 1;
		for(i = 0;i < 8;i++)
		{
			test &= ~mask;
			mask <<= 1;
			printf("0x%x, ",test);
			test = 0xff;
		}
		printf("\n");
		j += i;
	}

//	printf("\nclear from left\n");
	mask = 0x80;
	for(i = 0;i < 8;i++)
	{
		test &= ~mask;
		mask >>= 1;
		printf("0x%x, ",test);
		test = 0xff;
	}
	j += i;
	test = 0xff;
	printf("0x%x, ",test);
	j++;

	printf("\n");		
	printf("total: %d\n",j);
}
