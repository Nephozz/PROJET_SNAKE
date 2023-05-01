#include <stdio.h>
#include "myLib.h"
#include "mesTypes.h"
#include "SP_MENU.h"
#include "SP_GAME_OVER.h"
#include "SP_GESTION_JEU.h"

//Gere la partie jeu de Snake 2000

// TODO creer un mode sans mur
// TODO empecher le brisage de nuque

//Initialise la position et la taille du snake
void init_snake(ST_PARAM_JEU *PT_param_jeu, ST_SNAKE *PT_snake) {
    PT_snake->taille = 5;
    PT_snake->tete.x = PT_param_jeu->L_stade / 2;
    PT_snake->tete.y = PT_param_jeu->H_stade / 2;
    PT_snake->direction = 1;

    /* Exemple format du Snake (taille = 5):

        0| * | * | * | * | *
     tete|[4]|[3]|[2]|[1]|[0] */
    PT_snake->pos[PT_snake->taille - 1].x = PT_snake->tete.x + 1;
    PT_snake->pos[PT_snake->taille - 1].y = PT_snake->tete.y;

    for (int i = PT_snake->taille - 1; i >= 0; i--) {
        PT_snake->pos[i].x = PT_snake->pos[i + 1].x + 1;
        PT_snake->pos[i].y = PT_snake->pos[i + 1].y;
    }
}

//Affiche le stade ligne par ligne
void affiche_stade(ST_PARAM_JEU *PT_param_jeu) {
    for (int i = 1; i < PT_param_jeu->L_stade + 1; i++) {
        gotoxy(i,1);
        setColor(DARKGREY);
        printStadeElement();
    }

    for (int j = 2; j < PT_param_jeu->H_stade; j++) {
        gotoxy(1,j);
        setColor(DARKGREY);
        printStadeElement();

        for (int i = 2; i < PT_param_jeu->L_stade; i++) {
            gotoxy(i,j);
            setColor(PT_param_jeu->couleur_stade);
            printStadeElement();
        }

        gotoxy(PT_param_jeu->L_stade,j);
        setColor(DARKGREY);
        printStadeElement();
    }

    for (int i = 1; i < PT_param_jeu->L_stade + 1; i++) {
        gotoxy(i, PT_param_jeu->H_stade);
        setColor(DARKGREY);
        printStadeElement();
    }
}

//Affiche le serpent a l'ecran
void affiche_snake(ST_PARAM_JEU *PT_param_jeu, ST_SNAKE *PT_snake) {
    gotoxy(PT_snake->tete.x, PT_snake->tete.y);
    setColor(PT_param_jeu->couleur_snake);
    printSnakeHead();

    for (int i = PT_snake->taille - 1; i >= 0; i--) {
        gotoxy(PT_snake->pos[i].x, PT_snake->pos[i].y);
        printSnakeBody();
    }
}

//Creer la pomme de maniere pseudo aleatoire
void creer_pomme(ST_PARAM_JEU *PT_param_jeu, ST_POMME *PT_pomme) {
    PT_pomme->pos.x = (random() % (PT_param_jeu->L_stade - 3)) + 2;
    PT_pomme->pos.y = (random() % (PT_param_jeu->H_stade - 3)) + 2;
}

//Affiche la pomme
void affiche_pomme(ST_PARAM_JEU *PT_param_jeu, ST_POMME *PT_pomme) {
    setColor(PT_param_jeu->couleur_snake);
    gotoxy(PT_pomme->pos.x, PT_pomme->pos.y);
    printPomme();
}

//Affiche le score
void affiche_score(ST_PARAM_JEU *PT_param_jeu, ST_JOUEUR *PT_joueur) {
    gotoxy(1, PT_param_jeu->H_stade + 2);
    setColor(GREEN);
    printf("Score : %i\n", PT_joueur->score);
}

