# Index.js
We have 3 classes`Guest,User,Admin.

For example:

```sh
const user1 = new Guest()
const user2 = new User()
const user3 = new Admin()
```
## class Guest
Guest have only 3 methods:

##### addUser(name) 
Create user with name 'name'(you can create only 1 guest user).

```sh
user1.addUser("Ani")
```

##### delMe()
Delete your user.

```sh
user1.delMe()
```
Delete user "Ani".

##### profile()
This is general function(can used in User and Admin to!).Print current user!

```sh
user1.profile()
```

## class User
```sh
const user = new User()
```
#####  addUser(name, login, password)
Create new user wit some name 'name', login 'login', password 'password'!

```sh
user.addUser("Armen","qwerty","qwe123")
```

##### delMe(login, password)
Delete current User(needed login and password)!

```sh
user.delMe("qwerty","qwe123")
```

##### logIn(login, password)
Log In exiting account by login and password!

```sh
user.logIn("qwerty","qwe123")
```

##### logOut()
Log Out current account.

```sh
user.logOut()
```

##### addProps(props)
Add propertes for your account.

props - must be an array with format "key:value":

```sh
["name:Ani","surname:Andreasyan"]
```

for example:

```sh
user.addProps(["name:Ani","surname:Andreasyan"])
```

##### delProps(props)
Delete propertes for your account.

props - must be an array with format "key:value":

```sh
["name:Ani","surname:Andreasyan"]
```

for example:

```sh
user.delProps(["name:Ani","surname:Andreasyan"])
```

##### newPassword(newPass)
Change current password.

```sh
user.newPassword("qwer111")
```

##### refresh()
Refresh data!

```sh
user.refresh()
```

## Admin
Admin have all methods from User and more!

```sh
const user = new Admin()
```

##### findUser(props)
Find user by same propertes.

props - must be an array with format "key:value":

```sh
["name:Ani","surname:Andreasyan"]
```

for example:

```sh
user.findUser(["name:Ani","surname:Andreasyan"])
```

##### showUsers()
Show all users.

```sh
user.showUsers()
```

##### delUser(id)
Delete user by id!

```sh
user.delUser(2)
```

##### userAddProps(userId, props)
Add same propertes for same user.

```sh
user.userAddProps(2,["name:Ani","surname:Andreasyan"])
```

##### userDelProps(userId, props)
Delete same propertes for same user.

```sh
user.userDelProps(2,["name:Ani","surname:Andreasyan"])
```

##### Thank`s for reading!
