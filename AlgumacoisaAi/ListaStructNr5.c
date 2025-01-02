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
} ListaTelefonica;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data dt_inicio;
    Data dt_fim;
    ListaTelefonica participantes[10];
    int num_part;
    char nome[20];
    char desc[60];
} Evento;

ListaTelefonica novoContato() {
    ListaTelefonica contato;

    printf("Nome: ");
    fflush(stdin);
    fgets(contato.nome, 32, stdin);
    contato.nome[strcspn(contato.nome, "\n")] = '\0';

    printf("Endereco: ");
    fflush(stdin);
    fgets(contato.endereco, 45, stdin);
    contato.endereco[strcspn(contato.endereco, "\n")] = '\0';

    printf("Telefone: ");
    fflush(stdin);
    fgets(contato.telefone, 14, stdin);
    contato.telefone[strcspn(contato.telefone, "\n")] = '\0';

    printf("Email: ");
    fflush(stdin);
    fgets(contato.email, 32, stdin);
    contato.email[strcspn(contato.email, "\n")] = '\0';

    return contato;
}

Data novaData() {
    Data data;

    printf("Dia: ");
    scanf("%d", &data.dia);
    printf("Mes: ");
    scanf("%d", &data.mes);
    printf("Ano: ");
    scanf("%d", &data.ano);

    return data;
}

Data diffD(Data inicio, Data fim) {
    Data duracao = {0, 0, 0};

    if (fim.dia < inicio.dia) {
        fim.dia += 30;
        fim.mes -= 1;
    }
    duracao.dia = fim.dia - inicio.dia;

    if (fim.mes < inicio.mes) {
        fim.mes += 12;
        fim.ano -= 1;
    }
    duracao.mes = fim.mes - inicio.mes;

    duracao.ano = fim.ano - inicio.ano;

    return duracao;
}


