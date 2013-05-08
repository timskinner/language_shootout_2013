#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define EXPECT(x,y) __builtin_expect((x),(y))
#define LIKELY(x)   EXPECT((x),1)
#define UNLIKELY(x) EXPECT((x),0)
#define RANDOM_INDEX(arr) (arr[rand() % sizeof(arr)])
int main(int argc, char* argv[])
{
    static char const t[4] = {'A','C','T','G'};
    unsigned long int count = 0;
    if(argc != 2 || !argv || !*argv) {
        printf("Usage: make_sample <count>\n");
        exit(EXIT_FAILURE);
    }
    errno = 0;
    count = strtoul(argv[1],NULL,0);
    if(UNLIKELY(0 != errno)) {
        printf("Error: '%s' - Invalid size: %s\n",argv[1],argv[1]);
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    for(unsigned long i = 0; i < count; ++i) printf("%c",RANDOM_INDEX(t));
    printf("\n");
    return 0;
}
