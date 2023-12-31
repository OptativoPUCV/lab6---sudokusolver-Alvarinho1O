#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
    for(int i=0; i<9; i++){
        int filas[10] = {0}; 
        for(int j=0; j<9; j++){
            int num = n->sudo[i][j];
            if(num != 0){
                if(filas[num] == 1){
                    return 0; 
                }
                filas[num] = 1; 
            }
        }
    }
    
    for(int j=0; j<9; j++){
        int col[10] = {0}; 
        for(int i=0; i<9; i++){
            int num = n->sudo[i][j];
            if(num != 0){
                if(col[num] == 1){ 
                    return 0;
                }
                col[num] = 1;
            }
        }
    }
    for(int k=0; k<9; k++){ 
        int matriz[10] = {0}; 
        for(int i=k/3*3; i<k/3*3+3; i++){
            for(int j=k%3*3; j<k%3*3+3; j++){
                int num = n->sudo[i][j];
                if(num != 0){
                    if(matriz[num] == 1){ 
                        return 0;
                    }
                    matriz[num] = 1;
                }
            }
        }
    }
    
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    Node* nodoRemp;
    int condicion;
    for(int i=0; i<9; i++){ 
      if(condicion!=1) break;
      for(int j=0; j<9; j++){  
        if(condicion!=1) break;
        if(n->sudo[i][j]==0){ 
          condicion=1;
          for(int k=1; k<=9; k++){
            nodoRemp = copy(n);
            nodoRemp->sudo[i][j] = k;
            if(is_valid(nodoRemp)){
              pushBack(list, nodoRemp);
            }else{
              free(nodoRemp);
            }
          }
        }
      }
    }
    return list;
}


int is_final(Node* n){
  for(int i=0; i<9; i++){
    for(int k=0; k<9; k++){
      if(n->sudo[i][k]==0) return 0;
      }
    }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/