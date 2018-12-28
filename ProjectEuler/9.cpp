#include <iostream>

using namespace std;

int main()
{
    bool k = 0;
    int c;
    for (int a = 1; a < 999; a++)
        for (int b = 1; b < 999; b++)
            if (a + b < 1000 && !k)
            {
                c = 1000 - a - b;
                if (a * a + b * b == c * c)
                {
                    k = 1;
                    cout << a * b * c << endl;
                }
            }
    return 0;
}
