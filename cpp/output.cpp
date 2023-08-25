#include "../headers/header.h"
#include "../headers/output.h"

bool GetInput(struct CoefficientsStruct* equation_coefficients)
{
    MYASSERT(equation_coefficients != NULL);

    printf("Please, type the coefficients: ");
    if (scanf("%lf", &(equation_coefficients->a)) != 1) return false;
    if (scanf("%lf", &(equation_coefficients->b)) != 1) return false;
    if (scanf("%lf", &(equation_coefficients->c)) != 1) return false;

    MYASSERT(isfinite(equation_coefficients->a));
    MYASSERT(isfinite(equation_coefficients->b));
    MYASSERT(isfinite(equation_coefficients->c));

    MYASSERT(!isnan(equation_coefficients->a));
    MYASSERT(!isnan(equation_coefficients->b));
    MYASSERT(!isnan(equation_coefficients->c));

    return true;
}

bool GetFileInput(FILE* fp, struct CoefficientsStruct* equation_coefficients)
{
    MYASSERT(equation_coefficients != NULL);
    MYASSERT(fp                    != NULL);

    if (fscanf(fp, "%lf", &(equation_coefficients->a))!= 1) return false;
    if (fscanf(fp, "%lf", &(equation_coefficients->b))!= 1) return false;
    if (fscanf(fp, "%lf", &(equation_coefficients->c))!= 1) return false;

    MYASSERT(isfinite(equation_coefficients->a));
    MYASSERT(isfinite(equation_coefficients->b));
    MYASSERT(isfinite(equation_coefficients->c));

    MYASSERT(!isnan(equation_coefficients->a));
    MYASSERT(!isnan(equation_coefficients->b));
    MYASSERT(!isnan(equation_coefficients->c));

    return true;
}

bool GetTestFileInput(FILE* fp, struct TestsStruct* test_container)
{
    MYASSERT(test_container != NULL);
    MYASSERT(fp             != NULL);

    if (fscanf(fp, "%lf", &(test_container->equation_coefficients.a)) != 1) return false;
    if (fscanf(fp, "%lf", &(test_container->equation_coefficients.b)) != 1) return false;
    if (fscanf(fp, "%lf", &(test_container->equation_coefficients.c)) != 1) return false;
    if (fscanf(fp, "%lf", &(test_container->equation_roots_ref.x1))   != 1) return false;
    if (fscanf(fp, "%lf", &(test_container->equation_roots_ref.x2))   != 1) return false;
    if (fscanf(fp, "%d",  &(test_container->number_of_roots_ref))     != 1) return false;

    MYASSERT(isfinite(test_container->equation_coefficients.a));
    MYASSERT(isfinite(test_container->equation_coefficients.b));
    MYASSERT(isfinite(test_container->equation_coefficients.c));
    MYASSERT(isfinite(test_container->equation_roots_ref.x1));
    MYASSERT(isfinite(test_container->equation_roots_ref.x2));
    MYASSERT(isfinite(test_container->number_of_roots_ref));

    MYASSERT(!isnan(test_container->equation_coefficients.a));
    MYASSERT(!isnan(test_container->equation_coefficients.b));
    MYASSERT(!isnan(test_container->equation_coefficients.c));
    MYASSERT(!isnan(test_container->equation_roots_ref.x1));
    MYASSERT(!isnan(test_container->equation_roots_ref.x2));
    MYASSERT(!isnan(test_container->number_of_roots_ref));

    return true;
}

void PrintOutput(const TypeOfRoots number_of_roots, const struct RootsStruct* equation_roots)
{
    MYASSERT(equation_roots != NULL);

    switch(number_of_roots)
    {
        case TypeOfRoots::SS_NO_ROOTS:
            printf("Cannot be solved\n\n");
            break;
        case TypeOfRoots::SS_ONE_ROOT:
            printf("The only root is %lf\n\n", equation_roots->x1);
            break;
        case TypeOfRoots::SS_TWO_ROOTS:
            printf("The quadratic equation has two roots:\nx1 = %lf and x2 = %lf\n\n", equation_roots->x1, equation_roots->x2);
            break;
        case TypeOfRoots::SS_INF_ROOTS:
            printf("Infinite number of roots\n\n");
            break;
        default:
            printf("Something went wrong\n\n");
            break;
    }
    return;
}
