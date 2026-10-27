# Push_swap

![Screenshot Sorting visualiser](assets/images/Sorting_Visualizer.tiff)

Un projet d'algorithmique consistant à trier des données sur une pile, avec un ensemble d'instructions limité, en utilisant le moins de mouvements possible.

---

## Sommaire

### [1/ Le projet](#Le-projet) 
#### [a/ Les instructions](#Les-instructions)
#### [b/ Algorithme implenté](#Algorithme_implenté)
### [2/ Compilation](#Compilation) 
### [3/ Utilisation](#Utilisation)
#### [a/ MacOS](#macOS)
#### [b/ Linux](#Linux)
#### [c/ Windows (WSL)](#Windows_(WSL))
### [4/ Gestion des erreurs](#Gestion-des-erreurs) 

<br>

## Le Projet

Le but est d'écrire un programme en C nommé `push_swap` qui calcule et affiche sur la sortie standard les instructions (dans le langage d'assemblage de l'exercice) 
permettant de trier les entiers passés en paramètres. Le but est ainsi d'optimiser le nombre de calcul minimal plutôt que la vitesse. Pour cela il a fallu intégrer 
un algorithme qui calcul le nombre de déplacement, le "coût de déplacement" pour l'envoyer d'une position A à une position B. Ce projet utilise les listes chainées.

### Les Règles du Jeu
Vous disposez de deux piles, **A** et **B** :
*   La pile **A** contient au départ une quantité de nombres négatifs et/ou positifs sans doublons.
*   La pile **B** est vide au départ.
*   L'objectif est de trier la pile **A** par ordre croissant.

---

## 🛠️ Les Instructions Disponibles

| Commande | Action |
| :--- | :--- |
| **`sa`** / **`sb`** | Intervertit les 2 premiers éléments au sommet de la pile A / B. |
| **`ss`** | Fait `sa` et `sb` en même temps. |
| **`pa`** | Prend le premier élément au sommet de B et le met sur A. |
| **`pb`** | Prend le premier élément au sommet de A et le met sur B. |
| **`ra`** / **`rb`** | Décale d'un rang vers le haut tous les éléments de la pile A / B (le premier devient le dernier). |
| **`rr`** | Fait `ra` et `rb` en même temps. |
| **`rra`** / **`rrb`** | Décale d'un rang vers le bas tous les éléments de la pile A / B (le dernier devient le premier). |
| **`rrr`** | Fait `rra` et `rrb` en même temps. |

---

## Algorithme implémenté

Pour ce projet, j'ai implémenté l'algorithme Turk voici un résumé de son mode de fonctionnement:
1.  Étape 1 : envoyer 2 éléments de la pile A à la pile B.
2.  Étape 2 : calculer pour chaque élément de la pile A sa "cible de position" vers la pile B. Une cible de position répond a
   plusieurs critères : l'élément le plus proche dont la valeur est inferieur. Si celui-ci n'existe pas, alors la cible devient
   l'élément le plus grand dans la pile B.
3.  Étape 3 : calculer le coût de déplacement. Pour chaque élément de la liste A, voir le nombre d'action nécessaire pour le
   d éplacer vers sa cible de position.
4. Étape 4 : Envoyer jusqu'à ce qu'il ne reste plus que 3 éléments dans la pile A tous les élément ayant le coût de déplacement
   le moins élevé (le calcul doit être refait après chaque envoie d'un élément de la pile A à la pile B.
5. Étape 5 : Trier les 3 éléments de la liste A dans l'ordre (nécessite qu'une seule action).
6. Étape 6 : Déterminer la "cible de position" de la liste B à la liste A. Cette cible est définie
   comme la plus proche à la valeur suppérieur. Si celle-ci n'est pas présente alors, viser la valeur minimum.
7. Étape 7 : Renvoyer les éléments de la liste B vers la liste A. Si la valeur cible se trouve au delà de la median de la liste de A,
   envoyer les éléments avec les commandes `ra` ou `rra`.
8. Étape 8 : Maintenant que la pile A est triée il ne reste plus qu'à mettre l'élément le plus petit en haut de la pile.

---

