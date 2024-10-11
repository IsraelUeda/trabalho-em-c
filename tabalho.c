#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

//Função pra desenhar as extremidades do menu.
void desenhaLinha(int largura) {


    for (int i = 0; i < largura; i++) {
        printf("-");

    }
    printf("\n");
}

//função de login
void telalogin() {
    char usuario [30];
    char senha [30];
    char usuarioArquivo [30];
    char senhaArquivo[30];
    int encontrado = 0;

    desenhaLinha(30);
    wprintf(L"              LOGIN              \n");
    desenhaLinha(30);

    wprintf(L"Usuário: ");
    scanf("%s", usuario);

    printf("Senha: ");
    scanf("%s", senha);

//abre o arquivo 
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        wprintf(L"Erro ao abrir o arquivo de usuários.\n");
        return;
    }

//Faz uma leitura linha a linha do arquivo usuarios.txt, comparando as credenciais fornecidas pelo usuário (usuário e senha) com as credenciais armazenadas no arquivo.
    while(fscanf(arquivo, "%s %s", usuarioArquivo, senhaArquivo) != EOF){
        if(strcmp(usuario, usuarioArquivo) == 0 && strcmp(senha, senhaArquivo) == 0){
            encontrado = 1;
            break;
        } 
    }
    fclose(arquivo);

//se o usuario estiver no sistema
    if (encontrado) {
        printf("\nLogin bem-sucedido!\n");
        desenhaLinha(30);
        wprintf(L"PARABÉNS VOCÊ ACESSOU O SISTEMA!\n");
        desenhaLinha(30);
        exit(0);
    }else { //se a senha não bater
        wprintf(L"\nUsuário ou senha incorretos.\n");

    }
}

// função de cadastrar novo usuario
void cadastrarUsuario() {
    char novoUsuario[30];
    char novaSenha[30];

    desenhaLinha(30);
    wprintf(L"           CADASTRAR USUÁRIO          \n");
    desenhaLinha(30);

    wprintf(L"Novo Usuário: ");
    scanf("%s", novoUsuario);

    printf("Nova senha: ");
    scanf("%s", novaSenha);
    
    FILE *arquivo = fopen("usuarios.txt", "a");
    if (arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO DE USUÁRIOS.\n");
        return;
    }
//salva no arquivo o nome e senha
   fprintf(arquivo, "%s %s\n", novoUsuario, novaSenha);
   fclose(arquivo);
    wprintf(L"\nUsuário cadastrado com sucesso!\n");
}

//função para o usuario alterar a senha
void alterarSenha(){
    char usuario[30];
    char senhaAtual[30];
    char novaSenha[30];
    char usuarioArquivo[30];
    char senhaArquivo[30];
    int encontrado = 0;

    desenhaLinha(30);
    printf("       ALTERAR SENHA       \n");
    desenhaLinha(30);

    wprintf(L" Insira o usuário: \n");
    scanf("%s", usuario);

    FILE *arquivo = fopen("usuarios.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        wprintf(L"Erro ao abrir o arquivo de usuários.\n");
        return; 
    }

    while (fscanf(arquivo, " %s %s", usuarioArquivo, senhaArquivo) != EOF){
    if (strcmp(usuario, usuarioArquivo) == 0) {
        encontrado = 1;
        wprintf(L"Senha atual: ");
        scanf("%s", senhaAtual);
            if (strcmp(senhaAtual, senhaArquivo) == 0) {
            wprintf(L"Nova senha: ");
            scanf("%s", novaSenha);
            fprintf(temp, "%s %s\n", usuarioArquivo, novaSenha); 
        }

            else {
            wprintf(L"Senha atual incorreta!\n");
            fclose(arquivo);
            fclose(temp);
            remove("temp.txt");
            return;
            }
        }
            else {
            fprintf(temp, "%s %s\n", usuarioArquivo, senhaArquivo);
            }
    }

    fclose(arquivo);
    fclose(temp);

    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");

    if (encontrado) 
    {
        wprintf(L"\nSenha alterada com sucesso!\n");
    } 
    else 
    {
        wprintf(L"\nUsuário não encontrado.\n");
    }
}



//exclui a senha e o usuario 
void excluirUsuario() {
    char usuario[30], usuarioArquivo[30], senhaArquivo[30];
    int encontrado = 0;

    printf("------------------------------\n");
    printf("Exclusão de Usuário\n");
    printf("------------------------------\n");

    printf("Digite o nome do usuário que deseja excluir: ");
    scanf("%s", usuario);

    FILE *arquivo = fopen("usuarios.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!arquivo || !temp) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    while (fscanf(arquivo, "%s %s", usuarioArquivo, senhaArquivo) != EOF) {
        if (strcmp(usuario, usuarioArquivo) != 0) {
            fprintf(temp, "%s %s\n", usuarioArquivo, senhaArquivo);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");

    printf(encontrado ? "Usuário excluído com sucesso!\n" : "Usuário não encontrado!\n");
}

//função princiapl
int main () {
    int opcao;
    setlocale(LC_ALL, "");

    do {
        desenhaLinha(30);
        printf("       MENU PRINCIPAL       \n");
        desenhaLinha(30);
        printf("1. login\n");
        wprintf(L"2. Cadastrar novo usuário\n");
        printf("3. Alterar senha\n");
        printf("4. Deletar arquivo\n");
        printf("5. Sair\n");
        wprintf(L"escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao)
    {
        case 1:
            telalogin();
            break;

        case 2:
             cadastrarUsuario();
             break;
       
        case 3:
             alterarSenha();
             break;
           
             
        case 4:
             excluirUsuario();
             break;
        
        case 5:
             printf("Saindo...\n");
             break;

        default:
        wprintf(L"Opção inválida. Tente novamente.\n");
    }

    } while  (opcao != 5);
    return 0;
}