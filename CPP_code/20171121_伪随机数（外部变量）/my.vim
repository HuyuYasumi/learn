let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +32 F:\learn\CPP_code\20171121_伪随机数（外部变量）\r_drive1.c
badd +28 F:\learn\CPP_code\20171121_伪随机数（外部变量）\s_and_r.c
badd +0 F:\learn\CPP_code\20171121_伪随机数（外部变量）\roll.h
argglobal
silent! argdel *
$argadd F:\learn\CPP_code\20171121_伪随机数（外部变量）\r_drive1.c
edit F:\learn\CPP_code\20171121_伪随机数（外部变量）\r_drive1.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
wincmd =
argglobal
let s:l = 20 - ((19 * winheight(0) + 15) / 31)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
20
normal! 013|
wincmd w
argglobal
edit F:\learn\CPP_code\20171121_伪随机数（外部变量）\roll.h
let s:l = 6 - ((5 * winheight(0) + 12) / 24)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
6
normal! 023|
wincmd w
argglobal
edit F:\learn\CPP_code\20171121_伪随机数（外部变量）\s_and_r.c
let s:l = 22 - ((21 * winheight(0) + 28) / 56)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
22
normal! 016|
wincmd w
wincmd =
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
