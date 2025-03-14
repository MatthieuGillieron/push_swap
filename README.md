# Pushswap – Projet 42

Bienvenue dans **Pushswap**, mon projet à l'école 42. Le but de ce projet est de trier une pile de nombres à l'aide d'algorithmes efficaces et en utilisant un nombre limité d'opérations. Ce projet m'a permis de perfectionner mes compétences en algorithmique, en optimisant le tri et en travaillant sur des structures de données simples mais puissantes.

<br>

## Description du projet

Le projet **Pushswap** consiste à implémenter un algorithme de tri pour trier une pile de nombres. L'objectif est de trouver la méthode la plus efficace possible en termes d'opérations. L'application ne doit utiliser que deux piles (ou plus précisément deux tableaux), et le tri doit se faire en utilisant une combinaison des opérations suivantes :

- **`sa`** : Échanger les deux premiers éléments de la pile A.
- **`sb`** : Échanger les deux premiers éléments de la pile B.
- **`ss`** : Faire `sa` et `sb` en même temps.
- **`pa`** : Pousser le premier élément de la pile B vers la pile A.
- **`pb`** : Pousser le premier élément de la pile A vers la pile B.
- **`ra`** : Déplacer tous les éléments de la pile A d'une position vers le haut.
- **`rb`** : Déplacer tous les éléments de la pile B d'une position vers le haut.
- **`rr`** : Faire `ra` et `rb` en même temps.
- **`rra`** : Déplacer tous les éléments de la pile A d'une position vers le bas.
- **`rrb`** : Déplacer tous les éléments de la pile B d'une position vers le bas.
- **`rrr`** : Faire `rra` et `rrb` en même temps.

Pour réussir ce projet, j’ai utilisé différentes techniques comme les tri par insertion, les algorithmes de tri à plusieurs étapes, ainsi que des méthodes d'optimisation pour minimiser le nombre d’opérations nécessaires.

## Comment exécuter le projet

### 1. Cloner le repository


```bash
git clone https://github.com/matthieugillieron/pushswap.git
cd pushswap
```
### 2. Compiler le projet


```bash
make
```

### 3. Utilisation de l'exécutablePour utiliser l'exécutable, vous devez fournir une liste de nombres à trier en argument. Par exemple :

```bash
./pushswap 3 2 1 5 4
```
