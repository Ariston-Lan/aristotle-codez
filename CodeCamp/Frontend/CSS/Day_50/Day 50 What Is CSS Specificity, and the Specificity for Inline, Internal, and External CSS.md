# What Is CSS Specificity, and the Specificity for Inline, Internal, and External CSS?

## CSS specificity
CSS specificity is a fundamental concepts that determines which styles are applied to an element when multiple rules could apply. It's calculated based on the type of selectors used.

The highest specificity is attributed to inline styles, which are applied directly to an element through the style attribute

```html
<link rel="stylesheet" href="stylesheet.css">

<p style="color: red;">Red paragraph</p>
<p>Other paragraph</p>
```

```CSS
p {
    color: red;
}
```

- In this example, the style CSS rule would override the CSS rule defined in the stylesheet.css file.

ID selectors also have a high level of specificty. If you give an element a specific ID, and then go on to apply a CSS rule such as all p elements are red, but give the IDed element a conflicting rule, then CSS will choose the ID rule over the general one.

After the style element and IDs, next is class selectors, attribute selectors, and pseudo classes.

Classes, type selectors (such as div and h1), and pseudo elements like ::before and ::after have lower specificity compared to the previous groups.

And then lastly the universal selector (*) has the lowest specificity of them all.

### Specificity Values
Specifity values are calculated as a four-part value (a, b, c, d):
- a: Inline styles (1 or 0)
- b: Number of ID selectors
- c: Number of class selectors, attribute selectors, and pseudo-classes
- d: Number of type selectors, pseudo-elements, and universal selectors.

Each part of the specificty value carries different weight

- Inline styles(a) have the highest weight, contributing a value of 1 to the first part of the specificity value

- ID selectors(B) carry the next highest weight, with each ID contributing 1 to the second part of the specificty value

- Class selectors, attribute selectors, and pseudo classes(c) carry moderate weight, with each contributing 1 to the third party of the specificity value

- Type selecotrs and psuedo-elements(d) have the most weight, with each contributing 1 to the fourth part of the specificity value

- Univerasl selector (*): The universal selector contributes 0 to the specificity calculation and does not affect specificity. Its inclusion in a selector does not change the specificty value.

# What Is the Universal Selector, and What Is Its Specificity?

## Universl selector
The universal selector is a special type of CSS selector that matches any element in the document. It is often used to apply a style to all elements on the page, which can be useful for resetting or normalizing styles accross different web browsers.

### Universal Selectors Specificity
It has a specificity value of (0, 0, 0, 0).

This means any other selector will override the styles set by the universal selector.

# What Is the Specificity for Type Selectors?

## Type Selectors
Type selectors, also known as element selectors, target elements based on their tag name.

```css
p {
    color: blue;
}
```

### Type Selector's Specificity
Type selectors have a specificity of (0, 0, 0, 1)

This is relatively low compared to other selectors.

# What Is the Specificity for Class Selectors?

## class selectors
These are selectors based on class

```css 
.class {
    color: blue;
}
```
They can also be combined with other selectors to create more specific results.

```css
p.bold-text {
    font-weight: bold;
}
```

- In this example this rule only applies to p elements and only makes them bold.

### Class selector's value
The specificity value for class selectors are (0, 0, 1, 0)

They can override the unviersal selector and type selectors, but not IDs and inline styles.

