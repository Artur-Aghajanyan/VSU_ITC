
const url = ['https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/investments.json',
    'https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/users.json']

Promise.all([fetch(url[0]).then(res =>res.json()),fetch(url[1]).then(res =>res.json())])
    .then(data => {
        const investments = data[0].investments;
        const users = data[1].users;

        let array = investments.filter(invest => invest.amount > 600).map(item => {
            return {
                id: item.id,
                name: users.find(nam => nam.id == item.id).name,
                amount: item.amount,
            }
        })
        console.log("Users and investments")
        console.log(array)
    })
