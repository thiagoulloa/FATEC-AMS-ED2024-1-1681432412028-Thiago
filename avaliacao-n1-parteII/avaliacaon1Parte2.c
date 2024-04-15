#include <stdio.h>
#include <string.h>


typedef struct {
    int ID;
    char cidadeOr[50];
    char cidadeDes[50];
    int status;
    char conteudo[100];
} Pacote;

Pacote pacotes[100];
int numPacotes = 0; 
int ultimoID = 0;


void Incluir() {
    if(numPacotes >= 100) {
        printf("❌ Não é possível adicionar mais pacotes.\n");
        return;
    }
    Pacote *pacote = &pacotes[numPacotes++];
    printf("📦 Insira a cidade de origem do pacote: ");
    scanf("%s", pacote->cidadeOr);
    printf("🚀 Insira a cidade de destino do pacote: ");
    scanf("%s", pacote->cidadeDes);
    printf("📝 Insira o conteúdo do pacote: ");
    scanf(" %[^\n]", pacote->conteudo); 
    pacote->ID = ultimoID += 2; 
    pacote->status = 1;
    printf("\n"); 
}


void Alterar() {
    int id, valor;
    printf("🔎 Digite o ID do pacote que deseja alterar: ");
    scanf("%d", &id);
    int encontrado = 0;
    for(int i = 0; i < numPacotes; i++) {
        if(pacotes[i].ID == id) {
            printf("🔄 Digite o novo status do pacote (valores de 1, 2 ,3 ,4 ou 99): ");
            scanf("%d", &valor);
            pacotes[i].status = valor; 
            printf("\n");
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) {
        printf("❌ Pacote não encontrado.\n");
    }
}

void ListarTodos() {
    printf("📋 Listando todos os pacotes:\n");
    for(int i = 0; i < numPacotes; i++) {
        Pacote *pacote = &pacotes[i];
        printf("📦 ID: %d\n", pacote->ID);
        printf("🚀 cidadeOr: %s\n", pacote->cidadeOr);
        printf("📍 cidadeDes: %s\n", pacote->cidadeDes);
        printf("🔄 status: %d\n", pacote->status);
        printf("📝 conteudo: %s\n", pacote->conteudo);
        printf("\n"); 
    }
}

void Rastrear() {
    int opcao;
    printf("🔍 O que deseja fazer?\n");
    printf("1️⃣ = Consultar pacote\n");
    printf("2️⃣ = Listar todos pacotes\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); 
    switch(opcao) {
        case 1: {
            int ID;
            printf("🔎 Digite o ID do pacote que deseja consultar: ");
            scanf("%d", &ID);
            int encontrado = 0;
            for(int i = 0; i < numPacotes; i++) {
                if(pacotes[i].ID == ID) {
                    Pacote *pacote = &pacotes[i];
                    printf("📦 ID: %d\n", pacote->ID);
                    printf("🚀 cidadeOr: %s\n", pacote->cidadeOr);
                    printf("📍 cidadeDes: %s\n", pacote->cidadeDes);
                    printf("🔄 status: %d\n", pacote->status);
                    printf("📝 conteudo: %s\n", pacote->conteudo);
                    printf("\n"); 
                    encontrado = 1;
                    break;
                }
            }
            if(!encontrado) {
                printf("❌ Pacote não encontrado.\n");
            }
            break;
        }
        case 2:
            ListarTodos();
            break;
        default:
            printf("❌ Opção inválida.\n");
    }
}

int main() {
    while(1) {
        int opcao;
        printf("📦 1. Incluir pacote\n");
        printf("🔄 2. Alterar status do pacote\n");
        printf("🔍 3. Rastrear pacote\n");
        printf("🚪 4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 
        switch(opcao) {
            case 1:
                Incluir();
                break;
            case 2:
                Alterar();
                break;
            case 3:
                Rastrear();
                break;
            case 4:
                return 0;
            default:
                printf("❌ Opção inválida.\n");
        }
    }
}