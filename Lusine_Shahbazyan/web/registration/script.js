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
        return;
    }

    if(array.length === 0)
    {
        array.push(obj);
        console.log("Registration completed successfully")
    }

    for(let i = 0; i < array.length; ++i)
    {
        if(obj.username == array[i].username || obj.password == array[i].password)
        {
            console.log("There is user with this password and username");
            return;
        }
    }
    console.log("Registration completed successfully")
    array.push(obj);
}

function authentication(uname, passwd, array)
{
    for(let i = 0; i < array.length; ++i)
    {
        if(array[i].username == uname && array[i].password == passwd)
        {
            console.log("Authentication was successful");
            let userData = array[i].firstname + " " + array[i].lastname + " " + array[i].age;
            console.log(userData);
            return;
        }
    }
    console.log("There is no user with this password and username");
    return;
}

let usersDataBase = [];

let user1 = new Admin("uname1", "password1", 30, "Mary", "Makaryan");
registration(usersDataBase, user1);

let user2 = new Guests("uname2", "password2", 12, "Ani", "Andreasyan");
registration(usersDataBase, user2);

let user3 = new Guests("uname3", "password9", 19, "Aren", "Arayan");
registration(usersDataBase, user3);

let user4 = new Guests("uname3", "password3", 20, "Davit", "Adunc");
registration(usersDataBase, user4);

console.log(user1);
console.log(user2);
console.log(user3);
console.log(user4);
console.log(usersDataBase);

user1.writeComments();
user3.writeComments();
user1.replyComments();
user3.replyComments();
user1.writeArticles();

authentication("uname3", "password9", usersDataBase);