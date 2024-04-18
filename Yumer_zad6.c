#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1024
#define LETTERS_COUNT 26

char* caesar_decypher(char* cypher, int key)
{
    int length = strlen(cypher);
    
    char* result = (char*) malloc((length + 1) * sizeof(char));
    
    int i = 0;
    while(cypher[i] != '\0')
    {
        result[i] = (cypher[i] - 'a' - key + 26) % 26 + 'a';
        i++;
    }
    result[i] = '\0';
    return result;
}

int main()
{
    char cypher[MAXN];
    scanf("%s", cypher);
    for(int i = 0; i < LETTERS_COUNT; i++)
    {
        char*text = caesar_decypher(cypher, i);
        printf("Key = %d, text: %s\n", i, text);
    }
    return EXIT_SUCCESS;
}
