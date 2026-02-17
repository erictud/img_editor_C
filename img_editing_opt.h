// Basic resizing algorithm, makes an image smaller
int **resizeImg(int w, int h, int **img, int *new_w, int *new_h){    
    // determining a new size that keeps the w/h ratio
    float coef = (float)h/w;
    if(coef <= 1){
        *new_w = 400;
        *new_h = (int)(h * coef);
    }else{
        coef = (float)w/h;
        *new_h = 400;
        *new_w = (int)(w * coef);
    }

    // determining scaling factor
    float scaling_w = (float)w / (*new_w);
    float scaling_h = (float)h / (*new_h);
    // new image construction
    int **new_img = (int **)malloc((*new_h) * sizeof(int *));
    if(new_img == NULL) return NULL;
    for(int i = 0; i < *new_h; i++){
        new_img[i] = (int *)malloc(3 * (*new_w) * sizeof(int));
        for(int j = 0; j < *new_w; j++){
            int coord_x = (int)(i * scaling_h);
            int coord_y = (int)(j * scaling_w);
            new_img[i][j*3] = img[coord_x][coord_y*3];
            new_img[i][j*3+1] = img[coord_x][coord_y*3+1];
            new_img[i][j*3+2] = img[coord_x][coord_y*3+2];
        }
    }
    return new_img;
}

// Transforming every px in a character based on brightness
int transformAscii(char *nume_fis, int **img, int w, int h){
    // 
    FILE *fp = fopen(nume_fis, "wt");
    if(fp == NULL)
        return 0;

    // resizing image
    int new_w, new_h;
    int** new_img = resizeImg(w, h, img, &new_w, &new_h);
    if(new_img == NULL)
        return 0;

    // transforming every px into a character
    for(int i = 0; i < new_h; i++){
        for(int j = 0; j < new_w; j++){
            float brightness = (new_img[i][j*3] + new_img[i][j*3+1] + new_img[i][j*3+2]) / 3.0;
            brightness /= 255;
            if(brightness >= 0.9){
                fputc('@', fp);
            }else if(brightness >= 0.7){
                fputc('&', fp);
            }else if(brightness >= 0.5){
                fputc('+', fp);
            }else if(brightness >= 0.3){
                fputc('e', fp);
            }else if(brightness >= 0.1){
                fputc('v', fp);
            }else{
                fputc(' ', fp);
            }
        }
        fputc('\n', fp);
    }
    fclose(fp);

    // dealloc memory
    for(int i = 0; i < new_h; i++)
        free(new_img[i]);
    free(new_img);
}

