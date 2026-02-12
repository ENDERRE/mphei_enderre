#include <stdio.h>
#include <stdlib.h>
int checkno(char *s[],int *len){
    for (int i=0;i<*len;i++){
        if((*s)[i]=='n' && (*s)[i+1]=='o'){
            return 0;
            }
    }
    return 1;
}
void revers(char *str[], int *len){

	
	while(checkno(&(*str),&(*len))==0){
	for (int i=0;i<(*len)-1;i++){
		
		if((*str)[i]=='n' && (*str)[i+1]=='o'){
			(*str)[i]='o';
			(*str)[i+1]='n';
			}
		}
    }
}
		

int main() {
    char *str = NULL, c;
    int len = 0;
    str = (char*) malloc(sizeof(char));
    printf("input string: ");
    while((c = getchar()) != '\n') {
        str[len ] = c;
        len++;
        str = (char*) realloc(str, len);
    }
    str[len ] = '\0';
    
    revers(&str,&len);
    printf("output other: %s",str);
    return 0;
}
