#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


typedef struct ListaTelefonica {
    char nome[32];
    char endereco[45];
    char telefone[14];
    char email[32];

}ListaTelefonica;

ListaTelefonica novoContato(ListaTelefonica cts){
    printf("Digite os respectivos dados: \n");

    printf(" * nome:\n");
    scanf(" %[^\n]s",  cts.nome);

    printf(" * endereço:\n");
    scanf(" %[^\n]s", cts.endereco);

    printf(" * Telefone:\n");
    scanf(" %[^\n]s", cts.telefone);

    printf(" * email: \n");
    scanf(" %[^\n]s",  cts.email);

    return cts;
    }

ListaTelefonica  * ordenarLista(ListaTelefonica* cts, int n){
    int j = 1;
    ListaTelefonica c;
    while (j != 0){
            j = 0;

            for (int i = 0; i <n; i++){
                int comp = strcmp(cts[i].nome, cts[i+1].nome);
            
                if (comp > 0){

                   
                    c = cts[i];
                    cts[i] = cts[i+1];
                    cts[i+1] = c;
                    j = 1;
                }
        }

    }
    return cts;
}

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

Data novaData(Data dt ){
    printf("Digite:\n");
    printf(" > Ano: \n");
    scanf(" %d",  &dt.ano);

    do{
        printf(" > Mes: \n");
        scanf(" %d",  &dt.mes);
    }while(dt.mes>12);

    do{
        printf(" > Dia: \n");
        scanf(" %d",  &dt.dia);
    }while(dt.dia>31);
    return dt;
}

Data diffD(Data dtx, Data dty){
    Data dtdiff;
     dtdiff.dia=  dtx.dia-dty.dia;
    if (dtdiff.dia < 0){
        dtdiff.dia = dtdiff.dia *(-1);
    }

    dtdiff.mes = dtx.mes-dty.mes;
    if (dtdiff.mes< 0){
        dtdiff.mes = dtdiff.mes *(-1);
    }

    dtdiff.ano = dtx.ano -dty.ano;
    if ( dtdiff.ano< 0){
            dtdiff.ano = dtdiff.ano *(-1);
    }
    return dtdiff;
}

typedef struct{
    Data dt_inicio;
    Data dt_fim;
    ListaTelefonica  participantes[10];
    int num_part;
    char nome[20];
    char desc[60];
}Evento;

