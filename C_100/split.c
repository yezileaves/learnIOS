#include<stdio.h>
#include<string.h>

int main(int argc, const char *argv[])
{
	char ch[50],ch1[10];
	fgets(ch,sizeof(ch),stdin);
	ch[strlen(ch) - 1] = '\0';

	scanf("%s",ch1);

	int i = 0,k = 0;
	while (i < strlen(ch))
	{
		if (ch[i] == ch1[0])
		{
			for (k = 1;k < strlen(ch1);k++)
			{
				if (ch[i + k] != ch1[k])
					break;
			}
			if (k >= strlen(ch1))
			{
				printf("\n");
				i += strlen(ch1) - 1;
			}
			else
			{
				printf("%c",ch[i]);
			}
		}
		else
		{
			printf("%c",ch[i]);
		}
		i++;
	}
	return 0;
}