//Gere l'evolution du snake
void evolution_snake(ST_PARAM_JEU *PT_param_jeu,ST_SNAKE *PT_snake, ST_POMME *PT_pomme, int touche) {
    ST_POINT pos_temp;
    
    PT_snake->old_tail = PT_snake->pos[PT_snake->taille - 1];
    PT_snake->pos[PT_snake->taille - 1] = PT_snake->tete;

    switch (touche) {
    /*Deplacement a droite*/
    case 0:
        PT_snake->tete.x += 1;
        PT_snake->direction = 0;
        break;
    
    /*Deplacement a gauche*/
    case 1:
        PT_snake->tete.x -= 1;
        PT_snake->direction = 1;
        break;
    
    /*Deplacement en bas*/
    case 2:
        PT_snake->tete.y += 1;
        PT_snake->direction = 2;
        break;
    
    /*Deplacement en haut*/
    case 3:
        PT_snake->tete.y -= 1;
        PT_snake->direction = 3;
        break;
    
    /*Pas de changement de direction*/
    default:
        switch (PT_snake->direction) {
            case 0:
                PT_snake->tete.x += 1;
                break;
        
            case 1:
                PT_snake->tete.x -= 1;
                break;
            
            case 2:
                PT_snake->tete.y += 1;
                break;
            
            case 3:
                PT_snake->tete.y -= 1;
                break;
        }
        break;
    }

    /*Actualisation de la position de la queue*/
    for (int i = PT_snake->taille - 2; i >= 0; i--) {
            pos_temp = PT_snake->pos[i];
            PT_snake->pos[i] = PT_snake->old_tail;
            PT_snake->old_tail = pos_temp;
        }

    /*Refresh du jeu*/
    affiche_snake(PT_param_jeu, PT_snake);
    setColor(PT_param_jeu->couleur_stade);
    gotoxy(PT_snake->old_tail.x, PT_snake->old_tail.y);
    printStadeElement();
    msleep(200 / PT_param_jeu->difficulte);
}

//Test si le snake mange sa queue
int test_queue(ST_SNAKE *PT_snake) {
    for (int i = PT_snake->taille - 1; i >= 0; i--) {
        if (PT_snake->tete.x == PT_snake->pos[i].x && PT_snake->tete.y == PT_snake->pos[i].y) { return 1; }
    }

    return 0;
}

//Initialise et lance le jeu
void jeu(ST_PARAM_JEU *PT_param_jeu, ST_SNAKE *PT_snake, ST_JOUEUR *PT_joueur, FILE *scoreboard) {
    cls();
    PT_joueur->score = 0;
    ST_POMME pomme;
    hidecursor();
    init_snake(PT_param_jeu, PT_snake);
    affiche_stade(PT_param_jeu);
    affiche_snake(PT_param_jeu, PT_snake);
    creer_pomme(PT_param_jeu, &pomme);
    affiche_pomme(PT_param_jeu, &pomme);
    affiche_score(PT_param_jeu, PT_joueur);

    /*Le jeu s'arrete si le snake sort du stade*/
    while (PT_snake->tete.x < PT_param_jeu->L_stade && 
           PT_snake->tete.x > 1 && 
           PT_snake->tete.y < PT_param_jeu->H_stade && 
           PT_snake->tete.y > 1) {
        evolution_snake(PT_param_jeu, PT_snake, &pomme, SP_Gestion_Clavier());

        /*Test si le snake mange la pomme*/
        if (PT_snake->tete.x == pomme.pos.x && PT_snake->tete.y == pomme.pos.y) {
            /*Augmente le score en fonction de la dificulte*/
            PT_joueur->score += PT_param_jeu->difficulte;
            creer_pomme(PT_param_jeu, &pomme);
            affiche_pomme(PT_param_jeu, &pomme);
            PT_snake->taille += 1;
            affiche_score(PT_param_jeu, PT_joueur);
            printf("Taille du snake : %i\n", PT_snake->taille);
        }

        if (test_queue(PT_snake) == 1) { break; }

        /*Probleme de memoire, taille du snake limite a 30*/
        if (PT_snake->taille == 30) { break; }
    }

    game_over(PT_param_jeu, PT_snake, PT_joueur, scoreboard);
}