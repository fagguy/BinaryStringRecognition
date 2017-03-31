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

	tree.CalculateIdentityBitsCount();

	tree.PrintContents();

	system("Pause");
	return 0;
}
