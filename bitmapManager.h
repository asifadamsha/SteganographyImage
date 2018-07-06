
/**
 * Inspired from : https://github.com/amant/Steganography
 */

class BitmapManager {
public:
    long bitmapFilesize;
    long bitmapWidth;
    long bitmapHeight;
    long bitmapMaxAvailableData;

    BitmapManager(char *filename);

    int isFileExist(char *filename);

    int readHeader(char *filename);

    int encryptSecrets(char *bmpfile, char *txtfile, char *output);

    int decryptSecrets(char *bmpfile, char *txtfile);

    int isHidable(char *bmpfile, char *txtfile);
};
