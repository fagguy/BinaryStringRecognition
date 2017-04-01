#include "BinaryStringRecognition.h"

int main()
{
	GetInput();
	tree.PrintContents();

	cout << "min no. of identity bits: " << endl
		<< "> " << tree.CalculateIdentityBitsCount(true) << endl;

	system("Pause");
	return 0;
}

void GetInput()
{
	unsigned int K;
	string binaryString;

	cin >> K;

	for (unsigned int i = 0; i < K; ++i)
	{
		cin >> binaryString;
		tree.AddStringToBranch(binaryString);
	}
}
