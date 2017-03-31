#include "BinaryStringRecognition.h"

int main()
{
	PseudoTree tree;
	string test = "";

	test = "001110";
	tree.AddStringToBranch(test);
	test = "110101";
	tree.AddStringToBranch(test);
	test = "111100";
	tree.AddStringToBranch(test);
	test = "111010";
	tree.AddStringToBranch(test);
	test = "111001";
	tree.AddStringToBranch(test);
	test = "111000";
	tree.AddStringToBranch(test);

	tree.PrintContents();

	cout << tree.CalculateIdentityBitsCount() << endl;

	system("Pause");
	return 0;
}
