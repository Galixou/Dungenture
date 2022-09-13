// Les différends package que j'ai utiliser dans mon jeu.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char  entry[10]; // Pour lire le mot que l'on entre.
float playerHealth, playerMana, enemyHealth; // Les variables du joueur et celui de l'ennemi.
// Les différends booléens. 0 = false et 1 = true
int   preciousObjectEncounter, preciousObjectLuck, forgeEncounter, forgeLuck, speakingManEncounter, spiderFightUnlocked, spiderFightWin, spiderFightWinned, bossFightUnlocked, bossFightWin, fight1, fight1Win, fight1Winned, fight2, fight2Win, fight2Winned, fight3, fight3Win, fight3Winned, startGame, playerTurn, playerDead;

// Affiche les stats du joueur.
void showStat()
{
    printf("Joueur:\n");
    printf("PV: %.1f\n", playerHealth);
    printf("Mana: %.1f\n\n", playerMana);
}

// Affichage des possibilités lors du combat.
void menuShow()
{
    printf("Attaque - Attaquer l'ennemi\n");
    printf("Feu - Envoyer une boule de feu (-50 mana)\n");
    printf("Sante - Generer de la sante (-20 mana)\n");
    printf("Mana - Generer du mana (-1 tour)\n\n");
}

// Il affiche l'écran de fin, si l'on fini le boss de fin alors on gagne sinon on perd.
int end()
{
    if (bossFightWin == 1)
    {
        system("cls");
        printf("FELICITATION !\n");
        printf("VOUS AVEZ GAGNE !\n\n");

        system("pause");
        return 0;
    }
    else
    {
        system("cls");
        printf("Vous avez perdu.\n\n");

        system("pause");
        return 0;
    }
}

/* Les combats fonctionnent sur un système de tour par tour, le joueur attaque toujours en 1er, le combat se termine lorsque le joueur bat l'ennemi.
Les ennemies sont de plus en plus coriace, notamment le boss et l'arraignée. Le joueur a quant a lui la possibilités de faire 4 choix. 
Ils sous la forme de 4 sous-programme: Attaque, feu, Sante et Mana. */

// Une simple attaque, si l'on as rencontré le forgeron alors les attaques sont améliorés.
int attack()
{
    /* Si l'on as rencontrés le forgeron alors nos attaques sont -25PV pour l'ennemi, 
    sinon on envoie -20PV a l'ennemi. On termine notre tour après cette attaque */

    if (forgeLuck == 1)
    {
        enemyHealth -= 25;
    }
    else
    {
        enemyHealth -= 20;
    }

    playerTurn = 0;
}

// Permet d'envoyer une boule de feu a l'ennemi contre du mana.
int fire()
{
    /* On vérifie que le joueur a 50 Mana, si c'est le cas alors on envoie -75PV a l'ennemi contre 50 Mana et on termine notre tour.
    Sinon on annule l'action et on demande une autre action.*/

    if (playerMana >= 50)
    {
        enemyHealth -= 75;
        playerMana -= 50;

        playerTurn = 0;
    }
    else
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }
}

// Il genere de la sante pour le joueur contre du mana.
int generateHealth()
{
    /* Si la santé est déjà a 100% alors on annule et on demande une autre action, sinon on vérifie qu'il a le mana suffisant (20 Mana).
    Si le joueur a le Mana suffisant alors on ajoute 35 PV et on retire 20 Mana, on vérifie que l'on dépasse pas le 100%, si c'est le cas
    alors on le remet au bon taux, si l'on as rencontré le forgeron alors le 100% est a 150PV sinon 100PV */

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
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
}

// Il genere du mana pour le joueur contre un tour.
int generateMana()
{
    /* Si le mana est déjà a 100% alors on annule l'action et on redemande une autre action sinon on ajout 35 Mana au joueur, 
    si cela depasse les 100% alors on le remet a 100%. */

    if (playerMana == 100)
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }
    else
    {
        playerMana += 35;

        if (playerMana >= 100)
        {
            playerMana = 100;
        }

        playerTurn = 0;
    }
}

