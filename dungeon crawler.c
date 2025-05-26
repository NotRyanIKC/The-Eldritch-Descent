#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

char command;

char mapav[13][13];
char mapa[13][13];
char mapa2[23][23];
char mapa3[43][43];

bool chavePega;
bool monstroV_ativo = true;
bool botaoPressionado = false;

// struct chave falsas
typedef struct {
    int x;
    int y;
} Posicao;

Posicao chavesFalsas[] = {
    {23, 1},
    {36, 1},
    {21, 3},
    {36, 3},
    {40, 3}
};

int numChavesFalsas = sizeof(chavesFalsas) / sizeof(chavesFalsas[0]);

// struct com variaveis pros mapas e player
typedef struct {
    char nome[16];
    bool vivo;
    int hp;
    int PlayerX;
    int PlayerY;
    int NpcX;
    int NpcY;
    int ChaveX;
    int ChaveY;
    int PortaX;
    int PortaY;
    int BotaoX;
    int BotaoY;
    int Tp1X;
    int Tp2X;
    int Tp1Y;
    int temp2Y;
} player;

int continuar = 1;

player newPlayer;

int level = 1;
// funções de gerar mapas
void GenerateMapv(char mapav[13][13], int PlayerX, int PlayerY, int ChaveX, int ChaveY, int PortaX, int PortaY, int NpcX, int NpcY) {
    int i, j;
        char layout[13][13] = {
            "\t\t\t*********",
            "\t\t\t*        *",
            "\t\t\t***      *",
            "\t\t\t***      *",
            "\t\t\t*        *",
            "\t\t\t***      *",
            "\t\t\t*        *",
            "\t\t\t***      *",
            "\t\t\t*        *",
            "\t\t\t*********",
        };
		newPlayer.PortaX = 4;
		newPlayer.PortaY = 4;
        for (i = 0; i < 13; i++) {
            for (j = 0; j < 13; j++) {
                mapav[i][j] = layout[i][j];
                
            }
        }
    mapav[PlayerY][PlayerX] = '&';
    mapav[NpcY][NpcX] = 'P';
    if (chavePega == true) {
        mapav[ChaveY][ChaveX] = ' ';
        mapav[PortaY][PortaX] = '=';
    } else {
        mapav[ChaveY][ChaveX] = '@';
        mapav[PortaY][PortaX] = 'D';
    }
}

void GenerateMap1(char mapa[13][13], int PlayerX, int PlayerY, int ChaveX, int ChaveY, int PortaX, int PortaY) {
    int i, j;
        char layout[13][13] = {
            "\t\t\t*********",
            "\t\t\t**     **",
            "\t\t\t******  *",
            "\t\t\t***     *",
            "\t\t\t**** ****",
            "\t\t\t*  *@   *",
            "\t\t\t*  ***  *",
            "\t\t\t*  *D*  *",
            "\t\t\t*       *",
            "\t\t\t*********",
        };
		newPlayer.PortaX = 7;
		newPlayer.PortaY = 7;
        for (i = 0; i < 13; i++) {
            for (j = 0; j < 13; j++) {
                mapa[i][j] = layout[i][j];
                
            }
        }
    mapa[PlayerY][PlayerX] = '&';
    if (chavePega == true) {
        mapa[ChaveY][ChaveX] = ' ';
        mapa[PortaY][PortaX] = '=';
    } else {
        mapa[ChaveY][ChaveX] = '@';
        mapa[PortaY][PortaX] = 'D';
    }
}

void GenerateMap2(char mapa2[23][23], int PlayerX, int PlayerY, int ChaveX, int ChaveY, int PortaX, int PortaY, int monsteX, int monsteY, int BotaoX, int BotaoY) {
        int i, j;
        
        char layout2[23][23] = {
            "\t\t\t********************",
            "\t\t\t**        *****#O#**",
            "\t\t\t*          ****# #**",
            "\t\t\t******   ******# #**",
            "\t\t\t*            **   **",
            "\t\t\t*    #####    *## **",
            "\t\t\t*   #     #   #    *",
            "\t\t\t**     ##         **",
            "\t\t\t*  #  #  #    #    *",
            "\t\t\t**   # ##   #     **",
            "\t\t\t***#            #***",
            "\t\t\t***##############***",
            "\t\t\t***#            #***",
            "\t\t\t**                **",
            "\t\t\t*       ** **  *  **",
            "\t\t\t**      *  *   *  **",
            "\t\t\t** ##  ***  *   *  *",
            "\t\t\t**D## *****   @   **",
            "\t\t\t********************",
        };
        newPlayer.PortaX = 5; 
    	newPlayer.PortaY = 17;
        
        for (i = 0; i < 23; i++) {
            for (j = 0; j < 23; j++) {
                mapa2[i][j] = layout2[i][j];
            }
        }
        if (botaoPressionado) {
            for ( i = 0; i < 23; i++) {
                if (mapa2[11][i] == '#') {
                    mapa2[11][i] = ' ';
        }
    }
}
    
    mapa2[PlayerY][PlayerX] = '&';
    mapa2[monsteY][monsteX] = 'X';
    mapa2[BotaoX][BotaoY] = 'O';

    if (chavePega == true) {
        mapa2[ChaveY][ChaveX] = ' ';
        mapa2[PortaY][PortaX] = '=';
    } else {
        mapa2[ChaveY][ChaveX] = '@';
        mapa2[PortaY][PortaX] = 'D';
    }
}

