const users = [
    { id: 10, name: "Karen", age: 26, height: 164 },
    { id: 1, name: "Artur", age: 24, height: 170 },
    { id: 2, name: "Artur", age: 22, height: 178 },
    { id: 3, name: "Razmik", age: 24, height: 172 },
    { id: 5, name: "Gor", age: 17, height: 180 },
    { id: 7, name: "Nare", age: 21, height: 160 },
    { id: 4, name: "Van", age: 24, height: 170 },
    { id: 6, name: "Zina", age: 20, height: 154 },
    { id: 8, name: "Anna", age: 21, height: 160 },
    { id: 9, name: "Lusine", age: 39, height: 164 },
]

const investments = [
    { id: 1, amount: 340},
    { id: 2, amount: 356},
    { id: 3, amount: 657},
    { id: 4, amount: 2434},
    { id: 5, amount: 824},
    { id: 6, amount: 567},
    { id: 7, amount: 123},
    { id: 8, amount: 678},
    { id: 9, amount: 576},
    { id: 10, amount: 236},
]
/*list of names whose investments is over 600 */
let ids = investments.filter(item => item.amount > 600).map(item => item.id);
let userNames = []
for (i in ids) {
   userNames[i] = users.find(item => item.id == ids[i]).name;
}
console.log(userNames); 

/* new list id name amount */
let newlist = users.map(item => { 
    return{ 
        id: item.id,
        name: item.name,
        amount: investments.find(val => val.id == item.id).amount
    }
})
console.log(newlist); 