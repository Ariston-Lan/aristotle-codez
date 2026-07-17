# What Is CSS, and What Is Its Role on the Web?

## CSS
CSS stands for Cascading Style Sheets. It is a crucial component of the modern web. It's a stylesheet languaeg used to apply styles for HTML. In simpler terms, if HTML is the structure of a web page, CSS is what makes it look good.

The primary role of CSS is to seperate the content of w eb page from its visual presentation.

# What Is the Basic Anatomy  of a CSS Rule?

## Selector and Declaration
A CSS rule is made up of two main parts: a selector and decoration block.


- Selector
- - A selector is a pattern used in CSS to identify and target specific HTML elements for styling. Examples of selectors include type selectors, class selectors, and ID selectors.

```css
selector {
    property: value;
}
```

- Declaration
- - The curly braced provided in the basic syntax are known as a declaration block. A declaration block applies a set of styles for a given selector, or selectors. 

- - Inside the declaration block, you'll have a series of declarations. Each declaration consists of  a property and a value. 

- - - The property is the CSS identifier that specifies which feature is being styles. An example of this property would be the background-color property.

- - - The value would be the specific setting applied to that property. For example, if the property is background-color, a value could be purple, which sets the background color to purple.

- - After each property name, you need to place a colon, and after each value, you should have a semicolon.

### Example
```html
<link rel="stylesheet" href="styles.css">
<h1>Learning about CSS</h1>

<p>This is an example paragraph element</p>
<p>This is another example paragraph element</p>
```

```css
p {
    color: blue;
}
```
In this example, the type selector is targetting all paragraph elements on the page. Inside the type selector, there is one singular declaration. In that declaration, there is the color property with its value set to blue. This will change the text for all paragraph elements to be blue.

## Selector Lists
If you want to apply the same set of styles to muiltiple selectors, you can create a selector list with each selector seperated by a comma.

### Example
```html
<link rel="stylesheets" href="style.css">

<h1 id="title">Example heading</h1>
<h2 class="subheading">Example subheading</h2>
<p>This paragraph is not affected by the selector.</p>
```

```css
#title,
.subheading {
    color: navy;
}
```
In this example, there is a selector list. In the selector list, there is an id selector targetting the HTML element with the id value of title. All id selectors start with the hash '#' symbol.

Then there is a comma followed by a class selector, that targets all HTML elements with the class value of subheading. All class selectors must start with a dot '.'.

The entire selector list will recieve the same styling, with the text color set to navy.

# What Is the Meta Viewport Element Used For?

## Meta Viewport
The meta viewport element is a crucial component in responsive web design. It's a special HTML meta element that gives the browser instructions on how to control the page's dimensions and scaling on different devices, particularly on mobile phones and tablets.

The basic synatx of the meta viewport element is:
```html
<meta name="viewport" content="width=device-width initial-scale=1.0">
```
This element is typically placed in the head section of your HTML document. 

- width=device-with
- - This part tells the browser to set the width of the page to match the screen width of the device. 

- initial-scale=1.0
- - Sets the initial zoom level when the page is first loaded. A value of 1.0 means that the page is displayed at 100% zoom without any scaling.

The meta viewport element also allows you to control whether users can zoom in and out of your web pages. It is possible to disable zooming with the user-scalabe=no attribute, but its generally reccomended to avoid this for accessibility reasons.

# What are some Default Browser Styles Applied to HTML?

## Default Browser Styles
- Headings
- - Headings are styled by default to have varying sizes and wieghts

- hr
- - This element creates a horizontal rule often used to visually seperate sections of content. Broswers generally apply a simple linestlye to this element.

- blockquote
- - Blockquotes are used to indicate a section of text that is a quotation from another source. Browsers typically add indentation and sometimes italicize the text.

- <a> (Anchor element)
- - The anchor element is styled with a default blue color with an underlining to make it recognizable as a link.

- ul and ol
- - Browsers add basic formatting to lists, including indentation and bullets or numbers, depending on whether you are using unordered lists or ordered lists.

# What Are Inline, Internal, and External CSS, and When Should You Use Each One?

## Inline CSS
Inline CSS is written by directly within an HTML element using the style attribute. it applies styles to a specific element.

```html
<p style='color: green;'>This is an inline-styled paragraph</p>
```
Inline CSS is generally used for quick, one-off styles or to override other styles for a specific element. However, it should be avoided in most cases because it can clutter the HTML and make the code harder to maintain.

Most of the time it is better to use external CSS to keep your styles organized and maintanable.

## Internal CSS

Internal CSS is best used when you need to apply styles to a specific page rather than across multiple pages. It's useful for single-page websites or when styles don't need to be reused elsewhere.

### Example
```html
<head>
    <style>
        p {
            color: blue;
        }
    </style>
</head>
<body>
    <p>This paragraph is styled using internal CSS.</p>
</body>
```

## External CSS
External CSS is written in a seperate .cc file and linked to the HTMl document using the link element in the head section.

### Example
```html
<head>
    <link rel='stylesheet' href='style.css'>
</head>
<body>
    <p>This paragraph is styled via external CSS</p>
</body>
```

```css
p {
    color: red;
}
```

- The link element has a rel attribute that specifies the relationship between the current document and the linked resource, such as linking to a stylesheet or an external resource. On the other hand, the href attribute specifies the URL of the linked resource, indicating where the resource should be retrieved from.