#include <iostream>
#include <string>
using namespace std;

int main()
{
	string mBird[2];
	mBird[0] = " " + string(1, 223) + " ";
	mBird[1] = string(1, 220) + " " + string(1, 220);
	cout << mBird[0][1];
}