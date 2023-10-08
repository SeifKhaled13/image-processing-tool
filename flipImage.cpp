//================================== Osama Eslam ======================================
void flipImage()
{
  // first we need to ask the user to know how he wants the flip
  cout << "Do you want to rotate (H)orizontally or (V)ertically ? ";
  char c;
  cin >> c;

  if (c == 'H' || c == 'h')
  {
    /*
    in this loops we will take every pixel in the left and assign it to the pixel
    in the right and when reach the middle pixel it will do vice virsa
    */
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        toMirror[i][255 - j] = image[i][j];
      }
    }
  }
  /*
  here we will take pixels from top and assign them to bottom pixels
  and also when we will get to the middle pixel it will do the vice versa
  */
  else if (c == 'V' || c == 'v')
  {
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        toMirror[255 - i][j] = image[i][j];
      }
    }
  }
  else
  {
    cerr << "Error, Please enter a valid choice (h or v)" << endl;
    flipImage();
  }
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      image[i][j] = toMirror[i][j];
    }
  }
}
//================================== Osama Eslam ======================================