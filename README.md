# philosophers

*Ce projet a été réalisé dans le cadre du cursus de l'école 42.*

## Description

**philosophers** est une simulation du célèbre problème des philosophes qui dînent. Des philosophes sont assis autour d'une table ronde, avec une fourchette entre chaque paire. Chacun alterne entre manger, dormir et penser, mais doit prendre deux fourchettes pour manger. Si un philosophe ne mange pas à temps, il meurt.

L'objectif est de comprendre la programmation concurrente, la gestion des threads, la synchronisation avec les mutex et la prévention des data races et des deadlocks.

## Prototype

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

## Arguments

| Argument | Description |
|----------|-------------|
| `number_of_philosophers` | Nombre de philosophes (et de fourchettes) |
| `time_to_die` | Temps en ms avant la mort d'un philosophe sans manger |
| `time_to_eat` | Temps en ms pour manger (deux fourchettes occupées) |
| `time_to_sleep` | Temps en ms pour dormir |
| `number_of_times_each_philosopher_must_eat` | *(optionnel)* La simulation s'arrête quand tous ont mangé ce nombre de fois |

## Fonctionnement

| Étape | Description |
|-------|-------------|
| Initialisation | Crée les philosophes, les fourchettes (mutex) et les threads |
| Cycle | Chaque philosophe mange, dort puis pense en boucle |
| Fourchettes | Un philosophe prend deux fourchettes pour manger |
| Surveillance | Un moniteur vérifie si un philosophe est mort ou si tous ont assez mangé |
| Fin | La simulation s'arrête à la mort d'un philosophe ou quand tous ont mangé |

## Affichage

| Message | Description |
|---------|-------------|
| `timestamp_in_ms X has taken a fork` | Le philosophe X prend une fourchette |
| `timestamp_in_ms X is eating` | Le philosophe X mange |
| `timestamp_in_ms X is sleeping` | Le philosophe X dort |
| `timestamp_in_ms X is thinking` | Le philosophe X pense |
| `timestamp_in_ms X died` | Le philosophe X est mort |

## Fonctions autorisées

| Fonction | Rôle |
|----------|------|
| `memset` | Remplit une zone mémoire |
| `printf` | Affichage formaté |
| `malloc`, `free` | Alloue et libère la mémoire |
| `write` | Écrit dans un descripteur de fichier |
| `usleep` | Met le programme en pause |
| `gettimeofday` | Récupère l'heure actuelle |
| `pthread_create`, `pthread_detach`, `pthread_join` | Gestion des threads |
| `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock` | Gestion des mutex |

## Compilation

```bash
make        # compile le programme philo
make clean  # supprime les fichiers objets
make fclean # supprime les objets et l'exécutable philo
make re     # recompile entièrement
```

## Utilisation

Lancer la simulation avec 5 philosophes :

```bash
./philo 5 800 200 200
```

Lancer la simulation avec un nombre de repas limité :

```bash
./philo 5 800 200 200 7
```

## Normes

- Respect de la **Norme** de 42
- Compilation avec `-Wall -Wextra -Werror`
- Aucune fuite mémoire
- Aucune data race
- Aucun deadlock

## Auteur

@prsadamm
