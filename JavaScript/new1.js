/*x=document.getElementById("intro");
document.write('<p>id="intro"的段落是：' + x.innerHTML + '</p>');
y=document.getElementById("Tijn").innerHTML="Tijn";
document.write(y);*/


function changeimg(id){
document.getElementById("butong").src="file:///D:/GoogleDrive/GAME/PSP/SAVE/%E6%80%AA%E7%89%A9%E7%8C%8E%E4%BA%BAP3/ULJM05800/PIC1.PNG"
};
document.getElementById("p1").onclick=function(){
    changeimg();
    var para=document.createElement("p");
    var node=document.createTextNode("很遗憾只能更改一次，如需再次体验请按<F5>");
    para.appendChild(node);
    var element=document.getElementById("p1");
    var child=document.getElementById("p2");
    element.replaceChild(para,child)
};
