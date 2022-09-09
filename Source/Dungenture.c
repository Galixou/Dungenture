#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char  entry[10];
float playerHealth, playerMana;
float enemy1Health, enemy2Health, enemy3Health, bossHealth, spiderHealth;
int   transition1, preciousObjectEncounter, preciousObjectLuck, forgeEncounter, forgeLuck, speakingManEncounter, spiderFightUnlocked,  witchEncounter, witchUnluck, fight1, fight2, fight3, fight1Win, fight2Win, fight3Win, bossFightWin, startGame, playerTurn, playerDead;

int main()
{
    playerHealth = 100;
    playerMana = 100;


    printf("\nWelcome to Dungenture\n\n");
    printf("Commencer - Demarrer votre aventure\n\n");
    scanf("%s", &entry);

    while (strcmp(entry, "Commencer") != 0)
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }

    if (strcmp(entry, "Commencer") == 0)
    {
        system("cls");
        fight1 = 1;
    }

    if (transition1 == 1)
    {
        begining();
    }

    if(fight1 == 1)
    {
        enemy1();
    }

    if (preciousObjectEncounter == 1)
    {
        preciousObjectEvent();
    }

    if (speakingManEncounter == 1)
    {
        speakingManEvent();
    }

    if (forgeEncounter == 1)
    {
        forgeEvent();
    }
    
    if (witchEncounter == 1)
    {
        witchEvent();
    }

    /*if (spiderFightUnlocked == 1)
    {
        spiderFight();
    }*/
    
    if (playerDead == 1)
    {
        system("cls");
        printf("Vous avez perdu.\n\n");

        system("pause");
        return 0;
    }
    
    if (bossFightWin == 1)
    {
        system("cls");
        printf("FELICITATION !\n");
        printf("VOUS AVEZ GAGNE !\n\n");

        system("pause");
        return 0;
    }
}

void showStat()
{
    printf("Joueur:\n");
    printf("PV: %.1f\n", playerHealth);
    printf("Mana: %.1f\n\n", playerMana);
}

void begining()
{
    startGame = 0;

    printf("INTRODUCTION\n\n");
    showStat();
    printf("Vous entrez dans une grotte a l'entree detruite et abandonnee, avec votre epee et votre courage vous allez braver et conquerir ce donjon et le delivrer du mal.\n\n");
    printf("Continuer - Continuer la progression\n\n");
    scanf("%s", &entry);

    if(strcmp(entry, "Continuer") == 0)
    {
        system("cls");
    }
    else
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }
}

void preciousObjectEvent()
{
    preciousObjectEncounter = 0;

    printf("EVENEMENT\n\n");
    showStat();
    printf("Un objet scintillant attire votre curiosite, en le prenant tu ressent comme une chaleur dans ton corps, l'objet disparait.\n");
    printf("+50 PV definitif.\n\n");
    preciousObjectLuck = 1;
    playerHealth += 50;
    printf("Continuer - Continuer la progression\n\n");
    scanf("%s", &entry);

    if(strcmp(entry, "Continuer") == 0)
    {
        system("cls");
        speakingManEncounter = 1;
    }
    else
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }
}

void forgeEvent()
{
    forgeEncounter = 0;

    printf("EVENEMENT\n\n");
    showStat();
    printf("Sur votre chemin a travers une crevasse une lumiere scintille, en la traversant vous rencontrez un forgeron qui vous salut en frappant une epee encore chaude.\n");
    printf("Ils vous proposent d'aiguiser votre lame pour vous aidez. Vous acceptez.\n");
    printf("Degats ameliores.\n\n");
    forgeLuck = 1;
    printf("Continuer - Continuer la progression\n\n");
    scanf("%s", &entry);

    if(strcmp(entry, "Continuer") == 0)
    {
        system("cls");
        witchEncounter = 1;
    }
    else
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }
}

