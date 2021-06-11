Promise.all([
    fetch('https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/investments.json'),
    fetch('https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/users.json'),
    fetch('https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/index.json')
]).then(function (responses) {
    return Promise.all(responses.map(function (response) {
        return response.json();
    }));
}).then(function (data) {
 // Homework 1
 // 1.1
    let join_arrays = data[1].users.map(items => {
        let join_by_id = data[0].investments.find(element => element.id === items.id)
        return { ...items, ...join_by_id }
    }).filter(item => item.amount > 600).map(items => items.name)
    console.log(join_arrays);

//1.2
    let id_name_amount = data[1].users.map(items => {
        let join_by_id = data[0].investments.find(element => element.id === items.id)
        return { ...items, ...join_by_id }
    }).map(item => {
        return {
            id: item.id, name: item.name, amount: item.amount
        }
    });
    console.log(id_name_amount);

    //Homework 2
    //2.1 Get the total investments peoples whose age is not older than 18
    let total_ivest = data[2].data.filter(item => item.age <= 18).reduce((total, value) => total + value.investments, 0)
    console.log(total_ivest);

    //2.2 Get array which will contain strings, and each string of the array will be contained the name and investments with the following format "Gevorg invested 180 $"
    let name_invest = data[2].data.map(item => item.name + " invested " + item.investments + "$")
    console.log(name_invest);

    //2.3 Get the array which will contain the top 3 investor's names
    let top_3 = data[2].data.sort((a, b) => b.investments - a.investments).slice(0, 3).map(item => item.name);
    console.log(top_3);

}).catch(function (error) {
    console.log(error);
});
