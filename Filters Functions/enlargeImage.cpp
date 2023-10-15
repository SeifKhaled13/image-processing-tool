//================================== Seif Khaled ======================================
void enlargeImage() {
    int quarterToEnlarge;
    cout << "Enter the quarter you want to enlarge (1, 2, 3, or 4): ";
    cin >> quarterToEnlarge;

    // check for valid input
    if (quarterToEnlarge < 1 || quarterToEnlarge > 4) {
        cerr << "Invalid input. Enter a number from 1 to 4." << endl;
        return;
    }

    int quarterWidth = SIZE / 2;
    int quarterHeight = SIZE / 2;

    int sourceRowStart = ((quarterToEnlarge - 1) / 2) * quarterHeight;
    int sourceColStart = ((quarterToEnlarge - 1) % 2) * quarterWidth;

    unsigned char enlargedImage[256][256]; // Create a new 256x256 image

    // reduce the selected quarter into a new 256x256 image
    for (int row = 0; row < 256; row++) {
        for (int col = 0; col < 256; col++) {
            int originalRow = sourceRowStart + row / 2;
            int originalCol = sourceColStart + col / 2;
            enlargedImage[row][col] = image[originalRow][originalCol];
        }
    }

    // Copy the enlarged image back to the original image array
    for (int row = 0; row < 256; row++) {
        for (int col = 0; col < 256; col++) {
            image[row][col] = enlargedImage[row][col];
        }
    }
}
//================================== Seif Khaled ======================================