void GenerateMap3(char mapa3[43][43], int PlayerX, int PlayerY, int ChaveX, int ChaveY, int PortaX, int PortaY, int monsteX, int monsteY,int monste2X,int monste2Y, int BotaoX, int BotaoY, int Tp1X,int Tp2X,int Tp1Y,int Tp2Y) {
    int i,j;
    char layout3[43][43] = {
            "\t*****************************************",
            "\t**               *****@        ####@####*",
            "\t* #         #      *##  #     ####      *",
            "\t*             #    *@  ###    #####@ ##@*",
            "\t*    #        #   ***#####              *",
            "\t******* *******  ************    ********",
            "\t*  #       #   #  ***    #  #           *",
            "\t*                  *         #    #     *",
            "\t*   #     #        * #     #     #   # #*",
            "\t*    #             *                    *",
            "\t*        #    #    *    #   #  #     #  *",
            "\t*    #             *                    *",
            "\t*   #       #     ***   #       #   #   *",
            "\t*      #           *                    *",
            "\t*         #    #   *    #    #          *",
            "\t*  #   #     #     *            #       *",
            "\t*******         #  *   #        # *******",
            "\t*#                 *       #           #*",
            "\t*   #         #   ***                   *",
            "\t*******   #     #  *     #      # *******",
            "\t*    #        #    *                    *",
            "\t*           #      *      #      #      *",
            "\t*   #              *  #                 *",
            "\t*       #     #    *     #     #    #   *",
            "\t*   #             ***       #           *",
            "\t*         #        *    #        #     #*",
            "\t*     #       *    *       #            *",
            "\t**          #      *   #                *",
            "\t*  #           #  ***     #    #    #   *",
            "\t*     #   *****    *  #                 *",
            "\t*   #      *   #   *        #      #    *",
            "\t*****     *     #  *     #     #       **",
            "\t******    **   #   *                  ***",
            "\t*******   ***#   #***  #    #      # ****",
            "\t********  ****** *****     #          ***",
            "\t**   #            ***   #       #      **",
            "\t*                  *        #     #     *",
            "\t*      #   #      ***    #           #  *",
            "\t**     # D #     ***** #       #        **",
            "\t*****************************************",
        };

        for(i = 0; i < 43; i++) {
            for(j = 0; j < 43; j++) {
                mapa3[i][j] = layout3[i][j];
            }
        }

    mapa3[PlayerY][PlayerX] = '&';
    mapa3[monsteY][monsteX] = 'X';
    if (monstroV_ativo) {
    mapa3[monste2Y][monste2X] = 'V';
}
    mapa3[BotaoY][BotaoX] = 'O';
    mapa3[Tp1Y][Tp1X] = '<';
    mapa3[Tp2Y][Tp2X] = '>';
    
    if (chavePega == true) {
        mapa3[ChaveY][ChaveX] = ' ';
        mapa3[PortaY][PortaX] = '=';
    } else {
        mapa3[ChaveY][ChaveX] = '@';
        mapa3[PortaY][PortaX] = 'D';
    }
}
// funções de printar mapas
void PrintMapv(char mapav[13][13]) {
    int i, j;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < 13; j++) {
            printf("%c", mapav[i][j]);
        }
        printf("\n");
    }
}

void PrintMap1(char mapa[13][13]) {
    int i, j;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < 13; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}
void PrintMap2(char mapa2[23][23]) {
    int i, j;
    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            printf("%c", mapa2[i][j]);
        }
        printf("\n");
    }
}
void PrintMap3(char mapa3[43][43]) {
    int i, j;
    for (i = 0; i < 43; i++) {
        for (j = 0; j < 43; j++) {
            printf("%c", mapa3[i][j]);
        }
        printf("\n");
    }
}


