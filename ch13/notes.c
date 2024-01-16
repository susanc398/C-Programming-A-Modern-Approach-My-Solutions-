char *p;
p = "abc"; /* p points to the first character in the string */

char ch;
ch = "abc"[1]; /* the value of ch is the letter b */

char digit_to_hex_char(int digit)
{
    return "0123456789ABCDEF"[digit];
}

char date1[8] = "June 14";
char date1[8] = {'J', 'u', 'n', 'e', ' ', '1', '4', '\0'};
char date2[9] = "June 14";
char date3[7] = "June 14";
char date4[] = "June 14";
char *date = "June 14";

char str[] = "Are we having fun yet?";
printf("%s\n", str);
puts(str); /* after writing string, puts writes an additional new-line character */

char sentence[SENT_LEN+1];

printf("Enter a sentence:\n");
scanf("%s", sentence); /* scanf skips reading whitespace at the beginning of the input */
gets(sentence); /* gets doesnt skip reading whitespace at the beginning of the input */

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

/* accessing characters in a string */
int count_spaces(const char s[])
{
    int count = 0, i;

    for (i = 0; s[i] != '\0', i++)
        if (s[i] == ' ')
            count++;
    return count;
}

int count_spaces(const char *s)
{
    int count = 0;

    for (; *s != '\0'; s++)
        if (*s == ' ')
            count++;
    return count;
}