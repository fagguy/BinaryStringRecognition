#include "BinaryStringRecognition.h"

int main()
{
	GetInput();
	//tree.PrintContents();

	cout << tree.CalculateIdentityBitsCount() << endl;

	system("Pause");
	return 0;
}

void GetInput()
{
	unsigned int M, N, K;
	string binaryString, temp;

	cin >> M;
	cin >> N;
	cin >> K;

	for (unsigned int blockNum = 0; blockNum < K; ++blockNum)
	{
		binaryString = "";

		for (unsigned int inputRow = 0; inputRow < M; ++inputRow)
		{
			cin >> temp;
			binaryString += temp;
		}

		tree.AddStringToBranch(binaryString);
	}
}
