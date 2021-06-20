class Pagination {
    _items = [];
    _pageSize = 10;
    _count = 100;
	
    constructor(items, pageSize, count) {
        this._items = items;
        this._pageSize = pageSize;
        this._count = count;
    }
	
    goToPage(pageNumber) {
        let index = 0;
        let array = [];
		
        for (let i = (pageNumber-1)*this._pageSize; i < pageNumber*this._pageSize; ++i) {
			      if (this._items[i] === undefined) {
				        break;
			      }
            array[index] = this._items[i];
            ++index;
        }
		
        return array;
    }
	
	  prevPage = (pageNumber) => this.goToPage(pageNumber - 1);
	  nextPage = (pageNumber) => this.goToPage(pageNumber + 1);
	  firstPage = () => this.goToPage(1);
	  lastPage = () => this.goToPage(_pageSize);
	
	  onClick() {
		    let k;

		    if (this._count % this._pageSize === 0) {
		  	    k = this._count / this._pageSize;
		    } else {
			      k = this._count / this._pageSize + 1;
		    }
		
		    var num;
		
		    var prev = document.createElement("button");
		    prev.onclick = function() {
				    document.querySelectorAll("p").forEach(e => e.parentNode.removeChild(e));
				    var p = document.createElement("p");
				    p.innerHTML = pagination.prevPage(num);
				    --num;
				    document.body.appendChild(p);
			  };
			  prev.type = "button";
			  prev.innerHTML = "previous";
			  document.body.appendChild(prev);
		
		    for (let i = 1; i <= k; ++i) {
			      if (i == 1) {
				        var first = document.createElement("button");
				        first.onclick = function() {
					          document.querySelectorAll("p").forEach(e => e.parentNode.removeChild(e));
					          var p = document.createElement("p");
					          p.innerHTML = pagination.firstPage();
					          document.body.appendChild(p);
					          num = i;
				        };
				        first.type = "button";
				        first.innerHTML = i;
				        document.body.appendChild(first);
			      } else if(i == k) {
				        var last = document.createElement("button");
				        last.onclick = function() {
					          document.querySelectorAll("p").forEach(e => e.parentNode.removeChild(e));
					          var p = document.createElement("p");
					          p.innerHTML = pagination.lastPage();
					          document.body.appendChild(p);
					          num = i;
				        };
				        first.type = "button";
				        first.innerHTML = i;
				        document.body.appendChild(last);
			      } else {
				        var button = document.createElement("button");
				        button.onclick = function() {
					          document.querySelectorAll("p").forEach(e => e.parentNode.removeChild(e));
					          var p = document.createElement("p");
					          p.innerHTML = pagination.goToPage(i);
					          document.body.appendChild(p);
					          num = i;
				        };
				        button.type = "button";
				        button.innerHTML = i;
				        document.body.appendChild(button);
			      }
		    }				
		
		    var next = document.createElement("button");
		    next.onclick = function() {
			      document.querySelectorAll("p").forEach(e => e.parentNode.removeChild(e));
			      var p = document.createElement("p");
			      p.innerHTML = pagination.nextPage(num);
			      ++num;
			      document.body.appendChild(p);
		    };
		    next.type = "button";
		    next.innerHTML = "next";
		    document.body.appendChild(next);
	  }
}

const array = [];
const size = 3;
const count = 100;

for (let i = 0; i < count; ++i) {
    array[i] = i + 1;
}

let pagination = new Pagination(array, size, count);
pagination.onClick();
