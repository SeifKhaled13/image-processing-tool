void invertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Invert the pixel value by subtracting it from 255
            image[i][j] = 255 - image[i][j];
        }
    }
}