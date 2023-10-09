//================================== Seif Khaled ======================================
void rotateImage() {
    int choice;
    cout << "Choose rotation angle (90 degrees, 180 degrees or 270 degrees): ";
    cin >> choice;

    if (choice == 90) {
        unsigned char temp[SIZE][SIZE];
        int degrees = 90;
        // determine the number of 90-degree rotations needed
        int rotations = degrees / 90;

        for (int r = 0; r < rotations; r++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp[j][SIZE - 1 - i] = image[i][j]; // rotate clockwise
                }
            }

            // copy the rotated image from temp to the original image array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = temp[i][j];
                }
            }
        }
    } else if (choice == 180) {
        unsigned char temp[SIZE][SIZE];
        int degrees = 180;
        // determine the number of 90-degree rotations needed
        int rotations = degrees / 90;

        for (int r = 0; r < rotations; r++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp[j][SIZE - 1 - i] = image[i][j]; // rotate clockwise
                }
            }

            // copy the rotated image from temp to the original image array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = temp[i][j];
                }
            }
        }
    } else if (choice == 270) {
        unsigned char temp[SIZE][SIZE];
        int degrees = 270;
        // determine the number of 90-degree rotations needed
        int rotations = degrees / 90;

        for (int r = 0; r < rotations; r++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp[j][SIZE - 1 - i] = image[i][j]; // rotate clockwise
                }
            }

            // copy the rotated image from temp to the original image array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = temp[i][j];
                }
            }
        }
    } else {
        cerr << "Invalid choice. Please select 90, 180, or 270." << endl;
        rotateImage();
    }


}
//================================== Seif Khaled ======================================