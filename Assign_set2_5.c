#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
int i;
int count_char(char str2[])
{
        int i;
        for (i = 0; i <= strlen(str2); i++)
        {
                if (str2[i] != ' ' && str2[i] != '\0')
                {
                        count++;
                }
        }
        return count;
}
int main()
{
        FILE *ptr, *ptr1;
        char str[50];
        int pid = fork();
        if (pid == 0)
        {
                int x;
                ptr = fopen("main.txt", "r+");
                fgets(str, 50, ptr);
                x = count_char(str);
                printf("the number of the characters are %d\n", x - 1);
                fclose(ptr);
        }
        else
        {
                wait();
                ptr1 = fopen("main.txt", "r+");
                char str1[50];
                fgets(str1, 30, ptr1);
                for (i = 0; str1[i] != '\0'; i++)
                {
                        if (str1[i] == ' ' && str1[i + 1] != ' ' || str1[i] == '\0')
                        {
                                count++;
                        }
                }
                printf("the number of the words is %d\n", count + 1);
                fclose(ptr1);
        }
}
