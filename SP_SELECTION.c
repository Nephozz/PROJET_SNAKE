#include <stdio.h>
#include "SP_SELECTION.h"
#include "myLib.h"

//Permet de naviguer dans les menus avec les fleches directionnelles

// TODO creer les fonctions affichage menu

//Initialise le menu, sa taille, la position du curseur et les choix disponibles
void init_menu(menu_t *PT_menu, int size, int color, const char liste[][40], const char title[], int taille_bandeau) {
    PT_menu->color = color;
    PT_menu->size = size;
    PT_menu->taille_bandeau = taille_bandeau;
    PT_menu->cursor_pos = 0;
    for (int i = 0; i < PT_menu->size; i++) {
        for (int j = 0; j < 40; j++) { PT_menu->label[i][j] = liste[i][j]; }
        PT_menu->choice[i] = i + 1;
    }

    for (int i = 0; i<60; i++) { PT_menu->title[i] = title[i]; }

    setColor(PT_menu->color);
    gotoxy(1, 1 + PT_menu->taille_bandeau);
    printf("*** %s ***                             ", PT_menu->title);

    for (int i = 0; i < PT_menu->cursor_pos; i++) {
        gotoxy(1,i + 2 + PT_menu->taille_bandeau);
        printf("%s                              \n", PT_menu->label[i]);
    }

    gotoxy(1, PT_menu->cursor_pos + 2 + PT_menu->taille_bandeau);
    printf("-> %s                              \n", PT_menu->label[PT_menu->cursor_pos]);

    for (int i = PT_menu->cursor_pos + 1; i < PT_menu->size; i++) {
        gotoxy(1, i + 2 + PT_menu->taille_bandeau);
        printf("%s                             \n", PT_menu->label[i]);
    }

    printf("<-- Retour                      \n");
    for (int i = PT_menu->size + 1; i < PT_menu->size +5; i++) {
        gotoxy(1, i + 2 + PT_menu->taille_bandeau);
        printf("                             \n");
    }

    hidecursor();
}

//Gere la selection dans le menu 
void selection_menu(menu_t *PT_menu, int input, int *PT_selector) {
        switch (input) {
        /*Droite*/
        case 0:
            *PT_selector = PT_menu->choice[PT_menu->cursor_pos];
            break;
        
        /*Gauche*/
        case 1:
            *PT_selector = 0;
            break;

        /*Bas*/
        case 2:
            if (PT_menu->cursor_pos < PT_menu->size - 1) { PT_menu->cursor_pos += 1; }
            break;

        /*Haut*/
        case 3:
            if (PT_menu->cursor_pos > 0) { PT_menu->cursor_pos -= 1; }
            break;

        /*Pas de touche pressees*/
        default:
            break;
    }

    /*Affichage du menu avec curseur*/
    setColor(PT_menu->color);
    for (int i = 0; i < PT_menu->cursor_pos; i++) {
        gotoxy(1,i + 2 + PT_menu->taille_bandeau);
        printf("%s                             \n", PT_menu->label[i]);
    }

    gotoxy(1, PT_menu->cursor_pos + 2 + PT_menu->taille_bandeau);
    printf("-> %s                             \n", PT_menu->label[PT_menu->cursor_pos]);

    for (int i = PT_menu->cursor_pos + 1; i < PT_menu->size; i++) {
        gotoxy(1, i + 2 + PT_menu->taille_bandeau);
        printf("%s                             \n", PT_menu->label[i]);
    }

    hidecursor();
}

//Initialise le menu Y/N, la position du curseur et les choix disponibles
void init_menu_y_n(menu_t *PT_menu, int color, const char question[], int taille_bandeau) {
    PT_menu->color = color;
    PT_menu->size = 2;
    PT_menu->taille_bandeau = taille_bandeau;
    PT_menu->cursor_pos = 0;

    PT_menu->label[0][0], PT_menu->label[0][1], PT_menu->label[0][1] = 'O', 'u', 'i';
    PT_menu->label[1][0], PT_menu->label[1][1], PT_menu->label[1][1] = 'N', 'o', 'n';
    PT_menu->choice[0] = 1;
    PT_menu->choice[1] = 0;

    for (int i = 0; i<60; i++) { PT_menu->title[i] = question[i]; }

    setColor(PT_menu->color);
    gotoxy(1, 1 + PT_menu->taille_bandeau);
    printf("*** %s ***                             ", PT_menu->title);

    gotoxy(1, 2 + PT_menu->taille_bandeau);
    printf("-> Oui                             \n");
    printf("Non                             \n");

    for (int i = PT_menu->size + 1; i < PT_menu->size +8; i++) {
        gotoxy(1, i + 1 + PT_menu->taille_bandeau);
        printf("                                \n");
    }

    hidecursor();
}

//Gere la selection dans le menu Y/N
void selection_menu_y_n(menu_t *PT_menu, int input, int *PT_selector) {
    switch (input) {
        /*Droite*/
        case 0:
            *PT_selector = PT_menu->choice[PT_menu->cursor_pos];
            break;
        
        /*Gauche*/
        case 1:
            *PT_selector = 0;
            break;

        /*Bas*/
        case 2:
            if (PT_menu->cursor_pos < PT_menu->size - 1) { PT_menu->cursor_pos += 1; }
            break;

        /*Haut*/
        case 3:
            if (PT_menu->cursor_pos > 0) { PT_menu->cursor_pos -= 1; }
            break;

        /*Pas de touche pressees*/
        default:
            break;
    }

    setColor(PT_menu->color);
    if (PT_menu->cursor_pos == 0) {
        gotoxy(1, 2 + PT_menu->taille_bandeau);
        printf("-> Oui                             \n");
        printf("Non                             \n");
    } else {
        gotoxy(1, 2 + PT_menu->taille_bandeau);
        printf("Oui                             \n");
        printf("-> Non                             \n");
    }

    hidecursor();
}