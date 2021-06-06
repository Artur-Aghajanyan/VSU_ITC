window.addEventListener('scroll', function() {
    let header = document.getElementById('header');
    let navDiv = document.getElementById('nav-div');
    if (window.scrollY + document.querySelector('#header').getBoundingClientRect().top > 45) {
        header.classList.add("header-after")
        navDiv.classList.add("nav-div-after")
    }
    if(window.scrollY + document.querySelector('#header').getBoundingClientRect().top < 45){
        header.classList.remove("header-after")
        navDiv.classList.remove("nav-div-after")
    }
});
function menu(){
    let display = document.getElementById("navbarContent").style.display;
    if(display == "block"){
        document.getElementById("header").style.height = "120px"
        document.getElementById("navbarContent").style.display = "none"
        document.getElementById("hamburger_1").style.marginTop = "0px"
        document.getElementById("hamburger_1").style.transform = "rotate(0deg)"
        document.getElementById("hamburger_2").style.transform = "rotate(0deg)"
        document.getElementById("hamburger_3").style.display = "block"
    }
    else{
        document.getElementById("header").style.height = "310px"
        setTimeout(() =>{

            document.getElementById("navbarContent").style.display = "block"
        }, 500)
        document.getElementById("hamburger_1").style.marginTop = "9px"
        document.getElementById("hamburger_1").style.transform = "rotate(45deg)"
        document.getElementById("hamburger_2").style.transform = "rotate(-45deg)"
        document.getElementById("hamburger_3").style.display = "none"
    }
}

function arrowLeft(){
    let val = document.getElementsByClassName("carousel1")
    for(let i = 0; i < val.length; i++){
        if(val[i].classList.contains("active")){
            val[i].classList.remove("active")
            if(i == 0){
                val[val.length - 1].classList.add("active")
            }else {
                val[i - 1].classList.add("active")
            }
            break
        }
    }
}

function arrowRight(){
    let val = document.getElementsByClassName("carousel1")
    for(let i = 0; i < val.length; i++){
        if(val[i].classList.contains("active")){
            val[i].classList.remove("active")
            if(i + 1  == val.length){
                val[0].classList.add("active")
            }else {
                val[i + 1].classList.add("active")
            }
            break
        }
    }
}

function showDiv(id){
    if(id === "headingOne"){
        let collapse1_6 = document.getElementById("collapse1_6");
        let plus1 = document.getElementById("plus1")
        let minus1 = document.getElementById("minus1")
        if(collapse1_6.style.overflow === "hidden" || collapse1_6.style.overflow === ""){

            collapse1_6.style.height = "150px"
            setTimeout(() => {
                collapse1_6.style.overflow = "unset"
            }, 500)

            minus1.style.display = "inline-block"
            plus1.style.display = "none"
        }else{
            collapse1_6.style.overflow = "hidden"
            setTimeout(() => {
                collapse1_6.style.height = "0"
            }, 200)
            plus1.style.display = "inline-block"
            minus1.style.display = "none"
        }
    }
    else if(id === "headingTwo"){
        let collapse2_6 = document.getElementById("collapse2_6");
        let plus2 = document.getElementById("plus2")
        let minus2 = document.getElementById("minus2")
        if(collapse2_6.style.overflow === "hidden" || collapse2_6.style.overflow === ""){
            collapse2_6.style.height = "120px"
            setTimeout(() => {
                collapse2_6.style.overflow = "unset"
            }, 500)

            minus2.style.display = "inline-block"
            plus2.style.display = "none"
        }else{
            collapse2_6.style.overflow = "hidden"
            setTimeout(() => {
                collapse2_6.style.height = "0"
            }, 200)
            plus2.style.display = "inline-block"
            minus2.style.display = "none"
        }
    }
    else{
        let collapse3_6 = document.getElementById("collapse3_6");
        let plus3 = document.getElementById("plus3")
        let minus3 = document.getElementById("minus3")
        if(collapse3_6.style.overflow === "hidden" || collapse3_6.style.overflow === ""){
            collapse3_6.style.height = "120px"
            setTimeout(() => {
                collapse3_6.style.overflow = "unset"
            }, 500)

            minus3.style.display = "inline-block"
            plus3.style.display = "none"
        }else{

            collapse3_6.style.overflow = "hidden"
            setTimeout(() => {
                collapse3_6.style.height = "0"
            }, 200)

            plus3.style.display = "inline-block"
            minus3.style.display = "none"
        }
    }
}

function leftCarousel(){
    let val = document.getElementsByClassName("carousel2")
    let loadDisplay1 = window.getComputedStyle(val[0], null).getPropertyValue("display");
    if(loadDisplay1 === "" || loadDisplay1 === "none"){
        val[0].style.transform = "translateX(100%)"

        val[0].style.display = "block"
        setTimeout(() =>{
            val[0].style.transform = "translateX(0%)"
            val[1].style.transform = "translateX(-100%)"
            setTimeout(() =>{
                val[0].style.display = "block"
                val[1].style.display = "none"
            }, 600)
        }, 100)
    }
    else{
        val[1].style.transform = "translateX(100%)"
        val[1].style.display = "block"
        setTimeout(() =>{
            val[1].style.transform = "translateX(0%)"
            val[0].style.transform = "translateX(-100%)"
            setTimeout(() =>{
                val[1].style.display = "block"
                val[0].style.display = "none"
            }, 600)
        }, 100)

    }
}

function nextCarousel(){
    let val = document.getElementsByClassName("carousel2")
    let loadDisplay1 = window.getComputedStyle(val[0], null).getPropertyValue("display");
    if(loadDisplay1 === "" || loadDisplay1 === "none"){
        val[0].style.transform = "translateX(-100%)"

        val[0].style.display = "block"
        setTimeout(() =>{
            val[0].style.transform = "translateX(0%)"
            val[1].style.transform = "translateX(100%)"
            setTimeout(() =>{
                val[0].style.display = "block"
                val[1].style.display = "none"
            }, 600)
        }, 100)
    }
    else{
        val[1].style.transform = "translateX(-100%)"
        val[1].style.display = "block"
        setTimeout(() =>{
            val[1].style.transform = "translateX(0%)"
            val[0].style.transform = "translateX(100%)"
            setTimeout(() =>{
                val[1].style.display = "block"
                val[0].style.display = "none"
            }, 600)
        }, 100)

    }
}

function showVideo(){
    document.getElementById("video").style.display = "block"
}

function closeVideo(){
    document.getElementById("video").style.display = "none"
}

function topFunction() {
    document.documentElement.scrollTop = 0;
}