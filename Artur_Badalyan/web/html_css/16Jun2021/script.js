registrArray = [];

class User  {
    firstName = '';
    lastName = '';
    age = null;

    constructor() {
        this.currRole = 'guest';
    }

    registration(login, password, role) {
        registrArray.forEach(item => {
            if (item.login === login) {
                throw("This login already created");
            }
        });
        if (role === 'user') {
            registrArray.push({login: login, password: password, role: role});
            console.log("Created user and role: ", role);
        } else {
            console.log("The role can't be ", role);
        }
    }

    login(login, password) {
        for (let i = 0; i < registrArray.length; i++) {
            if (registrArray[i].login === login && registrArray[i].password === password && this.currRole === "guest") {
                this.currRole = "user";
                console.log("You are successfully logged in, Hi ", this.firstName);
                break;
            } else if (this.currRole === "user") {
                console.log("You are already logged in");
                break;
            } else if (registrArray[i].login === login && registrArray[i].password === password && this.currRole === "admin") {
                console.log("You are successfully logged in, Hi ", this.firstName);
                break;
            } else {
                console.log("Your login or password is incorrect");
                break;
            }
        }
    }


    logOut() {
        if (this.currRole === "user" || this.currRole === "admin") {
            this.currRole = "guest";
            console.log("So early ?, Byee ", this.firstName);
        } else {
            console.log("Тo log out of your account, you need to login !!!");
        }
    }

    setPersonData(firstName, lastName, age) {
        if (this.currRole === "user") {
            this.firstName = firstName;
            this.lastName = lastName;
            this.age = age;
        } else {
            console.log("To change your personal data, you need to register !!!");
        }

    }

    getPersonData() {
        if (this.currRole === "user") {
            console.log("First name: ", this.firstName, " Last name: ", this.lastName, " Age: ", this.age);
        } else {
            console.log("To get your personal data, you need to register !!!");
        }
    }
}

class Admin extends User {
    constructor() {
        super();
        this.currRole = "admin";
    }

    delUser(login) {
        for (let i = 0; i < registrArray.length; i++) {
            if (registrArray[i].login === login) {
                registrArray = registrArray.splice(i, i);
                break;
            }
        }
        console.log("User ", login, " deleted");
    }
}

// Creating user object
let user = new User();
console.log("Registration (fail)");
user.registration("Karen","pass","userrrr")
console.log("Registration");
user.registration("Karen","pass","user")
console.log("User login (fail)");
user.login("Karens", "asd");
console.log("User login");
user.login("Karen", "pass");
console.log("User set and get personal data");
user.setPersonData("Karen", "Harutyunyan", 22);
user.getPersonData();
// Creating admin object
let admin = new Admin();
console.log("Admin login");
admin.login("Karen", "pass");
console.log("Admin logout");
admin.logOut();
console.log("Deleting user from admin");
admin.delUser("Karen");









