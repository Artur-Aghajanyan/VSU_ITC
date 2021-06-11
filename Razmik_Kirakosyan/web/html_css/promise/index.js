const first_url='https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/users.json';const second_url='https://raw.githubusercontent.com/Artur-Aghajanyan/VSU_ITC/html_css/Artur_Aghajanyan/Web/Html_Css/01_06_2021/investments.json';

function find_invester(users,investments) {
	const aaa = investments.filter(value => value.amount > 600);
  	console.log(users.filter(user => aaa.find(investment => investment.id === user.id)).map(user => user.name));
}

function make_new_array(users, investments) {
const newarr=users.map( item => { return { id: item.id, name: item.name, amount: investments.find(value => value.id == item.id).amount}});
      console.log("print new array by this format  \n", newarr);
}

Promise.all([
	fetch(first_url).then(response1 => response1.json()),
	fetch(second_url).then(response2 => response2.json()), 
]).then(([users_response, investments_response]) => {
	console.log(users_response.users);
	console.log(investments_response.investments);
	find_invester(users_response.users,investments_response.investments)
	make_new_array(users_response.users, investments_response.investments)		
	
}).catch((err) => {
    console.log(err);
});



