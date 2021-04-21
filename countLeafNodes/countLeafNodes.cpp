#include <stdio.h>
#include <stdlib.h>  

//Binary tree has data,pointer left&right child
struct binaryTreeNode{  
    int data;  
    struct binaryTreeNode *left;  
    struct binaryTreeNode *right;  
};



//I created a new node  
struct binaryTreeNode *createNodes(int data){  
    //I created new node  
    struct binaryTreeNode *node = (struct binaryTreeNode*)malloc(sizeof(struct binaryTreeNode));  
    // Assign data to newNode, leftchildren= NULL and rightchildren=NULL  
    node -> data = data;  
    node -> left = NULL;  
    node -> right = NULL;  
      
    return node;  
}  

struct binaryTreeNode *generateBinaryTree(){
    //I define nodes
    struct binaryTreeNode *node =  createNodes(5);
    node->left = createNodes(7);
    node->right = createNodes(9);
    node->left->left = createNodes(11);
    node->left->right = createNodes(13);
    node->right->left = createNodes(15);
    node->right->right = createNodes(17);
    node->left->left->left = createNodes(19);
    node->right->left->left = createNodes(21);
    node->right->left->right = createNodes(23);
    node->right->left->left->left = createNodes(25);
    
    return node;
 
}


// I define the function for count of leaf nodes
int count = 0;
	
int countLeafNodes(struct binaryTreeNode *node){

//I checked whether they are NULL by looking at left or right from the nodes.
	if(node != NULL) {
		countLeafNodes(node -> left);
//If it is NULL;
//the leaf which is null is printed and the initially 0 count is increased by 1.
		if((node -> left == NULL) && (node -> right == NULL)) {
	
			printf("\n Leaf Node = %d \n",node->data);
			count++;
			
		}
		
		countLeafNodes(node -> right);
	
		
	}

//If the node is not NULL then count = 0.

	else {
		return count;
	}


}

int main() {
	
//I set root the binary tree nodes that I specified above
	struct binaryTreeNode *node = generateBinaryTree();
	
	printf(" \n The count of leaf nodes in binary tree: %d" ,countLeafNodes(node));

    return 0;
}
