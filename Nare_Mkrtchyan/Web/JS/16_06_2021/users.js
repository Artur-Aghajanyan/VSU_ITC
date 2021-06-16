class Guest {
    constructor() {
    }
    readArticle(art_name) {
        if(Admin.articlesAll.find(art => art === art_name) != undefined) {
            console.log(`You are reading ${art_name} aricle.`);
        }
        else {
            console.log(`There are no ${art_name} aricle`);
        }
    }
}
class User extends Guest {
    uniquePass(pass) {
        return users.find(element => element.password === pass) == undefined
    }
    uniqueLogin(login) {
        return users.find(element => element.login === login) == undefined
    }
    constructor(name, surname, age, login, password) {
        super();
        if(this.uniqueLogin(login) && this.uniquePass(password)) {
            this.login = login;
            this.password = password;
        }
        else {
            return;
        }
        this.name = name;
        this.surname = surname;
        this.age = age;
        this.password = password;
        this.authenticated = false;
        this.role = "user";
        this.articles = [];
    }
    isEmpty () {
        for(var key in this) {
            if(this.hasOwnProperty(key))
                return false;
        }
        return true;
    }
    //login password functions
    checkAuth() {
        if (this.authenticated) {
            return true;
        }
        else {
            console.log("Authenticate to continue.")
            return false;
        }
    }
    logOut(){
        this.authenticated = false;
    }
    changeLogin(curr_login, new_login) {
        if (this.checkAuth()) {
            if (curr_login === this.login) {
                this.login = new_login;
            }
            else {
                console.log("Entered login isn't correct, try again!!!")
            }
        }
    }
    changePassword(curr_pass, new_pass) {
        if (this.checkAuth()) {
            if (curr_pass === this.password) {
                this.password = new_pass;
            }
            else {
                console.log("Entered password isn't correct, try again!!!")
            }
        }
    }
    //article functions
    writeArticle(art_name) {
        if (this.checkAuth()) {
            if(Admin.articlesAll.find(art => art === art_name) == undefined) {
                this.articles.push(art_name);
                Admin.articlesAll.push(art_name)
                console.log(`You are writing ${art_name} aricle.`)
            }
            else {
                console.log("Article name is in use, try again!!!");
            }
        }
    }
    updateArticle(art_name) {
        if (this.checkAuth()) {
            if(this.articles.find(art => art === art_name) == undefined) {
                if(Admin.articlesAll.find(art => art === art_name) != undefined) {
                    console.log(`You can't update ${art_name} article, it is not yours.`)
                }
                else {
                    console.log(`You can't update ${art_name} article, because there are no such an article.`);
                }
            }
            else {
                console.log(`You have updated ${art_name} article.`);
            }
        }
    }
}
class Admin extends User {
    static articlesAll = [];
    constructor(name, surname, age, login, password) {
        super(name, surname, age, login, password);
        this.role = "admin";
    }
    createGroup(group_name) {
        if (this.checkAuth()) {
            console.log(`You have created ${group_name}group`);
        }
    }
    deleteGroup(group_name) {
        if (this.checkAuth()) {
            console.log(`You have deleted ${group_name}group`);
        }
    }
    updateArticle(art_name) {
        if (this.checkAuth()) {
            console.log(`You have updated ${art_name} article.`);
        }
    }
}
class Authentication{
    checkLogin(login) {
        return users.find(element => element.login === login);
    }
    checkPass(obj, pass) {
        if(obj != undefined) {
            obj.authenticated = true;
            return obj.password === pass;
        }
        else {
            console.log("Login is not correct!!!")
            return false;
        }
    }
    constructor(login, password) {
        if(this.checkPass(this.checkLogin(login), password)) {
            this.login = login;
            this.password = password;
            console.log("Successful Authentication.")
        }
        else {
            console.log("Authentication failed.")
        }
    }
}
let users = [];
let guests = [];
let admin = 0;
function createAdmin(name, surname, age, login, password) {
    if (admin < 1) {
        let adm = new Admin(name, surname, age, login, password)
        users.push(adm);
        admin = 1;
    }
    else {
        console.log("There can be only one admin")
    }
}
function createUser(name, surname, age, login, password) {
    if (admin < 1) {
        createAdmin(name, surname, age, login, password);
        console.log("You are admin.")
    }
    else {
        let user = new User(name, surname, age, login, password)
        if(!(user.isEmpty())) {
            users.push(user);
        }
        else {
            console.log("Entered login/password is in use, try again!!!")
        }
    }
}
function createGuest() {
    if (admin > 0) {
        guests.push(new Guest());
    }
    else {
        console.log("Page not found.");
    }
}
createGuest();
createUser("Nare", "Mkrtchyan", 21, "nm", "nm22");
createUser("Nare", "Mkrtchyan", 21, "nnnn", "nm222");
createUser("Nare", "Mkrtchyan", 21, "nnnn", "nm222");
createGuest();
console.log(users[0]);
console.log(users[1]);
console.log(guests[0]);
let aut = new Authentication("nm", "nm22");
