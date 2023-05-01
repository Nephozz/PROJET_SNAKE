#ifndef SP_SELECTION_H_INCLUDED
#define SP_SELECTION_H_INCLUDED

//Struct de menu
typedef struct {
    /*Nombre d'option*/
    int size;

    /*Nom de chaque option*/
    char label[10][40];

    /*Numéro de 'loption*/
    int choice[10];

    /*Position du curseur*/
    int cursor_pos;

    /*Couleur du menu*/
    int color;

    /*Titre du menu*/
    char title[60];

    /*Taille du bandeau au dessus du menu*/
    int taille_bandeau;
} menu_t;

void init_menu(menu_t *PT_menu, int size, int color, const char liste[][40], const char title[], int taille_bandeau);

void selection_menu(menu_t *PT_menu, int input, int *PT_selector);

void init_menu_y_n(menu_t *PT_menu, int color, const char question[], int taille_bandeau);

void selection_menu_y_n(menu_t *PT_menu, int input, int *PT_selector);

#endif // SP_SELECTION_H_INCLUDED