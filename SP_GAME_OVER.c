#include <stdio.h>
#include "myLib.h"
#include "SP_MENU.h"
#include "SP_JEU.h"
#include "mesTypes.h"
#include "SP_SELECTION.h"
#include "SP_GESTION_JEU.h"

//Gere le menu game over

int SP_Gestion_Clavier();

//Affiche le bandeau game over
void accueil_game_over() {
    cls();
    setColor(RED);

    printf("  ____                           _____                  \n");
    printf(" / ___)  __ _ _ __ ___   ___    / ___ \\ _    _ ___ _ __ \n");
    printf("| /   _ / _' | '_ ` _ \\ / _ \\  | /   \\ | \\  / / _ \\ '__)\n");
    printf("| \\__| | (_| | | | | | |  __/  | \\___/ |\\ \\/ /  __/ |   \n");
    printf(" \\_____/\\__,_|_| |_| |_|\\___|   \\_____/  \\__/ \\___|_|   \n");
}

//Sauvegarde le score et le nom du joueur si il le souhaite
void sauvegarde_score(ST_JOUEUR *PT_joueur, FILE *scoreboard) {
    char nom[] = "";
    int choix = -1;
    int clavier = -1;

    /*Initialisation du menu*/
    menu_t menu_sauvegarde;
    const char question[60] = {"Voulez vous enregistrer votre score ?"};
    init_menu_y_n(&menu_sauvegarde, WHITE, question, 6);

    while (choix != 0) {
        clavier = SP_Gestion_Clavier();

        gotoxy(1, 11);
        printf("Votre score est de %i", PT_joueur->score);

        if (clavier != -1) {
            selection_menu(&menu_sauvegarde, clavier, &choix);

            if (choix == 1) {
                printf("Entrez votre nom : ");
                fflush(stdin);
                scanf("%s", &nom);
                scoreboard = fopen("highscores.txt", "at");
                fprintf(scoreboard, "%s\t %i\n", nom, PT_joueur->score);
                fclose(scoreboard);
                break;
            }

            if (choix == 2) { choix = 0; }
        }
    }
}
// FIXME regler l'affichage du Oui/Non

//Game Over renvoie au menu principal ou relance une partie
void game_over(ST_PARAM_JEU *PT_param_jeu, ST_SNAKE *PT_snake, ST_JOUEUR *PT_joueur, FILE *scoreboard) {
    int choix = -1;
    int clavier = -1;

    accueil_game_over();
    sauvegarde_score(PT_joueur, scoreboard);

    /*Initialisation du menu*/
    menu_t menu_game_over;
    const char question[60] = {"Voulez vous rejouer ?"};
    init_menu_y_n(&menu_game_over, WHITE, question, 6);

    while (choix != 0) {
        clavier = SP_Gestion_Clavier();

        if (clavier != -1) {
            selection_menu_y_n(&menu_game_over, clavier, &choix);

            if (choix == 1) {
                jeu(PT_param_jeu, PT_snake, PT_joueur, scoreboard);
                break;
            }

            if (choix == 2) { choix = 0; }
        }
    }
    menu_principal(PT_param_jeu, PT_snake, PT_joueur, scoreboard);
}