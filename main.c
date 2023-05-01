#include <stdio.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "SP_MENU.h"
#include "mesTypes.h"
#include "SP_JEU.h"

// *INSERT DESCRIPTION SNAKE 2000*

// TODO faire description du jeu

ST_PARAM_JEU param_jeu;
ST_SNAKE snake;
ST_JOUEUR joueur;
FILE *scoreboard;


int main() {
    setBackgroundColor(BLACK);
    setColor(WHITE);

    scoreboard = fopen("highscores.txt", "at");
    fclose(scoreboard);

    init_parametre_jeu(&param_jeu);

    menu_principal(&param_jeu, &snake, &joueur, scoreboard);
    
    return 0;
}