//================================== Seif Khaled ======================================
void shuffleImage() {
    int quartersOrder[4];
    cout << "Enter the desired order of quarters (e.g., 1 2 3 4): ";

    for (int i = 0; i < 4; i++) {
        cin >> quartersOrder[i];

        // check for valid input
        if (quartersOrder[i] < 1 || quartersOrder[i] > 4) {
            cout << "Invalid input. Enter numbers from 1 to 4." << endl;
            return;
        }
    }

    unsigned char newImage[SIZE][SIZE];
    int quarterWidth = SIZE / 2;
    int quarterHeight = SIZE / 2;

    for (int i = 0; i < 4; i++) {
        int sourceRowStart = ((quartersOrder[i] - 1) / 2) * quarterHeight;
        int sourceColStart = ((quartersOrder[i] - 1) % 2) * quarterWidth;

        for (int row = 0; row < quarterHeight; row++) {
            for (int col = 0; col < quarterWidth; col++) {
                newImage[row + quarterHeight * (i / 2)][col + quarterWidth * (i % 2)] = image[row + sourceRowStart][col + sourceColStart];
            }
        }
    }

    // copy the shuffled image back to the original image array
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            image[row][col] = newImage[row][col];
        }
    }
}
//================================== Seif Khaled ======================================