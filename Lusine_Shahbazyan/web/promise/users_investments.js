let url1 = fetch('https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/investments.json')
let url2 = fetch('https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/users.json')
Promise.all([url1.then(res => res.json()), url2.then(res => res.json())])
    .then(data => {
        const investments = data[0].investments;
        const users = data[1].users;

        /*list of names whose investments is over 600 */
        let ids = investments.filter(item => item.amount > 600).map(item => item.id);
        let userNames = []
        for (i in ids) {
            userNames[i] = users.find(item => item.id == ids[i]).name;
        }
        console.log(userNames);

        /* new list id name amount */
        let newlist = users.map(item => {
            return {
                id: item.id,
                name: item.name,
                amount: investments.find(val => val.id == item.id).amount
            }
        })

        console.log(newlist);
    })
    .catch((err) => {
        console.log(err);
      });





