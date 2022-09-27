#include "treemap.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// treemap_funcs.c: Provides a small library of functions that operate on
// binary search trees mapping strings keys to string values.

/**
 * @brief Initialize the given tree to have a null root making it size 0.
 *
 * @param tree, a empty tree
 */
void treemap_init(treemap_t *tree)
{
    tree->root = NULL;
}

/**
 * @brief inserts a key/value into a tree
 *
 * @param tree the tree the key/value is inserted in
 * @param key way to find the val
 * @param val information stored
 * @return int 0 no new node created, 1 new node was created
 */
int treemap_add(treemap_t *tree, char key[], char val[])
{
    node_t *cur = tree->root;
    if (cur == NULL)
    {
        cur = (node_t*)malloc(sizeof(node_t));
        strcpy(cur->key, key);
        strcpy(cur->val, val);
        return 1;
    }
    else
    {
        while (1)
        {
            if (strcmp(cur->key, key) > 0) // if key is bigger go right
            {
                if (cur->right != NULL)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = malloc(sizeof(node_t));
                    strcpy(cur->right->key, key);
                    strcpy(cur->right->val, val);
                }
            }
            else if (strcmp(cur->key, key) < 0) // if key is smaller go left
            {
                if (cur->left != NULL)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = malloc(sizeof(node_t));
                    strcpy(cur->left->key, key);
                    strcpy(cur->left->val, val);
                }
            }
            else if (strcmp(cur->key, key) == 0) // if equal update the val and exit
            {
                strcpy(cur->val, val);
                return 0;
            }
        }
        // cur should be a null value now and the correct loc for key
    }
    return 2;//shouldnt reach
}


/**
 * @brief searches tree for key
 *
 * @param tree the tree to search through
 * @param key the key of the node to search for
 * @return char* returns the node if found or NULL if not found
 */
char *treemap_get(treemap_t *tree, char key[])
{
    node_t *cur = tree->root;
    while (cur != NULL)
    {
        if (strcmp(cur->key, key) > 0) // if key is bigger go right
        {
            cur = cur->right;
        }
        else if (strcmp(cur->key, key) < 0) // if key is smaller go left
        {
            cur = cur->left;
        }
        else if (strcmp(cur->key, key) == 0) // if equal return the node
        {
            return cur->val;
        }
    }
    return NULL; // only breaks out of the while loop if doesn't exist
}

/**
 * @brief clears all nodes and frees the memory
 *
 * @param tree tree to clear
 */
void treemap_clear(treemap_t *tree){
    node_remove_all(tree->root);
}

/**
 * @brief helps treemap_clear by freeing memory
 *
 * @param cur current node we are looking at current node we are looking at
 */
void node_remove_all(node_t *cur){
    //checks left
    if (cur->left != NULL)
    {
        node_remove_all(cur->left);
    }
    //checks right
    if (cur->right != NULL)
    {
        node_remove_all(cur->right);
    }
    //if there isn't a left or right clears 
    free(cur->key);
    free(cur->val);
    free(cur);
}

/**
 * @brief returns the number of nodes in the tree
 *
 * @param tree
 * @return int
 */
int treemap_size(treemap_t *tree){
    return node_count_all(tree->root);
}

/**
 * @brief returns the size of the tree under the current node
 *
 * @param cur current node we are looking at
 * @return int
 */
int node_count_all(node_t *cur){
    if (cur!= NULL)
    {
        return 1 + node_count_all(cur->left) + node_count_all(cur->right);
    }
    return 0;
}


/**
 * @brief prints the nodes in reverse order
 *  with 2 starting spaces per level of indentation
 *
 * @param tree tree to print out
 */
void treemap_print_revorder(treemap_t *tree){
    return node_print_revorder(tree->root, 0);
}

/**
 * @brief helper function that prints the nodes in reverse order
 *  with 2 starting spaces per level of indentation
 *
 * @param cur current node we are looking at
 * @param indent the value of spacing 2 spaces per indent
 */
void node_print_revorder(node_t *cur, int indent){
    node_print_revorder(cur->right, indent++);
    for (size_t i = 0; i < indent; i++)
    {
        printf("  ");
    }
    printf("%s", &cur->key);
    printf("%s", &cur->val);
    node_print_revorder(cur->left, indent++);
}

/**
 * @brief print the tree in pre order, prints with 2 spaces on the left per level deep
 *
 * @param tree tree to print out
 */
void treemap_print_preorder(treemap_t *tree){
    node_write_preorder(tree->root, stdout, 0);
}

/**
 * @brief Saves the tree by opening the named file
 *
 * @param tree tree to save
 * @param fname file to save to
 */
void treemap_save(treemap_t *tree, char *fname){
    FILE *ptr = fopen(fname, "w");
    node_write_preorder(tree->root, ptr, 0);
    fclose(ptr);
}

/**
 * @brief helper function to prin things in preorder
 *
 * @param cur current node
 * @param out loc to output to
 * @param depth the depth of tree/spacing used to print with
 */
void node_write_preorder(node_t *cur, FILE *out, int depth){
    for (size_t i = 0; i < depth; i++)
    {
        printf("  ");
    }
    printf("%s", &cur->key);
    printf("%s", &cur->val);
    node_print_preorder(cur->left, depth++);
    node_print_preorder(cur->right, depth++);
}

/**
 * @brief clears current tree and loads one from a file
 *
 * @param tree tree to replace/fill with elements
 * @param fname file to read from
 * @return int 1 if loaded 0 if failed
 */
int treemap_load(treemap_t *tree, char *fname){
    FILE *ptr = fopen(fname, "r");
    if (!ptr) //checks if file exists
    {
        return 0;
    }
    treemap_clear(tree); // clears if file exists
    
    treemap_add(tree, fscanf(ptr, "%s"),fscanf(ptr, "%s"));//should add the first val depending on how spaces are dealt with
    //loop  

}
// Clears the given tree then loads new elements to it from the
// named. Repeated calls to treemap_add() are used to add strings read
// from the file.  If the tree is stored in pre-order in the file, its
// exact structure will be restored.  Returns 1 if the tree is loaded
// successfully and 0 if opening the named file fails in which case no
// changes are made to the tree.
