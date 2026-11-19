# Technical Assignment Report
## Algorithm Battle – Which Data Structure Wins?

**Institution:** SRM Institute of Science and Technology, Tiruchirappalli  
**Course:** Data Structures and Algorithms (DSA)  
**Application:** Student Record Management System  
**Search key:** Student Register Number  
**Programming language:** C

## Part A – Problem Selection

### a. What is the problem?
A college maintains student records identified by unique register numbers. Staff need to retrieve a student's record quickly using the register number.

### b. Why is efficient searching required?
As the number of students grows, checking every record one by one takes more time. Efficient searching reduces key comparisons and improves response time.

### c. Why are BST, AVL and Hashing suitable?
All three support insertion and searching. BST and AVL organize keys in sorted tree order; hashing maps keys to table positions and resolves collisions using linear probing.

## Part B – Implementation
- `bst.c`: BST insertion, search, inorder traversal and height.
- `avl.c`: AVL insertion, search, LL/RR/LR/RL rotations, inorder traversal and height.
- `hashing.c`: hash insertion, search and collision resolution with linear probing.

## Part C – Mini Experiment

### Dataset
The same 30 unique register numbers are inserted into all three implementations, in ascending order:

`105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195, 200, 205, 210, 215, 220, 225, 230, 235, 240, 245, 250`

Successful search key: `175`  
Unsuccessful search key: `999`  
Additional insertion test: `252`

### Experimental observations
Values below are captured from compiling and running the included C programs. See `actual_program_output.txt`.

| Parameter | BST | AVL | Hashing |
|---|---:|---:|---:|
| Successful search (175) | Successful search 175: FOUND; comparisons = 0 | Successful search 175: FOUND; comparisons = 5 | Successful search 175: FOUND; comparisons = 0 |
| Unsuccessful search (999) | Unsuccessful search 999: NOT FOUND; comparisons = 0 | Unsuccessful search 999: NOT FOUND; comparisons = 5 | Unsuccessful search 999: NOT FOUND; comparisons = 0 |
| Initial height (levels) | Tree height (levels): 30 | Tree height (levels): 5 | Not applicable |
| Insertion collisions (30 keys) | Not applicable | Not applicable | Total insertion collisions: 0 |
| Search after inserting 252 | After inserting 252, search: FOUND; comparisons = 0 | After inserting 252, search: FOUND; comparisons = 5 | After inserting 252, search: FOUND; comparisons = 0 |

**Measurement definitions**
- A search comparison counts each visited tree node or examined hash-table slot.
- Tree height is measured in levels (empty tree = 0; one node = 1).
- A hash collision counts each occupied slot encountered during insertion before an empty slot is found.
- Hash function: `key % 61`; table size: 61.

## Part D – Algorithm Battle

| Parameter | BST | AVL | Hashing |
|---|---|---|---|
| Search comparisons | Depends on tree shape; worst case O(n) | O(log n) due to balancing | Average O(1) with a good hash function and low load; worst case O(n) |
| Insertion | Simple; may become skewed | May require rotations | Computes an index; probes on collision |
| Height | Depends on insertion order | Balanced; O(log n) | Not applicable |
| Collision handling | Not applicable | Not applicable | Linear probing |
| Ordered traversal | Inorder gives sorted keys | Inorder gives sorted keys | No natural sorted traversal |
| Overall observation | Simple, but order-sensitive | Predictable logarithmic tree operations | Usually fast for exact-key lookup |

## Part E – Final Verdict

**Winner for exact register-number lookup: Hashing with Linear Probing**, provided the table is appropriately sized and the hash function distributes keys well. It offers fast average-case searching and insertion.

**Alternative recommendation: AVL tree** if the application also needs sorted traversal, range queries, or guaranteed logarithmic worst-case search. The experiment shows that a plain BST can become skewed when keys arrive in sorted order.

## Conclusion
The three implementations were tested using the same 30 register numbers and insertion order. The BST became skewed, AVL maintained balance through rotations, and hashing used linear probing to resolve collisions. For exact register-number lookup, hashing is recommended; AVL is a strong alternative when ordered operations and worst-case guarantees matter.

## Before submission
1. Compile and run all three `.c` files on your own computer.
2. Check the output and understand the measurements.
3. Add your name, register number, department, section and faculty details if required.
4. Push the source files, dataset, report and output to GitHub.
5. Submit the GitHub repository link in Google Classroom.
