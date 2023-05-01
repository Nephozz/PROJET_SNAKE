#ifndef SP_JEU_H_INCLUDED
#define SP_JEU_H_INCLUDED
#include "mesTypes.h"

void init_snake(ST_PARAM_JEU *PT_param_jeu, ST_SNAKE *PT_snake);

void affiche_stade(ST_PARAM_JEU *PT_param_jeu);

void affiche_snake(ST_PARAM_JEU *param_jeu, ST_SNAKE *PT_snake);

void creer_pomme(ST_PARAM_JEU *PT_param_jeu, ST_POMME *PT_pomme);

void affiche_pomme(ST_PARAM_JEU *PT_param_jeu, ST_POMME *PT_pomme);

void affiche_score(ST_PARAM_JEU *PT_param_jeu, ST_JOUEUR *PT_joueur);

void evolution_snake(ST_PARAM_JEU *PT_param_jeu,ST_SNAKE *PT_snake, ST_POMME *PT_pomme, int touche);

void evolution_snake_2(ST_PARAM_JEU *PT_param_jeu,ST_SNAKE *PT_snake, ST_POMME *PT_pomme, int key);

int test_queue(ST_SNAKE *PT_snake);

void jeu(ST_PARAM_JEU *PT_param_jeu, ST_SNAKE *PT_snake, ST_JOUEUR *PT_joueur, FILE *scoreboard);

#endif // SP_JEU_H_INCLUDED