#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GOOD_GUY_AMOUNT 20
#define BAD_GUY_AMOUNT 20
#define ALB 5
#define AHB 15
#define DLB 1
#define DHB 3
#define HLB 10
#define HHB 50
#define EHB 4

typedef struct Guy{
    int health;
    int atck;
    int def;
    float evasion;
} guy;

guy* setup_guys(int num){
    int i;
    guy* retVal = malloc(sizeof(guy)*num);

    srand(time(NULL));

    printf("At De Hp Ev\n");
    for (i = 0; i < num; i++) {
        retVal[i].atck = (rand() % AHB) + ALB;
        retVal[i].def = (rand() % DHB) + DLB;
        retVal[i].health = (rand() % HHB) + HLB;
        retVal[i].evasion = (rand() % EHB)*0.25;
        printf("%d %d %d %f\n", retVal[i].atck, retVal[i].def, retVal[i].health,retVal[i].evasion);
    }
    return retVal;
}

int simulate(guy* good_guys, guy* bad_guys){
    int i = 0, j = 0;
    while(i < GOOD_GUY_AMOUNT && j < BAD_GUY_AMOUNT){
        printf("Good guy nr: %d %d %d %d %f\n", i, good_guys[i].atck, good_guys[i].def, good_guys[i].health, good_guys[i].evasion);
        printf("Bad guy nr: %d %d %d %d %f\n", j, bad_guys[i].atck, bad_guys[i].def, bad_guys[i].health, bad_guys[i].evasion);

        good_guys[i].health -= bad_guys[j].atck - (good_guys[i].def/2);
        bad_guys[j].health -= good_guys[i].atck - (bad_guys[i].def/2);
        if(good_guys[i].health <= 0){ 
            i++;
        }
        if(bad_guys[j].health <= 0){ 
            j++;
        }
    }
    if(i > j)
        return 1;
    else
        return -1;
}

int main()
{
    guy* good_guys;
    guy* bad_guys;
    printf("Good_guys\n");
    good_guys = setup_guys(GOOD_GUY_AMOUNT); 
    getchar();
    printf("Bad_guys\n");
    bad_guys = setup_guys(BAD_GUY_AMOUNT);

    getchar();
    if(simulate(good_guys, bad_guys) == 1){
        printf("Good guys win\n");
    }else{
        printf("Bad guys win\n");
    }

    free(good_guys);
    free(bad_guys);
    return 0;
}