// função creditos
void PrintCreditos() {
    system("cls");
    printf("========================================\n");
    printf("               CREDITOS\n");
    printf("========================================\n");
    printf("Desenvolvido por: Ryan Cavalcanti, Pedro Augusto e Luan Ramiro\n");
    printf("Feito com muito cafe e muito C! :) \n");
    printf("========================================\n");
    printf("\nPressione qualquer tecla para voltar ao menu...\n");
    getch();
    system("cls");
}
// função tela de morte
void TelaDeMorte() {
    system("cls");
    printf("\n\n");
    printf("  @@@@@                                        @@@@@        \n");
    printf(" @@@@@@@                                      @@@@@@@       \n");
    printf(" @@@@@@@           @@@@@@@@@@@@@@@            @@@@@@@       \n");
    printf("  @@@@@@@@       @@@@@@@@@@@@@@@@@@@        @@@@@@@@        \n");
    printf("      @@@@@     @@@@@@@@@@@@@@@@@@@@@     @@@@@     \n");
    printf("        @@@@@  @@@@@@@@@@@@@@@@@@@@@@@  @@@@@       \n");
    printf("          @@  @@@@@@@@@@@@@@@@@@@@@@@@@  @@     \n");
    printf("            @@@@@@@    @@@@@@    @@@@@@       \n");
    printf("            @@@@@@      @@@@      @@@@@        \n");
    printf("            @@@@@@      @@@@      @@@@@        \n");
    printf("             @@@@@@    @@@@@@    @@@@@      \n");
    printf("              @@@@@@@@@@@  @@@@@@@@@@       \n");
    printf("               @@@@@@@@@@  @@@@@@@@@    \n");
    printf("         @@     @@@@@@@@@@@@@@@@@   @@\n");
    printf("         @@@@    @@@@ @ @ @ @ @@@@  @@@@\n");
    printf("         @@@@@    @@@ @ @ @ @ @@@   @@@@@\n");
    printf("       @@@@@       @@@@@@@@@@@@@      @@@@@\n");
    printf("     @@@@           @@@@@@@@@@@          @@@@\n");
    printf("  @@@@@               @@@@@@@              @@@@@\n");
    printf(" @@@@@@@                                  @@@@@@@\n");
    printf("  @@@@@                                    @@@@@\n\n");
    printf("\nVoce morreu, Suas vidas acabaram. Tente novamente!\n");
    printf("\nPressione qualquer tecla para voltar ao menu...\n");
    getch();
    voltarMenu();
}


// função de inicialização do jogador e chave
void PlayerSettingsBase() {
    newPlayer.vivo = true;
    newPlayer.hp = 3;
    chavePega = false;
}
// função sair do jogo
void sair() {
    printf("Saindo do jogo...\n");
    exit(0);
}
// função voltar pro menu
void voltarMenu() {
    printf("\nVoltando para o menu...\n");
    system("pause");
    system("cls");
    main();
}

