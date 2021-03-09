#include <iostream>
#include <cstdlib>
using namespace std;
# define GLOBALSPACE 5
struct node
{
   int info;
   node* left;
    node* right;

};
 node *root=NULL;

node* createnode(int data)
{

    node* temp=new node;
    temp->info=data ;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}
 node* insert(node *root,int data)
{
    if(root==NULL)
    {
        root=createnode(data);
        return root;
    }



            if(data<root->info)
                root->left=insert(root->left,data);
            else
                root->right=insert(root->right,data);


   return root;
}
void inorder(node* root)
{
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}
void postorder(node * root)
{
    if(root==NULL)
    return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->info<<" ";
    
}

void print2D(node* root, int space)
{
    int i;
    if (root==NULL)
    return ;
    
    space=space+GLOBALSPACE;
    print2D(root->right,space);
    cout<<"\n";
    
    for (int i=GLOBALSPACE;i<space;i++)
    {
        cout<<" ";
    }
    cout<<root->info<<"\n";
    print2D(root->left,space);
    
}

int height (struct node* root)
{
    if(root==NULL)
    return -1;
    
    int lheight=height(root->left);
    int rheight=height(root->right);
    
    if(lheight>rheight)
        return lheight+1;
    else
        return rheight+1;
        
}
void printlevel(struct node* root, int level)
{
    if(root==NULL)
    return ;
    
    else if(level==0)
    cout<<root->info;
    
    else
    {
        printlevel(root->left,level-1);
        printlevel(root->right,level-1);
    }
}

void levelorder(struct node* root)
{
    int h=height(root);
    
    for(int i=0;i<=h;i++)
    {
        printlevel(root,i);
    }
    
}



struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is 
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->info)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->info)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->info = temp->info;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}



int main()
{

    int keys[] = {4,2,5,1,3};


    for (int key: keys) {
        root = insert(root, key);
    }

    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<height(root);
    cout<<endl;    
    levelorder(root);
    cout<<endl;
    print2D(root,3);

root = deleteNode(root, 3);
inorder(root);cout<<endl;
levelorder(root);
    return 0;
}


