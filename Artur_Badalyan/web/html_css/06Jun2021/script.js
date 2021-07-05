/* --------- Scroll to Top -------------- */
var scrollToTopBtn = document.getElementById("myBtn")
var rootElement = document.documentElement

window.onscroll = function() {scrollFunction()};

function scrollFunction() {
    if (document.body.scrollTop > 80 || document.documentElement.scrollTop > 80) {
        scrollToTopBtn.style.opacity = "1";
    } else {
        scrollToTopBtn.style.opacity = "0";
    }
}

function scrollToTop() {
    // Scroll to top logic
    rootElement.scrollTo({
        top: 0,
        behavior: "smooth"
    })
}
scrollToTopBtn.addEventListener("click", scrollToTop)

scrollToTopBtn.addEventListener("click", scrollToTop)



function  showDiv(id){
    if(id == "pl_mi1"){
        let div1 = document.getElementById("layer5-quest-text1")
        if(div1.style.display == "none" || div1.style.display == ""){

            div1.style.height = "100px"
            div1.style.display = "block"
            document.getElementById("plus1").style.display = "none"
            document.getElementById("minus1").style.display = "block"
        }
        else{
            div1.style.display = "none"
            document.getElementById("plus1").style.display = "block"
            document.getElementById("minus1").style.display = "none"
        }
    }
    else if(id == "pl_mi2"){
        let div1 = document.getElementById("layer5-quest-text2")
        if(div1.style.display == "none" || div1.style.display == ""){
            div1.style.height = "100px"
            div1.style.display = "block"
            document.getElementById("plus2").style.display = "none"
            document.getElementById("minus2").style.display = "block"
        }
        else{
            div1.style.display = "none"
            document.getElementById("plus2").style.display = "block"
            document.getElementById("minus2").style.display = "none"
        }
    }
    else {
        let div1 = document.getElementById("layer5-quest-text3")
        if(div1.style.display == "none" || div1.style.display == ""){
            div1.style.display = "block"
            document.getElementById("plus3").style.display = "none"
            document.getElementById("minus3").style.display = "block"
        }
        else{
            div1.style.display = "none"
            document.getElementById("plus3").style.display = "block"
            document.getElementById("minus3").style.display = "none"
        }
    }
}


/* Phone menu  */

let f = document.querySelector(".container-menu-icon")
let header = document.querySelector("header")

f.addEventListener("click",()=>{
    header.classList.toggle("active");
    f.classList.toggle("change");
})

/* Play videos code */

let playCircle = document.querySelector(".fa-play-circle")
let video = document.querySelector(".video")
let clossIcon = document.querySelector(".closs-icon")

clossIcon.addEventListener("click",()=>{
    video.classList.remove("show");
})

playCircle.addEventListener("click",()=>{
    video.classList.add("show");
})



let playCircless = document.querySelector(".fa-play-cirless")
let videoss = document.querySelector(".video")
let clossIconss = document.querySelector(".closs-icon")

clossIconss.addEventListener("click",()=>{
    videoss.classList.remove("show");
})

playCircless.addEventListener("click",()=>{
    videoss.classList.add("show");
})

/*     Slider           */

let slideIndex = 1;

showSlides(slideIndex);
function nextSlide() {
    showSlides(slideIndex += 1);
}

function previousSlide() {
    showSlides(slideIndex -= 1);
}

function showSlides(n) {
    let slides = document.getElementsByClassName("item");

    if (n > slides.length) {
        slideIndex = 1
    }
    if (n < 1) {
        slideIndex = slides.length
    }
    for (let slide of slides) {
        slide.style.display = "none";
    }
    slides[slideIndex - 1].style.display = "block";
}


/* -------- layer6 slider -----------*/

let index = 1;

Slider(index);
function nxtSlide() {
    Slider(index += 1);
}

function prevSlide() {
    Slider(index -= 1);
}

function Slider(n) {
    let slides = document.getElementsByClassName("layer6-slider-item");

    if (n > slides.length) {
        index = 1
    }
    if (n < 1) {
        index = slides.length
    }

    for (let slide of slides) {
        slide.style.display = "none";
    }

    slides[index - 1].style.display = "block";
}

