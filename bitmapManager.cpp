/* This is the bmpFile format reading class implementation. */

#include <cstdio>
#include "bitmapManager.h"

#ifndef __BmpFile
#define __BmpFile
#endif

// checks for existence of file, returns 0 if ok, returns -1 on error
int BitmapManager::isFileExist(char *filename) {
    FILE *bmpFilename;
    bmpFilename = fopen(filename, "rb");

    if (bmpFilename == NULL) {
        throw ("File doesn't exits or wrong Filename.\n");
        return (-1);
    }

    fclose(bmpFilename);
    return 0;
}

int BitmapManager::readHeader(char *filename) {
    char m1, m2;
    unsigned long width, height, fileSize;

    if (isFileExist(filename) == 0) {
        FILE *bmpFilename = fopen(filename, "rb");

        fseek(bmpFilename, 0, 2);

        fread(&bitmapFilesize, 4, 1, bmpFilename);

        fseek(bmpFilename, SEEK_CUR, 12);

        fread(&bitmapWidth, 4, 1, bmpFilename);

        fread(&bitmapHeight, 4, 1, bmpFilename);

        fclose(bmpFilename);

        width = bitmapWidth;
        height = bitmapHeight;
        fileSize = width * height * 3;
        bitmapMaxAvailableData = (fileSize / 8) - 54;

        return 0;
    }
    return -1;
}

BitmapManager::BitmapManager(char *filename) {
    if (isFileExist(filename) == 0) {
        readHeader(filename);
    }
}

int BitmapManager::isHidable(char *bmpfile, char *txtfile) {
    FILE *bfile, *tfile;
    long l = 0;

    // check and Initialize files...
    bfile = fopen(bmpfile, "rb");

    if (isFileExist(bmpfile) == -1) {
        throw ("BMP file doesn't exist");
        return -1;
    }

    tfile = fopen(txtfile, "rb");
    if (isFileExist(txtfile) == -1) {
        throw ("txt file doesn't exist");
        return -1;
    }

    while (!feof(tfile))                // read the length of txt file...
    {
        fgetc(tfile);
        l++;
    }

    readHeader(bmpfile);

    if (l >= bitmapMaxAvailableData) {
        throw "length of text file too big , select bigger bmp file";
        return -1;
    }

    fclose(bfile);
    fclose(tfile);
    return 0;
}

// encoding implementation...
int BitmapManager::encryptSecrets(char *bmpfile, char *txtfile, char *output) {

    FILE *bfile, *tfile, *outfile;
    unsigned char header[54];
    char bmpbuffer, txtbuffer;
    int i;
    char txtTerminatorIndicator = '*';

    if (isHidable(bmpfile, txtfile) == -1) {
        throw "error!, initialization failed...";
        return -1;
    }

    bfile = fopen(bmpfile, "rb");
    tfile = fopen(txtfile, "rb");
    outfile = fopen(output, "w+b");

    fread(header, 54, 1, bfile);        //read BMP header
    fwrite(header, 54, 1, outfile);    //write BMP header
    bitmapFilesize = bitmapFilesize - 54;

    // main hiding/encoding process
    while (!feof(tfile)) {
        txtbuffer = fgetc(tfile);
        for (i = 0; i < 8; i++) {
            bmpbuffer = fgetc(bfile);
            bmpbuffer &= 0xFE;        //FE, to make sure LSB is always zero
            bmpbuffer |= (char) ((txtbuffer >> i) & 1);
            fputc(bmpbuffer, outfile);

            bitmapMaxAvailableData--;
            bitmapFilesize--;
        }
    }

    // stuffing txt terminator indicator.
    for (i = 0; i < 8; i++) {
        bmpbuffer = fgetc(bfile);
        bmpbuffer &= 0xFE;
        bmpbuffer |= (char) ((txtTerminatorIndicator >> i) & 1);
        fputc(bmpbuffer, outfile);
        bitmapMaxAvailableData--;
        bitmapFilesize--;
    }

    // write remaing bmp bytes into the new bmp file.
    if (bitmapFilesize != 0) {
        while (!feof(bfile)) {
            fputc(fgetc(bfile), outfile);
        }
    }

    // close all file handlers
    fclose(bfile);
    fclose(tfile);
    fclose(outfile);

    return 0;
}

int BitmapManager::decryptSecrets(char *bmpfile, char *txtfile) {
    if (readHeader(bmpfile) == -1)
        return -1;

    FILE *bfile, *tfile;
    char ch, bmpBuffer[8];
    int i;
    bfile = fopen(bmpfile, "rb");
    tfile = fopen(txtfile, "w+b");

    fseek(bfile, 54, SEEK_SET);
    ch = 0;

    while (!feof(bfile)) {
        //read the last bit from BMP file
        ch = 0;
        for (i = 0; i <= 7; i++) {
            bmpBuffer[i] = fgetc(bfile);
        }

        for (i = 7; i >= 0; i--) {
            ch += (bmpBuffer[i] & 1);
            if (i != 0)
                ch <<= 1;
        }

        if (ch == EOF || ch == '*') {
            break;
        } else {
            fputc(ch, tfile);
        }
    }

    fclose(bfile);
    fclose(tfile);

    return 0;
}
