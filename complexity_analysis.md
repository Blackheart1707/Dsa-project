# Complexity Analysis

N = number of keys, H = height of the BST.

| Operation | Best | Average | Worst |
|---|---|---|---|
| BST insert / search | O(1) | O(log N) | O(N) (skewed tree, e.g. sorted input) |
| Linear search | O(1) | O(N) | O(N) |
| Traversals (any) | O(N) | O(N) | O(N) |

**Space:** BST uses O(N) for nodes; linear search on an array uses O(N) for the array and O(1) extra.
Recursive traversals use O(H) stack space (O(log N) balanced, O(N) skewed).

**Link to results:** here N = 9, H = 3, log2(9) is about 3.17. BST searches took 3-4 comparisons,
matching O(log N). Linear search took up to 9 = N comparisons, matching O(N).