Ainsi, une fois toutes les commandes réalisées on obtient une liste triée dans une pile en ayant fait un minimum de déplacements ! \
> [!TIP] Si vous voulez le tester avec un visualiseur je vous recommande des projets disponible sur Github comme celui de 
[[o-reo]([https://github.com/o-reo/push_swap_visualizer])]
> 
![Screenshot a visual final sort](assets/images/finalSort.tiff)

## Compilation

Le projet se compile à l'aide du Makefile fourni à la racine :

**Compilation du binaire push_swap** \
`make`

**Nettoyage des fichiers objets (.o)** \
`make clean`

**Nettoyage complet (objets + binaires)** \
`make fclean`

**Recompilation complète** \
`make re`


L'exécutable push_swap est généré à la racine du dépôt.

## Utilisation

Le programme prend en argument une liste d'entiers non triés (passés en paramètres multiples ou sous la forme d'une seule chaîne de caractères) et affiche la suite d'instructions nécessaires pour trier la pile a par ordre croissant :

**Arguments multiples** \
`./push_swap 2 1 3 6 5 8`

**En une seule chaîne de caractères** \
`./push_swap "2 1 3 6 5 8"`


**Tests et Vérification**

Les exécutables de vérification officiels pour macOS (checker_Mac) et Linux (checker_linux) sont inclus à la racine du projet et disposent déjà des droits d'exécution requis (chmod +x).

1. macOS

Sous macOS, la génération des nombres sans doublon s'effectue avec ruby (préinstallé nativement). \

Tester 100 nombres : \

**Génération de 100 nombres uniques** \
`ARG=$(ruby -e "puts (-1000..1000).to_a.sample(100).join(' ')")`

**Compter le nombre de coups** \
`./push_swap $ARG | wc -l`

**Vérifier que le tri est valide**\
`./push_swap $ARG | ./checker_Mac $ARG`


Tester 500 nombres : \

**Génération de 500 nombres uniques** \
`ARG=$(ruby -e "puts (-5000..5000).to_a.sample(500).join(' ')")`

**Compter le nombre de coups** \
`./push_swap $ARG | wc -l`

**Vérifier que le tri est valide** \
`./push_swap $ARG | ./checker_Mac $ARG`


> [!NOTE] macOS : Si Gatekeeper bloque l'exécution du checker lors du premier lancement, retirez la quarantaine système : \
> xattr -d com.apple.quarantine ./checker_Mac


2. Linux

Sous Linux, la génération aléatoire se fait via l'utilitaire shuf. \

Tester 100 nombres : \

**Génération de 100 nombres uniques** \
`ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')`

**Compter le nombre de coups** \
`./push_swap $ARG | wc -l`

**Vérifier que le tri est valide** \
`./push_swap $ARG | ./checker_linux $ARG`


Tester 500 nombres : \

**Génération de 500 nombres uniques** \
`ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' ')`

**Compter le nombre de coups** \
`./push_swap $ARG | wc -l`

**Vérifier que le tri est valide** \
`./push_swap $ARG | ./checker_linux $ARG`


3. Windows (WSL)

Le projet repose sur les standards POSIX et les binaires ELF / Mach-O. Il n'est donc pas exécutable nativement sous Windows (PowerShell / CMD). \

Pour l'exécuter sous Windows : \

Activez et installez WSL 2 (Windows Subsystem for Linux) avec une distribution Ubuntu : \

`wsl --install`

Ouvrez le terminal WSL et installez les outils de compilation essentiels : \

`sudo apt update && sudo apt install build-essential`

Suivez ensuite exactement la procédure décrite pour Linux (utilisation de shuf et de ./checker_linux). \


### Gestion des Erreurs

Le programme intercepte les entrées invalides, affiche Error\n sur la sortie d'erreur standard (stderr / fd 2) et quitte immédiatement sans fuite mémoire : \

**Valeurs non numériques** \
`./push_swap 1 2 a 4`

**Doublons** \
`./push_swap 1 3 2 3`

**Dépassements de capacité (> INT_MAX ou < INT_MIN)** \
`./push_swap 2147483648 1 2` \
`./push_swap -2147483649 1 2`

**Chaînes vides ou composées d'espaces** \
`./push_swap ""` \
`./push_swap "   "`

**Liste déjà ordonnée (ne doit rien afficher en sortie)** \
`./push_swap 1 2 3 4 5`

