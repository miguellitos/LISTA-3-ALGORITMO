#include <stdio.h>
#include <string.h>
#include <ctype.h>

int placavalida = 0;

int validarPlaca(char *placa)
{
    // Verificar o comprimento da placa
    if (strlen(placa) != 8 && strlen(placa) != 7)
    {
        placavalida = 0;
        return 0; // Formato inválido
    }

    // Verificar o formato antigo (LLL-NNNN)
    if (strlen(placa) == 8 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        placa[3] == '-' && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]))
    {
        placavalida = 1;
        return 1; // Formato antigo válido
    }

    // Verificar o formato do Mercosul (LLLNLNN)
    if (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]))
    {
        placavalida = 1; // Fix: Set placavalida to 1 for Mercosul format
        return 1;       // Formato Mercosul válido
    }

    return 0;
}

int main()
{
    char placa[10];
    char dia[15];
    scanf("%s", placa);
    scanf("%s", dia);

    char *dias[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    int valido = 0;
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(dia, dias[i]) == 0)
        {
            valido = 1;
            break;
        }
    }

    int resultado = validarPlaca(placa);

    if (!resultado && !valido)
    {
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");
        return 0;
    }

    if (!resultado)
    {
        printf("Placa invalida\n");
        return 0;
    }

    if (!valido)
    {
        printf("Dia da semana invalido\n");
        return 0;
    }

    int ultimo_digito = placa[strlen(placa) - 1] - '0';

    if (strcmp(dia, "SEGUNDA-FEIRA") == 0 && (ultimo_digito == 0 || ultimo_digito == 1))
    {
        printf("%s nao pode circular segunda-feira\n", placa);
    }
    else if (strcmp(dia, "TERCA-FEIRA") == 0 && (ultimo_digito == 2 || ultimo_digito == 3))
    {
        printf("%s nao pode circular terca-feira\n", placa);
    }
    else if (strcmp(dia, "QUARTA-FEIRA") == 0 && (ultimo_digito == 4 || ultimo_digito == 5))
    {
        printf("%s nao pode circular quarta-feira\n", placa);
    }
    else if (strcmp(dia, "QUINTA-FEIRA") == 0 && (ultimo_digito == 6 || ultimo_digito == 7))
    {
        printf("%s nao pode circular quinta-feira\n", placa);
    }
    else if (strcmp(dia, "SEXTA-FEIRA") == 0 && (ultimo_digito == 8 || ultimo_digito == 9))
    {
        printf("%s nao pode circular sexta-feira\n", placa);
    }
    else if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0)
    {
        printf("Nao ha proibicao no fim de semana\n");
    }
    else
{
    // Imprimir placa e dia em minúsculo
    printf("%s pode circular ", placa);
    for (int i = 0; dia[i]; i++)
    {
        putchar(tolower(dia[i]));
    }
    putchar('\n');
}
    return 0;
}
//CORRETO