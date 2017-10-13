//声明全局函数
var result_1;
var result_2;
var re;


//运算
function add(){
    var a=getFirst();
    var b=getTwice();
    re=Number(a)+Number(b);
    senResult(re);
}

function subtract(){
    var a=getFirst();
    var b=getTwice();
    re=a-b;
    senResult(re);
}

function ride(){
    var a=getFirst();
    var b=getTwice();
    re=a*b;
    senResult(re);
}

function devide(){
    var a=getFirst();
    var b=getTwice();
    re=a/b;
    senResult(re);
}

function addB() {
    var c= getSecond();
    reB = Number(re) + Number(c);
    senResultB(reB);
}

function subtractB(){
    var c= getSecond();
    reB = re - c;
    senResultB(reB);
}

function rideB() {
    var c= getSecond();
    reB = re * c;
    senResultB(reB);
}

function devideB() {
    var c= getSecond();
    reB = re / c;
    senResultB(reB);
}


//输出p值
function senResult(result_1){
    var num=document.getElementById("resultA");
    num.innerHTML=result_1;
}

function senResultB(result_2){
    var numB=document.getElementById("resultB");
    numB.innerHTML = result_2;
}


//获取输入值
function getFirst(){
    var first=document.getElementById("first").value;
    return first;
}

function getTwice(){
    var twice=document.getElementById("twice").value;
    return twice;
}

function getSecond(){
    var second=document.getElementById("second").value;
    return second;
}


//点击事件
function changeColorFir() {
    document.getElementById("first").setAttribute("style","background-color:#FFF");
}
function changeColorTwi() {
    document.getElementById("twice").setAttribute("style","background-color:#FFF");
}
function changeColorSec() {
    document.getElementById("second").setAttribute("style","background-color:#FFF");
}


/*function changeColorFir2() {
    document.getElementById("first").setAttribute("style","background-color:#98bf21");
}

function changeColorTwi2() {
    document.getElementById("twice").setAttribute("style","background-color:#98bf21");
}

function changeColorSec2() {
    document.getElementById("second").setAttribute("style","background-color:#98bf21");
}*/
