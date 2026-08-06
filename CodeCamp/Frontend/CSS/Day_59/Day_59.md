# What Are Examples of Location Pseudo-classes?

## Location Pseudo-classes

Location psuedo-classes are used for styling links and elements that are targeted within the current document. They offer a way to apply styles based on whether a link is visited or whether an element is currently in focus.

Some examples are:

- :link
- :visited
- :any-link
- :local-link
- :target

We already know link and visited, so lets look at the last three.

:any-link matches any anchor element with an href attribute, whether it has been visited or not (so its a combination of both link and visited)

:local-link targets links that point to the same document. It's primarily used for differentiating internal links from external ones. Although, no browser currently supports this.

:target selects an element that matches the current URL fragment identifier. Meaning when you link the link, and the href is to a specific element (like a section id for example), that element will have whatver values you specify within the block.

For instance:

```html
<link rel="stylesheet" href="styles.css" />
<nav id="table-of-contents">
  <ul>
    <li><a href="#section1">Introduction</a></li>
    <li><a href="#section2">Features</a></li>
  </ul>
</nav>

<section id="section1">
  <h2>Introduction</h2>
  <p>This is the introduction section.</p>
</section>

<section id="section2">
  <h2>Features</h2>
  <p>This section describes the features.</p>
</section>
```

```CSS
section:target {
  background-color: green;
  border: 2px solid green;
  padding: 10px;
}
```

In this example, when any section element is accessed via a link, it will have a background color of green, a border of green, and some padding applied.

# What are Examples of Tree-structural pseudo-classes?

## Tree-structural psuedo-classes

Tree-structural pseudo-classes allow you to target and style elements based on their position within the document tree. The document tree refers to the hierarchical structure of elements in an HTML document.

Here is a list of tree-structural pseudo-classes:
- :root
- :empty
- :nth-child(n)
- :nth-last-child(n)
- :first-child
- :only-child
- :nth-of-type
- :first-of-type
- :last-of-type
- :only-of-type

Let's taking a closer look at each

:root is usually the html element. It helps you target the highest level in the document so you can apply a common style to the entire document.

:empty targets empty elements. Like let's say you have a list that is updated upon user inputs, and one of the inputs is empty. This pseudo-class was made to distinguish that. The most practical use of this element is to just not display empty elements at all.

:nth-child(n) allows you to select elements based on  their position with a parent. while :nth-child(n) enables you to select elements by counting from the end.

The n can be a specific number or a keyword like odd or even. This is useful for styling table cells based on position: even and odd.

:first-child, :last-child, and :only-child all act on items within a parent container or the entire document.

:first-child selects the first element in a parent element or the document

:last-child selects the last element in a parent element or document

and :only-child selects the only element in a parent element or the document.

:first-of-type and :last-of-type select the first and last occurrence of a specific element type within its parent. It's useful for applying unique styles to the first or last instance of that element type among its siblings.

:nth-of-type(n) allows you to select a specific element within its parent based on its position among siblings of the same type. Like if you have 3 paragraphs you can choose p:nth-of-type(2) to choose the 2nd paragraph.

:only-of-type selects an element if it's the only one of its type within its parent. So if you have two divs, one containing two p elements, and one containing only one p element, p:only-of-type would only apply to the div containing a singular p element since in that container it is the only one of its type.

# Functional Pseudo-classes

Functional pseudo-classes allow you to select elements based on more complex conditions or relationships. Unlike regular pseudo-classes which target elements based on a state, for example, :hover, :focus, functional pseudo-classes accept arguments within parentheses, hence the name :functional pseudo-classes".

Examples of functional pseudo-classes are:
- :is()
- :where()
- :has()
- :not()

## :is()
The :is() pseudo class is useful when you want to style a group of elements that share some, but not all, characteristics. For instance, you might want to style different types of buttons on your website, including button elements, links styled as buttons, and input elements with types submit and reset. 

With is, you can group all of these (decoratively), as buttons so you give them all the decorations. Technically you could apply these styles to all of them by just adding commas but this is seen as more compact and understandable.'

Here is the basic syntax for it
```CSS
:is(button, a.button, input[type='submit', input[type='reset']]){
    color: white;
    background-color: darkblue;
}
```

In this example we group all of these elements together to have the same style, which is easier and more compact and readable than just assigning them in a long string of vertical commas.

## :where()
The :where() pseudo-class functions similarly to :is(), but it dosent increase the specificity of your selectors. This makes it ideal for applying styles without affecting the specificity of other rules.

You might use the :where() function to apply zero margin and padding to heading elements, but you can always override this by applying different styles later.

## :has()
the :has() pseudo class allows you to apply styles to a parent element based on the presence or state of its child elements. 

So if you have two divs, one with an h2 and one with an h3, 
```CSS
div:has(h2) {
    color: red;
}
```

This piece of code would only apply to the divs with an h2 in them.

## :not()

The :not() pseudo-class is ideal for situations where you want toa pply styles to a group of elements, excluding one or more specific exceptions. 

So if you have a bunch of buttons, you could style them buttons that are not primary are grey, like so:
```css
button:not(.primary){
    background-color: grey;
}
```

# Psuedo-elements

## Definition
Pseudo-elements are virtual or synthetic elements that don't directly match any actual HTML elements. They allow you to style specific parts of an element or insert content without adding extra HTML.

## Application
To apply a psuedo-element, attach it to the original element's selector using a double colon (::). Note that the selector can be any type, such as a class ID selector. Here is an example
```css
selector::pseudo-elemet {
    property: value;
}
```

This double colon is what distinguishes pseudo-elements from pseudo-classes.

## What do they do?
Pseudo-elements allow you to style specific parts of an element's content or insert content before or after it, but they cannot exicst independently. The element to which a pseudo-element is attatched is called its originating element.

Let's start with ::before and ::after.

::before lets you insert content just before the element's content 
while ::after lets you insert content after it.

so if you did 
```css
p::before {
    content: "PARAGRAPH";
    position: absolute;
    left: 3px;
    top: 8px;
}
```

The content property is used to represent the content you wish to add before the button text. In this example, we are adding a star. You'll notice that you can not only insert content but style whatever you insert it with.

For instance:
```html
<link rel="stylesheet" href="styles.css" />
<button class="cta-button">Learn More</button>
```

```css
.cta-button {
  background-color: orange;
  border: none;
  padding: 10px 30px;
  cursor: pointer;
  position: relative;
}

.cta-button::after {
  content: '➡️';
  position: absolute;
  right: 5px;
  bottom: 6px;
  font-size: 1.125rem;
  transition: transform 0.3s ease;
}
```

Here the transition property pushes the content (which is an arrow emoji) to the right by 2px any time the user hovers on the button. 

## ::first-letter

::first-letter is a pseudo element that targets the first letter of an element.

## ::marker

::marker is a pseudo element that lets you select the marker, bullet, or numbering of list items for styling