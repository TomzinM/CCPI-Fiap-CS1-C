#include <stdio.h>
#include <string.h>
#include <time.h>

void interface(char name[], char cpfs[], char response){
    printf("------------------------------------------\n");
    printf("Bem vindo, %s", name);

    // Aviso para registrar antes de pagar
    if (strcmp(name, "???") == 0 || strcmp(cpfs, "???") == 0){
        printf("\nRegistre sua informacao antes de recarga!\n");
    }
    if (strcmp(cpfs, "???") != 0){
        printf("CPF da compra atual: %s", cpfs);
    }
    if (response == 'Y' || response == 'y'){
        printf("\nCompra feita, aperte 3 para fechar interface, e aguarde recarga completa.\n");
    }
    else {
        printf("\nEscolha o numero relacionado com as opcoes a seguir para continuar.\n");
    }
    printf("------------------------------------------\n");
    
}

void purchaseLog(float price, char nome[]){
    
    time_t rawtime = time(NULL);
    
    struct tm *timeinfo = localtime(&rawtime);

    int year = timeinfo->tm_year + 1900;
    int month = timeinfo->tm_mon;
    int day = timeinfo->tm_mday;
    int hour = timeinfo->tm_hour;   
    int min = timeinfo->tm_min;     
    int sec = timeinfo->tm_sec;     

    FILE *fptr;

    fptr = fopen("log.txt", "w");

    fprintf(fptr, "\nCompra de R$%.2f feita por %sCompra feita em %d/%d/%d. Horario: %d:%d:%d\n", price, nome, day, month, year, hour, min, sec);
    fclose(fptr);

}


char recharge(char name[], char cpfs[], char response){
        
        response = 'N';
        int ch;
        int energia;
        char carro;

                // Saindo do switch se não esta registrado
            if (strcmp(name, "???") == 0|| strcmp(cpfs, "???") == 0){
                printf("\nPor favor, registre sua informacao primeiro.\n");
                return 'N';
            }
                // Saindo do switch se ja foi pago
            if (response == 'Y' || response == 'y'){
                printf("\nA recarga ja foi paga!\n");
                return 'Y';
            }

            printf("Que tipo de carro voce tem?\nG (grande)\nM (medio)\nP (pequeno)\n");
            scanf("%c", &carro);

            while ((ch = getchar()) != '\n' && ch != EOF);

            printf("Qual a porcentagem de energia que seu carro tem no momento?: ");
            scanf("%d", &energia);

            while ((ch = getchar()) != '\n' && ch != EOF);

            // Porcentagems tem que ser dentro de 0 e 100
            if (energia < 0 || energia > 100){
                printf("Energia nao e valida.\n");
                return 'N';
            }

            float kiloWattHora;

            if (carro == 'G' || 'g'){
                kiloWattHora = 1.3 * (100 - energia);
            } 
            else if (carro == 'M' || 'm'){
                kiloWattHora = 0.6 * (100 - energia);
            } 
            else if (carro == 'P' || 'p'){
                kiloWattHora = 0.4 * (100 - energia);
            }
            else { 
                printf("O tipo de carro escolhido nao esta dentro das opcoes dadas.\n");
                return 'N';
            }

            float preco = 1.5 * kiloWattHora; 
            float tempo = 0.5 * kiloWattHora;
            

            printf("Para uma recarga completa, demorara %.2f minutos e custara R$%.2f.\n", tempo, preco);
            printf("Quer prosseguir com pagamento? (Y/N) ");
            scanf("%c", &response);

            purchaseLog(preco, name);
            if (response == 'Y' || response == 'y'){
                printf("\nPagamento de R$%.2f processado.\n", preco);
            }
        return response;
}


int main(){

    int processoCarregador = 1;
    int opcao;
    char nome[100] = "???";
    char cpf[12] = "???";
    char resposta = 'N';
    int ch;
    char nome2[100];

    while (processoCarregador == 1){ 


        interface(nome, cpf, resposta);

        printf("1 - Registro de informacao\n2 - Recarga\n3 - Finalizacao de programa\n");
        scanf("%d", &opcao);

        // Toda vez que isso aparece é pra tirar o buffer ja que eu não sei como faz isso alem de não usar scanf mas eu tambem nao sei como usar fgets pra integer
        while ((ch = getchar()) != '\n' && ch != EOF);

        switch(opcao){
        case 1: 
            // Lendo o Nome
            printf("Qual seu nome completo? \n");
            fgets(nome, sizeof(nome), stdin);

            printf("Escreva o seu nome novamente para confirmar.\n");
            fgets(nome2, sizeof(nome2), stdin);

            if (strcmp(nome, nome2) != 0){
                printf("Nome invalido, nao e igual ao primeiro digitado.\n");
                strcpy(nome, "???");
                strcpy(cpf, "???");
                break;
            } 

            // Lendo o CPF
            printf("Qual seu CPF? \n");
            fgets(cpf, sizeof(cpf), stdin);
            if (strlen(cpf) != 11){
                printf("CPF Invalido, numero de digitos incorreto.\n");
                strcpy(nome, "???");
                strcpy(cpf, "???");
                break;
            }

            printf("Sua informacao agora esta registrada!\n");      
            break;
        case 2:
            resposta = recharge(nome, cpf, resposta); 
            break;

        case 3:
            printf("Obrigado por visitar o carregador GoodWe!");
            processoCarregador = 0;
            break;
        }        
    }
    return 0;
}