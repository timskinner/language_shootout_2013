#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1000

char* read_input()
{
    char* input_data  = NULL;
    size_t input_size = 0;
    input_size = getline(&input_data,&input_size,stdin);
    if('\n' == input_data[input_size - 1])
        input_data[input_size - 1] = '\0';
    return input_data;
}

int main(int argc, char* argv[])
{
    char* data = read_input();
    unsigned int counts[4] = {0};
    for(char* d = data;*d;d++) {
        switch(*d) {
            case 'A': counts[0]++; break;
            case 'C': counts[1]++; break;
            case 'G': counts[2]++; break;
            case 'T': counts[3]++; break;
            default:  printf("Parse Error!\n"); exit(0);
        }
    }
    free(data);
    printf("%d %d %d %d\n",counts[0],counts[1],counts[2],counts[3]);
    return 0;
}
