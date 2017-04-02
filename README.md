# Binary String Recognition Algorithm

This is my attempt to solve the following question:

>Say that we are given `K` different binary numbers, each with length `N` (`N` can be large). Is there an efficient algorithm to determine the minimal number of bits it needs to distinguish these numbers from each other?
>
>For example:
>
>Given `110` and `011`, we only have to check the first (or the last) bit to distinguish them, so the minimal number is `1`.
>
>Given `1000`, `0100`, `0010` and `0001`, we need to check at least three bits to distinguish, so the minimal number is `3`.
>
>Given `0000`, `0100`, `1000` and `1100`, we only have to check the first two bits, so the minimal number is `2`.
>
>Assume these binary numbers are the same length, i.e. `a1[0,1,…,N-1], …, aK[0,1,…,N-1]`.

## Basic Usage

This section provides basic instructions on how the code is used.

All the logic is provided by the **PseudoTree** class. To begin, create an instance of the **PseudoTree** class.

```
PseudoTree tree;
```

Next, add the binary numbers/strings to the **PseudoTree** using **AddStringToBranch()**.

```
string binaryNumber[] = {"0000", "0100", "1000", 1100"};

for (int i = 0; i < 4; ++i) {
  tree.AddStringToBranch(binaryNumber[i]);
}
```

Finally, use **CalculateIdentityBitsCount()** to find the minimum number of bits required to distinguish the binary string in the set.
**CalculateIdentityBitsCount()** output will be `-1` if the answer is impossible to find (e.g. due to duplicates in the set of numbers).

```
cout << tree.CalculateIdentityBitsCount() << endl; // 2
```
Calling **CalculateIdentityBitsCount()** with a `true` parameter will print the list of identity bits selected by the algorithm onto the console.

```
tree.CalculateIdentityBitsCount(true);
```
