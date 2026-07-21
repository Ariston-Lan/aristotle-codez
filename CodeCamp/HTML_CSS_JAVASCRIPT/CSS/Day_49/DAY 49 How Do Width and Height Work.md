# How Do Width and Height Work?

## Width and Height
In CSS the width and hieght properties are used to control the dimensions of elements on a webpage.

These properties can be defined in different units such as pixels (px), percentages (%), viewport units (vw, vh) and more.

- The width property specifies the width of an element. If you do not specify a width then the default is set to auto. This lets the browser determine the element's width based on its content parent, and display type. For a div element, width: auto makes it expand to fill the full width of its parent container. 

- The height property specifies the height of an element. Similarly, the height is auto by default, which means it will adjust to the content inside. 

### Example
```html
<head>
    <style>
        .box {
            width: 100px;
            height: 100px;
            background-color: skyblue;
        }
    </style>
</head>
<body>
    <div class='box'></div>
</body>
```
In this example, we have div element named box. This element will be occupying 100px in hieght and width, whereas the background color will be skyblue.

- The min-width property specifies the minimum width an element can be. Even if the content inside is smaller, the element won't shrink below this value.

- The min-height specifies the minimum height an element can be. It ensures that the element does not become shorter than the set value

```html
<head>
    <style>
        .box {
            width: 50px;
            min-width: 100px;
            height: 50px;
            min-height: 100px;
            background-color: lightcoral;
        }
    </style>
</head>
```

Even though the box has its width and height set to 50px, it will actually be 100px by 100px because the min-width and min-height are seet to 100px, which are larger than the specified width and height.

- The max width and max-height are the same rules as the minimum just flipped. Meaning it can't go any bigger than the specified limits.

# What Are the Different Types of CSS Combinators?

## CSS combinators
CSS combinators are used to define the relationship between selectors in CSS. They help in selecting elements based on their relationship to other elements, which allows for more precise and efficient styling.

### Descendant combinator
A descendant combinator is used to target elements matched by the second selector. if they are nested within an ancestor ekement that matches the first selector. An ancestor can be parent, grandparent, or any ancestor further up the document tree.

#### Example
```html
<link rel='stylesheet' href='stylesheet.css'>

<figure>
    <img src="blahblahblah.jpeg">
    <figcaption>This is a cute picture of a thing</figcaption>
</figure>
```

```css
figure img {
    border: 4px solid red;
}
```

- This example gives the element img, which is the child of figure, a solid red border that is 4px thick.

### Child conbinator
The child combinator (>) in CSS is used to select elements that are direct children of a specified parent element. This combinator targets only elements with a specific parent, making your CSS rules more precise and preventing uninteneded styling of deeper nested elements

#### Example
```html
<link rel="stylesheet" href="stylesheet.css">

<div class ="container">
    <p>First</p>
    <div>
        <p>Second</p>
    </div>
    <div>
        <p>Third</p>
    </div>
</div>
```

```CSS
.container > p {
    color: blue;
}
```
- In this example we are targeting the direct child of container class. This will give direct child the text color of blue. Since the other paragraph elements are nested inside div elements, they are not considered direct children of the container class and will not get the text color blue.

### Next-Siblings Combinator
The next-sibling combinator (+) in CSS selects an element that immediately follows a specified sibling element. 

This combinator is useful when you want to apply styles to an element that directly follows another element, allowing for targeted styling based  on the element's position relative to its siblings.

#### Example
```html
<link rel="stylesheet" href="styles.css">

<figure>
    <img
    src="NFjdsfsalfa.jpeg"
    alt="A picture of a big frog jumping on a log"
    >
    <figcaption>A big frog jumping on a log</figcaption>
</figure>
```

```CSS
img + figcatpion {
    border: 4px solid black;
}
```

- In this example, the next-sibling combinator selects the figcaption element that immediately follows up the img element. The applied CSS rule adds a 4px solid block border around the figcaption element

### Subsequent-Sibling combinator
Unlike the next-sibling combinator, which targets only the immediately following sibling, the subsequent-sibling combinator (~) can target any siblings that follow the specified element, offering greater flexibility in styling.

#### Example
```html
<link ref="stylesheet" href="stylesheet.css">

<div class="container">
    <h2>Subheading</h2>
    <p>First paragraph.</p>
    <p>Second Paragraph</p>
    <p>Third paragraph.</p>
    <p>Another paragraph element</p>
</div>
```

```CSS
h2 ~ p {
    color: green;
}
```
- In this example, all paragraph elements following the h2 element will have the text color green.

# What Is the Difference Between Inline and Block-Level Elements in CSS?

## Block-level elements
Block-level elements are elements that take up the full width avaliable to them by default, stretching across the width of their container.

These elements always start ona  new line and path other content to the next line, creating a "block" of content.

Block-level elements have the CSS property display: block; applied by default. This property ensures that the element stretches to fill the container's width and appears on a new line.

Some common block-level elements are div, paragraphs, headings, ordered lists, unordered lists, and section elements.

