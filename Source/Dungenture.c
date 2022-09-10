#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char  entry[10];
float playerHealth, playerMana;
float enemy1Health, enemy2Health, enemy3Health, bossHealth, spiderHealth;
int   preciousObjectEncounter, preciousObjectLuck, forgeEncounter, forgeLuck, speakingManEncounter, spiderFightUnlocked, bossFightUnlocked, witchEncounter, witchUnluck, fight1, fight2, fight3, fight1Win, fight2Win, fight3Win, bossFightWin, startGame, playerTurn, playerDead, spiderFightWin;

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

    if (fight1 == 1)
    {
        transition();
    }
    else if (fight2 == 1)
    {
        transition();
    }
    else if (fight3 == 1)
    {
        transition();
    }
    else if (fight1Win == 1 && fight2Win ==1 && fight3Win == 1)
    {
        bossFightUnlocked = 1;
        transition();
    }
    else if (spiderFightUnlocked == 1)
    {
        transition();
    }
}

void showStat()
{
    printf("Joueur:\n");
    printf("PV: %.1f\n", playerHealth);
    printf("Mana: %.1f\n\n", playerMana);
}

void enemy1()
{
    enemy1Health = 200;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("Tartan:\n");
    printf("PV: %.1f\n\n", enemy1Health);

    menuShow();

    while (enemy1Health > 0)
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
            printf("PV: %.1f\n\n", enemy1Health);

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
    transition();
}

void enemy2()
{
    enemy2Health = 200;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("Gargan:\n");
    printf("PV: %.1f\n\n", enemy2Health);

    menuShow();

    while (enemy2Health > 0)
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
            printf("PV: %.1f\n\n", enemy2Health);

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
    transition();
}

void enemy3()
{
    enemy3Health = 200;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("Fransica:\n");
    printf("PV: %.1f\n\n", enemy3Health);

    menuShow();

    while (enemy3Health > 0)
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
            printf("PV: %.1f\n\n", enemy3Health);

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
    transition();
}

void bossFight()
{
    bossHealth = 300;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("BOSS:\n");
    printf("PV: %.1f\n\n", bossHealth);

    menuShow();

    while (bossHealth > 0)
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
            printf("PV: %.1f\n\n", bossHealth);

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
    transition();
}

void spiderFight()
{
    spiderHealth = 250;
    playerTurn = 1;

    printf("COMBAT\n\n");

    showStat();
    printf("Arraignee:\n");
    printf("PV: %.1f\n\n", spiderHealth);

    menuShow();

    while (spiderHealth > 0)
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
            printf("PV: %.1f\n\n", spiderHealth);

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
    transition();
}

void menuShow()
{
    printf("Attaque - Attaquer l'ennemi\n");
    printf("Feu - Envoyer une boule de feu (-50 mana)\n");
    printf("Sante - Generer de la sante (-20 mana)\n");
    printf("Mana - Generer du mana (-1 tour)\n\n");
}

void attack()
{
    if (preciousObjectLuck == 1)
    {
        if (fight1 == 1)
        {
            enemy1Health -= 25;
        }
        else if (fight2 == 1)
        {
            enemy2Health -= 25;
        }
        else if (fight3 == 1)
        {
            enemy3Health -= 25;
        }
        else if (spiderFightUnlocked == 1)
        {
            spiderHealth -= 25;
        }
        else
        {
            bossHealth -= 25;
        }
    }
    else
    {
        if (fight1 == 1)
        {
            enemy1Health -= 20;
        }
        else if (fight2 == 1)
        {
            enemy2Health -= 20;
        }
        else if (fight3 == 1)
        {
            enemy3Health -= 20;
        }
        else if (spiderFightUnlocked == 1)
        {
            spiderHealth -= 20;
        }
        else
        {
            bossHealth -= 20;
        }
    }

    playerTurn = 0;
}

void fire()
{
    if (playerMana >= 50)
    {
        if (fight1 == 1)
        {
            enemy1Health -= 75;
        }
        else if (fight2 == 1)
        {
            enemy2Health -= 75;
        }
        else if (fight3 == 1)
        {
            enemy3Health -= 75;
        }
        else if (spiderFightUnlocked == 1)
        {
            spiderHealth -= 75;
        }
        else
        {
            bossHealth -= 75;
        }

        playerMana -= 50;

        playerTurn = 0;
    }
    else
    {
        printf("\033[A\033[2K");
        scanf("%s", &entry);
    }
}

