#ifndef LIB_F
#define LIB_F


#include "tree_s.h"



enum se search(Node** temp,Tree* tree,int key);
void iter_post(Tree* tree);
Node* createNode(int key, int value) ;
int add_tree(Tree** tree);
int insert(Tree* tree, int key, int value) ;
void print_tree(Tree* tree);
enum se delete(Tree* tree,int key, int num) ;
void free_tree(Tree* tree);
enum se search_s(Node** temp,Tree* tree,int key);
int input_txt(Tree* tree,char* name);
int out_file(Tree* tree,char* name);
int print_tree_png(Tree* tree);


#endif