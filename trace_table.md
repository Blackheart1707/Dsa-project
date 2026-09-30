# Trace Table

## BST insertion (keys: 45 20 60 10 30 50 70 25 55)

| Step | Key | Comparison path | Placement |
|---|---|---|---|
| 1 | 45 | tree empty | root |
| 2 | 20 | 20<45 | left of 45 |
| 3 | 60 | 60>45 | right of 45 |
| 4 | 10 | 10<45, 10<20 | left of 20 |
| 5 | 30 | 30<45, 30>20 | right of 20 |
| 6 | 50 | 50>45, 50<60 | left of 60 |
| 7 | 70 | 70>45, 70>60 | right of 60 |
| 8 | 25 | 25<45, 25>20, 25<30 | left of 30 |
| 9 | 55 | 55>45, 55<60, 55>50 | right of 50 |

Height of resulting tree = 3.

## Traversals
- Inorder: 10 20 25 30 45 50 55 60 70 (sorted)
- Preorder: 45 20 10 30 25 60 50 55 70
- Postorder: 10 25 30 20 55 50 70 60 45

## Search traces
- **25**: BST path 45 -> 20 -> 30 -> 25 (4 comparisons). Linear scans 45,20,60,10,30,50,70,25 (8).
- **55**: BST path 45 -> 60 -> 50 -> 55 (4). Linear scans all 9 elements (9).
- **90**: BST path 45 -> 60 -> 70 -> NULL (3). Linear scans all 9, not found (9).
