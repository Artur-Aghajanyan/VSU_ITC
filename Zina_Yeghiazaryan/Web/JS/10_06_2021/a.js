let a = Promise.all([
    fetch("https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/investments.json")
    .then(res => res.json()),
    fetch("https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/users.json")
    .then(res => res.json())
]).then(response => {
    const names = [];
    const data2 = response[0].investments.filter(value => value.amount > 600).map(value => value.id);
    for (let i = 0; i < data2.length; ++i) {
    	names[i] = response[1].users.find(item => item.id == data2[i]).name;
    }
    console.log(names);
    const data1 = response[0].investments.map(value => { return{
                                            id: value.id,
                                            name: response[1].users.find(item=>item.id==value.id).name,
                                            amount: value.amount
}})
    console.log(data1);
})
