x=document.getElementById("intro");
document.write('<p>id="intro"的段落是：' + x.innerHTML + '</p>');
y=document.getElementById("Tijn").innerHTML="Tijn";
document.write(y);


function changeimg(id){
document.getElementById("butong").src="https://78.media.tumblr.com/a6d791ffa511e4bf0deb71c0a019e05e/tumblr_ox48sk2BNU1qb2kz6o1_1280.jpg"
};
document.getElementById("butong").onclick=function(){
    changeimg();
    var para=document.createElement("p");
    var node=document.createTextNode("很遗憾只能更改一次，如需再次体验请按<F5>");
    para.appendChild(node);
    var element=document.getElementById("p1");
    var child=document.getElementById("p2");
    element.replaceChild(para,child)
};