// função interagir mapa vila
void Interactv() {
    if (newPlayer.PlayerX == newPlayer.ChaveX && newPlayer.PlayerY == newPlayer.ChaveY && !chavePega) {
        mapav[newPlayer.ChaveY][newPlayer.ChaveX] = ' ';
        chavePega = true;
        printf("Voce pegou a chave '@'!\n");
        mapav[newPlayer.PortaY][newPlayer.PortaX] = '=';
    }
    else if (newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY && chavePega) {
        printf("Voce abriu a porta e concluiu a fase!\n");
    }else if(mapav[newPlayer.PlayerY][newPlayer.PlayerX] == 'P'){
    printf("'W' = Mover para cima\n'A' = Mover para a esquerda\n'S' = Mover para baixo\n'D' = Mover para a direita\n'I' = Interagir com objetos (Somente quando estiver embaixo do jogador)\n\n");
    printf("Voce (Player) tem apenas 3 vidas, seu objetivo eh pegar a '@' (Chave) para abrir a porta identificada como 'D' e concluir a fase.\n");
    printf("Tome cuidado! Conforme voce avanca no jogo a dificuldade ira aumentar.\n");
    printf("Esteja atento com inimigos e obstaculos identificados como 'X' (inimigo nivel 1),'V' (inimigo nivel 2) e '#' (Espinhos).\n");
    printf("Caso sua vida chegue a 0 voce voltara para o menu.\n\n");
    printf("Obs: Aperte o botao ('O') encontrado em algumas fases e descubra algo secreto :)\n");

	}
    else {
        printf("Nada para interagir aqui.\n");
    }
}
// função interagir mapa 1
void Interact() {
    if (newPlayer.PlayerX == newPlayer.ChaveX && newPlayer.PlayerY == newPlayer.ChaveY && !chavePega) {
        mapa[newPlayer.ChaveY][newPlayer.ChaveX] = ' ';
        chavePega = true;
        printf("Voce pegou a chave '@'!\n");
        mapa[newPlayer.PortaY][newPlayer.PortaX] = '=';
    }
    else if (newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY && chavePega) {
        printf("Voce abriu a porta e concluiu a fase!\n");
        exit(0);
    }else if(mapa[newPlayer.PlayerY][newPlayer.PlayerX] == 'O'){
    	printf("COLOR YOUR NIGHT");
	}
    else {
        printf("Nada para interagir aqui.\n");
    }
}
// função interagir mapa 2
void Interact2() {
    if (newPlayer.PlayerX == newPlayer.ChaveX && newPlayer.PlayerY == newPlayer.ChaveY && !chavePega) {
        mapa2[newPlayer.ChaveY][newPlayer.ChaveX] = ' ';
        chavePega = true;
        printf("Voce pegou a chave '@'!\n");
        mapa2[newPlayer.PortaY][newPlayer.PortaX] = '=';
    }
    else if (newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY && chavePega) {
        printf("Voce abriu a porta e concluiu a fase!\n");
        exit(0);
    }else if(mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == 'O'){
    	printf("COGITO ERGO SUM\n");
        botaoPressionado = true;
    mapa2[newPlayer.PlayerY][newPlayer.PlayerX] = ' ';
    printf("Os espinhos sumiram!\n");
	}
    else {
        printf("Nada para interagir aqui.\n");
    }
}
// função interagir mapa 3
void Interact3() {
    int i;
    if (newPlayer.PlayerX == newPlayer.ChaveX && newPlayer.PlayerY == newPlayer.ChaveY && !chavePega) {
        mapa3[newPlayer.ChaveY][newPlayer.ChaveX] = ' ';
        chavePega = true;
        printf("Voce pegou a chave '@'!\n");
        mapa3[newPlayer.PortaY][newPlayer.PortaX] = '=';
    }
    else if (newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY && chavePega) {
        printf("Voce abriu a porta e concluiu a fase!\n");
        exit(0);
    }else if(mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == 'O'){
    	printf("ITS GOING DOWN NOW\n");
        if (monstroV_ativo) {
        monstroV_ativo = false;
        mapa3[newPlayer.BotaoY][newPlayer.BotaoX] = ' ';
        printf("Voce desativou o monstro V!\n");
        }
	} else {
        for (i = 0; i < numChavesFalsas; i++) {
            if (newPlayer.PlayerX == chavesFalsas[i].x && newPlayer.PlayerY == chavesFalsas[i].y) {
                printf("Essa Chave eh Falsa!!!\n");
                return;  
            }
        }   
        printf("Nada para interagir aqui.\n");
    }
}
// função de movimento aleatorio do monstro X
void monstmov(int *monsteX, int *monsteY) {
    int n = 4;

    int movement = rand() % (n + 1);

    if (movement == 1) {
        (*monsteX)++;
    } else if (movement == 2) {
        (*monsteX)--;
    } else if (movement == 3) {
        (*monsteY)++;
    } else {
        (*monsteY)--;
    }
}
// Funçõa verificar colisão monstro x jogador
void verificarColisaoComMonstros(int monsteX, int monsteY, int monste2X, int monste2Y) {
    if ((newPlayer.PlayerX == monsteX && newPlayer.PlayerY == monsteY) ||
        (newPlayer.PlayerX == monste2X && newPlayer.PlayerY == monste2Y)) {
        newPlayer.hp--;
        printf("O monstro te acertou! Vidas restantes: %d\n", newPlayer.hp);
        if (newPlayer.hp <= 0) {
            TelaDeMorte();
        }
    }
}


