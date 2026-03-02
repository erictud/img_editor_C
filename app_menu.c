#include "app_menu.h"
#include "img_editing_opt.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// menu options
char options[][30] = {"Transform image to ASCII art", 
                    "Create balck and white image", "Invert image colors", 
                    "Apply color filter", "Exit app"};
int pad_left = 5;
int options_num = 5;

void printWelcomeMessage(){
    printf("%s", "(C) Tudorica Eric feb. 2026\n");
    printf("%s", "______ ______   _____  \n");
    printf("%s", "\\____ \\____ \\ /      \\ \n");
    printf("%s", "|  |_> >  |_> >  Y Y  \\ \n");
    printf("%s", "|   __/|   __/|__|_|  / \n");
    printf("%s", "|__|   |__|         \\/ \n");
    printf("%s", "PPM image editor. Choose what to do:\n\n");

}                   

void printOptionMenu(char *opt, int print_long){
    // printing menu options
    for(int i = 0; i < options_num; i++){
        // determine padding for each option
        int pad_left_opt = strlen(options[i]) + pad_left;
        if(print_long){
            printf("[%d]%*s\n", i+1, pad_left_opt, options[i]);
        }
    }
    // determining wheter we print all the options again
    if(print_long){
        printf("%*s", 15, "Choose option: ");
    }else{
        printf("%*s", 23, "Choose another option: ");

    }

    // make sure that \n or spaces dont count as valid options
    char ch = getchar();
    while(ch == ' ' || ch == '\n')
        ch = getchar();
    *opt = ch;    
}

// Opt 1 - Transforming image to ASCII art
void opt1(char *img_name, int **img, int w_img, int h_img){
    // builds the result text file name (<name>_res.txt)
    char *res_img_name = buildFileResName(img_name, "txt");

    printf("Loading....\n");
    int res = transformAscii(res_img_name, img, w_img, h_img);
    if(res == 0){
        printf("Unexpected error! Please try again!\n");
        return;
    }
    printf("Succes! The text file with the ASCII art is %s \n", res_img_name);
}

// Opt 2 - Transforming image to black and white
void opt2(char *img_name, int **img, int w_img, int h_img){
    // builds the result text file name (<name>_res.ppm)
    char *res_img_name = buildFileResName(img_name, "ppm");

    printf("Loading....\n");
    int res = transformImage(res_img_name, img, w_img, h_img, applyTransformationBW);
    if(res == 0){
        printf("Unexpected error! Please try again!\n");
        return;
    }
    printf("Succes! The black and white image is %s \n", res_img_name);
}

// Opt 3 - Inverting color images
void opt3(char *img_name, int **img, int w_img, int h_img){
// builds the result text file name (<name>_res.ppm)
    char *res_img_name = buildFileResName(img_name, "ppm");

    printf("Loading....\n");
    int res = transformImage(res_img_name, img, w_img, h_img, applyTransformationInvert);
    if(res == 0){
        printf("Unexpected error! Please try again!\n");
        return;
    }
    printf("Succes! The inverted color image is %s \n", res_img_name);
}

// Opt 4 - Applying color filters
void opt4(char *img_name, int **img, int w_img, int h_img){
// builds the result text file name (<name>_res.ppm)
    char *res_img_name = buildFileResName(img_name, "ppm");

    printf("Choose color filter (red - r; green - g; blue - b): ");
    // make sure that \n or spaces dont count as valid options
    char filter_option = getchar();
    while(filter_option == ' ' || filter_option == '\n')
        filter_option = getchar();
    
    int res;
    if(filter_option == 'r'){
        res = transformImage(res_img_name, img, w_img, h_img, applyTransformationFilterRed);
    }else if(filter_option == 'g'){
        res = transformImage(res_img_name, img, w_img, h_img, applyTransformationFilterGreen);
    }else if(filter_option == 'b'){
        res = transformImage(res_img_name, img, w_img, h_img, applyTransformationFilterBlue);
    }else{
        printf("Invalid option! Moving back to the main menu...\n");
    }    

    if(res == 0){
        printf("Unexpected error! Please try again!\n");
        return;
    }
    printf("Succes! The new image is %s \n", res_img_name);
}