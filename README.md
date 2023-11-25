# 🐣 Rapport de Christian et Théo

##NIVEAU 1

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

##NIVEAU 2

### Miroir

| ![image](./images/logo.png)| ![image](./output/pouet_miroir.png)|
|:--------------------------:|:----------------------------------:|
|            Avant           |                Après               |

**Méthode :** On parcourt les pixels à *x* distance de l'extrémité gauche de l'image pour les échanger avec ceux à *x* distance de la droite (*image.width() - 1 - x*).

**Piège :** Il faut seulement parcourir la moitié gauche (*image.width()/2*) de l'image : on échangerait sinon des pixels déjà déplacés.

### Image bruitée

| ![image](./images/logo.png)| ![image](./output/pouet_bruit.png)|
|:--------------------------:|:----------------------------------:|
|            Avant           |                Après               |

**Méthode :** Pour chaque pixel, on génère un nombre aléatoire allant de 0 à *n*, *n* étant inversement proportionnel à la quantité de bruit que l'on désire. Si *n* = 0, alors les valeurs de rouge, de vert et de bleu du pixel sélectionné prennent une valeur aléatoire comprise entre 0 et 1 pour générer une nouvelle couleur.

### Rotation de 90°

| ![image](./images/logo.png)| ![image](./output/pouet_rotation.png)|
|:--------------------------:|:------------------------------------:|
|            Avant           |                 Après                |

**Méthode :** On crée une nouvelle image aux proportions inversées, puis on parcourt l'image d'origine pour copier ses pixels sur la nouvelle image en appliquant la rotation.

**Piège :** Puisqu'on parcourt les pixels de l'image d'origine de coordonnées *{x, y}*, il faut donc copier ceux de coordonnées *{x, image.height() - y - 1}* (à cause de la rotation) aux points *{y, x}* sur la nouvelle image (à cause d'inversion de proportions).

### RGB split

| ![image](./images/logo.png)| ![image](./output/pouet_split.png)|
|:--------------------------:|:---------------------------------:|
|            Avant           |                Après              |

**Méthode :** On crée une nouvelle image sur laquelle on va copier les pixels de l'image d'origine en décalant certaines couleurs.

**Piège :** Il faut prendre en compte les dépassements et gérer donc les cas où on demanderait à un pixel de prendre la couleur d'un autre qui serait en dehors de l'image.

### Luminosité

| ![image](./images/photo.jpg)| ![image](./output/photo_eclaircie.png)| ![image](./output/photo_assombrie.png)|
|:---------------------------:|:-------------------------------------:| :-----------------------------------: |
|            Normal           |                Éclairci               |                Assombri               |

**Méthode :** On parcourt les pixels un à un pour :
- augmenter leurs valeurs de rouge, de vert et de bleu grâce à une puissance supérieure à 1 ;
- diminuer ces valeurs à l'aide d'une puissance comprise entre 0 et 1.

##NIVEAU 3

###Disque

![image](./output/fond_disque.png)

**Méthode :**