// Função start mapa 3
void mapa3start(){
    newPlayer.hp = 3;
    monstroV_ativo = true;

    newPlayer.PlayerX = 10;
    newPlayer.PlayerY = 1;
        
    newPlayer.ChaveX = 31;
    newPlayer.ChaveY = 1;

    newPlayer.PortaX = 10;
    newPlayer.PortaY = 38;

    newPlayer.BotaoX = 23;
    newPlayer.BotaoY = 38;
    
    int monsteX = 12;
    int monsteY = 34;
    
    int monste2X = 22;
    int monste2Y = 10;

    int Tp1X = 3;
    int Tp1Y = 18;
    int Tp2X = 39;
    int Tp2Y = 18;

    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY,Tp1X,Tp2X,Tp1Y,Tp2Y);
    
    char command;
    PrintMap3(mapa3);
 // Mov Jogador
    while (1) {
        command = getch();

        switch (command) {
            case 'W':
            case 'w':
                if (mapa3[newPlayer.PlayerY - 1][newPlayer.PlayerX] != '*' && mapa3[newPlayer.PlayerY - 1][newPlayer.PlayerX] != 'D') {
                    newPlayer.PlayerY--;
                    
                    if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                        newPlayer.hp--;
                        newPlayer.PlayerY++;
                        printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                        system("pause");
                    
                        if (newPlayer.hp == 0) {
                    
                            TelaDeMorte();
                        } else {
                            printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
                        }
                    }
                    system("cls");
                    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY,Tp1X,Tp2X,Tp1Y,Tp2Y);
                    PrintMap3(mapa3);
                    verificarColisaoComMonstros(monsteX, monsteY, monste2X, monste2Y);
                }
                break;
            case 'S':
            case 's':
                if (mapa3[newPlayer.PlayerY + 1][newPlayer.PlayerX] != '*' && mapa3[newPlayer.PlayerY + 1][newPlayer.PlayerX] != 'D') {
                    newPlayer.PlayerY++;
                    
                    if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                        newPlayer.hp--;
                        newPlayer.PlayerY--;
                        printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                        system("pause");
                      
                        if (newPlayer.hp == 0) {
                         
                            TelaDeMorte();
                        } else {
                            printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
                        }
                    }
                    system("cls"); 
                    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY,Tp1X,Tp2X,Tp1Y,Tp2Y);
                    PrintMap3(mapa3);
                    verificarColisaoComMonstros(monsteX, monsteY, monste2X, monste2Y);
                }
                break;
            case 'D':
            case 'd':
                if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX + 1] != '*' && mapa3[newPlayer.PlayerY][newPlayer.PlayerX + 1] != 'D') {
                    newPlayer.PlayerX++;
                    if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                        newPlayer.hp--;
                        newPlayer.PlayerX--;
                        printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                        system("pause");
                     
                        if (newPlayer.hp == 0) {
                    
                            TelaDeMorte();
                        } else {
                            printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
                        }
                    }
                    system("cls"); 
                    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY,Tp1X,Tp2X,Tp1Y,Tp2Y);
                    PrintMap3(mapa3);
                    verificarColisaoComMonstros(monsteX, monsteY, monste2X, monste2Y);
                }
                break;
            case 'A':
            case 'a':
                if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX - 1] != '*' && mapa3[newPlayer.PlayerY][newPlayer.PlayerX - 1] != 'D') {
                    newPlayer.PlayerX--;

                    if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                        newPlayer.hp--;
                        newPlayer.PlayerX++;
                        printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                        system("pause");
                        if (newPlayer.hp == 0) {
                        
                            TelaDeMorte();
                        } else {
                            printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
                        }
                    }
                    system("cls"); 
                    GenerateMap3(mapa3, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, monsteX, monsteY, monste2X, monste2Y, newPlayer.BotaoX, newPlayer.BotaoY,Tp1X,Tp2X,Tp1Y,Tp2Y);                    
                    PrintMap3(mapa3);
                    verificarColisaoComMonstros(monsteX, monsteY, monste2X, monste2Y);
                }
                break;
            case 'I':
            case 'i':
                Interact3();
                break;
            case 'P':
            case 'p':
                printf("Cheat ativado: Pulando para a próxima fase!\n");
                system("pause");
                system("cls");
                printf("* ######     ###    ######     ###    ######   #######  ##   ##   ##### *\n");
                printf("*  ##  ##   ## ##    ##  ##   ## ##    ##  ##   ##   #  ###  ##  ##   ## *\n");
                printf("*  ##  ##  ##   ##   ##  ##  ##   ##   ##  ##   ##      #### ##  ## *\n");
                printf("*  #####   ##   ##   #####   ##   ##   #####    ####    #######   ##### *\n");
                printf("*  ##      #######   ## ##   #######   ##  ##   ##      ## ####       ## *\n");
                printf("*  ##      ##   ##   ## ##   ##   ##   ##  ##   ##   #  ##  ###  ##   ## *\n");
                printf("* ####     ##   ##  #### ##  ##   ##  ######   #######  ##   ##   ##### *\n\n");
                printf("Depois de uma ardua jornada(ou nao), Voce conseguiu recuperar o antigo tesouro do rei!\n");
                system("pause");
                system("cls");
                PrintCreditos();
                voltarMenu();
        break;
        }
        // Funcionamento do TP
        if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '<') {
            newPlayer.PlayerX = 39;
            newPlayer.PlayerY = 18;
        } else if (mapa3[newPlayer.PlayerY][newPlayer.PlayerX] == '>') {
            newPlayer.PlayerX = 3;
            newPlayer.PlayerY = 18;
        }
        // Funcioanmento Monstro V
        if(monstroV_ativo) {
    int movement = rand() % 2;
    if(movement == 0){
        if(newPlayer.PlayerX < monste2X){
            monste2X--;
        } else {
            monste2X++;
        }
    } else {
        if(newPlayer.PlayerY < monste2Y){
            monste2Y--;
        } else {
            monste2Y++;
        }
    }
}




        // funcionamento monstro X
        if(mapa3){
        int tempX = monsteX, tempY = monsteY;
        monstmov(&tempX, &tempY);
        
        if (mapa3[tempY][tempX] != '*' && mapa3[tempY][tempX] != '#') {
            monsteX = tempX;
            monsteY = tempY;
        }
        verificarColisaoComMonstros(monsteX, monsteY, monste2X, monste2Y);
    }

        if (mapa3[newPlayer.PortaY][newPlayer.PortaX] == '=' && newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY) {
            printf("Parabens! Voce abriu a porta e concluiu a fase!\n\n");
            system("cls");
            printf("* ######     ###    ######     ###    ######   #######  ##   ##   ##### *\n");
            printf("*  ##  ##   ## ##    ##  ##   ## ##    ##  ##   ##   #  ###  ##  ##   ## *\n");
            printf("*  ##  ##  ##   ##   ##  ##  ##   ##   ##  ##   ##      #### ##  ## *\n");
            printf("*  #####   ##   ##   #####   ##   ##   #####    ####    #######   ##### *\n");
            printf("*  ##      #######   ## ##   #######   ##  ##   ##      ## ####       ## *\n");
            printf("*  ##      ##   ##   ## ##   ##   ##   ##  ##   ##   #  ##  ###  ##   ## *\n");
            printf("* ####     ##   ##  #### ##  ##   ##  ######   #######  ##   ##   ##### *\n\n");
            printf("Depois de uma ardua jornada, Voce conseguiu recuperar o antigo tesouro do rei!\n ");
            system("pause");
            system("cls");
            PrintCreditos();
            voltarMenu();
        }
    }
}

     
// Função start mapa 2
void mapa2start(){
    newPlayer.hp = 3;

    newPlayer.PlayerX = 6;
    newPlayer.PlayerY = 1;
        
    newPlayer.ChaveX = 17;
    newPlayer.ChaveY = 17;

    newPlayer.PortaX = 5;
    newPlayer.PortaY = 17;

    newPlayer.BotaoX = 1;
    newPlayer.BotaoY = 19;
    
    int monsteX = 18;
    int monsteY = 14;
    
    GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
    
    char command;
    PrintMap2(mapa2);
 // Mov Jogador
    while (1) {
        command = getch();

        switch (command) {
        case 'W':
        case 'w':
            if (mapa2[newPlayer.PlayerY - 1][newPlayer.PlayerX] != '*' && mapa2[newPlayer.PlayerY - 1][newPlayer.PlayerX] != 'D'){
                newPlayer.PlayerY--;
                
                if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                    newPlayer.hp--;
                    newPlayer.PlayerY++;
                    printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                    system("pause");
              
                    if (newPlayer.hp == 0) {
               
                        TelaDeMorte();
            } else {
                printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
            }
        }
            system("cls"); 
            GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
            PrintMap2(mapa2);
            verificarColisaoComMonstros(monsteX, monsteY, -1, -1);
            }
            break;
        case 'S':
        case 's':
            if (mapa2[newPlayer.PlayerY + 1][newPlayer.PlayerX] != '*' && mapa2[newPlayer.PlayerY + 1][newPlayer.PlayerX] != 'D'){
                newPlayer.PlayerY++;
                
                if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                newPlayer.hp--;
                newPlayer.PlayerY--;
                printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                system("pause");
                
                if (newPlayer.hp == 0) {
               
                TelaDeMorte();
            } else {
                printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
            }
        }
            system("cls"); 
            GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
            PrintMap2(mapa2);
            verificarColisaoComMonstros(monsteX, monsteY, -1, -1);
            }
            break;
        case 'D':
        case 'd':
            if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX + 1] != '*' && mapa2[newPlayer.PlayerY][newPlayer.PlayerX + 1] != 'D'){
                newPlayer.PlayerX++;
                

                if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                newPlayer.hp--;
                newPlayer.PlayerX--;
                printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                system("pause");
                
            if (newPlayer.hp == 0) {
               
                TelaDeMorte();
            } else {
                printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
            }
        }
            system("cls"); 
            GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
            PrintMap2(mapa2);
            verificarColisaoComMonstros(monsteX, monsteY, -1, -1);
            }
            break;
        case 'A':
        case 'a':
            if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX - 1] != '*' && mapa2[newPlayer.PlayerY][newPlayer.PlayerX - 1] != 'D'){
                newPlayer.PlayerX--;
                
                if (mapa2[newPlayer.PlayerY][newPlayer.PlayerX] == '#') {
                newPlayer.hp--;
                newPlayer.PlayerX++;
                printf("Perdeu vida %d vezes.\n", newPlayer.hp);
                system("pause");
                
                if (newPlayer.hp == 0) {
                
                TelaDeMorte();
            } else {
                printf("Você tocou nos espinhos, mas ainda tem vida restante.\n");
            }
        }
            system("cls"); 
            GenerateMap2(mapa2, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY,monsteX,monsteY,newPlayer.BotaoX,newPlayer.BotaoY);
            PrintMap2(mapa2);
            verificarColisaoComMonstros(monsteX, monsteY, -1, -1);
            }
            break;
        case 'I':
        case 'i':
            Interact2();
            break;
        case 'P':
        case 'p':
            printf("Cheat ativado: Pulando para a proxima fase!\n");
            system("pause");
            system("cls");
            mapa3start();
        break;
        }
        
        if(mapa2) {
        int tempX = monsteX, tempY = monsteY;
        monstmov(&tempX, &tempY); 

       
        if (mapa2[tempY][tempX] != '*' && mapa[tempY][tempX] != '#') {
            monsteX = tempX;
            monsteY = tempY;
        }
        verificarColisaoComMonstros(monsteX, monsteY, -1, -1);
    }

        if (mapa2[newPlayer.PortaY][newPlayer.PortaX] == '=' && newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY) {
            printf("Parabens! Voce abriu a porta e concluiu a fase!\n");
            chavePega = false;
            system("pause");
            system("cls");
            mapa3start();
        }
    }
}



