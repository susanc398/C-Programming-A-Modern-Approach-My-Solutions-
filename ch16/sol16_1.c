/* Looks up what country belongs to an international dialing code */

#include <stdio.h>
#include "readline.h"

#define NUM_CODES sizeof(country_codes) / sizeof(struct dialing_code)

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] = 
    {{"Argentina",            54}, {"Bangladesh",     880},
     {"Brazil",               55}, {"Burma (Myanmar)", 95},
     {"China",                86}, {"Colombia",        57},
     {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
     {"Ethiopia",            251}, {"France",          33},
     {"Germany",              49}, {"India",           91},
     {"Indonesia",            62}, {"Iran",            98},
     {"Italy",                39}, {"Japan",           81},
     {"Mexico",               52}, {"Nigeria",        234},
     {"Pakistan",             92}, {"Phillippines",    63},
     {"Poland",               48}, {"Russia",           7},
     {"South Africa",         27}, {"South Korea",     82},
     {"Spain",                34}, {"Sudan",          249},
     {"Thailand",             66}, {"Turkey",          90},
     {"Ukraine",             380}, {"United Kingdom",  44},
     {"United States",         1}, {"Vietnam",         84}};

int find_part(int code);
void search(void);

int main(void)
{
    search();

    return 0;
}

/**********************************************************
 * find_code: Looks up a code in the country_codes        *
 *            array.                                      *
 **********************************************************/
int find_code(int code)
{
    int i = 0;

    while (i < NUM_CODES) {
        if (country_codes[i].code == code)
            return i;
        i++;
    }

    printf("Coountry code not found\n");
    return -1;
}

/**********************************************************
 * search: Prompts the user to enter a dialing code then  *
 *         looks up the code in the database. If the code *
 *         exists, prints the name of the corresponding   *
 *         country; if not, prints an error message.      *
 **********************************************************/
void search(void)
{
    int i, code;

    printf("Enter an international dialing code: ");
    scanf("%d", &code);
    
    i = find_code(code);
    printf("%s\n", country_codes[i].country);
}