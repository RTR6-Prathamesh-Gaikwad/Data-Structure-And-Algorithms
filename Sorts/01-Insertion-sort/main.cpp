#include"insertionSort.hpp"

int main(void)
{
    sort<int> A(10);
    sort<float> B(20);

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {

        A[i] = rand() % 100;
    }

    for (int i = 0; i < 20; i++)
    {

        B[i] = static_cast<float>(rand() % 100) * 1.1f;
    }
    std::cout << "Before Sort" << std::endl
              << A;
    A.insertion_sort();
    std::cout << "After Sort" << std::endl
              << A;

    std::cout << "Before Sort" << std::endl
              << B;
    B.insertion_sort();
    std::cout << "After Sort" << std::endl
              << B;
}
