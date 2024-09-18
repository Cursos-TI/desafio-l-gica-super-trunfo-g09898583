#include <stdio.h>

typedef struct
{
    char estado;
    char *cidade;
    int codigo;
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

int main()
{
    int opcao, totalcartas = 0;
    Carta cartas[2];

    // inicio de jogo
    while (opcao < 3)
    {
        printf("Menu Principal\n");
        printf("1. Cadastrar carta\n");
        printf("2. Ver Resultado\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1: // Cadastrar carta

            if (totalcartas == 2)
            {
                printf("\n Você já cadastrou o máximo de cartas permitido! \n");
                break;
            }

            Carta carta;

            printf("Digite a cidade: ");
            scanf(" %[^\n]s", &carta.cidade);

            printf("Digite a população: ");
            scanf("%d", &carta.populacao);

            cartas[totalcartas] = carta;

            totalcartas++;
            break;
        case 2: // Ver Resultado

            if (totalcartas < 2)
            {
                printf("\n Você não cadastrou todas as cartas! \n\n ");
                break;
            }

            int populacaoA = cartas[0].populacao;
            int populacaoB = cartas[1].populacao;

            if (populacaoA == populacaoB)
            {
                printf("Empate!");
            }
            else
            {
                char *cidadeVencedora = (populacaoA > populacaoB) ? cartas[0].cidade : cartas[1].cidade;

                printf("\n %s tem maior população. \n ", &cidadeVencedora);
                printf("A cidade vencedora é: %s \n", &cidadeVencedora);
            }

            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            opcao = 0;
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    // fim de jogo

    return 0;
}