void generateHealth()
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

void generateMana()
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

void end()
{
    system("cls");
    printf("Vous avez perdu.\n\n");

    system("pause");
    return 0;

    if (bossFightWin == 1)
    {
        system("cls");
        printf("FELICITATION !\n");
        printf("VOUS AVEZ GAGNE !\n\n");

        system("pause");
        return 0;
    }
}

void transition()
{
    if (startGame == 1)
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

        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (preciousObjectEncounter == 1)
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
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (forgeEncounter == 1)
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

        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (speakingManEncounter == 1)
    {
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
            speakingManEncounter = 0;

        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (witchEncounter == 1)
    {
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
            witchEncounter = 0;
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (fight1 == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Un 1er monstre apparait sur votre chemin et il se fait nommé \"Tartan\". Il ne vous laisse aucun choix et vous oblige a le battre.\n\n");
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
    else if (fight1Win == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Ce 1er combat vous fatigua et vous avez sous-estimez la difficulter de cette grotte, cependant votre fierter et bon sens vous dit de continuer alors vous laissez le cadavre se vider de son sang contre le mur pour poursuivre l'aventure.\n\n");
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
    else if (fight2 == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("La terre se met a trembler et cela ne vous laisse aucun choix que de vous arretez. Un monstre trou le sol et se hisse jusqu'a arriver sur ses pieds en vous soufflant un long grognement suivi d'un \"GARGAN JE SUIS!!\". Vous comprenez que vous allez devoir battre Gargan.\n\n");
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
    else if (fight2Win == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Votre epee trancha le cou de votre adversaire aisement et la tete vit s'eclater sur la roche en laissant son corps tomber sur le sol dur et poussiereux avant de glisser mollement dans le trou par lequel il est sorti. Vous sautez par dessus et couvert de sang vous poursuivez.\n\n");
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
    else if (fight3 == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Un petit rire se fit entendre et vous marchez tranquillement tout en ecoutant une douce voix feminine murmurer \"Mes enfants... tu les as tués...\". Pris d'un ennui vous baillez subitement ce qui la met en rogne silencieusement et en coupant vite la discution elle fit une explosion de terre et de roche en vous lancant froidement un \"meurt.\".\n\n");
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
    else if (fight3Win == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("L'ennemie que vous avez vaincu s'en alla discretement en s'evaporant dans les roches du couloir, vous ne l'entendez plus et continuez votre chemin.\n\n");
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
    else if (bossFightUnlocked == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Un frison vous parcours le corps en entier et sans que vous le remarquez un amas noir vous bloque le passage, vous le percutez, reculez et un regard vite se pose sur vous. Une larme de sang coule de ses 2 oeils et ils vous dit dans une langue que vous ne comprenez pas \"Liberos meos. Uxor mea. tu adjunge. Nunc.\".\n\n");
        printf("Continuer - Continuer la progression\n\n");
        scanf("%s", &entry);

        if(strcmp(entry, "Continuer") == 0)
        {
            system("cls");
            bossFight();
        }
        else
        {
            printf("\033[A\033[2K");
            scanf("%s", &entry);
        }
    }
    else if (bossFightWin == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Vous observez le corps geant tomber au sol lentement avant de creer un enorme bruit et de le voir disparaitre en poussiere, des cris retentits et le donjon que vous explorez commence a se detruire, vous decidez de fuir a pleine jambe en voyant les différents passages que vous avez découvert se faire ensevellir par la poussiere et les debris. Vous arrivez a sortir a temps et vous regardez l'entree du donjon definitivement sceller. Le soleil eclatant fit resortir la poussiere sur votre peau et votre arme ensanglantée.\n\n");
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
    else if (spiderFightUnlocked == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("Dans l'obscurité qui vous entoure vous sentez quelque chose de mou et fileux sous vos pieds. Vous continuez avant de remarquer que l'amas mou et fileux devient de plus en plus epais et vous vous retrouvez confronter a une impasse, en faisant demi-tour vous voyez 8 enorme yeux vous fixer et 2 crocs suivis de petit gemissement d'insecte.\n\n");
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
    else if (spiderFightWin == 1)
    {
        printf("EVENEMENT\n\n");
        showStat();
        printf("L'arraignee que vous avez vaincu lacha un fin soupir avant de s'écrouler, vous l'enjambez et rebroussez chemin pour remarquer que vous vous etes tromper de direction, vous reprenez la bonne direction.\n\n");
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
}