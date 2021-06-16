function Role(login, password, role) {
    this.login = login;
    this.password = password;
    this.role = role;
    putRole(role);
}

function User() {
    this.firstName = "";
    this.lastName = "";
    this.age = null;

    this.setPersonData = function (firstName, lastName, age) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
    };

    this.getPersonData = function () {
        return "First Name: " + this.firstName + "Last Name: " + this.lastName + "Age: " + this.age;
    };
}


function Admin() {
    this.firstName = "";
    this.lastName = "";
    this.age = null;

    this.setPersonData = function (firstName, lastName, age) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
    };

    this.getPersonData = function () {
        return "First Name: " + this.firstName + "Last Name: " + this.lastName + "Age: " + this.age;
    };
}

function putRole(role) {
    if (role.toUpperCase() === "ADMIN") {
        Role.prototype = new Admin();
        Role.prototype.constructor = Role;
    } else {
        Role.prototype = new User();
        Role.prototype.constructor = Role;
    }
}

let users = [
    new Role("Karen", "3333", "user"),
    new Role("Tigran", "14253678", "Admin"),
    new Role("Arman", "password78", "user")
];