int main()
{
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    int ncts=1,nevts=1, op = 0, contCts = 0, contEvt = 0;
    ListaTelefonica *listaCts, *aux, temp;
    Evento *listaEvt, *aux2;

    listaCts = (ListaTelefonica*)malloc(ncts*sizeof(ListaTelefonica));
    listaEvt = (Evento*)malloc(nevts*sizeof(Evento));

while(op != 6){
        printf("Selecione uma opcao:\n");
        printf("1. Vizualizar compromissos.\n");
        printf("2. Criar eventos. \n");
        printf("3. Adicionar contatos. \n");
        printf("4. Remover contatos. \n");
        printf("5. Ver lista de contatos \n");
        printf("6. Sair\n");
        scanf("%d", &op);

         switch(op){
       switch (op) {
        case 1: {
            Data dt;
            dt.ano = local_time->tm_year + 1900;
            dt.dia = local_time->tm_mday;
            dt.mes = local_time->tm_mon + 1;

            printf("\n\n----- Futuros Eventos -----\n\n");
            for (int i = 0; i < contEvt; i++) {
                printf(" T\u00edtulo: %s\n", listaEvt[i].nome);
                printf("  Descricao: %s\n", listaEvt[i].desc);
                printf("  Data de inicio: %d/%d/%d \n", listaEvt[i].dt_inicio.dia, listaEvt[i].dt_inicio.mes, listaEvt[i].dt_inicio.ano);
                printf("  Data de encerramento: %d/%d/%d \n", listaEvt[i].dt_fim.dia, listaEvt[i].dt_fim.mes, listaEvt[i].dt_fim.ano);
                Data duracao = diffD(listaEvt[i].dt_inicio, listaEvt[i].dt_fim);
                printf("  Dura\u00e7\u00e3o: %d dias, %d meses e %d anos\n\n", duracao.dia, duracao.mes, duracao.ano);
                printf(" Participantes: \n");
                for (int j = 0; j < listaEvt[i].num_part; j++) {
                    printf("  Nome: %s\n", listaEvt[i].participantes[j].nome);
                    printf(" Email: %s\n", listaEvt[i].participantes[j].email);
                    printf(" Telefone: %s\n", listaEvt[i].participantes[j].telefone);
                    printf(" Endereco: %s\n\n", listaEvt[i].participantes[j].endereco);
                }
            }
            system("PAUSE");
            retornarMenu();
            break;
        }
        case 2:
            printf("\n\n|----- Criar novo evento -----\ \n\n");
            int contPart = 0;
            while(op !=0){
                if(contEvt>nevts){
                    int n = nevts*2;
                    aux2 = realloc(listaEvt, sizeof(*aux2) * n);
                    if (aux2 != 0)
                    {
                        listaEvt = aux2;
                        nevts = n;
                    }
                }

                printf(" Nome: ");
                scanf(" %[^\n]s", listaEvt[contEvt].nome);
                printf(" Descricao: ");
                scanf(" %[^\n]s", listaEvt[contEvt].desc);
                printf("Data de inicio: \n");
                listaEvt[contEvt].dt_inicio = novaData(listaEvt[contEvt].dt_inicio);
                printf("Data de fim:\n");
                listaEvt[contEvt].dt_fim = novaData(listaEvt[contEvt].dt_fim);

                if(contCts != 0 && contCts != contPart){
                    printf("Deseja adicionar participantes?\n0.Nao \n1.Sim\n");
                    scanf("%d", &op);
                    while(op == 1){
                        for(int i = 0; i<contCts; i++){
                            printf(" %d. Nome: %s\n", i,listaCts[i].nome);
                            printf(" Email: %s\n", listaCts[i].email);
                            printf(" Telefone: %s\n", listaCts[i].telefone);
                            printf(" Endereco: %s\n\n", listaCts[i].endereco);
                        }
                        printf("Escolha o participante que deseja adicionar. \n");
                        scanf("%d", &op);
                        if(contPart==0){
                            listaEvt[contEvt].participantes[contPart] = listaCts[op];
                            contPart++;
                        }
                        else{
                            for(int i = 0; i< contPart; i++){
                                int check = 0;
                                if(listaEvt[contEvt].participantes[contPart].nome == listaEvt[contEvt].participantes[i].nome){
                                        printf("Esse contato já foi adcionado!\n\n");
                                        check =1;
                                        break;
                                }
                            }
                    }
                        listaEvt[contEvt].participantes[contPart] = listaCts[op];
                        contPart++;
                        printf("Deseja adicionar mais participantes?\n0.Nao \n1.Sim\n");
                        scanf("%d", &op);
            }
            }
                    listaEvt[contEvt].num_part = contPart;
                    contEvt++;
                    printf("Deseja adicionar outro Evento? \n0.Nao \n1.Sim\n");
                    scanf("%d", &op);
            }

            system("PAUSE");
            printf("\nRetornando ao menu");
            for(int i = 0; i<3; i++){
                Sleep(300);
                printf(".");
            }
            system("cls");
            break;
        case 3:
            printf("\n\n|----- Adicionar contatos -----\ \n\n");
            while(op !=0){
                if(contCts>=ncts){
                    int n = ncts*2;
                    aux = realloc(listaCts, sizeof(*aux) * n);
                    if (aux != 0)
                    {
                        listaCts = aux;
                        ncts = n;
                    }
                }
                listaCts[contCts] = novoContato(listaCts[contCts]);
                contCts++;
                printf("Deseja adicionar outro contato? \n0.Nao \n1.Sim\n");
                scanf("%d", &op);
            }
            listaCts =ordenarLista(listaCts, contCts-1);
            system("PAUSE");
            printf("Retornando ao menu");
            for(int i = 0; i<3; i++){
                Sleep(300);
                printf(".");
            }
            system("cls");
            break;
        case 4:
            while(op!=0){
            printf("\n\n----- Remover contatos -----\n\n");
            for(int i = 0; i<contCts; i++){
                printf(" %d. Nome: %s\n", i,listaCts[i].nome);
                printf(" Email: %s\n", listaCts[i].email);
                printf(" Telefone: %s\n", listaCts[i].telefone);
                printf(" Endereco: %s\n\n", listaCts[i].endereco);
            }
            printf("Qual contato deseja remover? \n");
            scanf("%d", &op);

            temp = listaCts[op];
            listaCts[op] = listaCts[contCts-1];
            listaCts[contCts-1] = temp;

            contCts--;
            printf("Deseja remover outro contato? \n0.Nao \n1.Sim\n");
            scanf("%d", &op);
        }
            system("cls");
            for(int i = 0; i<contCts; i++){
                printf(" %d. Nome: %s\n", i,listaCts[i].nome);
                printf(" Email: %s\n", listaCts[i].email);
                printf(" Telefone: %s\n", listaCts[i].telefone);
                printf(" Endereco: %s\n\n", listaCts[i].endereco);
            }
            system("PAUSE");
            printf("Retornando ao menu");
            for(int i = 0; i<3; i++){
                Sleep(300);
                printf(".");
            }
            system("cls");
            break;
        case 5:
            printf("\n\n|----- Lista de Contatos -----\ \n\n");

            for(int i = 0; i<contCts; i++){
                printf(" Nome: %s\n", listaCts[i].nome);
                printf(" Email: %s\n", listaCts[i].email);
                printf(" Telefone: %s\n", listaCts[i].telefone);
                printf(" Endereco: %s\n\n", listaCts[i].endereco);
            }
            system("PAUSE");
            printf("Retornando ao menu");
            for(int i = 0; i<3; i++){
                Sleep(300);
                printf(".");
            }
            system("cls");
            break;
        case 6:
            printf("Saindo");
            for(int i = 0; i<3; i++){
                Sleep(300);
                printf(".");
            }
            free(listaCts);
            free(listaEvt);
            free(local_time);
            return 0;
        }
}
            free(listaCts);
            free(listaEvt);
            free(local_time);
        printf("Saindo");
            for(int i = 0; i<3; i++){
                Sleep(300);
                printf(".");
            }
        return 0;
    }
}