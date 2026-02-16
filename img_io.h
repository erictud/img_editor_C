// returns the matrix of the pixels, along with width and height by using the w and h parameters
int** read_file(char *f_name, int *w, int *h){
    char buff[1000];
    int r, g, b, max_col;
    // file opening
    FILE *fp = fopen(f_name, "rt");
    if(fp == NULL)
        return NULL;
    // reads ppm format and check compatibility
    fgets(buff, 999, fp);
    if(strcmp(buff, "P3\n"))
        return NULL;

    // reads width and height
    int num_read = fscanf(fp, "%d%d", w, h);
    if(num_read != 2)
        return NULL;

    // reads max_col
    fscanf(fp, "%d", &max_col);
    printf("%d\n", max_col);
    if(max_col > 255)
        return NULL;

    // reads pixels rows
    int **img = (int **)malloc((*h)*sizeof(int *));
    for(int i = 0; i < *h; i++){
        img[i] = (int *)malloc(3 * (*w) * sizeof(int));
        for(int j = 0; j < *w; j++){
            fscanf(fp, "%d%d%d", &r, &g, &b);
            img[i][j*3] = r;
            img[i][j*3+1] = g;
            img[i][j*3+2] = b;
        }
    }
    return img;
}