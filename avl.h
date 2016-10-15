#ifndef AVL_HDR
#define AVL_HDR
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct avl_node_s avl_node_t;
typedef struct avl_tree_s avl_tree_t;

typedef int (*avl_compare_t)(const avl_node_t *a, const avl_node_t *b, const void *aux);

struct avl_node_s {
    uintptr_t parent;
    avl_node_t *left;
    avl_node_t *right;
    avl_node_t *prev;
    avl_node_t *next;
};

struct avl_tree_s {
    avl_node_t *root;
    avl_compare_t compare;
    void *aux;
};


void avl_init(avl_tree_t *tree, avl_compare_t compare, void* aux);

void avl_insert(avl_tree_t *tree, avl_node_t *node);
void avl_remove(avl_tree_t *tree, avl_node_t *node);

avl_node_t *avl_search(avl_tree_t *tree, avl_node_t *node);

avl_node_t *avl_head(const avl_tree_t *tree);
avl_node_t *avl_tail(const avl_tree_t *tree);

avl_node_t *avl_next(const avl_node_t *node);
avl_node_t *avl_prev(const avl_node_t *node);

#define avl_ref(ELEMENT, TYPE, MEMBER) \
    ((TYPE *)((unsigned char *)(ELEMENT) - offsetof(TYPE, MEMBER)))

#ifdef __cplusplus
}
#endif

#endif