### Example
```html
<p style="border: 2px solid red;">
    First paragraph
</p>
<p>Second paragraph</p>
```

- In this example we have two paragraph elements where the first one has a red border around it. The two paragraph elements do not share the same line because they are block level elements by default. So both paragraph elements will take up the full width of its conainer, which in this case is the body element.

- Block-level elements are ideal when you want to content to stack vertically, such as paragraphs, sections, or larger blocks of content. They're commonly used to define the layout and structure of a webpage.

## Inline elements
Inline elements, unlike block-level elements, only take up as much width as they need and do not start ona  new line. These elements flow iwth the content, allowing text and other inline elements to appear alongside them.

Inline elements have the CSS property display: inline; applied by default. This property ensures that the element remains with the wflow of the content and does not break onto a new file.

Common inline elements are span, a, and img elements.

### Example
```html
<p>This is a 
    <span style="color; red; border: 2px solid green;">red</span>
    word inside a paragraph.
</p>
```
- In this example, we have a span element nested inside of a paragraph element. The span element has a red text color with a green border around it so you can see the highlighted word better.

- The span element only takes up as much space as the word "red" and does not push the following content to a new line. Inline elements are best used for styling smaller portions of text or content within a line, such as emphasizing a word, creating hyperlinks, to applying specific styles to parts of a paragraph.

# How Does Inline-Block Work, and How Does It Differ from Inline and Block Elements?

## Inline-Block
Block-level elements behave like larger containers, or blocks that take up the full width of their parent container. They always start on a new line, and their height and width can be adjusted.

Inline elements only take up as much space as they need. They flow within the surrounding content and do not break onto a new line.

The inline-block property is a hybrid of these two behaviors. Like inline-elements, inline-block elemetns remain in the text flow without starting on a new line.

However, unlike inline-elements, you can adjust the width and height of an inline-block element just as you would with block-level elements. 

In short, the key difference between inline and inline-block is that inline elements cannot have their size controlled, whereas inline-block elements allow for full control over dimensions while still staying inline with other content.

### Example
```html
<link ref="stylesheet" href="stylesheet.css">

<div class="container">
    <span class="inline-block-element element1">Inline-Block</span>
    <span class="inline-block element element2">Inline-Block</span>
</div>
```

```CSS
.inline-block-element {
    display: inline-block;
    width: 150px;
    height: 100px;
}

.element 1 {
    background color: lightblue;
}

.element2 {
    background-color: lightgreen;
}
```

- In the example, we have a div with the class of container. Inside that div, we have two span elements. Each of the span elements is set to display: inline-block and has a width and height set as well.

- The inline-block elements will appear side by side because they have inline elements, but they also have a specififed width and height, which gives them block-like properties.

- If you remove the display: inline-block property, niether the height nor the width will be applied even though you defined it clearly. 

# What Are Margins and Padding, and How Do They Work?

## Margins
Margins control the spaces outside an element, helping seperate it from other elements and define the layout.

The four different margin properties are:
- margin-top
- margin-right
- margin-bottom
- margin-left

### Example
```html
<link rel="stylesheet" href="style.css">

<p>Paragraph one</p>
<p>Paragraph two</p>
<p>Paragraph three</p>
```

```CSS
p {
    margin-top: 20px;
    border: 2px solid black;
}
```

- In this eample we are applying a 20px of margin only to the top of each paragraph element. 

- But we could also apply margins that add spacing on the left or right of the element, or left, or bottom, or top. Basically any of the margin properties can be altered, so all the outside spacing can as well.

```CSS
p {
    margin-left: 20px;
    margin-right: 20px;
    margin-bottom: 30px;
    margin-left: 40px;
    border: 2px solid black;
}
```
- In this eample, we are assigning spacing values on all four sides of the paragraph element. 

### Margin Shorthand Noation
Another way to use the margin property is with shorthand notation. You can specify one, two, three, or four values at once.

When using a singular value on the margin shorthand, the exact value will be applied to all four sides of the target element.

#### Example
```html
<span>Paragraph one</span>
<p>Paragraph two</p>
<span>Paragraph three</span>
```

```CSS
p {
    margin: 10px;
}
```
- This code will apply 10px of margin equally to all four sides of the paragraph element.

```CSS
p {
    margin: 10px 20px;
}
```
- When using two rules, the first value applies to the top and bottom, while the second applies to the left and right sides of the element.

```CSS
p {
    margin: 10px 20px 30px;
}
```
- If three values are provided, the first values applies to the top margin, and the second value to the left and right margin, and the third value to the bottom margin.

```CSS
p {
    margin:m 10px 20px 30px 40px;
}
```
- And if you use all four values, the first value gets the top, second right, third bottom, andn fourth left.

## Padding
Padding controls the space inside an element, improving content, readability and aesthetic appeal.

Like the margin property, padding properties are padding up, right, bottom, and left. All the same shorthand logic for margin applies to padding as well.

