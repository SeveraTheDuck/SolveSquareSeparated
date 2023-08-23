#ifndef test_h
#define test_h

int TestEquation(struct TestsStruct test_container,
                    struct CoefficientsStruct* equation_coefficients,
                    struct RootsStruct* equation_roots,
                    const int test_number);

void UnitTests(struct CoefficientsStruct* equation_coefficients,
                struct RootsStruct* equation_roots);

#endif
