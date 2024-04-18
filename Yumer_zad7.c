#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#define MAXN 1024
#define LETTERS_COUNT 26
#define COMMON_COUNT 8

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

int* count_letters(char* cypher)
{
    int* counts = (int*) malloc(sizeof(int) * LETTERS_COUNT);
    memset(counts, 0, sizeof(int) * LETTERS_COUNT);
    int index = 0;
    while(cypher[index] != '\0')
    {
        char letter = tolower(cypher[index]);
        counts[letter - 'a']++;
        index++;
    }
    return counts;
}

int get_max_index(int* counts)
{
    int max_index = 0;
    for(int i = 0; i < LETTERS_COUNT; i++)
    {
        if(counts[i] > counts[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}
char most_common_letter(char* cypher)
{
    int* counts = count_letters(cypher);
    int max_index = get_max_index(counts);
    char letter = max_index + 'a';
    return letter;
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
    printf("%s", cypher);

    char common_letters[] = {'e','a','r','i','o','t','n','s'};
    for(int i = 0; i < COMMON_COUNT; i++)
    {
        int key = most_common_letter(cypher) - common_letters[i];
        printf("The key is: %d\n", key);
        char* text = caesar_decypher(cypher, key);
        printf("%s\n", text);
        printf("----------------\n");
    }
    return EXIT_SUCCESS;
}
