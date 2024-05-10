#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
static bool stringcheck(char *h)
{
    int n = 0; 
    int var= 100;
    char *stringsize = malloc(var);

    while (*h != '\0')
    {
        switch(*h)
       	{
        case '(':
        case '[':
        case '{':
            if (n + 1 >= var)
	    {
                var *= 2;
                stringsize = realloc(stringsize, var);
            }
            stringsize[n++] = *h;
            break;
        case ')':

            if (stringsize[--n] != '(') return false;
            break;

        case ']':
            if (stringsize[--n] != '[') return false;
            break;

        case '}':

            if (stringsize[--n] != '{') return false;
            break;

        default:
            return false;
        }
        h++;
    }
    return n == 0;
}
int main()
{

	char string[10];
	printf("Enter the String to check wether it is VALID or NOT-VALID\n");
	scanf("%s",string);
	printf("%s\n", stringcheck(string) ? "true" : "false");
    return 0;
}



