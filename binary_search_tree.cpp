#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    //constructor for the Node (creating heap in dynamic memory)

    Node(int val){
        data = val;
        left = right = NULL;
    }
}; 

Node* insertBST(Node* root , int val){    // function to insert element in a tree
    if (root == NULL){
        return new Node(val);         // if the root is null or no elements
    }
    else if (root->data >= val){                  // if value of new data is less than or equal to data of root
        root->left = insertBST(root->left , val);
    }
    else{
        root->right = insertBST(root->right , val);   // if value of new data is greater than the data of root
    }
    return root;
}

// to display the contents of the tree

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    else{
        inorder(root->left);
        cout<<root->data<<" "<<endl;
        inorder(root->right);
    }
}

// to search a element in the binary search tree

bool search(Node* root, int data){
    if (root == NULL){
        return false;
    }
    else if(data == root->data){
        return true;
    }
    else if(data <= root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

int FindMin(Node* root){   // to find the smallest element of the tree
    if(root == NULL){
        return -1;
    }
    else{
        while(root->left != NULL){
            root = root->left;
        }
        return root->data;
    }
}

int FindMax(Node* root){  // to find the gretest element of the tree
    if(root == NULL){
        return -1;
    }
    else{
        while(root->right != NULL){
            root = root->right;
        }
        return root->data;
    }
}

int FindHeight(Node* root){    // to find the height of the tree
    if(root == NULL){
        return -1;
    }
    return (max(FindHeight(root->left),FindHeight(root->right)) + 1);
}

void Level(Node* root){    // traversal of tree in level wise order
    if(root == NULL){
        return;
    }
    queue <Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* current = Q.front();
        cout<<current->data<<" ";
        if(current->left != NULL){
            Q.push(current->left);
        }
        if(current->right != NULL){
            Q.push(current->right);
        }
        Q.pop();
    }
}




int main(){
    Node* root = NULL;    //creating pointer for root
    root = insertBST(root,15);   // heap for root element
    insertBST(root,10);      
    insertBST(root,20);
    insertBST(root,8);      // creating tree.
    insertBST(root,12);
    insertBST(root,17);
    insertBST(root,25);
// printing the elements in the BST in order and when ever we do so the tree comes in sorted manner.
    inorder(root);
    int n;
    cout<<"Enter the element to be searched : ";
    cin>>n;
    if(search(root,n)){
        cout<<"Element is found"<<endl;
    }
    else{
        cout<<"Element was not found"<<endl;
    }
    cout<<"The samllest element is : "<<FindMin(root)<<endl;
    cout<<"The greatest element is : "<<FindMax(root)<<endl;
    cout<<"The height of the tree is : "<<FindHeight(root)<<endl;
    Level(root);
    return 0;
}