#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 5

int stack[TAMANHO];
int top = -1;

bool isEmpty(){
    return top == -1;
}

void push(int data){
    if(top == TAMANHO - 1){
        printf("Pilha Cheia!\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("Valor %d empilhado com sucesso!\n", data);
}

int pop(){
    if(isEmpty()){
        printf("Pilha Vazia!\n");
        return -1;
    }
    int temp = stack[top];
    top--;
    return temp;
}

void imprime_pilha(){
    if(isEmpty()){
        printf("Pilha Vazia!\n");
        return;
    }
    printf("Pilha: ");
    for(int i = 0; i <= top; i++){
        printf("%d -> ", stack[i]);
    }
    printf("topo\n");
}

void topo(){
    if(isEmpty()){
        printf("Pilha Vazia!\n");
        return;
    }
    printf("Topo: %d\n", stack[top]);
}

void menu(){
    printf("\n------ MENU PILHA ------\n");
    printf("1. Empilhar (push)\n");
    printf("2. Desempilhar (pop)\n");
    printf("3. Imprimir pilha\n");
    printf("4. Mostrar topo\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

int main(){
    int opcao, valor;
    
    do {
        menu();
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Digite o valor para empilhar: ");
                scanf("%d", &valor);
                push(valor);
                break;
            case 2:
                valor = pop();
                if(valor != -1){
                    printf("Valor desempilhado: %d\n", valor);
                }
                break;
            case 3:
                imprime_pilha();
                break;
            case 4:
                topo();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 5);
    
    return 0;
}