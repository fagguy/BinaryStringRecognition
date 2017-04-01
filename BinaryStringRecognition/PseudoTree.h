#pragma once

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class PseudoTree
{
private:
	struct _columnTracker
	{
		unsigned int column;
		unsigned int balanceRank = 0;
	};

	vector<vector<string *> *> _container;
	vector<_columnTracker> _columnTrackers;
	unsigned int _identityBitCount = 0;

public:
	PseudoTree();
	~PseudoTree();

	unsigned int AddBranch();
	unsigned int BranchCount();
	void AddStringToBranch(string& str, unsigned int branchIndex = 0);
	void PrintContents(); // used for debugging
	void SplitBranch(unsigned int branchIndex, unsigned int bitPosition);
	int CalculateIdentityBitsCount();

	void CalculateBalanceRanks(); // test function... to be removed
	void PrintBalanceRanks(); // used for debugging

private:
	void __InitColumnTrackers();
	void __CalculateBalanceRanks(unsigned int bitsToSkip = 0);
	unsigned int __GarbageCollect();

	static bool __PrintBalanceRanksSortFunction(_columnTracker& i, _columnTracker& j);
	static bool __SortByBalanceRanksFunction(_columnTracker& i, _columnTracker& j);
};
