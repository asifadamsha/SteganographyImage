#include <iostream>
#include <string.h>
#include "bmpFile.h"

unsigned char permutationTable[256];
unsigned char cle[] = "Bonjour le monde, voici ma superbe clé";

/**
 * Méthode permettant d'initialiser le contenu de notre table de permutation cette dernière contiendra 256 caractère (ascii étendu)
 *
 * On initialiser cette table avec des entiers successifs (1,2,3 ... 255)
 * On parcourera ensuite cette table caractère par caractère. Chaque caractère sera permuté en fonction du contenu de notre clé.
 */
void initTablePermutation() {
    int pointeurCle = 0;                                    // La position du caractère qu'on va lire dans notre clé
    int nombreCharCle = (int) strlen((const char *) cle);    // Le nombre de caractère de notre clé
    int tempoPermutationPosition;                               // Position temporaire qu'on va utilisé pour notre permutation
    unsigned char tempoPermutationValue;                        // Valeur que l'on va permuté
    int i;                                                      // Parceque sinon, c'est du C++ ;)

    // Rmplissage la table de permutation avec toute les valeurs possibles d'un unsigned char
    for (i = 0; i < 256; i++) {
        permutationTable[i] = i;
    }
    // Permutation
    for (i = 0; i < 256; i++) {
        //stockage de la valeur du tableau actuelle
        tempoPermutationPosition = cle[pointeurCle];
        tempoPermutationValue = permutationTable[tempoPermutationPosition];

        //permutation entre la position du compteur actuel et une position liée à la valeur de la clée
        permutationTable[tempoPermutationPosition] = permutationTable[i];
        permutationTable[i] = tempoPermutationValue;

        //incrémentation de la valeur de la clé (si on dépasse le nombre de caractères de la clé, on retourne au début de la clé)
        pointeurCle++;

        // Si la clé n'a plus de caractère permettant la permutation on réinitialiser le pointeur au début de la taille de la clé
        if (pointeurCle > nombreCharCle) {
            pointeurCle = 0;
        }
    }

}


/**
 * Fonction permettant de chiffrer un caractère avec notre table de permutation
 *
 * @param c
 * @return
 */
unsigned char chiffrement(unsigned char c) {
    return permutationTable[((int) c)];
}


/**
 * Fonction permettant de chiffrer un caractère avec notre table de permutation
 *
 * @param c
 * @return
 */
unsigned char deChiffrement(unsigned char c) {

    unsigned char tempo;

    for (int i = 0; i < 256; i++) {
        if (permutationTable[i] == c) {
            tempo = (unsigned char) i;
            break;
        }
    }

    return (int) tempo;
}


