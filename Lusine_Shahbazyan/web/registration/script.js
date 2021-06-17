class User
{
    constructor(uname, passwd, age)
    {
        this.username = uname;
        this.password = passwd;
        this.age = age;
    }

    writeComments()
    {
        if(this.role == "guests")
            console.log("I am guest.");
        else 
            console.log("I am admin");
    }

    replyComments()
    {
        if(this.role == "guests")
            console.log("Guests have no permission to reply.");
        else 
            console.log("Admin can reply to comments.");
    }
}

class Guests extends User
{
    role = "guests"
    constructor(uname, passwd, age, firstname, lastname)
    {
        super(uname, passwd, age, firstname, lastname);
        this.firstname = firstname;
        this.lastname = lastname;
    }
}

class Admin extends User
{
    role = "admin";
    constructor(uname, passwd, age, firstname, lastname)
    {
        super(uname, passwd, age, firstname, lastname);
        this.firstname = firstname;
        this.lastname = lastname;
    }

    writeArticles()
    {
        console.log("I am admin and i can write articles.")
    }
}

function registration(array, obj)
{
    if(obj.age < 15)
    {
        console.log("Only people over 15 can register");
        return false;
    }

    if(array.length === 0)
    {
        console.log("Registration completed successfully")
        return true;
    }

    for(let i = 0; i < array.length; ++i)
    {
        if(obj.username == array[i].username || obj.password == array[i].password)
        {
            console.log("There is user with this password and username");
            return false;
        }
    }
    console.log("Registration completed successfully")
    return true;
}

function authentication(array)
{
    let uname = prompt('Enter your username');
    let passwd = prompt('Enter your password');
    for(let i = 0; i < array.length; ++i)
    {
        if(array[i].username == uname && array[i].password == passwd)
        {
            console.log("Authentication was successful");
            return;
        }
    }
    console.log("There is no user with this password and username");
    return;
}

let users = [];

let user1 = new Admin("uname1", "password1", 30, "Mary", "Makaryan");
if(registration(users, user1))
{
    users.push(user1);
}
let user2 = new Guests("uname2", "password2", 12, "Ani", "Andreasyan");
if(registration(users, user2)) 
{
    users.push(user2);
}
let user3 = new Guests("uname3", "password9", 19, "Aren", "Arayan");
if(registration(users, user3)) 
{
    users.push(user3);
}
let user4 = new Guests("uname3", "password3", 20, "Davit", "Adunc");
if(registration(users, user4)) 
{
    users.push(user4);
}

console.log(user1);
console.log(user2);
console.log(user3);
console.log(user4);
console.log(users);

user1.writeComments();
user3.writeComments();
user1.replyComments();
user3.replyComments();
user1.writeArticles();

authentication(users);
