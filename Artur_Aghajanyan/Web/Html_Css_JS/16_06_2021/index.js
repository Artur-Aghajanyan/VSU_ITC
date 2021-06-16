let userList = [];

class Role {
  role = '';
  constructor(role) {
    this.role = role;
  }
}

class Admin extends Role {constructor() {super('admin');}}

class OrdinaryUser extends Role {constructor() {super('user');}}

function addProto(role) {
  if (role.toUpperCase() === 'ADMIN')
    User.prototype = new Admin();
  else
    User.prototype = new OrdinaryUser();
}

function User(role = 'user', name = 'User1', age, password) {
  this.name = name;
  this.role = role;
  this.age = age;
  this.password = password;
  this.id = uuidv4();
  this.login = false;
  addProto(role);

  this.printUsersList = () => {
    if (this.login) {
      if (role.toUpperCase() === 'ADMIN')
        console.log(userList);
      else
        console.error('You don\'t have access to this method because you  Ordinary User');
    }
    else console.error('User not logged');
  };
  this._obj = {
    name: this.name,
    role: this.role,
    age: this.age,
    password: this.password,
    id: this.id,
    login: this.login,
  }
  this.getData = () => {
    if(this.login)
      return this._obj
    else
      console.error('User not logged');
  }
}

function uuidv4() {
  return ([1e7] + -1e3 + -4e3 + -8e3 + -1e11).replace(/[018]/g, c =>
      (c ^ crypto.getRandomValues(new Uint8Array(1))[0] & 15 >> c / 4).toString(
          16),
  );
}

function loginUser(name, password) {
  let logRes = false;
  userList.forEach(res => {
    if (res.name === name && res.password === password) {
      res.login = true;
      console.log(`*************\nUser ${res.name} login successfully\n*************`);
      logRes = true;
      return 0;
    }
  });
  if (!logRes) {
    console.error('There is not user like that!!');
  }
}

function logoutUser() {
  userList.forEach(res => {
    if (res.login) {
      res.login = false;
      console.log(`*************\nUser ${res.name} logout successfully\n*************`);
    }
  });
}

for (let i = 0; i < 10; ++i) {
  if (i % 2 === 0) {
    userList.push(new User('admin', `user${i + 1}`, 15, `user${i + 1}`));
  }
  else {
    userList.push(new User('user', `user${i + 1}`, 15, `user${i + 1}`));
  }
}



console.log('This is my all Users:');
console.log(userList);
console.log('\nNow I trying login (name: user1, password: user1)');
loginUser('user1', 'user1');
userList.forEach(res => {
  if(res.login) {
    res.printUsersList();
    console.log("----------------\nLogged user data:");
    console.log(res.getData());
    console.log("\n----------------");
  }
});

console.log("Try To logout");
logoutUser();

console.log("Try To print users list");
userList.forEach(res => res.printUsersList());