int main() {

    // Taille de notre clé
    int nombreCaractereCle = (int) strlen((const char *) cle);

    //vecteur d'initialisation (on le remplira uniquement de 0 pour le moment
    unsigned char *vecteurInitialisation;
    vecteurInitialisation = (unsigned char *) malloc(sizeof(unsigned char) * nombreCaractereCle);
    memset(vecteurInitialisation, 0, nombreCaractereCle);

    //initialisation de la Table fe permutation
    initTablePermutation();

    // Ouverture du fichier (en lecture le texte à chiffrer, en écriture le texte de sauvegarde, pour le debug)
    FILE *secretInputFile = fopen("..\\data\\secret.txt", "r");

    char secretOutputPath[] = "..\\data\\secret_output.txt";

    FILE *secretOutputFile = fopen(secretOutputPath, "w+");

    //récupération du nombre de caractères pour le dernier bloc (on se place à la fin du fichier, on fait un modulo de la taille du buffer pour récupérer ce qu'il reste)
    fseek(secretInputFile, 0, SEEK_END);
    int nombreCaractereFichier = ftell(secretInputFile);
    int sizeLastBlock = nombreCaractereFichier % nombreCaractereCle;

    //création d'un buffer du contenu chiffré
    unsigned char bufferChiffre[nombreCaractereFichier];
    memset(vecteurInitialisation, 0, nombreCaractereCle);

    // placement du pointeur au début du fichier à lire
    fseek(secretInputFile, 0, SEEK_SET);

    /**
     * CHIFFREMENT ! ! !
     */
    //buffer de lecture et variable du nombre de charactère lu
    unsigned char buffer[nombreCaractereCle];       // buffer de lecture
    int nbReadChar = 0;                             // nombre de caractères lus
    int convert = 0;                                 //conversion (permettra la réalisation du xor et du chiffrement et inversement)
    int nombreBoucle = 0;                           // Nombre de boucle (pour n'utiliser le vecteur d'initialisation qu'une seule fois
    int pointeurCaractereBufferChiffre = 0;         // Permet de savoir dans quel emplacement on doit écrire dans le buffer chiffré
    int posBufferWrite = 0;                         // Permet de connaitre la position du charactere du bloc précédent permettant le xor


    //Lecture du fichier (par bloc égal au nombre de caractère de la clé)
    while ((nbReadChar = fread(buffer, sizeof(unsigned char), nombreCaractereCle, secretInputFile))) {

        //on va maintenant parcourrir le buffer remplis à partir du  fichier
        for (int i = 0; i < nbReadChar; i++) {

            // Réalisation des trantement de type xor et chiffrement
            // Traitement pour la première boucle (on n'a pas de bloc précédent, donc on utilise un vecteur d'initialisation)
            if (nombreBoucle == 0) {
                // XOR
                convert = buffer[i] ^ vecteurInitialisation[i];
                // Chiffrement
                convert = chiffrement(convert);
                // Traitement pour la seconde boucle et les suivantes
            } else {
                // Calcul de la position du caractère que l'on doit utiliser
                posBufferWrite = ((nombreBoucle * nombreCaractereCle) + i) - nombreCaractereCle;
                // XOR
                convert = buffer[i] ^ bufferChiffre[posBufferWrite];
                // Chiffrement
                convert = chiffrement(convert);
            }
            // Ecriture dans le buffeur
            bufferChiffre[pointeurCaractereBufferChiffre] = convert;
            // Incrémentation du pointeur pour la prochaine écriture d'un caractère
            pointeurCaractereBufferChiffre++;
        }
        //incrémentation du nombre de la boucle pour n'utiliser le vercteur d'initialisation qu'unse seule fois
        nombreBoucle++;

        // On remplis le buffer avec des 0 (non utilisé pour le moment)
        //memset(buffer, (unsigned char) 0x00, sizeof(buffer));
    };

    //OPTIONNEL : Ecriture du contenu CHIFFRE dans "lorem_ipsum_chiffre.txt"
    fwrite(bufferChiffre, sizeof(char), pointeurCaractereBufferChiffre, secretOutputFile);


    //fermeture des File Descriptor (lecture et écriture)
    fclose(secretInputFile);
    fclose(secretOutputFile);

    //TODO INTEGRER LA GESTION DE L'IMAGE ICI
    //TODO ATTENTION : A PARTIR DE CE MOMENT, LA VARIABLES CHIFFREE EST : bufferChiffre
    //TODO La TAILLE de bufferChiffre EST  : nombreCaractereFichier

    /**
     * Add secrets to bitmap image
     */
    char bitmapPath[] = "..\\data\\tiger.bmp";
    char outputBitmapPath[] = "..\\data\\tiger_edited.bmp";

    BmpFile bmpFileEncrypt(bitmapPath);
    bmpFileEncrypt.hide(bitmapPath, secretOutputPath, outputBitmapPath);


    /**
     * DECHIFFREMENT
     */

    /**
     * Read secret from bitmap
    */

    char decryptBitmapPath[] = "..\\data\\secret_decrypt.txt";

    BmpFile bmpFileDecrypt(outputBitmapPath);
    bmpFileDecrypt.unhide(outputBitmapPath, decryptBitmapPath);

    //OPTIONNEL : On écrira également le contenu DECHIFFRE  dans "lorem_ipsum_dechiffre.txt"
    secretOutputFile = fopen(decryptBitmapPath, "w+");

    //création d'un buffer du contenu déchiffré
    unsigned char bufferDechiffre[nombreCaractereFichier];
    memset(bufferDechiffre, 0, nombreCaractereCle);

    for (int i = 0; i < nombreCaractereFichier; i++) {

        // Déchiffrement du caractère
        convert = deChiffrement(bufferChiffre[i]);

        // réalisation du XOR pour le premier bloc se basant sur un vecteur d'initialisation(l'inverse d'un XOR est un XOR)
        if (i < nombreCaractereCle) {
            convert = convert ^ vecteurInitialisation[i];
        }
            // réalisation du XOR avec le contenu du bloc précédent lorsqu'on est au second bloc ou plus (l'inverse d'un XOR est un XOR)
        else {
            convert = convert ^ bufferChiffre[(i - nombreCaractereCle)];
        }
        bufferDechiffre[i] = convert;

    }
    //OPTIONNEL : Ecriture du contenu DECHIFFRE  dans "lorem_ipsum_dechiffre.txt" et fermeture de ce dernier
    fwrite(bufferDechiffre, sizeof(char), nombreCaractereFichier, secretOutputFile);
    fclose(secretOutputFile);

    //TODO LE CONTENU DECHIFFRE SE TROUVE DANS LA VARIABLE bufferDechiffre
    //TODO LA TAILLE DE bufferDechiffre EST nombreCaractereFichier

    return (0);
}

/*int main() {

    char bitmapPath[] = "..\\data\\tiger.bmp";
    char outputBitmapPath[] = "..\\data\\tiger_edited.bmp";
    char secretPath[] = "c";
    char outputSecretPath[] = "..\\data\\secret_output.txt";

    BmpFile bmpFile(bitmapPath);
    bmpFile.unhide(outputBitmapPath, outputSecretPath);
    //bmpFile.hide(bitmapPath, secretPath, outputBitmapPath);

    //hideBitmapText(bitmapPath,outputBitmapPath,secret);

    return 0;
}*/