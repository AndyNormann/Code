#include <iostream>

#define NUMS 10

int main() {
    float nums[] = {19.35, 19.30, 18.88, 18.93, 18.95,
                    19.03, 19.00, 18.97, 18.97, 18.98};

    float max = 0;
    int x, y;

    for (int i = 0; i < NUMS; ++i) {
        for (int j = i + 1; j < NUMS; ++j) {
            float cur = nums[i] - nums[j];
            if (cur < max) {
                max = cur;
                x = i;
                y = j;
            }
        }
    }

    printf("%f, %f\n", nums[x], nums[y]);

    return 0;
}
