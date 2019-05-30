#include <stdio.h>


int main()
{
/*
	char str[5];
	FILE *fp;
	fp = fopen("text.txt", "r");
	fscanf(fp, "%s", str);
	printf("%s", str);
*/
	char str[] = "quocDat";
	FILE *fp;
	fp = fopen("out.txt", "w");
	fputs("Dat", fp);
	fclose(fp);


	return 0;
}