// Le combat contre le 1er ennemi, 200PV et -10PV pour le joueur par attaque.
int enemy1()
{
    enemyHealth = 200;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("Tartan:\n");
    printf("PV: %.1f\n\n", enemyHealth);

    menuShow();

    while (enemyHealth > 0)
    {
        if(playerTurn == 1)
        {
            scanf("%s", &entry);

            if (strcmp(entry, "Attaque") == 0)
            {
                attack();
            }
            else if (strcmp(entry, "Feu") == 0)
            {
                fire();
            }
            else if (strcmp(entry, "Sante") == 0)
            {
                generateHealth();
            }
            else if (strcmp(entry, "Mana") == 0)
            {
                generateMana();
            }
            else
            {
                printf("\033[A\033[2K");
                scanf("%s", &entry);
            }
        }
        else
        {
            playerHealth -= 10;

            system("cls");

            printf("COMBAT\n\n");

            showStat();
            printf("Tartan:\n");
            printf("PV: %.1f\n\n", enemyHealth);

            menuShow();

            if (playerHealth <= 0)
            {
                playerHealth = 0;
                end();
            }

            playerTurn = 1;
        }
    }
    
    fight1 = 0;
    fight1Win = 1;
    fight1Winned = 1;
    system("cls");
    transition();
}

// Le combat contre le second ennemi, 200PV et -15PV pour le joueur par attaque.
int enemy2()
{
    enemyHealth = 200;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("Gargan:\n");
    printf("PV: %.1f\n\n", enemyHealth);

    menuShow();

    while (enemyHealth > 0)
    {
        if(playerTurn == 1)
        {
            scanf("%s", &entry);

            if (strcmp(entry, "Attaque") == 0)
            {
                attack();
            }
            else if (strcmp(entry, "Feu") == 0)
            {
                fire();
            }
            else if (strcmp(entry, "Sante") == 0)
            {
                generateHealth();
            }
            else if (strcmp(entry, "Mana") == 0)
            {
                generateMana();
            }
            else
            {
                printf("\033[A\033[2K");
                scanf("%s", &entry);
            }
        }
        else
        {
            playerHealth -= 15;

            system("cls");

            printf("COMBAT\n\n");

            showStat();
            printf("Gargan:\n");
            printf("PV: %.1f\n\n", enemyHealth);

            menuShow();

            if (playerHealth <= 0)
            {
                playerHealth = 0;
                end();
            }

            playerTurn = 1;
        }
    }
    
    fight2 = 0;
    fight2Win = 1;
    fight2Winned = 1;
    system("cls");
    transition();
}

// Le combat contre le 3ème ennemi, 200PV et -20PV pour le joueur par attaque.
int enemy3()
{
    enemyHealth = 200;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("Fransica:\n");
    printf("PV: %.1f\n\n", enemyHealth);

    menuShow();

    while (enemyHealth > 0)
    {
        if(playerTurn == 1)
        {
            scanf("%s", &entry);

            if (strcmp(entry, "Attaque") == 0)
            {
                attack();
            }
            else if (strcmp(entry, "Feu") == 0)
            {
                fire();
            }
            else if (strcmp(entry, "Sante") == 0)
            {
                generateHealth();
            }
            else if (strcmp(entry, "Mana") == 0)
            {
                generateMana();
            }
            else
            {
                printf("\033[A\033[2K");
                scanf("%s", &entry);
            }
        }
        else
        {
            playerHealth -= 20;

            system("cls");

            printf("COMBAT\n\n");

            showStat();
            printf("Fransica:\n");
            printf("PV: %.1f\n\n", enemyHealth);

            menuShow();

            if (playerHealth <= 0)
            {
                playerHealth = 0;
                end();
            }

            playerTurn = 1;
        }
    }

    fight3 = 0;
    fight3Win = 1;
    fight3Winned = 1;
    system("cls");
    transition();
}

