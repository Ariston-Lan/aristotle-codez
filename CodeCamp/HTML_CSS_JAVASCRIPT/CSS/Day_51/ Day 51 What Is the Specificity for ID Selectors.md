# What Is the Specificity for ID Selectors?

## ID selectors
ID selectors are defined by a hash symbol followed by the ID name. They should be unique within an HTML document.

### ID selectors value
ID selectors have a value of (0, 1, 0, 0)

# What Is the important Keyword, and What Are the Best Practices for Using It?

## Important keyword
The !important keyword in CSS is used to give a style rule to the highest priority, allowing it to override any other declarations for a property.

When used, it forces the browser to apply the specified style, regardless of the specificity of other selectors.

### Example
```html
<link rel="stylesheet" href="styles.css">

<p class="para" style="background-color: lightblue; color: black;">This is a paragraph stylized via inline CSS but being overridden by the !important modifier
    </p>
```

```css
.para {
    background-color: black !important;
    color: white !important;
}
```

# How Does the Cascade Algorithm Work at a High Level?

## Cascade Algorithm
The Cascade Algorithm is the process the broswer uses to decide which CSS rules to apply when there are multiple styles targeting the same element. It ensures that the most appropriate styles are used, based on a set of well-defined rules.

### Relevance
The process begins with relevance. The browser first filters all the CSS rules to find those that actually apply to the element in question. This includes matching selectors and considering media queries that might be in effect.

- A media query is a CSS technique used to apply styles based ont he characteristics of the device or viewport, such as width, height, or orientation.

### Origin and Importance
Next, the algorithm considers the origin and importance. CSS can come from different sources: the browser's default styles (user-agent), styles set by the user, and styles written by the author (you).

Following the consideration of origin, the algorithm then evaluates the importance of each rule, giving priority to rules marked with !important, which override other rules given regardless of their source. 

### Specificity
After filtering by origin and importance, the algorithm looks at specificity. When two rules from the same origin and importance level apply, the rule with the higher specificity will be applied. 

- Specificity is a measure of how targeted a selector is, with more specific selectors taking precedence over more general ones.

### Order of Appearance
Finally if everything else is equal, the order of appearance comes into play. When two rules have the same specificity, the one that appears last in the CSS will be applied. This is why the order in which you write your styles can sometimes affect the outcome.

For instance,
```css
p {
    color: blue;
}

p {
    color: green;
}
```
- Since in this example, the element p selector with the decleration of color: green; is applied lasst, that's the one that actually applies to all the p elements rather than the first one. 

# How Does Inheritance Work with CSS at a High Level?

## Inheritance
Inheritance in CSS is a concept that determines how styles are passed down from parent elements to their child elements.

In CSS, not all properties are inherited by default. For example, properties like color, font-family, and line-height are inherited. This means if you set the text color on a parent element, all of its child elements will inherit that color unless you specifically override it.

For instance:
```html
<div style="color: blue;">
    This is the parent element
    <p>This is the child element, inheriting the color.</p>
</div>
```
- In this example, the paragraph element inside of the div inherits the color blue from its parent element, div.

On the other hand, properties like margin, padding, border, and background are not inherited by default. If you want a child element to inherit these styles, you need to explicitly set them, either directly on the child element or by using the inherit keyword.

The inherit keyword can be used to force inheritance of a property from a parent element, even if that property is not normally inherited.

For instance:
```html
<div style="padding: 20px;">
    This is the parent element with padding.
    <p style="padding: inherit;:">This is the child element inheriting padding</p>
</div>
```
- In this example the paragraph element inherits the padding from its parent, despite the fact that padding isnt inheritable, because of the fact that paragraph has its padding property set to inherit.

# How Do You Space List Items Using margin or line-height?

##  Spacing w/ Margins
Marigns can be used to create space between list items by applying margin properties to the li elements. This method allows you to contorl the spacing outside each list item, effectively increasing or decreasing the gap between them.

For instance:
```html
<link rel="stylesheet" href="stylesheet.css">

<ul>
    <li>Item 1</li>
    <li>Item 2</li>
    <li>Item 3</li>
</ul>
```

```CSS
ul li {
    margin-bottom: 40px;
}
```

- In this example, 40px of margin will be added to the bottom of each list item inside the unordered list.

## Spacing w/ Line Height
The line-height property adjusts the vertical spacing between lines within a single list item. 

While it primarily affects the spacing between lines of text within each item, it can also indrectly influence the overall spacing between list items if the items contain only a single line of text.

If list items have multiple lines of text, the line-height will affect the spacing between those lines, but it does not directly adjust the spacing between seperate list items themselves.

To control the spacing between individual list items, you would use margin or padding properties instead.

For instance:
```html
<link rel="stylesheet" href="stylesheet.css">

<ul>
    <li>Item 1</li>
    <li>Item 2</li>
    <li>Item 3</li>
</ul>
```

```CSS
ul li {
    line-height: 2;
}
```

- In this example the line height is set to be twice the font size, creating more vertical space within each list item.

# How Do the Different list-style Properties Work?

## list-style
The list-style property is used to control the appearance of lists on a webpage. It is also a short hand for three other properties:
- list-style-type
- list-style-position
- list-style-image

### list-style-type
The list-style-type property allows you to define the type of bullet point or number used in a list.

For unordered lists, you can choose from several bullet styles, such as discs, circles, or squares. 

For ordered lists, you can use different numbering systems, like decimal, Roman numerals, or even alphabetical characters.

For instance:
```html
<ul style="list-style-type: square;">
    <li>Item 1</li>
    <li>Item 2</li>
    <li>Item 3</li>
</ul>
```
- In this example, the bullet points of the unordered list are changed to squares.

### list-style-position
The list-style-position property controls the position of the buillet or number in releation to the list item's content. There are two values you can use: inside and outside. 

When you use the value outside, the bullet or number appears outside of the content, which is the default behavior.

When you use the value inside, the bullet or number appears inside the content, which my cause the text to wrap and align with the bullet or number.

### list-style-image
The list-style-image property allows you to use an image as the bullet point for your list items. This can be useful for adding a unique visual style to your lists. 

### list-style shorthand
The order of the values in the shorthand property dosent matter, but all three can be specified together.

For instance:
```html
<ul style="list-style: square inside url(randomimage.jpg);">
    <li>Item 1</li>
    <li>Item 2</li>
    <li>Item 3</li>
</ul>
```

As you can see, all list-item properties were specified, and since they are all differnet, the order dosen't matter.

# Why Are Default Link Styles Important for Usability on the Web?

## Default link styles
Default link styles are important for usability and accessibility.

The default style is blue for unvisited links, purple for visited links, both underlined, and red for actively clicking on it.

If you choose to edit these styles, make sure the core mechanics are still there (i.e. visited links have a different color, an indication that you've clicked on them etc.)

# How Do You Style Different Link States?

## Link states
There are different states of a link, including:
- link
- visited
- hover
- focus
- active

You can style any of these by doing
```css
a:link-state-name {
    property: value;
}
```

An example of this would be 
```css
a:visited{
    color: red;
}
```
This would make all visited links red on your webpage.