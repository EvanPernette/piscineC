#include <assert.h>
#include <stdio.h>

struct test
{
    int i;
};

int fact(int *val)
{
    assert(val != NULL);

    if (*val > 1)
        return (*val * fact(val - 1));
    else
        return 1;
}
int a_0(void)
int b_1(int a)
int print_me(int h1)
int c_2(int a, int b)
** int main(void)
void *xmalloc(size_t n)
int main(int argc, char **argv)
int a_(int    a, int b)
int     main(void)
struct student get_student(char *name)
struct student *grow_2fast(struct student *s, int age_diff)

int main(void)
{
    int val = 2;
    scanf("%d", &val);
    printf("%d\n", fact(&val));
    return 0;
}
