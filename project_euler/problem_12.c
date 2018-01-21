/*
Project Euler Problem 12
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?
*/
#include "stdio.h" //printf()
#include "time.h" //clock(), CLOCKS_PER_SEC, clock_t

unsigned int get_triangle_num(unsigned int position);
unsigned int count_factors(unsigned int triangle_num);

unsigned int get_triangle_num(unsigned int position)
{
    unsigned int sum = 0;
    for (unsigned int i = 1; i < position + 1; i++)
    {
        sum += i;
    }
    return sum;
}

unsigned int count_factors(unsigned int triangle_num)
{
    // Implicit floor
    unsigned int upper_limit = triangle_num / 2;
    unsigned int count = 0;

    for (unsigned int i = 1; i <= upper_limit; i++)
    {
        // Check if the current test num is a factor
        if (triangle_num % i == 0)
        {
            count++;
        }
    }
    return count;
}


int main(int argc, char *argv[])
{
    unsigned int nth_triangle_num = 1;
    unsigned int curr_triangle_num = 0;
    unsigned int count = 0;
    unsigned int max_count = 0;
    clock_t start = clock();
    while (max_count <= 500000)
    {
        curr_triangle_num = get_triangle_num(nth_triangle_num);
        count = count_factors(curr_triangle_num);
        if (count > max_count)
        {
            max_count = count;
        }
        nth_triangle_num++;
    }
    clock_t end = clock();
    double total_ms = (((double)(end - start)) / CLOCKS_PER_SEC)*1000;

    printf("Triangle num:%d has %d factors\n",curr_triangle_num, max_count);
    printf("Time taken: %f ms\n", total_ms);
    return 0;
}