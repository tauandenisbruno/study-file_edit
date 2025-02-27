#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* return_line(int linha)
{
    char *dados = malloc(1024);
    FILE *arquivo = fopen("file", "r");

    int linha_atual = 0;
    while (fgets(dados, sizeof(dados), arquivo) != NULL)
    {
        linha_atual++;
        if (linha_atual == linha)
        {
            break;
        }
    }
    return dados;
    fclose(arquivo);
    free(dados);
}

void edit_line(int linha, char *texto)
{
    char* txt_tmp[100][1024]; // Texto temporário

    int i = 0; // Contador
    FILE *arquivo = fopen("file", "r"); // Abre arquivo no modo de LEITURA
    while (fgets(txt_tmp[i], 1024, arquivo) != NULL)
    {
        i++;
    }
    fclose(arquivo);

    strcpy(txt_tmp[linha -1], texto);

    arquivo = fopen("file", "w");
//    for (i = 0; i < 100; i++)
//    {
//        fputs(txt_tmp[i], arquivo);
//    }

    for (i = 0; i < 100; i++)
    {
        fprintf(arquivo, "%s", txt_tmp[i]);
    }

    fclose(arquivo);
}

int main()
{
    char palavra[1024]; // Armazenamento temporário do nome
    int linha = 1; // Nº da linha a ser alterada

    while (linha != 4)
    {
        printf("1- USUÁRIO CADASTRADO: %s2- IDADE: %s3- ESCOLA: %s4- SAIR\n5- RESETAR\n", return_line(1), return_line(2), return_line(3));

        printf("\nEDITAR LINHA> ");
        scanf("%d", &linha);

        if (linha > 0 && linha < 4)
        {
            printf("ATUAL: %s\n", return_line(linha));

            printf("TEXTO> ");
            scanf("%s", palavra);
            strcat(palavra, "\n");

            edit_line(linha, palavra);

            printf("EDITADO> %s", return_line(linha));
        }

        if (linha == 5)
        {
            int i = 1;
            for (i = 1; i < 4; i++)
            {
                edit_line(i, "NULL\n");
            }
        }
        system("clear");
    }

    return 0;
}
