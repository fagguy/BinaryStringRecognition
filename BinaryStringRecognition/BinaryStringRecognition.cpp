#include "BinaryStringRecognition.h"

int main()
{
	PseudoTree tree;
	string test = "";

	test = "100000000";
	tree.AddStringToBranch(test);
	test = "001000000";
	tree.AddStringToBranch(test);
	test = "000000001";
	tree.AddStringToBranch(test);
	test = "000000100";
	tree.AddStringToBranch(test);
	test = "000010000";
	tree.AddStringToBranch(test);
	test = "010000000";
	tree.AddStringToBranch(test);
	test = "101111101";
	tree.AddStringToBranch(test);
	test = "111010010";
	tree.AddStringToBranch(test);
	test = "101101010";
	tree.AddStringToBranch(test);
	
	//tree.PrintContents();

	cout << "min no. of identity bits: " << endl
		<< "> " << tree.CalculateIdentityBitsCount(true) << endl;

	system("Pause");
	return 0;
}
