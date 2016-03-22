#include <stdio.h>

int main()
{
	int data[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;

	/* delete 5 */
	for (i = 0; i < 10; i++) {
		if (data[i] == 5)
			break;
	}
	if (i == 10)
		puts("no found");

	while (i + 1 <= 9) {
		data[i] = data[i+1];
		i++;
	}


	for (i = 0; i < 10; i++)
		printf("%3d\n", data[i]);

	return 0;
}
