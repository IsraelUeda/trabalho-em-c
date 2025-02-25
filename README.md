Sistema de Gerenciamento de Usuários
Este projeto é um sistema de gerenciamento de usuários desenvolvido em C. Ele permite que os usuários realizem login, cadastrem novos usuários, alterem senhas e excluam usuários. O sistema armazena os dados dos usuários em um arquivo de texto.

Funcionalidades
Login: Verifica se o usuário e a senha fornecidos correspondem a um usuário registrado.

Cadastrar Novo Usuário: Permite o registro de novos usuários, salvando suas informações em um arquivo.

Alterar Senha: Permite que os usuários alterem suas senhas.

Excluir Usuário: Permite a exclusão de um usuário do sistema.

Estrutura do Código
O código é dividido em várias funções para facilitar a manutenção e a leitura:

desenhaLinha(int largura): Desenha uma linha de caracteres de acordo com a largura especificada.

telalogin(): Realiza o login do usuário.

cadastrarUsuario(): Cadastra um novo usuário.

alterarSenha(): Permite que o usuário altere sua senha.

excluirUsuario(): Exclui um usuário do sistema.

main(): Função principal que exibe o menu e chama as funções apropriadas com base na escolha do usuário.

Como Executar
Certifique-se de ter um compilador C instalado em seu sistema.

Compile o código usando o comando:

gcc -o gerenciador_usuarios gerenciador_usuarios.c
Execute o programa:

./gerenciador_usuarios
Arquivo de Usuários
O sistema utiliza um arquivo chamado usuarios.txt para armazenar os dados dos usuários. Cada linha do arquivo contém um nome de usuário e uma senha, separados por um espaço.

Observações
Certifique-se de que o arquivo usuarios.txt exista no mesmo diretório do programa executável.

O sistema é case-sensitive, ou seja, diferencia letras maiúsculas de minúsculas ao verificar o nome de usuário e a senha.
