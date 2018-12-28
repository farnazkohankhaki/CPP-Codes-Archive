#include <iostream>

using namespace std;

int main ()
{
	int ans = 0;
	for (int i = 0; i <= 200; i++)
		for (int j = 0; j <= 100; j++)
			for (int l = 0; l <= 40; l++)
				for (int x = 0; x <= 20; x++)
					for (int y = 0; y <= 10; y++)
						for (int a = 0; a <= 4; a++)
							for (int b = 0; b <= 2; b++)
								if (i + j * 2 + l * 5 + x * 10 + y * 20 + a * 50 + b * 100 == 200)
									ans++;
	cout << ans + 1 << endl;
	return 0;
}