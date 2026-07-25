# What Is User-Centered Design?

## User-Centered Design
User-Centered Design is a web development approach that prioritizes the end user, from their needs to their perferences and limitations. The goal of user centered design is to craft a web page that is intuitive, efficient to use, and pleasing for your users to interact with.
# What Are User Requirements, User Research, and Testing?

## User Research
User research is the systematic study of the people who use your product. The goal is to measure user needs, behaviors, and pain points.

This comes in many forms. Perhaps one of the most common is the Net Promoter Score, or NPS. The NPS measures how likely your users are to recommend your product to a friend. NPS is measured through a survey offered at key milestones along the user's joruney, such as after 7 days, 30 days, and 90 days. NPS is emasured on a scale of 0 to 10, with 9 and 10 indicating an active promoter of your site.

Another research vector is an exit interview. This is a survey you show to your users when they cancel a subscription or delete an account. Data from this survey can give you insight into the factors causing user churn, so you can address them.

## User Testing
User testing refers to the practice of capturing data from users as they interface with your application. For example, a video game going through beta testing is a form of user testing.

One you might run into as a web dev is A/B testing. A/B testing involves shipping a new feature to a randomly selected subset of your user base. You can then leverage analytics data to determine if the feature is beneficial.

## User Requirements
User requirements refer to the stories or rubric that your application needs to folllow. This can inform the development process. User requirements might be defined by user research, or industry standards. 

These requirements may be functional, meaning they dictate how your application shouldwork, or non functional, meaning they define how your application should behave. User requirements are not static either. The information from both user testing and user research can impact the requirements and they will change as your use rbase changes.

# What Are Best Practices for Designing a Dark Mode Feature?

## Dark mode
Dark Mode is a special feature which turns the default light color scheme into a dark color scheme. I won't go too deep into the specifics, just no darkmode isnt just black background with white text. It's about reducing eye strain. So try doing a soft contrast, like a dark gray background with a light grey text instead.

# What Are Best Practices for Designing Breadcrumbs?

## Breadcrumbs
Breadcrumbs are a navigation aid that shows the user where they are in the site's hierarchy. Here is an example of what breadcrumbs look like for a mockup electronics website

```html
<link rel='stylesheet' href='styles.css'>
<div class="breadcrumbs">
    Home / Electronics  Phones / Smartphone XYZ
</div>
```

In most websites breadcrums are displayed a the top of the page, showing the user the path they took to get to the current page. Starting from the Homepage, the user navigated to Electronics, and so on.

The use of breadcrumbs is helpful because it can help users understand where they are in the site's hierarchy and how to navigate back to the previous pages. 

When it comes to designing breadcrums, there are a few considerations to keep in mind. The first is to decide on what the separator will be. It can be '/' or '>' or '>>' just be specific and consistent.

The second consideration is the placement of the breadcrumbs. You should have them either at the top of the page or below the navigation bar.

Another consideration is the size of the breadcrumbs. You want to make sure htey are large enough to be easily read, but not so large they take up too much space on the page.

# What Are Best Practices for Designing Cards?

## Card Components
Card componenets are a very common occurrence in e-commerce, social media, and news sites. They are used to help display information in a structures way. When you are designing your cards, it is important to understand best practices so your users can easily understand the information you are trying to convey.

The first consideration for card design should be simplicity. Just make the cards simple and easy to read, sometimes doing too much makes them cluttered and defeats the whole purpose of them.

Another consideration is where the user can click on the card. Some card designs will have a single button, making it obvious where the user can click. other card designs will have the entire card clickable. When the user hovers over any part of the card, the card will change color or have a shadow effect to show the card is clickable. Whatever design you choose, it needs to be consistent throughout your site

Another consideration is the use of media on your cards. Choosing high-quality media can enhance the user experience. If you are using images or videos for say a product card, the higher quality the more the user will be interested in that product. 

# What Are Best Practices for Designing Infinite Scrolls?

## Infinite Scrolls
Infinite scrolling is a design pattern that loads more content as the user scrolls down the page. Oftentimes, this is used on social media sites like Twitter. For example, if you are logged in and want to see more tweets you can scroll down and more tweets will load. This is an example of infinite scrolling.

Infinite Scrolling is also used as a substitute for pagination. Pagination is a design pattern that breaks up content into different pages.

As you incorporate infinite scrolling into your design, there are a few best practices to keep in mind. The first consideration is to provide a "Load More" button that lloads net set of results when the user clicks on it.

Another consideration is the back button so the user dosent have to scroll all the way back up.

Also maybe keep the footer visible at all times otherwise they obviously can't scroll down and click it.

# What Are Best Practices for Designing Modal Dialogs?

## Modal Dialogs
Ammodal is the type of pop-up that a website might show you on top of their content. HTML has a dialog element that you can use to create modals. The content behind a modal is usually dimmed. This helps the user visually focus on the area you want them to interace with, in this case the modal.

It's always a good idea to allow the user to click outisde of the modal to close it.

Modals should also have a close button, and a CTA (call to action) button.