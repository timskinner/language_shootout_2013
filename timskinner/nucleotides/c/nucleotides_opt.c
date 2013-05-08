#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1000
#define EXPECT(x,y) __builtin_expect((x),(y))
#define LIKELY(x)   EXPECT((x),1)
#define UNLIKELY(x) EXPECT((x),0)

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
    unsigned int counts[85] = {0};
    for(char* d = data;*d;d++) {
        counts[*d]++;
    }
    free(data);
    printf("%d %d %d %d\n",counts['A'],counts['C'],counts['T'],counts['G']);
    return 0;
}