// função start mapa 1

void mapa1start() {
    newPlayer.hp = 3;
    
    newPlayer.PlayerX = 7;
    newPlayer.PlayerY = 1;
        
    newPlayer.ChaveX = 7;
    newPlayer.ChaveY = 5;

    newPlayer.PortaX = 4;
    newPlayer.PortaY = 6;

    GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);

    char command;
    PrintMap1(mapa);
     // Mov Jogador
    while (1) {
        command = getch();

        switch (command) {
        case 'W':
        case 'w':
      
            if (mapa[newPlayer.PlayerY - 1][newPlayer.PlayerX] != '*' && mapa[newPlayer.PlayerY - 1][newPlayer.PlayerX] != 'D') {
                newPlayer.PlayerY--; 
                system("cls"); 
                GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);
                PrintMap1(mapa);
            }
            break;
        case 'S':
        case 's':
            
            if (mapa[newPlayer.PlayerY + 1][newPlayer.PlayerX] != '*' && mapa[newPlayer.PlayerY + 1][newPlayer.PlayerX] != 'D') {
                newPlayer.PlayerY++; 
                system("cls");
                GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);
                PrintMap1(mapa);
            }
            break;
        case 'D':
        case 'd':
         
            if (mapa[newPlayer.PlayerY][newPlayer.PlayerX + 1] != '*' && mapa[newPlayer.PlayerY][newPlayer.PlayerX + 1] != 'D') {
                newPlayer.PlayerX++;
                system("cls"); 
                GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);
                PrintMap1(mapa);
            }
            break;
        case 'A':
        case 'a':
            if (mapa[newPlayer.PlayerY][newPlayer.PlayerX - 1] != '*' && mapa[newPlayer.PlayerY][newPlayer.PlayerX - 1] != 'D') {
                newPlayer.PlayerX--; 
                system("cls"); 
                GenerateMap1(mapa, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY);
                PrintMap1(mapa);
            }
            break;
        case 'I':
        case 'i':
            Interact();
            break;
        case 'P':
        case 'p':
            printf("Cheat ativado: Pulando para a proxima fase!\n");
            system("pause");
            system("cls");
            mapa2start();
        break;
        }
        if (mapa[newPlayer.PortaY][newPlayer.PortaX] == '=' && newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY) {
            printf("Parabens! Voce abriu a porta e concluiu a fase!\n");
            chavePega = false;
            system("pause");
            system("cls");
            mapa2start();
            
        }
    }
}
// função start mapa vila
void mapavstart() {
    
    newPlayer.hp = 3;

    newPlayer.PlayerX = 7;
    newPlayer.PlayerY = 1;

    newPlayer.NpcX = 9;
    newPlayer.NpcY = 1;
        
    newPlayer.ChaveX = 5;
    newPlayer.ChaveY = 8;

    newPlayer.PortaX = 7;
    newPlayer.PortaY = 7;

    GenerateMapv(mapav, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, newPlayer.NpcX, newPlayer.NpcY);

    char command;
    PrintMapv(mapav);
    // Mov Jogador
    while (1) {
        command = getch();

        switch (command) {
        case 'W':
        case 'w':
            if (mapav[newPlayer.PlayerY - 1][newPlayer.PlayerX] != '*' && mapav[newPlayer.PlayerY - 1][newPlayer.PlayerX] != 'D') {
                newPlayer.PlayerY--; 
                system("cls"); 
                GenerateMapv(mapav, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, newPlayer.NpcX, newPlayer.NpcY);
                PrintMapv(mapav);
            }
            break;
        case 'S':
        case 's':
            if (mapav[newPlayer.PlayerY + 1][newPlayer.PlayerX] != '*' && mapav[newPlayer.PlayerY + 1][newPlayer.PlayerX] != 'D') {
                newPlayer.PlayerY++; 
                system("cls"); 
                GenerateMapv(mapav, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, newPlayer.NpcX, newPlayer.NpcY);
                PrintMapv(mapav);
            }
            break;
        case 'D':
        case 'd':
            if (mapav[newPlayer.PlayerY][newPlayer.PlayerX + 1] != '*' && mapav[newPlayer.PlayerY][newPlayer.PlayerX + 1] != 'D') {
                newPlayer.PlayerX++; 
                system("cls"); 
                GenerateMapv(mapav, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, newPlayer.NpcX, newPlayer.NpcY);
                PrintMapv(mapav);
            }
            break;
        case 'A':
        case 'a':
           
            if (mapav[newPlayer.PlayerY][newPlayer.PlayerX - 1] != '*' && mapav[newPlayer.PlayerY][newPlayer.PlayerX - 1] != 'D') {
                newPlayer.PlayerX--; 
                system("cls"); 
                GenerateMapv(mapav, newPlayer.PlayerX, newPlayer.PlayerY, newPlayer.ChaveX, newPlayer.ChaveY, newPlayer.PortaX, newPlayer.PortaY, newPlayer.NpcX, newPlayer.NpcY);
                PrintMapv(mapav);
            }
            break;
        case 'I':
        case 'i':
            Interactv();
            break;
            case 'P':
            case 'p':
                printf("Cheat ativado: Pulando para a proxima fase!\n");
                system("pause");
                system("cls");
                mapa1start();
        break;
        }
        if (mapav[newPlayer.PortaY][newPlayer.PortaX] == '=' && newPlayer.PlayerX == newPlayer.PortaX && newPlayer.PlayerY == newPlayer.PortaY) {
            printf("Parabens! Voce abriu a porta e concluiu a fase!\n");
            chavePega = false;
            system("pause");
            system("cls");
            mapa1start();
            
        }
    }
}

