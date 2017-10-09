var result_1;

//加法
function add(){
    var a=getFirst();
    var b=getTwice();
    var re=Number(a)+Number(b);
    senResult(re);
}

function subtract(){
    var a=getFirst();
    var b=getTwice();
    var re=a-b;
    senResult(re);
}

function ride(){
    var a=getFirst();
    var b=getTwice();
    var re=a*b;
    senResult(re);
}

function devide(){
    var a=getFirst();
    var b=getTwice();
    var re=a/b;
    senResult(re);
}

//输出p值
function senResult(result_1){
    var num=document.getElementById("result");
    num.innerHTML=result_1;
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




