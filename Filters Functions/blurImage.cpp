//================================== Mohamed Ezz ======================================
void blurImage() {
    unsigned char tempImage[SIZE][SIZE];

    for (int x = 1; x <= SIZE-1 ; x++) { // loop for all pixels
        for (int y = 1; y < SIZE-1 ; y++) {
            int neighbored_pixels = 0;

            for (int dx = -1; dx <= 4; dx++) { // loop for all pixels and calculate the neighbours of 6*6 array of the current pixel
                for (int dy = -1; dy <= 4; dy++) {
                    neighbored_pixels += image[x + dx][y + dy];

                }
            }

            tempImage[x][y] = neighbored_pixels / 36; //here when i calculate 6*6 array of the neighbour current pixel,we calculate the average to blur the pixel as we can
        }
    }
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) { // loop for all pixels and copy the image we do operations on it to the original image
            image[x][y] = tempImage[x][y];
        }
    }
}
//================================== Mohamed Ezz ======================================