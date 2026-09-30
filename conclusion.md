# Final Conclusion

On the given data, BST search used 11 comparisons in total versus 26 for linear search. The tree was
nearly balanced (height 3), so search cost stayed close to log N.

BST is the better choice when searches are frequent and data arrives in mixed order. Its weakness is
that sorted insertion order produces a skewed tree with O(N) search. A self-balancing tree (AVL or
Red-Black) removes that risk. Linear search is only preferable for very small or rarely searched data,
since it needs no extra structure.
