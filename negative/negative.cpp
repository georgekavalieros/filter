#include "negative.h"

Color* FillColorFromRawData(Color* color, float* data, int width, int height) {
	int p = 0; // Holds the position of the current 
			   // color value within the raw data array.

	// Iterate through the image data and fill r, g, b
	// respectively with data from the 1-dimensional 
	// float array.
	//
	// For each color value move the position by 1
	// i.e. r -> pos(0), g -> pos(1), b -> pos(2)...
	//
	// Then increase the position pointer by 3, since a pixel 
	// consists of three r, g, b values.
	//
	//                             (p = p + 3)
	//                             |
	// Raw data   : [134, 58, 109, 90, 204, 20, ...]
	//               |     |   |
	//               |     |   (p + 2)
	//               (p) (p + 1)
	//
	// Color data : [{134, 58, 109}, {90, 204, 20}, ...]
	for (int i = 0; i < IMAGE_SIZE; i++) {
		color[i].r = data[p];
		color[i].g = data[p + 1];
		color[i].b = data[p + 2];

		p = p + 3;
	}

	return color;
}

Color* ApplyNegativeFilter(Color* color, int width, int height) {
	Color* white = new Color(1, 1, 1); // (1, 1, 1) is white since each color channel 
									   // goes from 0.0f (darkness) to 1.0f (full color brightness).

	// Calculate negative using the type:
	// p(x, y) = (1, 1, 1) - p(x, y)
	for (int i = 0; i < IMAGE_SIZE; i++) {
		color[i] = *white - color[i];
	}

	return color;
}