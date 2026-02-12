#ifndef LIB_STACK
#define LIB_STACK
 



 void free_stack(stack *tmp);
int add_stack(stack** tmp);
int cube_switch_stack(puzzle* cube, stack* tmp);
int cube_undo_stack(stack* tmp,el** tt);




#endif
