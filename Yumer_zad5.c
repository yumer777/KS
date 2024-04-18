#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    const int MAXN = 1024;
    char cypher[MAXN];
    scanf("%s", cypher);
    
    int key;
    scanf("%d", &key);
    
    char* result = caesar_decypher(cypher, key);
    
    printf("%s\n", result);
    
}