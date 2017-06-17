#include "fileDialog.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void openFileDialog(char *rom_name, char *filters) {
    /* Open file dialogue */
    char cwd[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, cwd);

    OPENFILENAME ofn;

    char szFile[MAX_PATH];

    /* open a file name */
    ZeroMemory( &ofn , sizeof( ofn));
    ofn.lStructSize = sizeof ( ofn );
    ofn.hwndOwner = NULL  ;
    ofn.lpstrFile = szFile ;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof( szFile );
    ofn.lpstrFilter = "Chip8\0*.ch8\0All\0*.*\0";
    ofn.nFilterIndex =1;
    ofn.lpstrFileTitle = NULL ;
    ofn.nMaxFileTitle = 0 ;
    ofn.lpstrInitialDir=NULL ;
    ofn.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST ;

    if (!GetOpenFileName( &ofn)) {
        return;
    }

    /* Change current working directory back to location of executable */
    SetCurrentDirectory(cwd);

    if (szFile != NULL) {
        strcpy(rom_name, szFile);
    }

    return;
}