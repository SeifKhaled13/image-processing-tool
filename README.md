# Image Processing Tool (Version 1.0)

This Image Processing Tool is developed for the Faculty of Computer Science and Artificial Intelligence (FCAI) at Cairo University under the guidance of Prof. Mohammed El-Ramly.

## Table of Content
* [Overview](#overview)
* [Usage](#usage)
* [Example Usage](#example-usage)
* [Authors](#authors)
* [License](#license)

## Overview

This C++ project provides a set of six image processing functions, designed to enhance and manipulate images. These functions include:

1. [**Black & White Filter:**](blackAndWhite.cpp) Convert an image to black and white, removing color information.
2. [**Invert Filter:**](invertImage.cpp) Invert the colors of an image.
3. [**Merge Filter:**]() Merge two images into a single image.
4. [**Flip Image:**](flipImage.cpp) Flip an image horizontally or vertically.
5. [**Rotate Image:**](rotateImage.cpp) Rotate an image by a specified angle.
6. [**Darken and Lighten Image:**]() Adjust the brightness of an image to make it darker or lighter.

## Usage

To use this Image Processing Tool, follow these steps:

1. Clone this repository to your local machine.
2. Compile the C++ code using a C++ compiler.
3. Run the compiled program.
4. Choose one of the available image processing functions from the menu.
5. Provide the necessary input, such as image files and parameters, as prompted.
6. The processed image will be generated and saved as output.

Feel free to explore and modify the code to suit your needs or extend its functionality.

## Example Usage

Here's an example of how to use the Black & White Filter:

```bash
$ ./image-processing-tool
Please select a filter to apply or 0 to exit: 
1. Black & White Filter
2. Invert Filter
3. Merge Filter
4. Flip Image
5. Rotate Image
6. Darken and Lighten Image
Your Choice Here --> 1

Enter the source image file name: input.bmp
Enter the target image file name: output.bmp

Filter applied successfully!
```

## Authors

Seif Khaled - [Github](https://github.com/SeifKhaled13)

Osama Eslam - [Github](https://github.com/Osama2004o)

Mohamed Ahmed Ezz_eldin - [Github](https://github.com/mo-ezz-eldin)

## License
[MIT License](LICENSE)