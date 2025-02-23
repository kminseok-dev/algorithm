#include <iostream>

using namespace std;

int mycount[100000] = {0 ,};

int main(void)
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		mycount[temp]++;
	}
	for (int i = N; i >= 0; i--)
	{
		if (mycount[i] == i)
		{
			cout << i << endl;
			return (0);
		}
	}
	cout << "-1" << endl;
	return (0);
}