// Le combat contre le boss, 300PV et -30PV pour le joueur par attaque.
int bossFight()
{
    enemyHealth = 300;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("BOSS:\n");
    printf("PV: %.1f\n\n", enemyHealth);

    menuShow();

    while (enemyHealth > 0)
    {
        if(playerTurn == 1)
        {
            scanf("%s", &entry);

            if (strcmp(entry, "Attaque") == 0)
            {
                attack();
            }
            else if (strcmp(entry, "Feu") == 0)
            {
                fire();
            }
            else if (strcmp(entry, "Sante") == 0)
            {
                generateHealth();
            }
            else if (strcmp(entry, "Mana") == 0)
            {
                generateMana();
            }
            else
            {
                printf("\033[A\033[2K");
                scanf("%s", &entry);
            }
        }
        else
        {
            playerHealth -= 30;

            system("cls");

            printf("COMBAT\n\n");

            showStat();
            printf("BOSS:\n");
            printf("PV: %.1f\n\n", enemyHealth);

            menuShow();

            if (playerHealth <= 0)
            {
                playerHealth = 0;
                end();
            }

            playerTurn = 1;
        }
    }
    
    bossFightWin = 1;
    system("cls");
    transition();
}

// Le combat contre l'arraignée, 250PV et -25PV pour le joueur par attaque.
int spiderFight()
{
    enemyHealth = 250;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("Arraignee:\n");
    printf("PV: %.1f\n\n", enemyHealth);

    menuShow();

    while (enemyHealth > 0)
    {
        if(playerTurn == 1)
        {
            scanf("%s", &entry);

            if (strcmp(entry, "Attaque") == 0)
            {
                attack();
            }
            else if (strcmp(entry, "Feu") == 0)
            {
                fire();
            }
            else if (strcmp(entry, "Sante") == 0)
            {
                generateHealth();
            }
            else if (strcmp(entry, "Mana") == 0)
            {
                generateMana();
            }
            else
            {
                printf("\033[A\033[2K");
                scanf("%s", &entry);
            }
        }
        else
        {
            playerHealth -= 25;

            system("cls");

            printf("COMBAT\n\n");

            showStat();
            printf("Arraignee:\n");
            printf("PV: %.1f\n\n", enemyHealth);

            menuShow();

            if (playerHealth <= 0)
            {
                playerHealth = 0;
                end();
            }

            playerTurn = 1;
        }
    }

    spiderFightUnlocked = 0;
    spiderFightWin = 1;
    spiderFightWinned = 1;
    system("cls");
    transition();
}

/* Etant donné que c'est un jeu textuel se basant sur des action et du roleplay alors j'ai créer un sous-programme qui permet
d'afficher la page correspondante en fonction des booléens. */

