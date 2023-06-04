#include <iostream>
#include<fstream>
using namespace std;

struct tree
{
    int info;
    tree* left;
    tree* right;
};
void add_node(tree* root, int data)
{
    if (data < root->info)
    {
        if (root->left == NULL)
        {
            tree* r = new tree;
            r->info = data;
            r->left = NULL;
            r->right = NULL;
            root->left = r;
        }
        else
            add_node(root->left, data);
    }
    else
    {
        if (root->right == NULL)
        {
            tree* r = new tree;
            r->info = data;
            r->left = NULL;
            r->right = NULL;
            root->right = r;
        }
        else
            add_node(root->right, data);
    }
}
void print_RNL(tree* root)
{
    if (root != NULL)
    {
        print_RNL(root->right);
        cout << root->info << " ";
        print_RNL(root->left);
    }
}
bool check3(tree* root) {
    if (root != NULL) {
        if (root->left != NULL) {
            if (root->info == root->left->info) {
                return true;
            }
        }
        if (root->right != NULL) {
            if (root->info == root->right->info) {
                return true;
            }
        }
        return check3(root->left) || check3(root->right);
    }
    return false;
}
int list(tree* t)
{
    if (t != NULL)
    {
        if (t->left != NULL && t->right != NULL)
        {
            return 1 + list(t->left) + list(t->right);
        }
        return list(t->left) + list(t->right);
    }
    return 0;
}
int sum(tree* t)
{
    if (t != NULL)
    {
        if (t->left != NULL && t->right != NULL)
        {
            return t->info + list(t->left) + list(t->right);
        }
        return list(t->left) + list(t->right);
    }
    return 0;
}
void max(tree* t)
{
    if (t->right == NULL)t->info *= 2;
    else
        max(t->right);
}
int main()
{
    tree* root = new tree;
    int x;
    cin >> x;
    root->info = x;
    root->left = NULL;
    root->right = NULL;
    for (cin >> x; x != 0; cin >> x)
        add_node(root, x);
    if (check3(root) == 1)
    {
        int k = list(root);
        cout << sum(root) / k;
    }
    else
    {
        max(root);
        print_RNL(root);
    }

}