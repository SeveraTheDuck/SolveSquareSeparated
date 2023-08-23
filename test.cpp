#include "header.h"

int TestEquation (const double a, const double b, const double c,
                    const double x1_ref, const double x2_ref,
                    const int number_of_roots_ref, const int test_number)
{
    double x1 = 0, x2 = 0;
    TypeOfRoots number_of_roots = SolveGivenEquation(a, b, c, &x1, &x2);
    if (!CompareEquality(x1, x1_ref) || !CompareEquality(x2, x2_ref) || number_of_roots != number_of_roots_ref)
    {
        printf("FAILED TEST NUMBER %3d: x1 = %10lf, x2 = %10lf, \n", test_number, x1, x2);
        printf("number of roots = %d\n", number_of_roots);
        printf("EXPECTED:               x1 = %10lf, x2 = %10lf, \n", x1_ref, x2_ref);
        printf("number of roots = %d\n", number_of_roots_ref);
        printf("Let's head to your own equation!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

void UnitTests()
{
    char test_selector = 'n';
    printf("Do you want to run prepared tests? [y/n]\n");
    scanf("%c", &test_selector);
    if (test_selector == 'y')
    {
        int number_of_success = 0;
        number_of_success += TestEquation(0, 0, 0, 0, 0, SS_INF_ROOTS, 1);
        number_of_success += TestEquation(0, 0, 1, 0, 0, SS_NO_ROOTS, 2);
        number_of_success += TestEquation(0, 1, 0, 0, 0, SS_ONE_ROOT, 3);
        number_of_success += TestEquation(1, 1, 1, 0, 0, SS_NO_ROOTS, 4);
        number_of_success += TestEquation(1, 2, 1, -1, 0, SS_ONE_ROOT, 5);
        number_of_success += TestEquation(1, 3, 2, -1, -2, SS_TWO_ROOTS, 6);
        number_of_success += TestEquation(2, 5, 2, -0.5, -2, SS_TWO_ROOTS, 7);
        number_of_success += TestEquation(5, 10, 5, -1, 0, SS_ONE_ROOT, 8);
        number_of_success += TestEquation(3, 10, 3, -0.333333333, -3, SS_TWO_ROOTS, 9);
        number_of_success += TestEquation(0, -5, 2, 0.4, 0, SS_ONE_ROOT, 10);
        printf("OK! Succes: %d\n", number_of_success);
        return;
    }
    else if (test_selector != 'n')
    {
        printf("Wrong letter selected. Automaticly skipping to your own equation.\n");
        return;
    }
    else
    {
        printf("OK. Automaticly skipping to your own equation.\n");
    }
}
