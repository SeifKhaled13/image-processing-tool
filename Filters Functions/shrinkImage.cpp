//================================== Mohamed Ezz ======================================
void shrinkImage() {
    int shrunked[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            shrunked[i][j] = 255;
        }
    }
    cout << "choose the size of the image you want" << endl << "1 : 0.5\n" << "2 : 0.3\n" << "3 : 0.25\n";
    float block;
    cin >> block; // allowing user for choose the size he wants to shrink
    if (block == 0.5 || block == 0.25 || block == (float) 1 / 3 || block == (float) 1 / 2 || (float) block == 1 / 4) {
        block = 1 / block;
        for (int i = 0; i < SIZE; i += block) { // loop for all pixels and increment by the size he choose
            for (int j = 0; j < SIZE; j += block) {
                int sum_array_of_block = 0;
                for (int x = i; x < i + block; x++) {
                    for (int y = j; y < j + block; y++) {
                        sum_array_of_block += image[x][y];
                    }
                }
                shrunked[i / (int) block][j / (int) block] =
                        sum_array_of_block / (block * block); //calculate the everage of the asked array of the block
            }

        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = shrunked[i][j];
            }
        }

    } else {
        cout << "Invalid choice,please try again" << endl;
        shrinkImage();
    }
}
//================================== Mohamed Ezz ======================================