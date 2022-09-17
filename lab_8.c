#include<stdio.h>
#include<stdlib.h>

/* Este Algoritimo se propõe a resolver o seguinte problema:

Crie um algoritmo de ordenação que funciona da seguinte maneira:

Ele seleciona o maior elemento do vetor e o coloca na 1ª posição. Depois, seleciona o menor elemento, e o
coloca na última posição. Seleciona o 2º maior elemento, e coloca na 2ª posição. Seleciona
o 2º menor elemento e o coloca na penúltima posição. E assim sucessivamente até que o
vetor esteja ordenado de forma decrescente.
Exemplo de ordenamento:
Entrada: 5 10 20 3 1 4 -> Seleciona maior elemento e o coloca na 1ª posição
20 10 5 3 1 4 -> Seleciona menor elemento e o coloca na última posição
20 10 5 3 4 1 ...
e assim sucessivamente.

Após a ordenação, você deve implementar e criar um menu a ser manipulado pelo usuário com as seguintes funções:
- imprimir na tela os elementos do vetor (parâmetros: vetor e tamanho)
- remover elemento específico do vetor, substituindo por 0 o valor removido e
deixando o valor 0 na última posição do vetor (parâmetros: tamanho, vetor, posição a
ser removida)
- sair

Restrições:
- O vetor deve ser criado e preenchido por você (tamanho 10)
- A ordenação deve ser uma função e deve ser chamada também por você
- O menu deve ser executado pelo usuário. Ele informa o que quer remover e pode imprimir o vetor quantas vezes desejar.

*/


void printarLista(int * lista, int tam_lista){
    printf("\n");
    for (int i=0; i<tam_lista; i++) {
        if( i==0 ){
            printf("\t[ %d,",lista[i]);
        }else if ( i == tam_lista-1){
            printf("%d",lista[i]);
        }else{
            printf("%d,",lista[i]);
        }
        
    }
    printf(" ]\n");
}

void trocarElementos(int * lista,int indice_e1, int indice_e2){
    int aux = lista[indice_e1];
    lista[indice_e1] = lista[indice_e2];
    lista[indice_e2] = aux; 
}

void moverElementoParaFinal(int * lista, int tam_lista, int indice_elemento){
    for (int i = indice_elemento; i < tam_lista-1; i++){
        trocarElementos(lista, i, i+1);
    }
    
}

void moverElementoParaInicio(int * lista, int tam_lista, int indice_elemento){
    for (int i = indice_elemento; i > 0; i--){
        trocarElementos(lista, i, i-1);
    }
    
}

int menorElemento(int * lista, int tam_lista){
    int aux = lista[0];
    if (tam_lista > 1 ){
        for (int i = 1; i < tam_lista; i++){
            if(aux>lista[i]){
                aux= lista[i];
            }
        
        }
    }
    return aux;
}

int selecioneIndiceMenorElemento(int * lista, int tam_lista){
    int aux = menorElemento(lista, tam_lista);
    int indice_menor_elemento = 0;

    for (int i = 0; i < tam_lista; i++){    
        if(lista[i] == aux){
            return indice_menor_elemento;
        }else{
            indice_menor_elemento++;
        }
    }
    return -1;
    
}

int maiorElemento(int * lista, int tam_lista){
    int aux = lista[0];
    if (tam_lista > 1) {
        for (int i = 1; i < tam_lista; i++){
            if(aux<lista[i]){
                aux= lista[i];
            }
        }
    }
    return aux;
}

int selecioneIndiceMaiorElemento(int * lista, int tam_lista){
    int aux = maiorElemento(lista, tam_lista);
    int indice_maior_elemento = 0;

    for (int i = 0; i < tam_lista; i++){    
        if(lista[i] == aux){
            return indice_maior_elemento;
        }else{
            indice_maior_elemento++;
        }
    }
    return -1;
    
}

int selecioneIndiceElemento(int * lista, int tam_lista,int elemento){
    int indice_elemento = 0;

    for (int i = 0; i < tam_lista; i++){    
        if(lista[i] == elemento){
            return indice_elemento;
        }else{
            indice_elemento++;
        }
    }
    return -1;
    
}

void copiarListaEmTecho(int * lista,int tam_lista, int * lista_copia, int inicio_lista_copia){
    printf("\n");
    for (int i = 0; i < tam_lista; i++){
        
        lista_copia[i+inicio_lista_copia] = lista[i];
    }
    printf("\n");
}

/*Remove elemento específico do vetor, substituindo por 0 o valor removido e
deixando o valor 0 na última posição do vetor (parâmetros: vetor,tamanho, posição a
ser removida)*/
void deletarElemento(int * lista,int tam_lista, int indice_elemento){
    if( indice_elemento != -1 ){
        for(int i = indice_elemento; i < tam_lista-1; i++){
            lista[i] = lista[i + 1];
        }
    }else{
        printf("\n\t|  Elemento nao encontrado!                |\n");
    }
}

int * ordenarListaDecrescente(int * lista, int tam_lista){
    int lista_aux[10];
    int inicio_lista=0;
    int tam_lista_aux=tam_lista;
    int cont =1;

    copiarListaEmTecho(lista,tam_lista_aux,lista_aux,0);

    while (inicio_lista < tam_lista_aux){

        moverElementoParaInicio(lista_aux, tam_lista_aux ,selecioneIndiceMaiorElemento(lista_aux,tam_lista_aux));
        moverElementoParaFinal(lista_aux, tam_lista_aux, selecioneIndiceMenorElemento(lista_aux,tam_lista_aux));
 
        copiarListaEmTecho(lista_aux,tam_lista_aux,lista,inicio_lista);

        deletarElemento(lista_aux,tam_lista_aux,tam_lista_aux);
        tam_lista_aux--;
        deletarElemento(lista_aux,tam_lista_aux,0);
        tam_lista_aux--;
        inicio_lista++;
        
    }

}

void printarMenu(){
    printf("\n\t*** MENU DE BATALHA ***\n");
    printf("\n\t======================================");
    printf("\n\t|1. Imprimir Vetor;                |\n");
    printf("\t|2. Remover Elemento Do Vetor;       |\n");
    printf("\t|3. Sair;                            |\n");
    printf("\t======================================");
    printf("\n\tDigite uma das opcoes acima: ");
}

void menu(int * lista, int tam_lista){
    int opcao=0;
    int tam = tam_lista;
    while(opcao != 3){
        printarMenu();
        scanf("%d",&opcao);
        ordenarListaDecrescente(lista,tam);

        if (opcao == 1){
            printarLista(lista, tam);
        }else if( opcao == 2){
            int elemento=-1;
            printf("\n\t|  Informe o elemento que deseja excluir:   ");
            scanf("%d",&elemento);
            int indice_elemento = selecioneIndiceElemento(lista,tam,elemento);
            deletarElemento(lista,tam,indice_elemento);
            if(indice_elemento != -1){
                tam--;
            }
            
        }else if( opcao == 3 ){
            exit(0);
        }else{
            printf("\n\t|  Opcao invalida, tente novamente:       |\n");
        }
    }

}

int main() {
    int v[10] = {0,1,2,3,4,5,6,7,8,9};
    int tam_lista=10;

    menu(v,tam_lista);

}