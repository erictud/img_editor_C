#include "utils.h"
#include "img_io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// AUXILIARY FUNCTIONS

// build file name 
// transform <file>.ppm -> <file>_res.<extension>
char *buildFileResName(char *img_name, const char *extension){
    int l_img_name = strlen(img_name);
    char *res_img_name = (char *)malloc(l_img_name + 5);
    strcpy(res_img_name, strtok(img_name, ".")); //
    strcat(res_img_name, "_res.");
    strcat(res_img_name, extension);
    res_img_name[l_img_name + 4] = '\0';
    return res_img_name;
}

// creates a new image with a cretain effect
int transformImage(char *res_name, int **img, int w_img, int h_img, void (*applyTransformation)(int **img, int **new_img, int i, int j)){
    // allocating new image
    int **new_img =  (int **)malloc(h_img * sizeof(int *));
    if(new_img == NULL) return 0;
    //
    for(int i = 0; i < h_img; i++){
        new_img[i] = (int *)malloc(3 * w_img * sizeof(int));
        if(new_img[i] == NULL) return 0;
        for(int j = 0; j < w_img; j++){
            applyTransformation(img, new_img, i, j);
        }
    }

    // creating image result file name
    write_img(res_name, new_img, w_img, h_img);

    // deallocating
    for(int i = 0; i < h_img; i++)
        free(new_img[i]);
    free(new_img);
    return 1;
}

