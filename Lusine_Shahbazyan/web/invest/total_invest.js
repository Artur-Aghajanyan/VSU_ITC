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


 /* Get the total investments peoples whose age is not older than 18 */
 let total_investments = data.filter(item => item.age < 18).reduce((total, item) => total + item.investments,0);
 console.log(total_investments);


 /* Get array which will contain strings, and each string of the array will be contained 
 the name and investments with the following format "Gevorg invested 180 $" */
 let newdata = data.map(item => item.name + "  invested  " + item.investments + "  $.");
 console.log(newdata);


 /* Get the array which will contain the top 3 investor's names */
 let top_invest = data.sort((a,b) => b.investments-a.investments).slice(0,3).map(value => value.name);
 console.log(top_invest);
