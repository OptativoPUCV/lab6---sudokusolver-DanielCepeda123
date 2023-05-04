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
  int arregloNumeros[9];
  arregloNumeros[0] = 0;
  arregloNumeros[1] = 0;
  arregloNumeros[2] = 0;
  arregloNumeros[3] = 0;
  arregloNumeros[4] = 0;
  arregloNumeros[5] = 0;
  arregloNumeros[6] = 0;
  arregloNumeros[7] = 0;
  arregloNumeros[8] = 0;

  int i, j, k;
  
    for ( j = 0 ; j < 9 ; j++){
      for ( k = 0 ; k < 9 ; k++){
        i = n->sudo[j][k];
        if (arregloNumeros[i - 0] == 1) return 0;
        if (arregloNumeros[i - 0] == i) arregloNumeros[i - 0] = 1;
      }
    } 

  int p;
   for (k = 0 ; k <= 9 ; k++){  
    for(p=0;p<9;p++){
      int i=3*(k/3) + (p/3) ;
      int j=3*(k%3) + (p%3) ;
      //printf("%d ",n->sudo[i][j]);
      //if(p%3 == 2) printf("\n");
      }
 }
  

    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();

  int i,j, k;
  
  for( i = 0 ; i < 9 ; i++)
    {
      for( j = 0 ; j < 9 ; j++)
        {
          if (n->sudo[i][j] == 0){
            for ( k = 1 ; k <= 9 ; k++ ){
              Node* nuevoNodo = copy(n);
              nuevoNodo->sudo[i][j] = k;
              pushBack(list, nuevoNodo);
            }
              
          }
        }
    }
    return list;
}


int is_final(Node* n){
    return 0;
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