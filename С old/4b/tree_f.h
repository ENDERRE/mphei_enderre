

#ifndef LIB_F
#define LIB_F
#include "tree_s.h"

enum se search(Node** temp,Tree* tree,int key);
enum se search_s(Node** temp,Tree* tree,int key);
Node* createNode(int key, int value);
int add_tree(Tree** tree);
void norm_mass_deph(Node* temp);
int find_goat_par(Node* newNode,Node** goat);
enum se search_iter(Node** temp,Node* goat,int key);
void iter_post_goat(Node* goat,Node** fir);
int insert(Tree* tree, int key, int value,Node** new);
void free_goat(Node* goat);
int check_mid(int mid,Node* min,Node* temp);
void norm_tree(Tree* tree,Node* goat);
void iter_post(Tree* tree);
int print_tree_png(Tree* tree);
void print_tree(Tree* tree);
enum se delete(Tree* tree,int key) ;
void free_tree(Tree* tree);
int input_txt(Tree* tree,char* name);
int out_file(Tree* tree,char* name);
int search_time(Tree* tree);
int dell_time(Tree* tree);

#endif