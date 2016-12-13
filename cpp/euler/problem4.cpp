#include <iostream>

int pow (int num, int exp)
{
  int out = 1;
  while (exp-- > 0)
    out *= num;
  return out;
}

int reverse(int num)
{
  int nb_digits = 0;
  while (num / pow(10,nb_digits) > 0)
    ++nb_digits;

  int out = 0, iterator = nb_digits;
  while (iterator > 0)
  {
    out += num / pow(10,iterator-1) * pow(10,nb_digits-iterator);
    num %= pow(10,--iterator);
  }
  return out;
}

int main()
{
    int res = 0;
    int i, j;
    
    for (i = 999; i > 0; --i)
        for (j = 999; j > 0; --j) {
            int cur = i*j;
            if (cur == reverse(cur) && cur > res)
                    res = cur;
        }
    std::printf("%d\n", res);
    return 0;
}
