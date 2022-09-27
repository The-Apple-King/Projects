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

// Inserts given key/value into a binary search tree. Uses an
// ITERATIVE (loopy) approach to insertion which starts a pointer at
// the root of the tree and changes its location until the correct
// insertion point is located. If the key given already exists in the
// tree, no new node is created; the existing value is changed to the
// parameter 'val' and 0 is returned.  If no node with the given key
// is found, a new node is created and with the given key/val, added
// to the tree, and 1 is returned. Makes use of strcpy() to ease
// copying characters between memory locations.

/**
 * @brief searches tree for key
 *
 * @param tree the tree to search through
 * @param key the key of the node to search for
 * @return char* returns the node if found or null if not found
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

// Searches the tree for given 'key' and returns its associated
// value. Uses an ITERATIVE (loopy) search approach which starts a
// pointer at the root of the tree and changes it until the search key
// is found or determined not to be in the tree. If a matching key is
// found, returns a pointer to its value. If no matching key is found,
// returns NULL.

/**
 * @brief clears all nodes and frees the memory
 *
 * @param tree tree to clear
 */
void treemap_clear(treemap_t *tree){
    node_remove_all(tree->root);
}
// Eliminate all nodes in the tree setting its contents empty. Uses
// recursive node_remove_all() function to free memory for all nodes.

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
// Recursive helper function which visits all nodes rooted at node
// `cur` and frees the memory associated with them. This requires a
// post-order traversal: visit left sub-tree, visit right sub-tree,
// then free the `cur` node.

/**
 * @brief returns the number of nodes in the tree
 *
 * @param tree
 * @return int
 */
int treemap_size(treemap_t *tree){
    return node_count_all(tree->root);
}
// Returns the number of nodes currently in the tree. Uses
// node_count_all() to recursively count all nodes.

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
// Counts all nodes in the tree rooted at `cur`. Uses recursion to
// descend to the left and right branch if present and count nodes
// there, adding 1 for the `cur` if non-null. Returns 0 if `cur` is
// NULL.

/**
 * @brief prints the key/val pairs in reverse order
 *
 * @param tree
 */
void treemap_print_revorder(treemap_t *tree){
    return node_print_revorder(tree->root, 0);
}
// Prints the key/val pairs of the tree in reverse order at differing
// levels of indentation which shows all elements and their structure
// in the tree. Visually the tree can be rotated clockwise to see its
// structure. See the related node_print_revorder() for additional
// detals.

/**
 * @brief helper function that prints the nodes
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
// Recursive helper function which prints all key/val pairs in the
// tree rooted at node 'cur' in reverse order. Traverses right
// subtree, prints cur node's key/val, then traverses left tree.
// Parameter 'indent' indicates how far to indent (2 spaces per indent
// level).
//
// For example: a if the root node "El" is passed into the function
// and it has the following structure:
//
//         ___El->strange_____
//        |                   |
// Dustin->corny       ___Mike->stoic
//                    |
//               Lucas->brash
//
// the recursive calls will print the following output:
//
//   Mike -> stoic                 # root->right
//     Lucas -> brash              # root->right->left
// El -> strange                   # root
//   Dustin -> corny               # root->left

/**
 * @briefprint the tree in pre order
 *
 * @param tree
 */
void treemap_print_preorder(treemap_t *tree){
    node_write_preorder(tree->root, stdout, 0);
}
// Print all the data in the tree in pre-order with indentation
// corresponding to the depth of the tree. Makes use of
// node_write_preorder() for this.

/**
 * @brief
 *
 * @param tree
 * @param fname
 */
void treemap_save(treemap_t *tree, char *fname){
    
}
// Saves the tree by opening the named file, writing the tree to it in
// pre-order with node_write_preorder(), then closing the file.

/**
 * @brief
 *
 * @param cur
 * @param out
 * @param depth
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
// Recursive helper function which writes/prints the tree in pre-order
// to the given open file handle. The parameter depth gives how far to
// indent node data, 2 spaces per unit depth. Depth increases by 1 on
// each recursive call. The function prints the cur node data,
// traverses the left tree, then traverses the right tree.

/**
 * @brief
 *
 * @param tree
 * @param fname
 * @return int
 */
int treemap_load(treemap_t *tree, char *fname){

}
// Clears the given tree then loads new elements to it from the
// named. Repeated calls to treemap_add() are used to add strings read
// from the file.  If the tree is stored in pre-order in the file, its
// exact structure will be restored.  Returns 1 if the tree is loaded
// successfully and 0 if opening the named file fails in which case no
// changes are made to the tree.
