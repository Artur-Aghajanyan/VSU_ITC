# Page Redirection
  * Content
  * How to run
  * Classes
  * Useful notes

# CONTENT
 1. index.html - to run users.js file
 2. users.js - classes to create users, authenticate, etc.


# HOW TO RUN
google-chrome/firefox index.html
Type F12 and see result in console.log

# CLASSES

  * Guest
  * User - from Guest
  * Admin - from User
  * Authentication

# GUEST
 - to create guest call "createGuest()" function;
  (If there are no admin you can't create guest.)
 - guests are in "guests" array.
 - functions` 
    readArticle("article_name");

# USER
 - to create user call "createUser("name", "surname", age, "login", "password")" function.
  (if there are no admin first call of this function creates admin, admin is first element of "users" array, other users also are elements of "users" array.) 
 - user have to authenticate before using main functions of user.
 - functions` 
    logOut();
    changeLogin(curr_login, new_login);
    changePassword(curr_pass, new_new);
    writeArticle(art_name) ;
    updateArticle(art_name);  -- can update only own articles
    
# ADMIN
  - to create call "createAdmin("name", "surname", age, "login", "password")" or "createUser("name", "surname", age, "login", "password")" functions.
  - There can be only one admin;
  - admin becomes first element of "users" array.
  - functions`
      createGroup(group_name);
      deleteGroup(group_name) ;
      updateArticle(art_name); -- overrides user updateArticle(art_name) function 

# USEFUL NOTES

 - Admin is created
 - one simple user is also created.
 - guest is created

 - Admin is authenticated

 - There are also a few functions to do checks during user creation and authentication.
