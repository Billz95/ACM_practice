# range tree/ segment tree

    normally for the fixed array, you can calculate the sums before hand. for the

for root tree, every root is the sum of their child. And it is a **binary tree**
when a node is updated, we only need to change their parents ( one node on each layer )
only change $log(n)$ nodes

when a range of sum is required, we go from the root, then recursively find modifeied range on their child and sum up in the end
complexity of $log(n)$

Implementaion using array, similar to heap
whenever have complete tree, use array for efficiency
multiply the size of input by two for the parents
able to build tree by repitition

```c++
    void update(int a, int val, int i = 1, int start = 1, int end = MAX_N){

    }
```
