Promise.all([fetch("https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/investments.json"), fetch("https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/users.json")])
    .then(response => Promise.all(response.map(data => data.json())))
    .then(arrays => {
        const investments = arrays[0].investments
        const users = arrays[1].users

        const data = []
        investments.filter(value => value.amount > 600).map(value => value.id).forEach(value => data.push(users.find(val => val.id == value)))

        console.log("amount > 600 \n",data)

        const newData = users.map(value => { return{ id: value.id,
                                                    name: value.name,
                                                    amount: investments.find(item => item.id == value.id).amount }})

        console.log("Format:{id,name,amount} \n",newData)

    })