int main() {
    int option;
    bool creditos = false;
    printf("\n\n");
    printf("\n*  #####  #                    #####   ##        #           #     #            #             ####                                       #    *");
    printf("\n*    #    #                    #        #        #                 #            #              #  #                                      #    *");
    printf("\n*    #    # ##    ###          #        #     ## #  # ##    ##    ####    ###   # ##           #  #   ###    ###    ###    ###   # ##   ####  *");
    printf("\n*    #    ##  #  #   #         ####     #    #  ##  ##  #    #     #     #   #  ##  #          #  #  #   #  #      #   #  #   #  ##  #   #    *");
    printf("\n*    #    #   #  #####         #        #    #   #  #        #     #     #      #   #          #  #  #####   ###   #      #####  #   #   #    *");
    printf("\n*    #    #   #  #             #        #    #  ##  #        #     #  #  #   #  #   #          #  #  #          #  #   #  #      #   #   #  # *");
    printf("\n*    #    #   #   ###          #####   ###    ## #  #       ###     ##    ###   #   #         ####    ###   ####    ###    ###   #   #    ##  *");
    printf("\n\n");                                                                                 
                                                        
    do {
        printf("\t1 - Jogar\n\t2 - Creditos\n\t3 - Sair\n");
        scanf("%d", &option);
        system("cls");

        switch (option) {
        case 1:
            PlayerSettingsBase();
            mapavstart();
            break;
        case 2:
            system("cls");
            PrintCreditos();
            if (!creditos) {
                creditos = true;
            }
            printf("\n\n"); 
            printf("\n*  #####  #                    #####   ##        #           #     #            #             ####                                       #    *");
            printf("\n*    #    #                    #        #        #                 #            #              #  #                                      #    *");
            printf("\n*    #    # ##    ###          #        #     ## #  # ##    ##    ####    ###   # ##           #  #   ###    ###    ###    ###   # ##   ####  *");
            printf("\n*    #    ##  #  #   #         ####     #    #  ##  ##  #    #     #     #   #  ##  #          #  #  #   #  #      #   #  #   #  ##  #   #    *");
            printf("\n*    #    #   #  #####         #        #    #   #  #        #     #     #      #   #          #  #  #####   ###   #      #####  #   #   #    *");
            printf("\n*    #    #   #  #             #        #    #  ##  #        #     #  #  #   #  #   #          #  #  #          #  #   #  #      #   #   #  # *");
            printf("\n*    #    #   #   ###          #####   ###    ## #  #       ###     ##    ###   #   #         ####    ###   ####    ###    ###   #   #    ##  *");                                                                                                                  
            printf("\n\n"); 
            break;
        case 3:
            sair();
            break;
        default:
            printf("Opçao invalida.");
            system("cls");
            printf("\n\n"); 
            printf("\n*  #####  #                    #####   ##        #           #     #            #             ####                                       #    *");
            printf("\n*    #    #                    #        #        #                 #            #              #  #                                      #    *");
            printf("\n*    #    # ##    ###          #        #     ## #  # ##    ##    ####    ###   # ##           #  #   ###    ###    ###    ###   # ##   ####  *");
            printf("\n*    #    ##  #  #   #         ####     #    #  ##  ##  #    #     #     #   #  ##  #          #  #  #   #  #      #   #  #   #  ##  #   #    *");
            printf("\n*    #    #   #  #####         #        #    #   #  #        #     #     #      #   #          #  #  #####   ###   #      #####  #   #   #    *");
            printf("\n*    #    #   #  #             #        #    #  ##  #        #     #  #  #   #  #   #          #  #  #          #  #   #  #      #   #   #  # *");
            printf("\n*    #    #   #   ###          #####   ###    ## #  #       ###     ##    ###   #   #         ####    ###   ####    ###    ###   #   #    ##  *");                                                                                                                  
            printf("\n\n"); 
        }
    } while (option != 3);

    getch();
    return 0;
}
