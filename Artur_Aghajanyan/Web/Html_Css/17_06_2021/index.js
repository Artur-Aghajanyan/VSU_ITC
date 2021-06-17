class Pagination {
  #pageEleArr;
  #numOfEleToDisplay;
  #elementCount;
  #numOfPages;
  #pageNo = 1;

  constructor(pageEleArr, size) {
    this.#pageEleArr = pageEleArr;
    this.#numOfEleToDisplay = size;
    this.#elementCount = this.#pageEleArr.length;
    this.#numOfPages = Math.ceil(this.#elementCount / this.#numOfEleToDisplay);
    let ulLiItem = document.getElementById('ul-li-item');
    for (let i = 0; i < this.#numOfPages; ++i) {
      let li = document.createElement('li');
      li.classList.add('page-item');
      li.style.display = 'inline';

      let a = document.createElement('a');
      a.href = '#';
      a.classList.add('page-link');
      a.innerHTML = `${i + 1}`;
      if (i === 0)
        li.classList.add('active');

      li.append(a);
      ulLiItem.append(li);
    }

    document.getElementById('previous').classList.add('disabled');
    let lists = ulLiItem.getElementsByTagName('li');
    for (let i = 0; i < lists.length; ++i) {
      lists[i].addEventListener('click', ($event) => {
        for (let j = 0; j < lists.length; ++j) {
          if (lists[j].innerHTML === lists[i].innerHTML) {
            lists[j].classList.add('active');
            this.#pageNo = $event.target.innerText;
            this.#display(this.#pageNo);
          }
          if ((lists[j].innerHTML !== lists[i].innerHTML)
              && lists[j].classList.contains('active')) {
            lists[j].classList.remove('active');
          }
        }
      });
    }
  }

  pageElements(arr, eleDispCount) {
    const arrLen = arr.length;
    let pageArr = [];
    let perPageArr = [];
    let index = 0;
    let condition = 0;
    let remainingEleInArr = 0;

    for (let i = 0; i < this.#numOfPages; i++) {
      if (i === 0) {
        index = 0;
        condition = eleDispCount;
      }
      for (let j = index; j < condition; j++)
        perPageArr.push(arr[j]);


      pageArr.push(perPageArr);
      if (i === 0)
        remainingEleInArr = arrLen - perPageArr.length;
      else
        remainingEleInArr -= perPageArr.length;

      if (remainingEleInArr > 0) {
        if (remainingEleInArr > eleDispCount) {
          index += eleDispCount;
          condition += eleDispCount;
        }
        else {
          index = index + perPageArr.length;
          condition += remainingEleInArr;
        }
      }
      perPageArr = [];
    }
    return pageArr;
  }

  #display(pageNo) {
    let previous = document.getElementById('previous');
    let next = document.getElementById('next');

    document.getElementById('row').innerHTML = '';
    let val = this.pageElements(this.#pageEleArr,
        this.#numOfEleToDisplay)[pageNo - 1];
    val.forEach(res => {
      createCard(res.url, res.title);
    });

    let ulLiItem = document.getElementById('ul-li-item');
    let listsA = ulLiItem.getElementsByClassName('page-link');
    for (let i = 0; i < listsA.length; ++i) {
      if (listsA[i].innerText == pageNo) {
        ulLiItem.getElementsByTagName('li')[i].classList.add('active');
      }
      if ((listsA[i].innerText != pageNo)
          &&
          ulLiItem.getElementsByTagName('li')[i].classList.contains('active')) {
        ulLiItem.getElementsByTagName('li')[i].classList.remove('active');
      }
    }
    if (pageNo == 1) {
      previous.classList.add('disabled');
      next.classList.remove('disabled');
    }
    else if (pageNo == this.#numOfPages) {
      previous.classList.remove('disabled');
      next.classList.add('disabled');
    }
    else {
      previous.classList.remove('disabled');
      next.classList.remove('disabled');
    }
    this.#pageNo = pageNo;
  }

  prevPage() {
    if (this.#pageNo > 1) {
      this.#display(this.#pageNo - 1);
    }
  }

  nextPage() {
    if (this.#pageNo < this.#numOfPages) {
      this.#display(+(this.#pageNo) + 1);
    }
  }
}

fetch('https://jsonplaceholder.typicode.com/photos?_start=1&_limit=100').
    then(response => response.json()).
    then(res => {
      const pagination = new Pagination(res, 12);
      document.getElementById('next').
          addEventListener('click', () => pagination.nextPage());
      document.getElementById('previous').
          addEventListener('click', () => pagination.prevPage());
    });

function createCard(src, title) {
  let div1 = document.createElement('div');
  div1.classList.add('col-md-4');

  let div2 = document.createElement('div');
  div1.classList.add('card');
  div1.classList.add('mb-4');
  div1.classList.add('box-shadow');
  div1.append(div2);

  let img = document.createElement('img');
  img.classList.add('card-img-top');
  img.dataSrc = 'holder.js/100px225?theme=thumb&amp;bg=55595c&amp;fg=eceeef&amp;text=Thumbnail';
  img.alt = title;
  img.src = src;
  img.dataHolderRendered = 'true';
  img.style.width = '100%';
  img.style.height = '225px';
  div2.append(img);

  let div3 = document.createElement('div');
  div3.classList.add('card-body');
  div2.append(div3);

  let p = document.createElement('p');
  p.classList.add('card-text');
  p.innerHTML = title;
  div3.append(p);

  let div4 = document.createElement('div');
  div4.classList.add('d-flex');
  div4.classList.add('justify-content-between');
  div4.classList.add('align-items-center');
  div3.append(div4);

  let div5 = document.createElement('div');
  div5.classList.add('btn-group');
  div4.append(div5);

  let small = document.createElement('small');
  small.classList.add('text-muted');
  small.innerHTML = new Date().getMilliseconds() + ' mils';
  div4.append(small);

  let button1 = document.createElement('button');
  button1.type = 'button';
  button1.classList.add('btn');
  button1.classList.add('btn-sm');
  button1.classList.add('btn-outline-secondary');
  button1.innerHTML = 'View';
  div5.append(button1);

  let button2 = document.createElement('button');
  button2.type = 'button';
  button2.classList.add('btn');
  button2.classList.add('btn-sm');
  button2.classList.add('btn-outline-secondary');
  button2.innerHTML = 'Edit';
  div5.append(button2);

  let row = document.getElementById('row');
  row.append(div1);
}

window.onload = () => {
  createCard('https://via.placeholder.com/600/810b14', 'some Title');
  createCard('https://via.placeholder.com/600/771796', 'some Title');
  createCard('https://via.placeholder.com/600/810b14', 'some Title');
  createCard('https://via.placeholder.com/600/771796', 'some Title');
  createCard('https://via.placeholder.com/600/810b14', 'some Title');
  createCard('https://via.placeholder.com/600/771796', 'some Title');
  createCard('https://via.placeholder.com/600/810b14', 'some Title');
  createCard('https://via.placeholder.com/600/771796', 'some Title');
  createCard('https://via.placeholder.com/600/810b14', 'some Title');
};

