#include <stdio.h>
#include <string.h>
#define MAX 200

typedef struct{
	int cmd;
	int pr1;
	int pr2;
} Estrutura;
Estrutura CI[MAX];
typedef struct{
	char *nome;
	int valor;
} estrutura;
estrutura VAR[MAX];
int PC, REG[MAX], lenvar;
FILE *pont;
char *token;

loadCI(){
    int i=1;
    PC=1;
	char *arq;
	printf("digite o nome do arquivo a ser carregado\n");
	gs: gets(arq);
	pont=fopen(arq, "r");
	
	if (pont==NULL){
	    printf("ERRO, arquivo nao encontrado, digite de novo\n");
	    goto gs;
	}
	
	token=strtok(arq, ":");
	if (strcmp(token, "NAT")==0){
		while (token!=NULL){ //fazer o loop parar quando atingir a quebra de linha/loop so para a carga de variaveis
			token=strtok(NULL, " ,");
			VAR[i].nome=token;
			i++;
		}
		lenvar=i;
		token=strtok(NULL, " \n");
	}
}
runCI(){
	int x, i;
	PC=1;
	printf("digite o valor das variaveis na ordem em que foram declaradas:");
	for (i=1; i<=lenvar; VAR[i++].valor=x) scanf ("%d", &x);
	while (CI[PC].cmd!=0){
		if (CI[PC].cmd==1) //reset
		    VAR[CI[PC].pr1].valor=0;
		if (CI[PC].cmd==2) //inc
		    VAR[CI[PC].pr1].valor++;
		if (CI[PC].cmd==3) //cpyr
		    REG[CI[PC].pr1]=VAR[CI[PC].pr2].valor;
		if (CI[PC].cmd==4) //jmpz
		    if (REG[CI[PC].pr1]==0)
		        PC=CI[PC].pr2;
		if (CI[PC].cmd==5) //dec
		    
		if (CI[PC].cmd==6) //jmp
		    
		PC++;
	}
	printf("run concluido\n");
}
helpshell(){
   printf("Digite um dos comandos:\n\n");
   printf(" load     solicita o nome de um arquivo contendo um programa MH e carrega para execucao.\n");
   printf(" run      executa um programa previamente carregado.\n");
   printf(" input    solicita os valores iniciais das variaveis do programa MH carregado.\n");
   printf(" dspvar   exibe o conteudo das variaveis do programa carregado.\n");
   printf(" dspmh    exibe o codigo fonte MH carregado.\n");
   printf(" dspci    exibe o codigo intermediario gerado a partir do fonte MH carregado.\n");
   printf(" exit     termina o MHshell.\n");
   printf(" ?        exibe este help... :)\n");
}
prompt(){
	printf(">>> ");
}
getprompt(){
	char strcmd[20];
	gets(strcmd);
	if (strcmp(strcmd, "exit")==0)
	    return 0;
	if (strcmp(strcmd, "load")==0)
	    return 1;
	if (strcmp(strcmd, "run")==0)
	    return 3;
	if (strcmp(strcmd, "helpshell")==0)
	    return 10;
}
void shell(){
	int cmdprompt=1;
	while(cmdprompt){
		prompt();
		cmdprompt=getprompt();
		switch(cmdprompt){
			case 0: //exit
                printf("fechando Shell\n");
				break;
			case 1: //load
				loadCI();
				break;
			case 2: //input de variaveis
				
				break;
			case 3: //run
			    runCI();
			    break;
			case 10: //helpshell
				helpshell();
				break;
		}
	}
}
void header(){
	printf("MH Shell V1.0\n");
}
int main(){
	header();
	shell();
}
