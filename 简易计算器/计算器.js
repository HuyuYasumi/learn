var result_1;

//加法
function add(){
    var a=getFrist();
    var b=getTwice();
    var re=a+b;
    senResult(re);
}

function subtract(){
    var a=getFrist();
    var b=getTwice();
    var re=a-b;
    senResult(re);
}

function ride(){
    var a=getFrist();
    var b=getTwice();
    var re=a*b;
    senResult(re);
}

function devide(){
    var a=getFrist();
    var b=getTwice();
    var re=a/b;
    senResult(re);
}

//获取输入值
function getFirst(){
    var first=document.getElementById("first").value;
    return first;
}

function getTwice(){
    var twice=document.getElementById("twice").vavlue;
    return twice;
}

//输出p值
functuon senResult(result_1){
    var num=document.getElementById("result");
    num.innerHTML=result_1;
}


