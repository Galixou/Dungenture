#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char entry[10];
    float playerHealth, playerMana;
    float enemy1Health, enemy2Health, enemy3Health, bossHealth, spiderHealth;
    int   preciousObjectEncounter, preciousObjectLuck, forgeEncounter, forgeLuck, speakingManEncounter, spiderFightUnlocked,  witchEncounter, witchUnluck, fight1, fight2, fight3, fight1Win, fight2Win, fight3Win, bossFightWin, inTransition1, inCombat, inEvent, playerTurn;

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
        inTransition1 = 1;
    }

    if (inTransition1 == 1)
    {
        inTransition1 = 0;

        printf("Vous entrez dans une grotte a l'entree detruite et abandonnee, avec votre epee et votre courage vous allez braver et conquerir ce donjon et le delivrer du mal.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        while(strcmp(entry, "Continuer") != 0)
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            preciousObjectEncounter = 1;
        }
    }

    if (preciousObjectEncounter == 1)
    {
        preciousObjectEncounter = 0;

        printf("Un objet scintillant attire votre curiosite, en le prenant tu ressent comme une chaleur dans ton corps, l'objet disparait.\n");
        printf("+50 PV definitif.\n\n");
        preciousObjectLuck = 1;
        playerHealth += 50;
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        while(strcmp(entry, "Continuer") != 0)
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            speakingManEncounter = 1;
        }
    }

    if (speakingManEncounter == 1)
    {
        speakingManEncounter = 0;

        printf("Sur votre chemin un homme vous fait signe et decide de vous racontez une anecdote.\n");
        printf("\"Je me souviens quand les mineurs travaillees ici, j'etais moi-meme un mineur. en l'an 1410. Cette bonne epoque me manque... fichu arraignee...\"\n");
        printf("Apres l'avoir ecouter il s'en va dans la direction oppose a la votre. Vous poursuivez votre chemin.\n\n");
        spiderFightUnlocked = 1;
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        while(strcmp(entry, "Continuer") != 0)
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            forgeEncounter = 1;
        }
    }

    if (forgeEncounter == 1)
    {
        forgeEncounter = 0;

        printf("Sur votre chemin a travers une crevasse une lumiere scintille, en la traversant vous rencontrez un forgeron qui vous salut en frappant une epee encore chaude.\n");
        printf("Ils vous proposent d'aiguiser votre lame pour vous aidez. Vous acceptez.\n");
        printf("Degats ameliores.\n\n");
        forgeLuck = 1;
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        while(strcmp(entry, "Continuer") != 0)
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            witchEncounter = 1;
        }
    }
    
    if (witchEncounter == 1)
    {
        witchEncounter = 0;

        printf("Sur votre chemin une sorciere apparait devant vous et rigole de votre malheur, vous perdez confiance en vous.\n");
        printf("Chance de passer votre tour lors des combats.\n\n");
        witchUnluck = 1;
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        while(strcmp(entry, "Continuer") != 0)
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            bossFightWin = 1;
        }
    }
    
    if (bossFightWin == 1)
    {
        printf("FELICITATION !\n");
        printf("VOUS AVEZ GAGNE !\n\n");

        system("pause");
        return 0;
    }
    else
    {
        printf("Vous avez perdu.\n\n");

        system("pause");
        return 0;
    }
}