// Affichage de chaque écran, des différentes transitions entre chaque morceau de l'histoire
int transition()
{
    if (startGame == 1) // C'est l'écran de démarrage, pour introduire dans l'aventure qu'on va jouer.
    {
        printf("INTRODUCTION\n\n");
        showStat();
        printf("Vous entrez dans une grotte a l'entree detruite et abandonnee, avec votre epee et votre courage vous allez braver et conquerir ce donjon et le delivrer du mal.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            startGame = 0;
            preciousObjectEncounter = 1;
            transition();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (preciousObjectEncounter == 1) // C'est la rencontre avec l'objet precieux.
    {
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
            preciousObjectEncounter = 0;
            fight1 = 1;
            transition();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (forgeEncounter == 1) // C'est lorsqu'on rencontre le forgeron.
    {
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
            forgeEncounter = 0;
            fight2 = 1;
            transition();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (speakingManEncounter == 1) // C'est la rencontre avec l'homme qui nous raconte une anecdote.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Sur votre chemin un homme vous fait signe et decide de vous racontez une anecdote.\n");
        printf("\"Je me souviens quand les mineurs travaillees ici, j'etais moi-meme un mineur. en l'an 1410. Cette bonne epoque me manque... fichu arraignee...\"\n");
        printf("Apres l'avoir ecouter il s'en va dans la direction oppose a la votre. Vous poursuivez votre chemin.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            speakingManEncounter = 0;
            spiderFightUnlocked = 1;
            transition();

        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (fight1 == 1) // La transition vers le 1er combat de l'aventure.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Un 1er monstre apparait sur votre chemin et il se fait nommer \"Tartan\". Il ne vous laisse aucun choix et vous oblige a le battre.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            enemy1();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (fight1Winned == 1) // Lorsqu'on bat le 1er ennemi.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Ce 1er combat vous fatigua car vous avez sous-estimez la difficulter de cette grotte, cependant votre fierter et bon sens vous dit de continuer alors vous laissez le cadavre se vider de son sang contre le mur pour poursuivre l'aventure.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            fight1Winned = 0;
            forgeEncounter = 1;
            transition();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (fight2 == 1) // La transition vers le second combat de l'aventure.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("La terre se met a trembler et cela ne vous laisse aucun choix que de vous arretez. Un monstre creer un trou le sol et se hisse jusqu'a arriver sur ses pieds en vous soufflant un long grognement suivi d'un \"GARGAN JE SUIS!!\". Vous comprenez que vous allez devoir battre Gargan.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            enemy2();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (fight2Winned == 1) // Lorsqu'on bat le second ennemi.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Votre epee trancha le cou de votre adversaire aisement et la tete vit s'eclater sur la roche en laissant son corps tomber sur le sol dur et poussiereux avant de glisser mollement dans le trou par lequel il est sorti. Vous sautez par dessus et couvert de sang vous poursuivez.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            fight2Winned = 0;
            speakingManEncounter = 1;
            transition();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (fight3 == 1) // La transition vers le 3ème combat de l'aventure. 
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Un petit rire se fit entendre et vous marchez tranquillement tout en ecoutant une douce voix feminine murmurer \"Mes enfants... tu les as tuer...\". Pris d'un ennui vous baillez subitement ce qui la met en rogne silencieusement et en coupant vite la discution elle fit une explosion de terre et de roche en vous lancant froidement un \"meurt.\".\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            enemy3();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (fight3Winned == 1) // Lorsqu'on bat le 3ème ennemi.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("L'ennemie que vous avez vaincu s'en alla discretement en s'evaporant dans les roches du couloir, vous ne l'entendez plus et continuez votre chemin.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            fight3Winned = 0;
            bossFightUnlocked = 1;
            transition();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (bossFightUnlocked == 1) // Lorsqu'on débloque le Boss final.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Un frisson vous parcours le corps en entier et sans que vous le remarquez un amas noir vous bloque le passage, vous le percutez, reculez et un regard vide se pose sur vous. Une larme de sang coule de ses 2 yeux et il vous dit dans une langue que vous ne comprenez pas \"Liberos meos. Uxor mea. tu adjunge. Nunc.\".\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            bossFightUnlocked = 0;
            bossFight();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (bossFightWin == 1) // Lorsqu'on bat le Boss final.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Vous observez le corps geant tomber au sol lentement avant de creer un enorme bruit et de le voir disparaitre en poussiere, des cris retentits et le donjon que vous explorez commence a se detruire, vous decidez de fuir a pleine jambe en voyant les differents passages que vous avez decouvert se faire ensevellir par la poussiere et les debris. Vous arrivez a sortir a temps et vous regardez l'entree du donjon definitivement sceller. Le soleil eclatant fit resortir la poussiere sur votre peau et votre arme ensanglanter.\n\n");
        printf("Terminer - Terminer l'histoire\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Terminer") == 0)
        {
            system("cls");
            end();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (spiderFightUnlocked == 1) // La transition vers le combat avec l'arraignée.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Dans l'obscuriter qui vous entoure vous sentez quelque chose de mou et fileux sous vos pieds. Vous continuez avant de remarquer que l'amas mou et fileux devient de plus en plus epais et vous vous retrouvez confronter a une impasse, en faisant demi-tour vous voyez 8 enorme yeux vous fixer et 2 crocs suivis de petit gemissement d'insecte.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            spiderFight();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (spiderFightWinned == 1) // Lorsqu'on bat l'arraignée.
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("L'arraignee que vous avez vaincu lacha un fin soupir avant de s'ecrouler, vous l'enjambez et rebroussez chemin pour remarquer que vous vous etes tromper de direction, vous reprenez la bonne direction.\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            spiderFightWinned = 0;
            fight3 = 1;
            transition();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
}

int main()
{
    playerHealth = 100;
    playerMana = 100;


    printf("\nWelcome to Dungenture\n\n");
    printf("Commencer - Demarrer votre aventure\n\n");
    scanf("%s", &entry);

    if (strcmp(entry, "Commencer") == 0)
    {
        system("cls");
        startGame = 1;
        transition();
    }
    else
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }
}

