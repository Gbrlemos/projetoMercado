#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

typedef struct {
	int codigo, quantidade;
	char produto[20];
	float preco;
}produto;

produto produtos[5];

void cadastro();
void apresentarproduto();
void vender();
void renovar();


int *codigoProduto;
int *quant;
float *total;

int main(){
	
	codigoProduto = (int*) malloc (sizeof(int));
	quant = (int*) malloc (sizeof(int));	
	total = (float*) malloc (sizeof(float));
	
	int op=1;
	while(op!=0){
	printf("CONTROLE DE PRODUTOS\n\n\n\n");
	printf("O QUE TU QUER FAZER?\n1 - Cadastrar item\n2 - Buscar item\n3 - Vender\n4 - Renovar estoque\n0 - Sair\n");
	scanf("%d", &op);
	system("cls");
	switch(op){
		case 1 : 
			cadastro();
		break;
		
		case 2 : 
			apresentarproduto();
		break;
		
		case 3 : 
			vender();
			printf("Seu total foi: R$%.2f \nObrigado pela preferencia.", *total);
			system("pause");
			system("cls");
			free(total);
		break;
		
		case 4 :
			renovar();
	}
	}
	
	printf("\nAte a proxima!! =D");
	
}


void cadastro(){
	printf("\nQuandos produtos ira cadastrar: ");
	scanf("%d", quant);
	for(int c=0; c<*quant; c++){
	printf("Digite o codigo do produto: ");
	scanf("%d", &produtos[c].codigo);
	printf("Digite o nome do produto: ");
	scanf(" %s", &produtos[c].produto);
	printf("Digite o valor do produto: ");
	scanf("%f", &produtos[c].preco);
	printf("Digite a quantidade do produto: ");
	scanf("%d", &produtos[c].quantidade);
	system("cls");
	}
}

void apresentarproduto(){
	printf("\nDigite o codigo do produto que voce deseja visualizar: ");
	scanf("%d", codigoProduto);
	system("cls");
	for(int c=0; c<*quant; c++){
		if(*codigoProduto==produtos[c].codigo){
			*codigoProduto=c;
		printf("\n\nCodigo do produto: %d\nNome do Produto: %s\nPreco do produto: %.2f\nQuantidade do produto: %d\n", produtos[*codigoProduto].codigo, produtos[*codigoProduto].produto, produtos[*codigoProduto].preco, produtos[*codigoProduto].quantidade);
		system("pause");
		system("cls");
		} else if(c == *quant-1) {
			printf("\n\nProduto nao existe\n\n");
			system("pause");
		}

	}

}


void vender(){
	int manterPrograma=1;
	float x;
	
	while(manterPrograma!=0){

	printf("Digite o codigo do produto: ");
	scanf("%d", codigoProduto);
	printf("Digite a quantidade do produto: ");
	scanf("%f", &x);
	for(int c=0; c<*quant; c++){
		if(*codigoProduto==produtos[c].codigo){
			*codigoProduto=c;
			if(produtos[*codigoProduto].quantidade >= x){
			*total = *total + (produtos[*codigoProduto].preco * x);
			produtos[*codigoProduto].quantidade = produtos[*codigoProduto].quantidade - x;
			printf("Total ate o momento: R$%.2f", *total);
		} else {
		printf("Nao temos essa quantidade no estoque\nQuantidade atual no estoque: %d\n", produtos[*codigoProduto].quantidade);
	}
	printf("\nDeseja comprar algo mais?\n1 - Sim\n0 - Nao\n");
	scanf("%d", &manterPrograma);
	system("cls");
	}
	}
	
	
	}
	system("cls");
	
}

void renovar(){
	
}
