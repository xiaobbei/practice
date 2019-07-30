
#include<stdio.h>
#include<stdlib.h>

int romanToInt(char * s) {
	int array[256];
	int sum = 0;
	array['I'] = 1;
	array['V'] = 5;
	array['X'] = 10;
	array['L'] = 50;
	array['C'] = 100;
	array['D'] = 500;
	array['M'] = 1000;
	for (int i = 0; i < strlen(s); i++)
	{
		if (i + 1 >= strlen(s) || array[s[i + 1]] <= array[s[i]])
		{
			sum += array[s[i]];
		}
		else
			sum -= array[s[i]];
	}
	return sum;
}

int main()
{
	char *s = "MCMXCIV";
	int i = romanToInt(s);
	printf("%d",i);
	system("pause");
	return 0;
}