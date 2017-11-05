function treasuieSubmenuover() {
    var a=document.getElementById("nav-treasuie-submenu");
    a.setAttribute("style","display:block;z-index:3;border-color:#eee;");
}
function treasuieSubmenuout() {
    document.getElementById("nav-treasuie-submenu").setAttribute("style","display:none;z-index:2;");
}
function bookSubmenuover() {
    var a=document.getElementById("nav-book-submenu");
    a.setAttribute("style","display:block;z-index:3;border-color:#eee;");
}
function bookSubmenuout() {
    document.getElementById("nav-book-submenu").setAttribute("style","display:none;z-index:2;");
}
function businessSubmenuover() {
    var a=document.getElementById("nav-business-submenu");
    a.setAttribute("style","display:block;z-index:3;border-color:#eee;");
}
function businessSubmenuout() {
    document.getElementById("nav-business-submenu").setAttribute("style","display:none;z-index:2;");
}

function center_menu() {
    document.getElementById("center_menu").setAttribute("style","background-color:#454343;txt-color:#ff0036;");
    document.getElementById("center_menu_1111").setAttribute("style","background-color:#ff0036");
}
function center_menu_1111() {
    document.getElementById("center_menu_1111").setAttribute("style","background-color:#454343;color:#ff0036;");
    document.getElementById("center_menu").setAttribute("style","center_menu");
}
