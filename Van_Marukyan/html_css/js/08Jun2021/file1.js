
//     const data = [
//         {name: "Armen", age: 32, job: "bugalter", investments: 150},
//         {name: "Artak", age: 28, job: "developer", investments: 120},
//         {name: "Karen", age: 26, job: "developer", investments: 140},
//         {name: "Ashot", age: 45, job: "teacher", investments: 250},
//         {name: "Nelli", age: 21, job: "teacher", investments: 150},
//         {name: "Hakob", age: 16, job: "", investments: 80},
//         {name: "Gevorg", age: 20, job: "developer", investments: 60},
//         {name: "Mane", age: 18, job: "", investments: 120},
//         {name: "Mariam", age: 32, job: "doctor", investments: 200},
//         {name: "Hayk", age: 44, job: "doctor", investments: 250},
//         {name: "Arman", age: 26, job: "police", investments: 100},
//         {name: "Davit", age: 22, job: "police", investments: 80},
//         {name: "Armine", age: 17, job: "", investments: 140},
//         {name: "Karine", age: 26, job: "teacher", investments: 180}
//      ]
//     //1. Get the total investments peoples whose age is not older than 18
    
//      const adults = data.filter(person => person.age <= 18).reduce((total,person) => total + person.investments, 0)
//      console.log(adults)
   

//   //   2. Get array which will contain strings, and each string of the array will be contained the name
//      //and investments with the following format "Gevorg invested 180 $"
 
//      const newData = data.map(person =>`${person.name} invested ${person.investments} $`)
//      console.log(newData)

     
//      //3. Get the array which will contain the top 3 investor's names
//      let count = 3;
//      let array = data.sort((a,b) => b.investments - a.investments).filter(() =>{
//         if (count > 0) {
//             count--
//             return true
//         } 
//         return false
//      })
//      console.log(array)