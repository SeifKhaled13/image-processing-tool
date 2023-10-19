//================================== Mohamed Ezz ======================================
void skewImageVertically(double degrees) {
    double radians = degrees * M_PI / 180.0; // Convert degrees to radians
    unsigned char tempImage[SIZE][SIZE];
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            tempImage[i][j]=255;
        }
    }
    for (int i = 0; i <SIZE; i++) {
        for (int j = SIZE-1; j >=0; j--) {
            int newX =  i- (SIZE/2)+j * tan(radians); // Calculate the new x-coordinate
            if (newX >= 0 && newX < SIZE) {
                tempImage[i][j] = image[newX][j]; // Perform the skew transformation
            }
        }
    }

    // Copy the skewed image back to the original image
    memcpy(image, tempImage, sizeof(image));
}
//================================== Mohamed Ezz ======================================