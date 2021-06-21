# Pagination
- Content
- How to run
- How works JS file


# Content
1. pagination.html - to run pagination.css and pagination.js files
2. pagination.css - to give stile to pagination
3. pagination.js - to give pages wich have similar content

# How to run
To run the code you need to open pagination.html file with google-chrome/firefox, then click F12 or ctrl+shift+I then watch the result in console. <br>

# How works JS file
In 109-111 lines I made 'array', 'size', 'count' variables, from which 'count' shows the count of 'array' elements. In code array elements are numbers from 1 to 100, which are given with for loop(113-115). 'size' shows as how much elements of array will contain a page.  Then in line 117 I made an object 'pagination' of class 'Pagination' with 3 arguments: 'array', 'size', 'count'. The class has constructor with 3 arguments and following functions:
1. goToPage - takes as an argument the number of page and returns the content of that page,
2. prevPage - takes as an argument the number of page and returns the content of preveous page,
3. nextPage - takes as an argument the number of page and returns the content of next page,
4. firstPage - doesn't take any arguments and returns the content of first page,
5. lastPage - doesn't take any arguments and reutrns the content of last page,
6. onClick - doesn't take any arguments, in this function I made buttons which are giving some information after clicking on them.
