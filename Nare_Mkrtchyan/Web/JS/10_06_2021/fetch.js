
let user_promise = fetch('https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/users.json')
let inv_promise = fetch('https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/investments.json')

let my_promise = Promise.all([
    user_promise,
    inv_promise,
]).then(async([users, investements]) => {
    const u = await users.json();
    const i = await investements.json();
    return [u.users, i.investments]
  }).then((user_inv) => {

    //1.1
    console.log("Get the list of people who invested more then 600.");
    const a_gt_600 = user_inv[1].filter(item => item.amount > 600);
    let names = [];
    for (i in a_gt_600) {
        names[i] = user_inv[0].find(item => item.id == a_gt_600[i].id ).name;
    }
    console.log(names);

    //1.2
    console.log("Get array, in which every element has { id, name, amount } fields.");
    const id_name_amount = user_inv[0].map(item => {
        return {
            id: item.id,
            name: item.name,
            amount: user_inv[1].find(am => am.id == item.id).amount
        }
    });
    console.log(id_name_amount)

  }).catch((err) => {
    console.log(err);
  });