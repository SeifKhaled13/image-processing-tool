//================================== Osama Eslam ======================================
void blackAndWhite()
{
  // first calculate average gray level
  int number = 0;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      number += image[i][j];
    }
  }
  number /= (SIZE * SIZE); // to get the average
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      // the pixel greater than average be white
      if (image[i][j] > number)
      {
        image[i][j] = 255;
      }
      // the pixel lower than the average be black
      else
      {
        image[i][j] = 0;
      }
    }
  }
}
//================================== Osama Eslam ======================================