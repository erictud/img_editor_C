// menu options
char option_1[] = "[1] Transform image to ASCII art\n";
char option_2[] = "[2] Create balck and white image\n";
char option_3[] = "[3] Invert image colors\n";
char option_4[] = "[4] Exit app\n";
int pad_left = 5;

void printWelcomeMessage(){
    printf("%s", "(C) Tudorica Eric feb. 2026\n");
    printf("%s", "______ ______   _____  \n");
    printf("%s", "\\____ \\____ \\ /      \\ \n");
    printf("%s", "|  |_> >  |_> >  Y Y  \\ \n");
    printf("%s", "|   __/|   __/|__|_|  / \n");
    printf("%s", "|__|   |__|         \\/ \n");
    printf("%s", "PPM image editor. Choose what to do:\n");

}                   

void printOptionMenu(char *opt, int print_long){
    // determine padding for each option
    int pad_left_opt1 = strlen(option_1) + pad_left;
    int pad_left_opt2 = strlen(option_2) + pad_left;
    int pad_left_opt3 = strlen(option_3) + pad_left;
    int pad_left_opt4 = strlen(option_4) + pad_left;

    // printing menu
    if(print_long){
        printf("%*s", pad_left_opt1, option_1);
        printf("%*s", pad_left_opt2, option_2);
        printf("%*s", pad_left_opt3, option_3);        
        printf("%*s", pad_left_opt4, option_4);
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

// TRANSFORM IMG TO ASCII ART
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

void opt2(char *img_name, int **img, int w_img, int h_img){
    // builds the result text file name (<name>_res.ppm)
    char *res_img_name = buildFileResName(img_name, "ppm");

    printf("Loading....\n");
    int res = transformBlachWhite(res_img_name, img, w_img, h_img);
    if(res == 0){
        printf("Unexpected error! Please try again!\n");
        return;
    }
    printf("Succes! The black and white image is %s \n", res_img_name);
}

void opt3(char *img_name, int **img, int w_img, int h_img){
// builds the result text file name (<name>_res.ppm)
    char *res_img_name = buildFileResName(img_name, "ppm");

    printf("Loading....\n");
    int res = invertImg(res_img_name, img, w_img, h_img);
    if(res == 0){
        printf("Unexpected error! Please try again!\n");
        return;
    }
    printf("Succes! The inverted color image is %s \n", res_img_name);
}
