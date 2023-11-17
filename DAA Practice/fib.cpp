// https://chat.openai.com/c/4cf5391f-f1b3-44c0-b5d7-34fefc0547a6
#include <iostream>
using namespace std;

class Fibonacci
{
public:
    int recursiveFib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        else
            return recursiveFib(n - 1) + recursiveFib(n - 2);
    }

    int iterativeFib(int n)
    {
        int x = 0, y = 1;
        int z = x + y;

        for (int i = 2; i <= n; i++)
        {
            z = x + y;
            x = y;
            y = z;
        }

        return z;
    }
    Fibonacci(int n)
    {
        cout << recursiveFib(n) << endl;
        cout << iterativeFib(n) << endl;
    }
};

int main()
{
    Fibonacci fb = Fibonacci(4);
    return 0;
}