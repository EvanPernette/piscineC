#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

int size(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + size(tree->left) + size(tree->right);
    }
}

int height(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return -1;
    }
    else
    {
        int lefth = height(tree->left);
        int righth = height(tree->right);
        if (lefth <= righth)
        {
            return righth + 1;
        }
        else
        {
            return lefth + 1;
        }
    }
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        dfs_print_prefix(tree->left);
        dfs_print_prefix(tree->right);
    }
}

void __dfs_print_infix(const struct binary_tree *tree)
{
    if (tree->left)
    {
        dfs_print_infix(tree->left);
    }
    if (tree != NULL)
    {
        printf("%d ", tree->data);
    }
    if (tree->right)
    {
        dfs_print_infix(tree->right);
    }
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        __dfs_print_infix(tree);
    }
}

void __dfs_print_postfix(const struct binary_tree *tree)
{
    if (tree->left)
    {
        dfs_print_postfix(tree->left);
    }
    if (tree->right)
    {
        dfs_print_postfix(tree->right);
    }
    if (tree != NULL)
    {
        printf("%d ", tree->data);
    }
}

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        __dfs_print_postfix(tree);
    }
}

int is_perfect(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return 1;
    }
    int len = height(tree);
    int size1 = size(tree);
    int count = 1;
    int count2 = 0;
    while (len >= 0)
    {
        count2 += count;
        count *= 2;
        len--;
    }
    if (count2 == size1)
    {
        return 1;
    }
    return 0;
}

int __is_complete(const struct binary_tree *tree, int i, int node)
{
    if (tree == NULL)
    {
        return 1;
    }
    if (i >= node)
    {
        return 0;
    }
    if (__is_complete(tree->left, 2 * i + 1, node) == 1
        && __is_complete(tree->right, 2 * i + 2, node) == 1)
    {
        return 1;
    }
    return 0;
}

int is_complete(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return 1;
    }
    int x = size(tree);
    return __is_complete(tree, 0, x);
}

int is_degenerate(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return 1;
    }
    if (tree->right && tree->left)
    {
        return 0;
    }
    if (tree->right)
    {
        return is_degenerate(tree->right);
    }
    if (tree->left)
    {
        return is_degenerate(tree->left);
    }
    return 1;
}

int is_full(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return 1;
    }
    if (tree->right == NULL && tree->left == NULL)
    {
        return 1;
    }
    if (tree->right && tree->left)
    {
        if (is_full(tree->right) == is_full(tree->left))
        {
            return 1;
        }
    }
    return 0;
}

int __is_bst(const struct binary_tree *tree, int min, int max)
{
    if (tree == NULL)
    {
        return 1;
    }
    if (tree->data < min || tree->data > max)
    {
        return 0;
    }
    if (__is_bst(tree->left, min, tree->data - 1) == 1
        && __is_bst(tree->right, tree->data + 1, max) == 1)
    {
        return 1;
    }
    return 0;
}

int is_bst(const struct binary_tree *tree)
{
    if (tree == NULL)
    {
        return 1;
    }
    return __is_bst(tree, -100000, 100000);
}
