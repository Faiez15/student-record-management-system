# Viva Preparation – Student Record Search

1. **What is a BST?**  
   A Binary Search Tree is a binary tree where keys smaller than a node go to its left subtree and larger keys go to its right subtree.

2. **What is the main disadvantage of an ordinary BST?**  
   It can become skewed if keys are inserted in sorted order. Its worst-case search and insertion time becomes O(n).

3. **What is an AVL tree?**  
   An AVL tree is a self-balancing BST. For every node, the height difference between left and right subtrees is at most 1.

4. **What is a balance factor?**  
   Height(left subtree) minus height(right subtree). In a balanced AVL node it must be -1, 0 or +1.

5. **Name the four AVL rotations.**  
   LL, RR, LR and RL.

6. **What is hashing?**  
   Hashing applies a hash function to a key to calculate an array index.

7. **What is a collision?**  
   A collision occurs when two different keys map to the same table index.

8. **What is linear probing?**  
   If the calculated slot is occupied, check the next slot, continuing circularly until an empty slot or the key is found.

9. **What hash function is used here?**  
   `key % 61`.

10. **Why is the table size 61?**  
    The table has 61 slots for 30 initial records, keeping the load factor below 0.5. A larger table generally reduces clustering and collisions.

11. **What is the load factor?**  
    Number of stored keys divided by table capacity. Initially it is 30/61, approximately 0.492.

12. **What is inorder traversal?**  
    Visit left subtree, node, then right subtree. In a BST or AVL tree it prints keys in ascending order.

13. **Why does the BST become skewed in this experiment?**  
    The keys are inserted in ascending order, so each new key becomes the right child of the previous key.

14. **Which structure is best for exact register-number search?**  
    Hashing is generally best on average, provided the table has a suitable size and hash function. AVL is preferable when ordered traversal or range searching is needed.

15. **What happens if the faculty asks you to insert 260?**  
    In BST, follow comparisons to the correct empty child position. In AVL, insert as in BST and then update heights and rotate if necessary. In hashing, calculate 260 % 61 and use linear probing if that slot is occupied.
