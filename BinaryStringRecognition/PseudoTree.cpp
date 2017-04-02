#include "PseudoTree.h"

PseudoTree::PseudoTree()
{
	this->AddBranch();
}

PseudoTree::~PseudoTree()
{
	for (auto& branch : _container)
	{
		for (auto str : branch)
		{
			delete str;
			--_stringCount;
		}
	}
}

unsigned int PseudoTree::AddBranch()
{
	vector<string *> newBranch;
	_container.push_back(newBranch);

	return _container.size() - 1; // returns the branch index
}

unsigned int PseudoTree::BranchCount()
{
	return _container.size();
}

void PseudoTree::AddStringToBranch(string & str, unsigned int branchIndex)
{
	_container[branchIndex].push_back(new string(str));
	++_stringCount;
}

void PseudoTree::PrintContents()
{
	for (unsigned int idx = 0; idx < _container.size(); ++idx)
	{
		cout << "branch " << idx << ":" << endl;

		for (auto str : _container[idx])
		{
			cout << "> " << *str << endl;
		}

		cout << endl;
	}
}

void PseudoTree::SplitBranch(unsigned int branchIndex, unsigned int bitPosition)
{
	this->__SplitBranch(branchIndex, bitPosition);
	this->__GarbageCollect();
}

int PseudoTree::CalculateIdentityBitsCount(bool debug)
{
	this->__InitColumnTrackers();

	while (!_container.empty())
	{
		if (_identityBitCount == _columnTrackers.size())
		{
			return -1; // impossible to find answer... means that there is a duplicate among inputs
		}

		// calculate the balance ranks
		this->__CalculateBalanceRanks(_identityBitCount);
		// then shift the lowest ranked one to our "working front"
		this->__ShiftMinBalanceRankToFront(_identityBitCount);
		// further split branches based on 'most balanced bit'
		for (int idx = _container.size() - 1; idx >= 0; --idx)
		{
			this->__SplitBranch(idx, _columnTrackers[_identityBitCount].column);
		}
		// clear empty or single item branches
		this->__GarbageCollect();

		++_identityBitCount;
	}

	if (debug) this->__PrintIdentityBits();

	return _identityBitCount;
}

void PseudoTree::CalculateBalanceRanks()
{
	this->__CalculateBalanceRanks();
}

void PseudoTree::PrintBalanceRanks()
{
	vector<_columnTracker> temp = _columnTrackers;

	sort(temp.begin(), temp.end(), __PrintBalanceRanksSortFunction);

	for (auto& tracker : temp)
	{
		cout << tracker.balanceRank << " ";
	}
	cout << endl;
}

void PseudoTree::__SplitBranch(unsigned int branchIndex, unsigned int bitPosition)
{
	// create a new branches first
	unsigned int zeroBranchIndex = this->AddBranch();
	unsigned int oneBranchIndex = this->AddBranch();

	// iterate through the selected branch and transfer strings over
	for (auto str : _container[branchIndex])
	{
		if ((*str)[bitPosition] == '0')
		{
			_container[zeroBranchIndex].push_back(str);
		}
		else if ((*str)[bitPosition] == '1')
		{
			_container[oneBranchIndex].push_back(str);
		}
	}

	// delete the selected branch
	_container.erase(_container.begin() + branchIndex);
}

void PseudoTree::__InitColumnTrackers()
{
	_columnTracker tracker;

	for (unsigned int idx = 0; idx < (_container[0])[0]->length(); ++idx) // length of first string of first branch
	{
		tracker.column = idx;
		_columnTrackers.push_back(tracker);
	}
}

void PseudoTree::__CalculateBalanceRanks(unsigned int bitsToSkip)
{
	for (unsigned int idx = bitsToSkip; idx < _columnTrackers.size(); ++idx)
	{
		_columnTrackers[idx].balanceRank = 0; // reset the balance rank

		for (auto& branch : _container)
		{
			int rawSum = 0;

			for (auto str : branch)
			{
				if ((*str)[_columnTrackers[idx].column] == '1') ++rawSum;
				else if ((*str)[_columnTrackers[idx].column] == '0') --rawSum;
			}

			_columnTrackers[idx].balanceRank += abs(rawSum);
		}
	}
}

void PseudoTree::__ShiftMinBalanceRankToFront(unsigned int front)
{
	auto trackersFront = _columnTrackers.begin() + front;
	auto minTracker = min_element(trackersFront, _columnTrackers.end(), __SortByBalanceRanksFunction);

	iter_swap(trackersFront, minTracker);
}

void PseudoTree::__PrintIdentityBits()
{
	cout << "identity bits: " << endl << "> ";

	for (unsigned int idx = 0; idx < _identityBitCount; ++idx)
	{
		cout << _columnTrackers[idx].column << " ";
	}

	cout << endl;
}

unsigned int PseudoTree::__GarbageCollect()
{
	unsigned int garbageCount = 0;

	for (int index = _container.size() - 1; index >= 0; --index)
	{
		if (_container[index].size() < 2) // if branches contain one string or empty
		{
			for (auto str : _container[index])
			{
				delete str;
				--_stringCount;
			}

			_container.erase(_container.begin() + index);
			++garbageCount;
		}
	}

	return garbageCount; // returns number of branches deleted
}

bool PseudoTree::__PrintBalanceRanksSortFunction(_columnTracker& i, _columnTracker& j)
{
	return (i.column < j.column);
}

bool PseudoTree::__SortByBalanceRanksFunction(_columnTracker & i, _columnTracker & j)
{
	return (i.balanceRank < j.balanceRank);
}
