#ifndef SP_GAME_OVER_H_INCLUDED
#define SP_GAME_OVER_H_INCLUDED
#include "mesTypes.h"

void sauvegarde_score(ST_JOUEUR *PT_joueur, FILE *scoreboard);

void game_over(ST_PARAM_JEU *PT_param_jeu, ST_SNAKE *PT_snake, ST_JOUEUR *PT_joueur, FILE *scoreboard);

#endif // SP_GAME_OVER_H_INCLUDED