Users = []
Id = 0

class Guest{
    who = "Guest"
    whoRole = "guest"
    whoId = undefined
    guestsCount = 0

    addUser(name){
        if(this.guestsCount == 0){
            Users.push({
                name: name,
                role: this.whoRole,
                id: Id     
            })
            this.who = name
            this.whoId = Id
            Id++
            console.log("User ", name, " is added!")
            this.guestsCount++
        }
        else{
            console.log("You can make only 1 user!")
        }
    } 

    delMe(){
        if(this.who != "Guest"){
            const me = Users.findIndex(element => element.id == this.whoId,)
            Users.splice(me,1)
            console.log("User ", this.who, " deleted!")
            this.who = "Guest"
            this.whoId = undefined
        }
        else{
            console.log("You are not in account!")
        }
    }

    profile(){
        console.log("Your profile:")
        console.log(JSON.stringify(this.who))
    }
}

class User extends Guest{  
    constructor(){
        super()
        this.whoRole = "user"
    }

    addUser(name, login, password){
        let bool = false
        Users.forEach(user => user.login === login ? bool = true : bool = false)
        if (bool == false){
            Users.push({
                name: name,
                login: login,
                password: password,
                role: this.whoRole,
                id: Id       
            })
            Id++
            console.log("User ", name, " is added!")
        }
        else{
            console.log("Login ", login, " is already used!")
        }
    } 

    delMe(login, password){
        if(this.who == "Guest"){
            console.log("Plz, Log In!")
            return
        }
        if(this.who.login == login && this.who.password == password){
            const me = Users.findIndex(element => element.id == this.who.id)
            Users.splice(me,1)
            console.log("User ", this.who.name, " deleted!")
            this.who = "Guest"
        }
        else{
            console.log("Wrong login or password!")
        }
    }

    refresh(){
        console.log("Refreshed!")
        const a = Users.findIndex(element => 
            element.login == this.who.login &&
            element.password == this.who.password)
        if (a < 0){
            console.log("Sory, but your account was deleted!")
            this.who = "Guest"    
        }
        else{
            Users[a] = this.who
        }
    }

    logIn(login, password){
        if (this.who != "Guest"){
            console.log("Plz, exit from account ", this.who.name)
            return
        }
        Users.forEach(user => {
            if(user.login === login && user.password === password){
                this.who = user
                return
            }
        })
        this.who == "Guest" ? console.log("Wrong login or password!") : console.log("Hello ", this.who.name)
    }

    logOut(){
        if (this.who == "Guest"){
            console.log("Yoy are not in account!")
            return
        }
        console.log("Exit from account ", this.who.name)
        this.who = "Guest"
    }

    addProps(props){
        if(this.who == "Guest"){
            console.log("Plz, Log In!")
            return
        }
        props.forEach(prop => {
            const propName = prop.split(":")[0]
            const propProp = prop.split(":")[1]
            if(propName !== "login" && "password" && "role" && "id"){
                this.who[propName] = propProp
            }
        })
        this.refresh()
    }

    delProps(props){
        if(this.who == "Guest"){
            console.log("Plz, Log In!")
            return
        }
        props.forEach(prop => {
            if(prop !== "login" && "password" && "role" && "name" && "id"){
                delete this.who[prop]
            }
        })
        this.refresh()
    }

    newPassword(newPass){
        if(this.who == "Guest"){
            console.log("Plz, Log In!")
            return
        }
        this.who.password = newPass
        this.refresh()
        console.log("Password updated!")
    }
}

class Admin extends User{
    constructor(){
        super()
        this.whoRole = "admin"
    }

    findUser(props){
        const arr = []
        Users.forEach(user => {
            props.forEach(prop => {
                const propName = prop.split(":")[0]
                const propProp = prop.split(":")[1]
                if(user[propName]  == propProp){
                    arr.push(user)
                    return
                }
            })
        })
        if (arr.length > 0){
            console.log("Finded users:")
            arr.forEach(user => console.log(JSON.stringify(user)))
        }
        else{
            console.log("No result!")
        }
    }

    showUsers(){
        if (this.who == "Guest"){
            console.log("Plz, Log In!")
            return
        }
        console.log("Users:")
        Users.forEach(user => console.log(JSON.stringify(user)))
    }

    delUser(id){
        if (this.who == "Guest"){
            console.log("Plz, Log In!")
            return
        }
        const user = Users.findIndex(element => element.id == id)
        delete Users[user]
        console.log("User deleted!")
    }

    delAllUsers(){
        if (this.who == "Guest"){
            console.log("Plz, Log In!")
            return
        }
        console.log("All users are deleted!")
        Users = [this.who]
    }

    userAddProps(userId,props){
        if (this.who == "Guest"){
            console.log("Plz, Log In!")
            return
        }
        const user = Users.findIndex(element => element.id == userId)
        const admin = this.who
        this.who = Users[user]
        this.addProps(props)
        this.who = admin
    }

    userDelProps(userId,props){
        if (this.who == "Guest"){
            console.log("Plz, Log In!")
            return
        }
        const user = Users.findIndex(element => element.id == userId)
        const admin = this.who
        this.who = Users[user]
        this.delProps(props)
        this.who = admin
    }
}


const user1 = new Guest()
const user2 = new User()
const user3 = new Admin() 