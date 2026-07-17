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

