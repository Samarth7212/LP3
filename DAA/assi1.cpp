// Write a program non-recursive and recursive program to calculate Fibonacci
// numbers and analyze their time and space complexity.

#include <iostream>

class Assignments1
{
public:
    static int fib_numR(int n)
    {
        if (n == 0 || n == 1)
            return n;
        return (fib_numR(n - 1) + fib_numR(n - 2));
    }

    static int fib_numI(int n)
    {
        int a = 0, b = 1;
        int c = a + b;
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    int main()
    {
        std::cout << fib_numR(8) << std::endl;
        std::cout << fib_numI(8) << std::endl;
        return 0;
    }
};

int main()
{
    Assignments1 obj;
    obj.main();
    return 0;
}
