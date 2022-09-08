# Dungenture

## Concept

petit jeu RPG textuel fait dans le language C.

## Fonctions

### General

- evenements aléatoires a chaque partie.
- 3 combats + 1 boss
- les 3 combats doit être fini avant de pouvoir faire le boss

### Joueur

- 100 PV
- 100 Mana
- Stats visibles a chaque tour.
- 1 épée
- 1 pouvoir, eventuellement boule de feu

### Combat

Les combats seront noté d'un titre "COMBAT"

- Tour par tour
- chaque combat sera +/- dur
- leurs dégâts varie en fonction de l'attaque
- le joueur emet un nombre de dégâts en fonction de son attaque
- possibilités d'esquive
- regeneration de santé -= 20 de mana et 1 tour
- regeneration de mana -= 1 tour
- coup critique possible
- chaque ennemies ont ~200 PV

### Evenements

Des evenements pourront être rencontrés pendant l'aventure. Ils seront noté par un titre "EVENEMENT" En voici la liste:

- Un objet scintillant attire ta curiosite, en le prenant tu ressent comme une chaleur dans ton corps, l’objet disparait, + 50 PV definitif.
- Sur votre chemin a travers une crevasse une lumiere scintille, en la traversant vous rencontrez un forgeron qui vous salut en frappant une épée encore chaude. ils vous proposent d’aiguiser votre lame pour vous aidez. Vous Acceptez. meilleurs degats obtenus (~+5 degats avec lame).
- Sur votre chemin un homme vous fait signe et decide de vous racontez une anecdote. "Je me souviens quand les mineurs travaillees ici, j'étais moi-même un mineur. en l'an 1410. Cette bonne époque me manque... fichu arraignée...". Après l'avoir ecouter il s'en va dans la direction oppose a la votre. Vous poursuivez votre chemin. (cela debloque un combat optionnel, une arraigné géante)
- (rare/très rare) sur votre chemin une sorcière apparaît devant vous et rigole de votre malheur, vous perdez confiance en vous, chance de passez votre tour lors des combats.

### Transition

Des transitions seront présente pour indiquer les stats du joueur. cette transition indiquera si l'on as perdu, si l'on as gagné un combat etc. Eventuellement le joueur pourra se regenerer du mana ou sa santé, cela engagera la suite directement autrement il devra écrire "continuer"

## Contrôles

Le jeu se jouera principalement en entrant des mots en guise d'action, chaque commande possible sera noté lors du moment présent:

- "Mana" - Generer du mana (-1 tour)
- "Sante" - Generer de la santé (-20 mana)
- "Attaque" - Attaquer l'ennemi
- "Feu" - Envoyer une boule de feu
- "Continuer" - Continuer la progression (lors des transition si le joueur décide de ne pas agir)
- "Commencer" - Démarrer votre aventure (au menu du jeu)
