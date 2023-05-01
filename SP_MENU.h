#ifndef SP_MENU_H_INCLUDED
#define SP_MENU_H_INCLUDED
#include "mesTypes.h"

void accueil();

void init_parametre_jeu(ST_PARAM_JEU *PT_param_jeu);

const char* affichage_couleur(int int_couleur);

void modification_stade(ST_PARAM_JEU *PT_param_jeu);

void highscores(int scoreboard);

void menu_principal(ST_PARAM_JEU *PT_param_jeu, ST_SNAKE *PT_snake, ST_JOUEUR *PT_joueur, FILE *scoreboard);

#endif // SP_MENU_H_INCLUDED
