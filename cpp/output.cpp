#include "../headers/header.h"

bool GetInput(struct CoefficientsStruct* equation_coefficients)
{
    printf("Please, type the coefficients: ");
    assert(equation_coefficients != NULL);

    if (scanf("%lf", &(equation_coefficients->a)) != 1) return false;
    if (scanf("%lf", &(equation_coefficients->b)) != 1) return false;
    if (scanf("%lf", &(equation_coefficients->c)) != 1) return false;

    assert(isfinite(equation_coefficients->a));
    assert(isfinite(equation_coefficients->b));
    assert(isfinite(equation_coefficients->c));

    assert(!isnan(equation_coefficients->a));
    assert(!isnan(equation_coefficients->b));
    assert(!isnan(equation_coefficients->c));

    return true;
}

bool GetFileInput(FILE* fp, struct TestsStruct* test_container)
{
    assert(test_container != NULL);

    if (fscanf(fp, "%lf", &(test_container->a)) != 1) return false;
    if (fscanf(fp, "%lf", &(test_container->b)) != 1) return false;
    if (fscanf(fp, "%lf", &(test_container->c)) != 1) return false;
    if (fscanf(fp, "%lf", &(test_container->x1_ref)) != 1) return false;
    if (fscanf(fp, "%lf", &(test_container->x2_ref)) != 1) return false;
    if (fscanf(fp, "%d", &(test_container->number_of_roots_ref)) != 1) return false;

    assert(isfinite(test_container->a));
    assert(isfinite(test_container->b));
    assert(isfinite(test_container->c));
    assert(isfinite(test_container->x1_ref));
    assert(isfinite(test_container->x2_ref));
    assert(isfinite(test_container->number_of_roots_ref));

    assert(!isnan(test_container->a));
    assert(!isnan(test_container->b));
    assert(!isnan(test_container->c));
    assert(!isnan(test_container->x1_ref));
    assert(!isnan(test_container->x2_ref));
    assert(!isnan(test_container->number_of_roots_ref));

    return true;
}

void PrintOutput(const TypeOfRoots number_of_roots, const struct RootsStruct equation_roots)
{
    switch(number_of_roots)
    {
        case TypeOfRoots::SS_NO_ROOTS:
            printf("Cannot be solved");
            break;
        case TypeOfRoots::SS_ONE_ROOT:
            printf("The only root is %lf", equation_roots.x1);
            break;
        case TypeOfRoots::SS_TWO_ROOTS:
            printf("The quadratic equation has two roots:\nx1 = %lf and x2 = %lf", equation_roots.x1, equation_roots.x2);
            break;
        case TypeOfRoots::SS_INF_ROOTS:
            printf("Infinite number of roots");
            break;
        default:
            printf("Something went wrong");
            break;
    }
    return;
}