void speakingManEvent()
{
    speakingManEncounter = 0;

    printf("EVENEMENT\n\n");
    showStat();
    printf("Sur votre chemin un homme vous fait signe et decide de vous racontez une anecdote.\n");
    printf("\"Je me souviens quand les mineurs travaillees ici, j'etais moi-meme un mineur. en l'an 1410. Cette bonne epoque me manque... fichu arraignee...\"\n");
    printf("Apres l'avoir ecouter il s'en va dans la direction oppose a la votre. Vous poursuivez votre chemin.\n\n");
    spiderFightUnlocked = 1;
    printf("Continuer - Continuer la progression\n\n");
    scanf("%s", &entry);

    if(strcmp(entry, "Continuer") == 0)
    {
        system("cls");
        forgeEncounter = 1;
    }
    else
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }
}

void witchEvent()
{
    witchEncounter = 0;

    printf("EVENEMENT\n\n");
    showStat();
    printf("Vous croisez une sorciere qui apparait devant vous et rigole de votre malheur, vous perdez confiance en vous.\n");
    printf("Chance de passer votre tour lors des combats.\n\n");
    witchUnluck = 1;
    printf("Continuer - Continuer la progression\n\n");
    scanf("%s", &entry);

    if(strcmp(entry, "Continuer") == 0)
    {
        system("cls");
    }
    else
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }
}

void enemy1()
{
    fight1 = 0;

    enemy1Health = 200;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("Ennemi:\n");
    printf("PV: %.1f\n\n", enemy1Health);

    menuShow();

    while (enemy1Health > 0)
    {
        if(playerTurn == 1)
        {
            scanf("%s", &entry);

            if (strcmp(entry, "Attaque") == 0)
            {
                if (preciousObjectLuck == 1)
                {
                    enemy1Health -= 25;
                }
                else
                {
                    enemy1Health -= 20;
                }

                playerTurn = 0;
            }
            else if (strcmp(entry, "Feu") == 0)
            {
                if (playerMana >= 50)
                {
                    enemy1Health -= 75;
                    playerMana -= 50;

                    playerTurn = 0;
                }
                else
                {
                    printf("\033[A\033[2K");
                    scanf("%s", &entry);
                }
            }
            else if (strcmp(entry, "Sante") == 0)
            {
                if (playerHealth == 100 || playerHealth == 150)
                {
                    printf("\033[A\033[2K");
                    scanf("%s", &entry);
                }
                else
                {
                    if (playerMana > 20)
                    {
                        playerHealth += 35;
                        playerMana -= 20;

                        if (preciousObjectLuck == 1)
                        {
                            if (playerHealth >= 150)
                            {
                                playerHealth = 150;
                            }
                        }
                        else
                        {
                            if (playerHealth >= 100)
                            {
                                playerHealth = 100;
                            }
                        }

                        playerTurn = 0;
                    }
                }
            }
            else if (strcmp(entry, "Mana") == 0)
            {
                if (playerMana == 100)
                {
                    printf("\033[A\033[2K");
                    scanf("%s", &entry);
                }
                else
                {
                    playerMana += 35;
                    playerTurn = 0;

                    if (playerMana >= 100)
                    {
                        playerMana = 100;
                    }
                }
            }
            else
            {
                printf("\033[A\033[2K");
                scanf("%s", &entry);
            }
        }
        else
        {
            playerHealth -= 100;

            system("cls");

            printf("COMBAT\n\n");

            showStat();
            printf("Ennemi:\n");
            printf("PV: %.1f\n\n", enemy1Health);

            menuShow();

            playerTurn = 1;
        }
    }

    if (playerHealth < 0)
    {
        playerDead = 1;
        playerHealth = 0;
    }
    
    fight1Win = 1;
}

void menuShow()
{
    printf("Attaque - Attaquer l'ennemi\n");
    printf("Feu - Envoyer une boule de feu (-50 mana)\n");
    printf("Sante - Generer de la sante (-20 mana)\n");
    printf("Mana - Generer du mana (-1 tour)\n\n");
}
