#include <stdio.h>
#include "myLib.h"
#include "mesTypes.h"
#include "SP_MENU.h"
#include "SP_SELECTION.h"
#include "SP_GESTION_JEU.h"

//Gere le menu options ainsi que ses sous menus

//Lance le menu de selection de le couleur du snake
void menu_couleur_snake(ST_PARAM_JEU *PT_param_jeu) {
    int choix = -1;
    int clavier = -1;

    /*Initialisation du menu*/
    menu_t menu_couleur_snake_obj;
    const char label[][40] = {
        "Noir", 
        "Bleu",
        "Vert",
        "Cyan",
        "Rouge",
        "Magenta",
        "Jaune",
        "Blanc" 
    };
    const char title[60] ={"Couleur Snake"};
    init_menu(&menu_couleur_snake_obj, 8, YELLOW, label, title, 26);
    /*- Noir    = 0
      - Bleu    = 1
      - Vert    = 2
      - Cyan    = 3
      - Rouge   = 4
      - Magenta = 5
      - Jaune   = 14
      - Blanc   = 15 */
    
    while (choix != 0) {
        clavier = SP_Gestion_Clavier();

        if (clavier != -1) {
            selection_menu(&menu_couleur_snake_obj, clavier, &choix);

            if (choix <= 8 && choix >= 1) {
                PT_param_jeu->couleur_snake = choix - 1;
                choix = 0;
            } 

            if (choix == 7 || choix == 8) {
                PT_param_jeu->couleur_snake = choix + 7;
                choix = 0;
            }

            if (choix == PT_param_jeu->couleur_stade) {
                setColor(RED);
                printf("Erreur, le snake ne peut pas etre de la meme couleur que le stade!\n");
            }
        }
    }
}

//Lance le menu de selection de la couleur du stade
void menu_couleur_stade(ST_PARAM_JEU *PT_param_jeu) {
    int choix = -1;
    int clavier = -1;

    /*Initialisation du menu*/
    menu_t menu_couleur_stade_obj;
    const char label[][40] = {
        "Noir", 
        "Bleu",
        "Vert",
        "Cyan",
        "Rouge",
        "Magenta",
        "Jaune",
        "Blanc"
    };
    const char title[60] ={"Couleur Stade"};
    init_menu(&menu_couleur_stade_obj, 8, YELLOW, label, title, 26);
    /*- Noir    = 0
      - Bleu    = 1
      - Vert    = 2
      - Cyan    = 3
      - Rouge   = 4
      - Magenta = 5
      - Jaune   = 14
      - Blanc   = 15 */
    
    while (choix != 0) {
        clavier = SP_Gestion_Clavier();

        if (clavier != -1) {
            selection_menu(&menu_couleur_stade_obj, clavier, &choix);

            if (choix <= 8 && choix >= 1) {
                PT_param_jeu->couleur_stade = choix - 1;
                choix = 0;
            } 

            if (choix == 7 || choix == 8) {
                PT_param_jeu->couleur_stade = choix + 7;
                choix = 0;
            }

            if (choix == PT_param_jeu->couleur_snake) {
                setColor(RED);
                printf("Erreur, le stade ne peut pas etre de la meme couleur que le snake!\n");
            }
        }
    }
}

//Lance le menu de selection de la difficulte
void menu_difficulte(ST_PARAM_JEU *PT_param_jeu) {
    int choix = -1;
    int clavier = -1;
    
    /*Iniatialisation menu*/
    menu_t menu_difficulte_obj;
    const char label[][40] = {
        "Facile",
        "Normal",
        "Dur sa mere !"
    };
    const char title[60] = {"Dificulte"};
    init_menu(&menu_difficulte_obj, 3, YELLOW, label, title, 26);

    while (choix != 0 ) {
        clavier = SP_Gestion_Clavier();

        if (clavier != -1) {
            selection_menu(&menu_difficulte_obj, clavier, &choix);

            if (choix <= 3 && choix > 0) {
                PT_param_jeu->difficulte = choix;
                choix = 0;
            }
        }
    }
}

