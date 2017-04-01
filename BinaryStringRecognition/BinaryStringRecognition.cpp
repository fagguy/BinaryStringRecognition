#include "BinaryStringRecognition.h"

int main()
{
	PseudoTree tree;
	string test = "";

	test = "00111";
	tree.AddStringToBranch(test);
	test = "10110";
	tree.AddStringToBranch(test);
	test = "11101";
	tree.AddStringToBranch(test);
	test = "11100";
	tree.AddStringToBranch(test);
	test = "11011";
	tree.AddStringToBranch(test);
	test = "01010";
	tree.AddStringToBranch(test);
	test = "00001";
	tree.AddStringToBranch(test);
	test = "00000";
	tree.AddStringToBranch(test);
	
	tree.PrintContents();

	cout << "min no. of identity bits: " << endl
		<< "> " << tree.CalculateIdentityBitsCount(true) << endl;

	system("Pause");
	return 0;
}
