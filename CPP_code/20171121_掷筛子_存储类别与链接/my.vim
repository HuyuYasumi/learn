let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +17 F:\learn\CPP_code\20171121_��ɸ��_�洢���������\main.c
badd +0 F:\learn\CPP_code\20171121_��ɸ��_�洢���������\diceroll.c
badd +0 F:\learn\CPP_code\20171121_��ɸ��_�洢���������\diceroll.h
argglobal
silent! argdel *
$argadd F:\learn\CPP_code\20171121_��ɸ��_�洢���������\main.c
edit F:\learn\CPP_code\20171121_��ɸ��_�洢���������\main.c
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
let s:l = 20 - ((19 * winheight(0) + 21) / 42)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
20
normal! 013|
wincmd w
argglobal
edit F:\learn\CPP_code\20171121_��ɸ��_�洢���������\diceroll.h
let s:l = 1 - ((0 * winheight(0) + 6) / 13)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 012|
wincmd w
argglobal
edit F:\learn\CPP_code\20171121_��ɸ��_�洢���������\diceroll.c
let s:l = 18 - ((17 * winheight(0) + 28) / 56)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
18
normal! 016|
wincmd w
2wincmd w
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
