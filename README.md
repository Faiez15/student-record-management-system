# DSA Algorithm Battle – Student Record Search

## Selected application
**Student Record Management System** using a student's unique register number as the search key.

## Problem (Part A)
A college stores many student records. Staff need to find a student's record quickly using the register number. A slow search becomes inconvenient as the number of records grows.

BST, AVL tree and hashing are suitable for comparison because all support insertion and searching, but organize data differently:
- **BST:** compares keys and follows left/right child links. Its performance depends on insertion order.
- **AVL:** a self-balancing BST. Rotations keep the tree height logarithmic.
- **Hashing:** computes an array index from the key. Linear probing checks the next slot when a collision occurs.

## Files
- `bst.c` – BST insertion, search, inorder traversal and height.
- `avl.c` – AVL insertion, search, rotations, inorder traversal and height.
- `hashing.c` – hashing, insertion, search and linear probing.
- `dataset.txt` – 30 unique register numbers and sample student labels.
- `actual_program_output.txt` – output captured by compiling and running the three programs.
- `report.md` – assignment write-up and comparison.
- `viva_questions.md` – short viva preparation.

## Compile and run (macOS / Linux)
Open Terminal in this folder:

```bash
gcc bst.c -o bst && ./bst
gcc avl.c -o avl && ./avl
gcc hashing.c -o hashing && ./hashing
```

On a Mac, install the Xcode Command Line Tools if `gcc` is not available:
`xcode-select --install`

## Dataset and experiment method
All three programs use the same 30 register numbers in the same insertion order:
105, 110, 115, ..., 250.

The programs perform:
1. Build the structure by inserting all 30 keys.
2. Successful search for `175`.
3. Unsuccessful search for `999`.
4. Insert a new key `252` and search for it.
5. Report the relevant measurements.

**Measurement definitions**
- Search comparisons: number of stored keys/slots inspected by the search operation. For hashing, each probed slot counts as one comparison.
- Tree height: number of levels (empty tree = 0, one-node tree = 1).
- Hash collisions: number of occupied slots encountered during insertion before an empty slot is found. The hash function is `key % 61`; table size is 61.

## Important
The data set is deliberately inserted in ascending order. This demonstrates a key difference: an ordinary BST can become skewed, while AVL rotations maintain balance. Your own compiler output is saved in `actual_program_output.txt`. Run the programs yourself before submission and be prepared to explain the measurement definitions.
