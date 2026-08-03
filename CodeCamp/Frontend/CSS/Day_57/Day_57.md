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

# What Are vh and vw Units, and When Should You Use Them?
In CSS vh and ww are viewport-relative units that allow you to size elements based on the dimensions of the browser window. These units are particularly useful for creating responsive designs that adapt to different screen sizes.

## vh and vw
vh stands for "viewport hiehgt", and 1vh is equal to 1% of the viewport's height.

Similar vw stands for "viewport width" and 1vw is equal to 1% of the viewport's width.

This means if you set an element's height to 100% vh, it will occupy the full height of the viewport.

These units are handy for full screen layouts, you might want to use them to create a hero section that always fills the entire screen.

vh and vw can also be used for typography to create responsive text sizes. 

Beware that they can cause layout shifts when the mobile address bar appears and dissapears. 

# What Is the calc() Function, and How Does It Work?

## calc()

With the calc function, you can perform calculations directly within your stylesheets to determine property values dynamically. This emans that you can create flexible and responsive user interfaces by caluclating dimensions based on the viewports size or otehr elements.

You can perform calculations on values that represent length, angle, time, percentages, numbers, and colors. You can also combine different units like pixels, percentages, and ems.

With numbers, all the values in the expiression must have their correspanding units.

You can use addition, subtraction, muliplcation, and divison operators in the expression.

# What Are Pseudo-classes, and How Do They Work?

## Pseudo-classes
Pseudo-classes are special CSS keywords that allow you to select an element based on its specific state or position. The element's state or position could include:

- active
- hovered
- focused
- first child of a parent
- last child of a parent
- link has been visited
- When it's disabled

And other things too.

To use a psuedo-class you add it to the selector by using a colon : followed by the name of the pseudo-class.

I am not gonna go over all of them but there are some pretty useful ones to know.

:first-child pseudo-class sselects an element that is the first child of its parent element.

for instance:
```html
<style>
    div:first-child {
        color: red;
    }
</style>
<div>
    <p>I am red</p>
    <p>I am not</p>
    <p>I am also not red</p>
</div>
```


The :last-child pseudo-class targets the last element that is the child of the parent. I won't show an example because I am lazy but it's fairly obvious

The :disabled pseudo-class lets you style an interactive element in disabled mode (so while it's disabled it looks different, which is great for users).

# What Are Examples of Element User Action Pseudo-classes?
User feedback is a crucial element of web design. It's important for users to receive visual cues when they interact with elements on a website.

## User Action Pseudo-classes
User action pseudo-classes in CSS are special keywords that allow you to provide user feedback without needing Javascript.

Basically, psuedo-classes like :hover, :active, :focus, :visited, and many more enable you to change the appearance of elements based on the state they are in. This is useful for changing the state of links after they've been visited, giving important user feedback.

:checked is another psuedo-class in CSS that allows you to style form elements such as checkboxes and radio buttons when they are selected

# What Are Examples of Input Pseudo-classes?

## Input Pseudo-Classes
input-psuedo-classes can make your forms feel more intuitive and user-friendly. Let's look at some examples.

:focus allows you to target an input element when a user selects or clicks on it.

:hover does the same, but when a user hovers over it

:required targets input elements that have the required attribute. Signlaing to users they must fillout those forms first.

:valid psuedo-class styles the input fields that meet the validation critera. Similarly, :invalid styles the input fields that do not meet the criteria.

### cursor: not-allowed
cursor: not-allowed isnt a pseudo-class, but it is a property value that changes the appearance of the cursor to indicate that an action is not permitted.

Some other examples are
- :autofill
- :optional
- :in-range and :out-of-range (style elements based on whether their values are within or outside range constraints)