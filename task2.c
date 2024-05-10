#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char** bracket(int n, int* returnSize)
{
    int left, right, cap = 5000, ctr = 0;
    char *stack = malloc(2 * n + 1);
    char **para = malloc(cap * sizeof(char *));

    char *p = stack;
    left = right = 0;
    stack[2 * n] = '\0';

    while (p != stack || ctr == 0) 
    {
        if (left == n && right == n) 
        {
            para[ctr] = malloc(2 * n + 1);
            strcpy(para[ctr], stack);
            ctr++;

            while (--p != stack)
             {
                if (*p == '(') {
                    if (--left > right)
                     {
                        *p++ = ')';
                        right++;
                        break;
                    }
                } else {
                    right--;
                }
            }
        } else 
        {
            
            while (left < n) 
            {
                *p++ = '(';
                left++;
            }
            while (right < n) 
            {
                *p++ = ')';
                right++;
            }
        }
    }

    *returnSize = ctr;
    return para;
}

int main(void)
{
    int i, ctr;
   printf("Please Enter the Number for Brackets :\n");
   scanf("%d",&i);
    char ** lists = bracket(i, &ctr);
    for (i = 0; i < ctr; i++) {
        printf("%s\n", lists[i]);
    }
    return 0;
}

