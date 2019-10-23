#include <stdlib.h>
#include <math.h>

#include "colorUtils.h"

int max(int a, int b, int c) {
  return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}

int min(int a, int b, int c) {
  return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int toGrayScale(int *r, int *g, int *b, Mode mode) {
  if(r == NULL || b == NULL || g == NULL) {
    return 3;
  }
  int red = *r, blue = *b, green = *g;
  if(red < 0 || blue < 0 || green < 0){
    return 1;
  }else if(red > 255 || blue > 255 || green > 255) {
    return 2;
  }else if(mode != AVERAGE && mode != LIGHTNESS && mode != LUMINOSITY) {
    return 4;
  }
  else {
  if(mode == AVERAGE){
    *r = round(((double)red + (double)green + (double)blue) / 3.0);
    *g = round(((double)red + (double)green + (double)blue) / 3.0);
    *b = round(((double)red + (double)green + (double)blue) / 3.0);
  }else if(mode == LIGHTNESS) {
    *r = round(((double)max(red, green, blue) + (double)min(red, green, blue)) / 2.0);
    *g = round(((double)max(red, green, blue) + (double)min(red, green, blue)) / 2.0);
    *b = round(((double)max(red, green, blue) + (double)min(red, green, blue)) / 2.0);
  }else if(mode == LUMINOSITY) {
    *r = round((0.21 * red) + (0.72 * green) + (0.07 * blue));
    *g = round((0.21 * red) + (0.72 * green) + (0.07 * blue));
    *b = round((0.21 * red) + (0.72 * green) + (0.07 * blue));
  }
return 0;
}
}

int toSepia(int *r, int *g, int *b) {
  if(r == NULL || b == NULL || g == NULL) {
    return 3;
  }
  int red = *r, blue = *b, green = *g;
  if(red < 0 || blue < 0 || green < 0){
    return 1;
  }else if(red > 255 || blue > 255 || green > 255) {
    return 2;
  }

  else {
  *r = round(0.393 * red + 0.769 * green + 0.189 * blue);
  *g = round(0.349 * red + 0.686 * green + 0.168 * blue);
  *b = round(0.272 * red + 0.534 * green + 0.131 * blue);
  return 0;
}
}
