# What is Color Theory in Design?

## Color Theory

Color theory is the study of how colors interact with each other and how theya ffect our perception. It covers color relationships, color harmony, and psychological impact of color.

Colors can be classified as either primary, secondary, or tertiary.

### Primary Colors
Primary colors, yellow, blue, and red, ar ethe fundamental hues from which all other colors are derived.

### Secondary colors

Secondary colors result from mixing equal amounts of two primary colors, such as green, orange, and purple.

### Tertiary colors

Tertiary colors result from combining a primary color with a neighboring secondary color. Yellow-green, Blue-Green, and Blue-Violet are example of tertiary colrors.

## Warm colors

Warm colors are based on their temperature. Warm colors are like red, orange, or yellow

## Cool colors

Whereas cooler colors like blue, green, and purple evoke professionalism.

## Color Schemes
A color scheme is the set of colors chosen for a specific design or project. They usually are based on the principles of color theory.


### Analgous color schemes

Analgous color schemes create cohesive and soothing experiences. They have analogous colors, which are colors adjacnet to each other on the color wheel.

### Complementary color schemes

Complemntary color schemes create high contrast and visual impact. Their colors are located on the opposite ends of the color wheel, relative to each other.

### Triadic Color scheme

A triadic color scheme has vibrant colors, they are made from colors that are equidistant from each other. They make a triangle on the color wheel

### Monochromatic color scheme
In this color scheme, all the colors are derived from the same base color by adjusting its lightness.

# What are Named Colors in CSS, and When to Use them?

## Named colors

One way to define colors in CSS is by using named colors, such as predefined color names recognized by browsers.

Named colors in CSS are a collection of 140 standard color names like red, blue, yellow, aqua, black, and so on.

# What is the RGB Color Model, and How does the RGB Function work in CSS?

## RGB color model

The RGB color model stands for red green blue, primary colors of light. These three colors create a wide variety of colors.

RGB color model is an additive color model, meaning colors are created by combining light at varying intensities.

# What Is the HSL Color Model, and How Does the HSL Function Work in CSS?

## HSL Color Model

The HSL color model represents colors in a way that is more in line with how humans percieve color. 

The hue is the color type, represented as an angle on the color wheel, which ranges from 0 to 360 degrees. 0 degrees is red, 120 is green, and 240 is blue.


Saturation referes to the intensity of the color.

Lightness determines how light or dark the color is.

the hsl() function is used to define colors using the HSL color model:

```CSS
element {
    color: hsl(hue stauration lightness);
}
```

You can make colors semi-transparent using the HSL model by adding a /separator with an alpha value.

# What Are Hex Codes, and How Do they work in CSS?

## Hex Codes
A hex code is a six-char string used to rep colors in the RGB model. The "hex" refers to the base-16 numbering system, which uses digits 0 to 9 and letters A to F.

Hex codes specify the amounts of red, green, and blue that make up a particular color.

#000000 is black and #FFFFFF is white, and the representation for colors is first two char red, next two green, last two blue.

You can do shorthand by doing #000 which reads as red, then green, then blue. #FFF would still be white

# What are Linear and Radial Gradients, and How Do They Work in CSS?

## Gradients

Gradients in CSS allow you to create a smooth transition between two or more specified colors. Theya re often used to add depth, texture, and visual interest to web designs without the need for image files.

### Linear gradients
Linear gradients create a gradual blend between colors along a straight line:

```CSS
div {
    background: linear-gradient(to right, red, blue);
    width: 80%;
}
```

### Radial gradients
Radial gradients create a circular or elliptical gradient that radiates from a central point

```CSS
div {
    background: radial-gradient(circle, red, blue);
}
```
