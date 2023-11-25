# 🐣 S1 | Prog: Workshop

Template de projet pour le workshop de prog des Imac1. Vous trouverez le sujet ici: https://dsmte.github.io/Learn--cpp_programming/Workshop

## Rapport de Christian et Théo

### Ne gardez que le vert

| ![image](./images/logo.png)| ![image](./output/pouet_vert.png)|
|:--------------------------:|:--------------------------------:|
|            Avant           |               Après              |

**Méthode :** On parcourt un à un tous les pixels de l'image, puis on fixe la valeur du rouge et du bleu à 0 pour chacun d'entre eux : seuls le vert et le noir ressortent donc.

### Échanger les canaux

| ![image](./images/logo.png)| ![image](./output/pouet_canaux.png)|
|:--------------------------:|:----------------------------------:|
|            Avant           |                Après               |

**Méthode :** On sélectionne tous les pixels un par un de la même manière que pour l'exercice précédent, sauf qu'on échange cette fois-ci les valeurs de rouge et de bleu pour chacun d'entre eux grâce à un *swap*.

### Noir & Blanc

| ![image](./images/logo.png)| ![image](./output/pouet_gris.png)|
|:--------------------------:|:--------------------------------:|
|            Avant           |               Après              |

**Méthode :** On attribue à chaque pixel la moyenne de ses valeurs de rouge, de vert et de bleu de sorte à obtenir une image colorée en niveaux de gris.

### Négatif

| ![image](./images/logo.png)| ![image](./output/pouet_negatif.png)|
|:--------------------------:|:-----------------------------------:|
|            Avant           |                 Après               |

**Méthode :** On parcours tous les pixels, puis on obtient de nouvelles valeurs de rouge, de vert et de bleu pour chacun d'entre eux en soustrayant à 1 les valeurs d'origine.

### Noir & Blanc

| ![image](./images/logo.png)| ![image](./output/pouet_gris.png)|
|:--------------------------:|:--------------------------------:|
|            Avant           |               Après              |

**Méthode :** On parcourt les colonnes une à une. Pour chacune d'entre elles, on définit une valeur allant du noir au blanc en fonction de la position du *x* sur la largeur totale de l'image.

**Piège :** Il faut bien penser à convertir les *x* en *float* grâce à un *static_cast* pour définir les niveaux de gris.