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
  
  int i, j, k, p, num;

  for(i = 0 ; i < 9 ; i++){
    int filas[10] = {0,0,0,0,0,0,0,0,0};
    for(j = 0 ; j < 9 ; j++){
      num = n->sudo[i][j];
      if (num != 0){
        if(filas[num - 1] == 0){
           filas[num - 1] = 1; 
        }else{
          return 0;
        } 
      }
    }
  }

  for (i = 0 ; i < 9 ; i++){
    int columnas[10] = {0,0,0,0,0,0,0,0,0};
    for(j = 0 ; j < 9 ; j++){
      num = n->sudo[j][i];
      if(num != 0){
        if(columnas[num - 1] == 0){
          columnas[num - 1] = 1;
        }else{
          return 0;
        }
      }
    }
  }

  for(k = 0; k < 9 ; k++){
    int submatriz[10] = {0,0,0,0,0,0,0,0,0};
    for(p=0;p<9;p++){
      i=3*(k/3) + (p/3);
      j=3*(k%3) + (p%3);
      num = n->sudo[i][j];
      if(num != 0){
        if(submatriz[num - 1] == 0){
          submatriz[num - 1] = 1;
        }else{
          return 0;
        }
      }
      
    }
  }
  
  return 1;
}

List* get_adj_nodes(Node* n){
  List* list=createList();

  int i, j, k;
  
  for( i = 0 ; i < 9 ; i++)
    {
      for( j = 0 ; j < 9 ; j++)
        {
          if (n->sudo[i][j] == 0){
            for( k = 1 ; k <= 9 ; k++ ){
              Node* nuevoNodo = copy(n);
                nuevoNodo->sudo[i][j] = k;
                if(is_valid(nuevoNodo) == 1){
                  pushBack(list, nuevoNodo);
                }
            }
             return list; 
          }
        }
    }
    return list;
}

int is_final(Node* n){
  int i, j, aux;

  for(i = 0 ; i < 9 ; i++){
    for(j = 0 ; j < 9 ; j++){
      aux = n->sudo[i][j];
      if (aux == 0) return 0;
    }
  }
    return 1;
}

Node* DFS(Node* initial, int* cont){

  Stack* pila = createStack();
  push(pila, initial);

  while(get_size(pila) != 0){
    (*cont)++;
    Node* n = top(pila);
    pop(pila);
    if(is_final(n) == 1) return n;
    List* listaAdyacentes = get_adj_nodes(n);
    Node* aux = first(listaAdyacentes);

    while(aux){
      push(pila, aux);
      aux = next(listaAdyacentes);
    }
    free(aux);
    free(n);
  }
  
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