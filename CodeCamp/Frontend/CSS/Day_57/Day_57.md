# What Are Absolute Units in CSS, and When Should You Use Them?

As you design your page you will work with different properties like widths, heights, padding, margins, and more. When you define these properties, you will need to specify the length units of measurement you want to use.

There are two types of units you can use to define these properties: relative units and absolute untis.

## Absolute Units
Absolute units are of fixed length and are not relative to anything else. Relative means the length is relative to something else. For instance, if I have a dix with the class of box, and I add an image in that div and make the images width property: 50px, then even if box is smaller than 50px, the image itself will stay 50px in size.

Moreover, if you are on a device with a small screen, the image would still be 50px wide. If you are on a device with a big screen, still 50px wide.

So, when should you use absolute units like pixel? Generally, you use pixels when you need precise control over element dimensions, spacing, and layout. sometimes you might use pixels for margins, padding, and borders.

Here are some Absolute Units from largest to smallest:
- in
- cm
- mm
- q
- pc
- pt

# What Are Precentages in CSS, and When Should You Use Them?

## Precentages
Precentages in CSS are relative units that allow you to define sizes, dimensions, and other properties as a proportion of their parent element.

So basically when you set a percentage you are saying "in comparison to its container"

So an image in a div for example, if you set its width to 50% it will be 50% wide in comparison to the width of the div. So if the div is 100px, the image will be 50px. If you grow the div to 200px, the image will be 100px wide. 

They can also be used for font-sizes too.

Also they are pretty useful for vertical centering. Using the transform property you can set an image to always be in a certain position relative to its parent as well.

Using precentages for flexible images is a pretty common practice, and in general are ideal for creating fluid layouts that adjust to various screen sizes.

# What Are ems and rems in CSS, and When Should You Use Them?
ems and rems are two types of relative units

## ems
em units are relative to the font size of an element. If you're using ems for the font-size property, the size of the text will be relative to the font size of the parent element.

Let's show an example:
```html
<link rel="stylesheet" href="stylesheet.css">

<p class="para">I am a p element</p>

<div class="blue-box"></div>
```

```css
.para {
    font-size: 20px;
    margin-bottom: 1.5em;
    border: 2px solid red;
}

.blue-box {
    background-color: blue;
    color: white;
    padding: 10px;
    width: 100px;
    height: 100px;
}
```

For the HTML, we have a paragraph and a div element. The paragraph element has a class of para, and the div element has a class of blue box.

In the para class, we set the font-size to 20px, and then we set the margin bottom to be 1.5em. This means that the margin-bottom will be 1.5 times the font size of the paragraph element. 1.5em results in 30px of margin-bottom of the paragraph. then the border is just for you to see the margin  better.

If we removed the font-size property from the para class, the em would then be relative to the font size of the parent element, which in this case would be the body element, which has a default font size of 16px.

Good use cases for ems would be when you are working with modular components like butotns or cards. By using em units, you can ensure that all aspects of the component are proportional.

## rems

For this with visual impairments, they may increase the font size to make it easier to read. But if you are setting pizels for font-sizes in your web designs, the text will not scale proportionally with the rest of the content. 

One way to address this is to use rem units for typography. A rem unit is relative to the font size of the root element, which is the html element.

By default, the font size of the html element is 16px. If the user increases the font size in their browser setting, the font size of the html element will increase, and all rem units will scale proportionally.

here is an example:

```html
<link rel="stylesheet" href="stylesheet.css">

<p>Regular Text</p>
<p class='para'>This text is slightly larger</p>
```

```css
.para {
    font-size: 1.2rem;
    margin-bottom: 1.5em;
    border: 2px solid red;
}
```

By setting the font-size to 1.2 rem, the font size of the paragraph wlement will be 1.2 times the font size of the root element. if the user hasn't changed the default font size, the font size will be 19.2px because it is 1.2 times 16px.
