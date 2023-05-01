#include <stdio.h>
#include "myLib.h"
#include "mesTypes.h"
#include "SP_JEU.h"
#include "SP_SELECTION.h"
#include "SP_GESTION_JEU.h"
#include "SP_OPTIONS.h"

// Gere la partie menu de jeu Snake 2000

// TODO refaire le menu High scores

int SP_Gestion_Clavier();

//Affiche le bandeau d'acceuil du jeu
void accueil() {
    cls();

    setColor(WHITE);
    printf(" _____  _                                              _                 \n");
    printf("|  _  \\(_) ___ _ ____    _____ _ __  _   _  ___     __| | __ _ _ __  ___ \n");
    printf("| |_) /| |/ _ \\ '_ \\ \\  / / _ \\ '_ \\| | | |/ _ \\   / _` |/ _' | '_ \\/ __|\n");
    printf("| |_) \\| |  __/ | | \\ \\/ /  __/ | | | |_| |  __/  | (_| | (_| | | | \\__ \\ \n");
    printf("|_____/|_|\\___|_| |_|\\__/ \\___|_| |_|\\__,_|\\___|   \\__,_|\\__,_|_| |_|___/\n\n");

    gotoxy(1,40);
    printf("  ____             _              _\n");
    printf(" / ___) ___  _ __ | |_ _ __  ___ | | ___  ___    _                    ___HAUT\n");
    printf("| /    / _ \\| '_ \\| __| '__|/ _ \\| |/ _ \\/ __|  |_| 	             /\n");
    printf("| \\___| (_) | | | | |_| |  | (_) | |  __/\\__ \\   _                  [^]\n");
    printf(" \\____)\\___/|_| |_|\\__|_|   \\___/|_|\\___||___/  |_|    RETOUR____[<][v][>]____SELECTION\n");
    printf("					                             \\\n");
    printf("				                                      \\__BAS\n");

    gotoxy(1,7);
    setColor(GREEN);
    printf("          ######                 ####        ###      ###         ##    ######  \n");
    printf("       ##########   ######      #####     #######   ######      ###### ######## \n");
    printf("    ############    #######    #####    #########    ######   ###### #####      \n");
    printf("   ######          #########   #####    ####  ####     ########### #####        \n");
    printf("  #####             #### ####  #####   ####    ######## ########   ##### ####   \n");
    printf(" ################### ###  ########## #####  ########    #########    #####      \n");
    printf("             ####### ###    ####### #########   #####   ####  #####  ########## \n");
    printf("           ######## ####     ###    #####               ####   ###    ######    \n");
    printf("   #############                                                                \n");
    printf("   #########                                                                    \n");
    printf("            ####                                                                \n");
    printf("      ############             ######           #######           #######       \n");
    printf("      ##      ####          ###########       ##########       ###########      \n");
    printf("           ######         #######  #####    #######  #####    #######  ####     \n");
    printf("         ######          #####       ###   #####       ###   #####      ####    \n");
    printf("       #####             ###        ####   ###        ####   ###        ####    \n");
    printf("    ######               ###       #####   ###      ######  ####      #####     \n");
    printf("  #####################  ##############    ##############    #############      \n");
    printf("   #######                 #########         #########         #########        \n\n");
}

//Initialise les parametre du jeu
void init_parametre_jeu(ST_PARAM_JEU *PT_param_jeu) {
   PT_param_jeu->couleur_snake = GREEN;
   PT_param_jeu->couleur_stade = BLUE;
   PT_param_jeu->couleur_fond = BLACK;
   PT_param_jeu->difficulte = 2;
   PT_param_jeu->H_stade = 30;
   PT_param_jeu->L_stade = 60;
}

//Affiche la couleur en toute lettre
const char* affichage_couleur(int int_couleur) {
    /*- Noir    = 0
      - Bleu    = 1
      - Vert    = 2
      - Cyan    = 3
      - Rouge   = 4
      - Magenta = 5
      - Jaune   = 14
      - Blanc   = 15 */
    switch (int_couleur) {
        case 0:
            return "Noir";

        case 1:
            return "Bleu";

        case 2:
            return "Vert";

        case 3:
            return "Cyan";
        
        case 4:
            return "Rouge";

        case 5:
            return "Magenta";

        case 14:
            return "Jaune";

        case 15:
            return "Blanc";
        
        default:
            return "Erreur";
    }
}

