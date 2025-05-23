/*

.                                                NOTES OF TREES 

📌 Introduction to binary trees;


* Type of hierarchical data structure but can be implemented as dynamic.
* At most two children nodes

📌 main element at the top of tree is called as ROOT.
📌 it sub nodes are called as CHILDREN. 
📌 the node which does not have sub nodes are called as LEAF;

📌 SUB TREE just beneath the node
📌 ANCESTORS : the nodes which are above the particular node are the ancestors

📌📌📌      TYPES OF BINARY TREE       📌📌📌
1) FULL BINARY TREE 
   ->> either 0 or 2 children nodes in a tree are known as full binary tree.
2) COMPLETE BINARY TREE
   ->> all levels should be completely filled except the last level.
   ->> and the last level nodes should be as left as possible..
3) PERFECT BINARY TREE
   ->> all leaf nodes are at same level..
4) BALANCED BINARY TREE
   ->>height of the tree should be at max log(N)
5) DEGENERATE TREE
.   ->>every node has a single children...

📌📌📌 Traversal of tree   📌📌📌

there are two types of traversal in binary tree:
1) BFS (BREADTH FIRST SEARCH)
2) DFS (DEPTH FIRST SEARCH)

📌📌 DFS
the traversal is done in length wise or depth wise there are three methods of it :
📌INORDER TRAVERSAL 
  ->> LEFT -> ROOT -> RIGHT
   check inorder_traversal.cpp
📌PREORDER TRAVERSAL 
  ->> ROOT -> LEFT -> RIGHT
   check preorder_traversal.cpp
📌POSTORDER TRAVERSAL
  ->> LEFT -> RIGHT -> ROOT

📌📌 BFS 
the traversal is done level wise first, second and so on that too from left to right..



*/