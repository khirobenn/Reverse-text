#include <stdio.h>
#include <stdlib.h>

void display_reverse_line(int *i, char *tab);

int main(void)
{
    int size = 5;
    char *rev_tab = malloc(sizeof(char)*size);
    int i = 0;
    int c;
    while ((c = getchar()) != EOF){
        if(c == '\n'){
            display_reverse_line(&i, rev_tab);
            continue;
        }
        if(i == size){
            rev_tab = realloc(rev_tab, size*2);
            size *= 2;
        }
        rev_tab[i++] = c; 
    }


    display_reverse_line(&i, rev_tab); 

    printf("\nTaille finale du tableau : %d\n", size);
    free(rev_tab);
    return 0;
}

void display_reverse_line(int *i, char *tab){
    if(*i != 0){
        for(*i = *i-1; *i >= 0; (*i)--){
            putchar(tab[*i]);
        }
    }
    *i = 0;
    putchar('\n');
}