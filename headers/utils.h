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