//Modifie la taille du Stade avec une taille minimale de 10 x 20
void modification_stade(ST_PARAM_JEU *PT_param_jeu) {
    int saisie;

    printf("Hauteur du stade :");
    fflush(stdin);
    scanf("%i", &saisie);

    while (saisie < 10) {
        setColor(RED);
        printf("\nHauteur min 10");
        setColor(YELLOW);
        printf("\nHauteur du stade :");
        fflush(stdin);
        scanf("%i", &saisie);
    }

    PT_param_jeu->H_stade = saisie;

    printf("Longueur du stade :");
    fflush(stdin);
    scanf("%i", &saisie);

    while (saisie < 20) {
        setColor(RED);
        printf("\nLongueur min 20");
        setColor(YELLOW);
        printf("\nLongueur du stade :");
        fflush(stdin);
        scanf("%i", &saisie);
    }

    PT_param_jeu->L_stade = saisie;
}

//Affiche le scoreboard
void highscores(FILE *scoreboard) {
    int choix_sc = -1;
    int charactere_actuel = 0;

    while (choix_sc != 0) {
        accueil();
        setColor(WHITE);

        /*Test de l'existance du fichier*/
        if (scoreboard != NULL) {
            char nom[50];
            int score;
            printf("Nom\t Score\n\n");
            scoreboard = fopen("highscores.txt", "rt");
            while (charactere_actuel != EOF) {
                fscanf(scoreboard, "%s\t %i", &nom, &score);
                printf("%s\t %i\n", nom, score);
                charactere_actuel = getc(scoreboard);
            }
            fclose(scoreboard);
        } else {
            printf("Pas de score pour le moment\n");
        }

        printf("\n1 - Remise a zero des scores\n");
        printf("0 - Retour\n");
        printf("Votre choix :");
        fflush(stdin);
        scanf("%i", &choix_sc);

        if (choix_sc == 1) {
            char validation;
            printf("Etes vous sur de vouloir effacer le scoreboard ? (y/n)\n");
            fflush(stdin);
            scanf("%c", &validation);
            switch (validation) {
                case 'y':
                    scoreboard = fopen("highscores.txt", "w+");
                    fclose(scoreboard);
                    break;
                
                case 'n':
                    choix_sc = 0;
                    break;
                    
                default:
                    break;
            }
        }
    }
}
// FIXME regler le probleme d'affichage double du scoreboard

//Lance le menu principal du jeu
int menu_principal(ST_PARAM_JEU *PT_param_jeu, ST_SNAKE *PT_snake, ST_JOUEUR *PT_joueur, FILE *scoreboard) {
    int choix = -1;
    int clavier = -1;

    /*Initialisation du menu*/
    accueil();
    menu_t menu_principal_obj;
    const char label[][40] = {
        "Jouer",
        "Options",
        "High scores"
    };
    const char title[30] = {"Menu Principal"};
    init_menu(&menu_principal_obj, 3, WHITE, label, title, 26);

    while (choix != 0) {
        clavier = SP_Gestion_Clavier();

        if (clavier != -1) {
            selection_menu(&menu_principal_obj, clavier, &choix);

            /*Lance le jeu*/
            if (choix == 1) {
                jeu(PT_param_jeu, PT_snake, PT_joueur, scoreboard);
                break;
            }

            /*Rentre dans les options*/
            if (choix == 2) {
                options(PT_param_jeu);
                menu_principal(PT_param_jeu, PT_snake, PT_joueur, scoreboard);
                break;
            }

            /*Montre le scoreboard*/
            if (choix == 3) {
                highscores(scoreboard);
                menu_principal(PT_param_jeu, PT_snake, PT_joueur, scoreboard);
                break;
            }
        }
    }
    
    return 0;
}
// FIXME regler probleme retour menu apres plusieurs essais