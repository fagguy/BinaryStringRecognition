#include "BinaryStringRecognition.h"

int main()
{
	PseudoTree tree;
	string test = "";

	test = "010011";
	tree.AddStringToBranch(test);
	test = "000011";
	tree.AddStringToBranch(test);
	test = "011011";
	tree.AddStringToBranch(test);
	test = "000111";
	tree.AddStringToBranch(test);

	tree.PrintContents();

	unsigned int splitBit = 1;
	cout << "Splitting at position: " << splitBit << "..." << endl;

	tree.SplitBranch(0, splitBit);

	tree.PrintContents();

	tree.CalculateBalanceRanks();
	tree.PrintBalanceRanks();

	system("Pause");
	return 0;
}
