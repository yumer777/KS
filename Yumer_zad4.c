#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1024

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

char* read_cypher(char* filename)
{
    FILE* file = fopen(filename, "r");
    
    if (file == NULL)
    {
        printf("Error opening the file.");
        return NULL;
    }
    
    char* cypher = (char*) malloc( MAXN * sizeof(char) );
    if(fgets(cypher, MAXN, file) == NULL)
    {
        printf("Error reading from file.");
        return NULL;
    }
    
    fclose(file);
    return cypher;
}

int main()
{
    char filename[1024];
    scanf("%s", filename);
    
    char* cypher = read_cypher(filename);

    int key;
    scanf("%d", &key);
    
    char* result = caesar_decypher(cypher, key);
    
    printf("%s\n", result);
    
}