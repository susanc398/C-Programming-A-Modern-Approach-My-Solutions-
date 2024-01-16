#include <string.h>

int main(void)
{
    char str1[10] = "abc", str2[10];
    int len;

    len = strlen("abc");   /* len is now 3 */
    len = strlen("");      /* len is now 0 */
    strcpy(str1, "abc");
    len = strlen(str1);    /* len is now 3 */
    
    strcpy(str1, "abc");
    strcat(str1, "def");   /* str1 now contains "abcdef" */

    if (strcmp(str1, str2) <=  0) /* is str1 <= str2? */
        ...
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') 
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int count_spaces(const char s[])
{
    int count = 0, i;

    for (i = 0; s[i] != '\0'; i++) 
        if (s[i] == ' ')
            count++;
    return count;
}