//Lance le menu de selection de la couleur du fond
void menu_couleur_fond(ST_PARAM_JEU *PT_param_jeu) {
    int choix = -1;
    int clavier = -1;

    /*Initialisation du menu*/
    menu_t menu_couleur_fond_obj;
    const char label[][40] = {
        "Noir", 
        "Bleu",
        "Vert",
        "Cyan",
        "Rouge",
        "Magenta",
        "Jaune",
        "Blanc"
    };
    const char title[60] ={"Couleur Fond"};
    init_menu(&menu_couleur_fond_obj, 8, YELLOW, label, title, 26);
    /*- Noir    = 0
      - Bleu    = 1
      - Vert    = 2
      - Cyan    = 3
      - Rouge   = 4
      - Magenta = 5
      - Jaune   = 14
      - Blanc   = 15 */
    
    while (choix != 0) {
        clavier = SP_Gestion_Clavier();

        if (clavier != -1) {
            selection_menu(&menu_couleur_fond_obj, clavier, &choix);

            if (choix <= 8 && choix >= 1) {
                PT_param_jeu->couleur_fond = choix - 1;
                choix = 0;
            } 

            if (choix == 7 || choix == 8) {
                PT_param_jeu->couleur_fond = choix + 7;
                choix = 0;
            }
        }
    }
}

//Affiche les parametres selectionnes
void affiche_options(ST_PARAM_JEU *PT_param_jeu) {
    gotoxy(26, 26 + 2);
    printf("%s\n", affichage_couleur(PT_param_jeu->couleur_snake));

    gotoxy(26, 26 + 3);
    printf("%s\n", affichage_couleur(PT_param_jeu->couleur_stade));

    gotoxy(26, 26 + 4);
    printf("%i\n", PT_param_jeu->difficulte);

    gotoxy(26, 26 + 5);
    printf("%i x %i\n", PT_param_jeu->H_stade, PT_param_jeu->L_stade);
    
    gotoxy(26, 26 + 6);
    printf("%s\n", affichage_couleur(PT_param_jeu->couleur_fond));
}

//Lance le menu option
void options(ST_PARAM_JEU *PT_param_jeu) {
    int choix = -1;
    int clavier = -1;

    /*Initialisation du menu*/
    menu_t menu_options;
    const char label[][40] = {
        "Couleur du serpent :",
        "Couleur du stade :",
        "Difficulte :",
        "Taille stade :",
        "Couleur du fond :"
    };
    const char title[60] = {"Options"};
    init_menu(&menu_options, 5, YELLOW, label, title, 26);
    affiche_options(PT_param_jeu);

    while (choix != 0) {
        clavier = SP_Gestion_Clavier();

        if (clavier != -1) {
            selection_menu(&menu_options, clavier, &choix);
            affiche_options(PT_param_jeu);

            /*Menu choix couleur snake qui doit etre differente de celle du stade*/
            if (choix == 1) {
                menu_couleur_snake(PT_param_jeu);
                options(PT_param_jeu);
                break;
            }

            /*Menu choix couleur stade*/
            if (choix == 2) {
                menu_couleur_stade(PT_param_jeu);
                options(PT_param_jeu);
                break;
            }

            /*Menu choix difficulte
            Plus la difficulte est eleve et plus le snake est rapide. 
            Mais le score gagner est aussi plus eleve. */
            if (choix == 3) {
                menu_difficulte(PT_param_jeu);
                options(PT_param_jeu);
                break;
            }

            /*Menu choix taille stade*/
            if (choix == 4) {
                modification_stade(PT_param_jeu);
                options(PT_param_jeu);
                break;
            }

            /*Menu choix couleur du fond*/
            if (choix == 5) {
                menu_couleur_fond(PT_param_jeu);
                setBackgroundColor(PT_param_jeu->couleur_fond);
                options(PT_param_jeu);
                break;
            }
        }
    }
}