int main() {
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    int ncts = 1, nevts = 1, op = 0, contCts = 0, contEvt = 0;
    ListaTelefonica *listaCts, *aux;
    Evento *listaEvt, *aux2;

    listaCts = (ListaTelefonica *)malloc(ncts * sizeof(ListaTelefonica));
    listaEvt = (Evento *)malloc(nevts * sizeof(Evento));

    while (op != 6) {
        printf("Selecione uma opcao:\n");
        printf("1. Visualizar compromissos.\n");
        printf("2. Criar eventos. \n");
        printf("3. Adicionar contatos. \n");
        printf("4. Remover contatos. \n");
        printf("5. Ver lista de contatos \n");
        printf("6. Sair\n");
        scanf("%d", &op);

        switch (op) {
        case 1: {
            Data dt;
            dt.ano = local_time->tm_year + 1900;
            dt.dia = local_time->tm_mday;
            dt.mes = local_time->tm_mon + 1;

            printf("\n\n----- Futuros Eventos -----\n\n");
            for (int i = 0; i < contEvt; i++) {
                printf("Titulo: %s\n", listaEvt[i].nome);
                printf("Descricao: %s\n", listaEvt[i].desc);
                printf("Data de inicio: %02d/%02d/%04d\n",
                       listaEvt[i].dt_inicio.dia,
                       listaEvt[i].dt_inicio.mes,
                       listaEvt[i].dt_inicio.ano);
                printf("Data de encerramento: %02d/%02d/%04d\n",
                       listaEvt[i].dt_fim.dia,
                       listaEvt[i].dt_fim.mes,
                       listaEvt[i].dt_fim.ano);

                Data duracao = diffD(listaEvt[i].dt_inicio, listaEvt[i].dt_fim);
                printf("Duracao: %d dias, %d meses e %d anos\n\n",
                       duracao.dia, duracao.mes, duracao.ano);

                printf("Participantes:\n");
                for (int j = 0; j < listaEvt[i].num_part; j++) {
                    printf("  Nome: %s\n", listaEvt[i].participantes[j].nome);
                    printf("  Email: %s\n", listaEvt[i].participantes[j].email);
                    printf("  Telefone: %s\n", listaEvt[i].participantes[j].telefone);
                    printf("  Endereco: %s\n\n", listaEvt[i].participantes[j].endereco);
                }
            }

            system("PAUSE");
            printf("Retornando ao menu");
            for (int i = 0; i < 3; i++) {
                Sleep(300);
                printf(".");
            }
            system("cls");
            break;
        }

       case 2: { // Criar eventos
    if (contEvt == nevts) {
        nevts *= 2;
        aux2 = (Evento *)realloc(listaEvt, nevts * sizeof(Evento));
        if (aux2 == NULL) {
            printf("Erro ao alocar memoria para novos eventos.\n");
            exit(1);
        }
        listaEvt = aux2;
    }

    printf("Insira o nome do evento: ");
    fflush(stdin);
    fgets(listaEvt[contEvt].nome, 20, stdin);
    listaEvt[contEvt].nome[strcspn(listaEvt[contEvt].nome, "\n")] = '\0';

    printf("Insira a descricao do evento: ");
    fflush(stdin);
    fgets(listaEvt[contEvt].desc, 60, stdin);
    listaEvt[contEvt].desc[strcspn(listaEvt[contEvt].desc, "\n")] = '\0';

    printf("Insira a data de inicio do evento.\n");
    listaEvt[contEvt].dt_inicio = novaData();

    printf("Insira a data de encerramento do evento.\n");
    listaEvt[contEvt].dt_fim = novaData();

    listaEvt[contEvt].num_part = 0;
    char continuar;

    printf("Deseja adicionar participantes? (s/n): ");
    scanf(" %c", &continuar);

    while (continuar == 's' && listaEvt[contEvt].num_part < 10) {
        printf("Adicionando participante %d:\n", listaEvt[contEvt].num_part + 1);
        listaEvt[contEvt].participantes[listaEvt[contEvt].num_part] = novoContato();
        listaEvt[contEvt].num_part++;

        if (listaEvt[contEvt].num_part < 10) {
            printf("Deseja adicionar outro participante? (s/n): ");
            scanf(" %c", &continuar);
        } else {
            printf("Limite de participantes atingido!\n");
        }
    }

    printf("Evento criado com sucesso!\n");
    system("PAUSE");
    system("cls");
    contEvt++;
    break;
}


        case 3: {
            if (contCts == ncts) {
                ncts *= 2;
                aux = (ListaTelefonica *)realloc(listaCts, ncts * sizeof(ListaTelefonica));
                if (aux == NULL) {
                    printf("Erro ao alocar memoria para novos contatos.\n");
                    exit(1);
                }
                listaCts = aux;
            }

            printf("Insira os dados do novo contato:\n");
            listaCts[contCts] = novoContato();
            contCts++;
            printf("Contato adicionado com sucesso!\n");
            system("PAUSE");
            system("cls");
            break;
        }

        case 4: {
            char nomeRemover[32];
            printf("Digite o nome do contato que deseja remover: ");
            fflush(stdin);
            fgets(nomeRemover, 32, stdin);
            nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

            int encontrado = -1;
            for (int i = 0; i < contCts; i++) {
                if (strcmp(listaCts[i].nome, nomeRemover) == 0) {
                    encontrado = i;
                    break;
                }
            }

            if (encontrado != -1) {
                for (int i = encontrado; i < contCts - 1; i++) {
                    listaCts[i] = listaCts[i + 1];
                }
                contCts--;
                printf("Contato removido com sucesso!\n");
            } else {
                printf("Contato nao encontrado.\n");
            }

            system("PAUSE");
            system("cls");
            break;
        }

        case 5: {
            printf("----- Lista de Contatos -----\n\n");
            for (int i = 0; i < contCts; i++) {
                printf("Nome: %s\n", listaCts[i].nome);
                printf("Email: %s\n", listaCts[i].email);
                printf("Telefone: %s\n", listaCts[i].telefone);
                printf("Endereco: %s\n\n", listaCts[i].endereco);
            }
            system("PAUSE");
            system("cls");
            break;
        }

        case 6: {
            printf("Saindo do programa...\n");
            Sleep(1000);
            break;
        }

        default:
            printf("Opcao invalida. Tente novamente.\n");
            system("PAUSE");
            system("cls");
        }
    }

    free(listaCts);
    free(listaEvt);

    return 0;
}
