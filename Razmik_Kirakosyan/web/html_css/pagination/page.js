class Pagination {
	new_array=[];
	current_page = 0
	pagesize = 0;
	div = document.getElementById("index")
	div1 = document.getElementById("index1")
	next = document.getElementById("next")
	previous = document.getElementById("prev")
	page (array=[],pagesize=0) {
		this.pagesize=pagesize;
		console.log(array.length);
		for(let i = 0; i < Math.ceil(array.length / this.pagesize); i++){
				this.new_array[i] = array.slice(i * this.pagesize, i * this.pagesize + this.pagesize)
			
		}

		for (let i = 1; i <= this.pagesize; i++) {
			let p = document.createElement("p");
			p.id = i;
			this.div1.appendChild(p);
		}

		for (let i = 1; i <= Math.ceil(array.length / this.pagesize); i++) {
			let x = document.createElement("button")
			x.id = i;
			x.innerHTML = i;
			x.onclick = (event) => {
				this.current_page = event.target.id-1;
				this.change_context()
			}
			this.div.insertBefore(x,this.next);
			x.style.width = "30px";
			x.style.height = "20px";
			x.style.marginRight = "10px";	
			}

		this.change_context()
	}

	change_context() {
		for (let i = 1; i <= this.pagesize; i++) {
		    let p = document.getElementById(i)
			p.innerHTML = this.new_array[this.current_page][i-1]
		}
		this.check()
	}
	
	first_page() {
		this.current_page = 0;
		this.change_context();	
	}

	last_page() {
		this.current_page = Math.ceil(array.length / this.pagesize);
		this.change_context();
	}

	next_page() {
		this.current_page ++;
		this.change_context();
	}

	previous_page() {
		this.current_page --;
		this.change_context();
	}

	check() {
		if (this.current_page == 0) {
			this.previous.style.display = "none"
		} else {
			this.previous.style.display = "inline"	
		}

		if (this.current_page == this.new_array.length - 1) {
			this.next.style.display = "none"
		} else {
			this.next.style.display = "inline"
		}
	}

}
	
let obj=new Pagination();
obj.page([1,2,3,4,5,6,7,8,9,10],2);
console.log(obj.new_array);

