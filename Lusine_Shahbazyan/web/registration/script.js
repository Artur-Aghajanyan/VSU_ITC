class User
{
    constructor(uname, passwd, age)
    {
        this.username = uname;
        this.password = passwd;
        this.age = age;
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
    writeComments()
    {
        console.log("You can write comments.")
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
    answerComments()
    {
        console.log("You can  answer in comments.")
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