#include <stdio.h>
#define number 1000000

int main(int argc, const char *argv[])
{
	int i,j;
	for (i = 1;i <= number;i++) {
		for (j = 2;j < i;j++) {
			if(!(i%j))
				break;
			if(i == j + 1)
				printf("%d\n",i);
		}
	}
	return 0;
}
