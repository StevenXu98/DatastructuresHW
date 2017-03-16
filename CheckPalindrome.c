#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];
	int n;
	gets(str);
	n = strlen(str);

	printf("%c", str[0]);
	printf("%c", str[n-1]);

	int i, j;
	int judge = 0;

	for(i = 0, j = n-1; i < j; ++i, --j){
		if(str[i] != str[j]){
			judge = 1;
			break;
		}
	}

	if(judge) printf("no\n");
	else printf("yes\n");


	return 0;
}
