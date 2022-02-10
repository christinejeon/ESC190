#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char *my_strcat(char *dest, char *src)
{
	*dest = *dest + *src;
	
	return dest; // first char changes?
}

int my_strcmp_rec(char *str1, char *str2)
{
	int a_diff = 0;
	a_diff = str1[0] - str2[0];
	
	if (a_diff == 0) // same
	{
		my_strcmp_rec(str1 + 1, str2 + 1);
	}
	else // different. stop
	{
		return a_diff;
	}
}


int my_atoi(char *str)
{
	int res = 0;
	int str_len = 0;
	int cnt = 0;
	int num = 0;
	
	while (str[str_len] != NULL)
	{
		str_len++;
	}
	printf("str_len: %d\n", str_len);
	
	// (10**(str_len - cnt)) -> pow(10, str_len - (cnt + 1));
	while ((str_len - cnt) > 0)
	{
		num = str[cnt]-'0';
		res += num * (pow(10, str_len - (cnt + 1)));
		printf("%d\n", res);
		cnt++;
	}
	
	
	return res;
}


int main(void)
{
	
	char str1[] = "abcdefg";
	char str2[] = "hijkl";
	char str3[] = "abcde";
	char str4[] = "abCdef";
	char str5[] = "987624";
	
	//Q1
	printf("Q1\n");
	printf("%s\n%s\n", str1, str2);
	printf("strcat: %s\n", strcat(str1, str2));
	printf(my_strcat(str1, str2));
	printf("\nstr1: %s\n", str1);
	
	//Q2
	printf("\nQ2\n");
	//printf("strcmp: %d\n", strcmp(str3, str4));
	printf("my_strcmp: %d\n", my_strcmp_rec(str3, str4));
	
	//Q3
	printf("\nQ3\n");
	printf("std atoi: %d\n", atoi(str5));
	printf("my atoi: %d\n", my_atoi(str5));
	
	
	
	return 0;
}
