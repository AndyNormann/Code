#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    char **strings = calloc((size_t)N, sizeof(char*));

    int i;
    for (i = 0; i < N; ++i) {
        char buf[1500];
        scanf("%s", buf);
        char *temp = calloc(strlen(buf), sizeof(char));
        strcpy(temp, buf);
        strings[i] = temp;
    }

    int M;
    scanf("%d", &M);

    for (i = 0; i < M; ++i) {
        char buf[1500];
        scanf("%s", buf);
        int cur_len = (int)strlen(buf)-1;

        int j, k;
        int cur_matches = 0;
        
        for (j = 0; j < N; ++j) {
            for (k = 0; k < (int)strlen(strings[j])-cur_len; ++k) {
                if(strncmp(buf, &strings[j][k], strlen(buf)) == 0){
                    cur_matches++;
                }
                //printf("comping %s to %s\n", buf, &strings[j][k]);
            }
        }
        printf("%d\n", cur_matches);
    }

    return 0;
}

