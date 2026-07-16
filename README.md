# Push_swap

Un projet d'algorithmique consistant à trier des données sur une pile, avec un ensemble d'instructions limité, en utilisant le moins de mouvements possible.

---

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

## Utilisation

### Compilation

Générez l'exécutable à l'aide du `Makefile` :
```bash
make
