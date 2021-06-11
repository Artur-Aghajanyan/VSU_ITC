const data = [
    {"name": "Armen", "age": 32, "job": "bugalter", "investments": 150},
    {"name": "Artak", "age": 28, "job": "developer", "investments": 120},
    {"name": "Karen", "age": 26, "job": "developer", "investments": 140},
    {"name": "Ashot", "age": 45, "job": "teacher", "investments": 250},
    {"name": "Nelli", "age": 21, "job": "teacher", "investments": 150},
    {"name": "Hakob", "age": 16, "job": "", "investments": 80},
    {"name": "Gevorg", "age": 20, "job": "developer", "investments": 60},
    {"name": "Mane", "age": 18, "job": "", "investments": 120},
    {"name": "Mariam", "age": 32, "job": "doctor", "investments": 200},
    {"name": "Hayk", "age": 44, "job": "doctor", "investments": 250},
    {"name": "Arman", "age": 26, "job": "police", "investments": 100},
    {"name": "Davit", "age": 22, "job": "police", "investments": 80},
    {"name": "Armine", "age": 17, "job": "", "investments": 140},
    {"name": "Karine", "age": 26, "job": "teacher", "investments": 180}
 ]

const newData1 = data.filter(value => value.age <= 18).reduce((total,value) => total += value.investments,0)

console.log("Total investments peoples whose age is not older than 18 \n",newData1)

const newData2 = data.map(value => value.name + " invested " + value.investments + "$")

console.log("Format {Gevorg invested 180$} \n",newData2)

const newData3 = data.sort((a,b) => b.investments-a.investments).slice(0,3).map(value => value.name)

console.log("Top 3 investor's names \n",newData3)