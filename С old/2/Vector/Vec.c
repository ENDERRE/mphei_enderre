
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 

#include "../game_l.h"
#include "Vec.h"
#include "../game_global.h"
 

void free_vectr(vectr** VV){
    free((*VV)->vec);
    free(*VV);
}
int add_vectr(vectr **VV){
    (*VV)=malloc(sizeof(vectr));
    if(!(*VV)){
        return 0;
    }
    if(check_int_input(&((*VV)->g))==0 || (*VV)->g==0){
        free(VV);
        return 0;
    }

    (*VV)->vec=NULL;
    (*VV)->vec=malloc(sizeof(pos)*((*VV)->g));
    if(!(*VV)->vec){
        free(VV);
        return 0;
    }
    
    
    (*VV)->top=0;
    return 1;
}
int push(vectr* VV,puzzle* cube){

    if((VV->top)==(VV->g)){
        undo(VV);
        
        VV->vec[(VV->top)-1]=cube->empt;
    }else{
        VV->vec[VV->top]=cube->empt;
        VV->top+=1;
    }
    return 1;

}
int pop(pos* tt,vectr *VV){
    if((VV->top)!=0){
        *tt=VV->vec[VV->top-1];
        
        (VV->top)-=1;

    }else if ((VV->top)==0){
        return 0;
    }
    return 1;
}
