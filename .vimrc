call plug#begin()
Plug 'preservim/nerdtree'
Plug 'arzg/vim-colors-xcode'
call plug#end()

colorscheme xcodedark

set nocompatible
syntax enable
filetype plugin on
set termguicolors

set number relativenumber
set nu rnu
set cursorline
nmap <F6> :NERDTreeToggle<CR>
set tabstop=4
set shiftwidth=4
set expandtab

set path+=**
set wildmenu

let g:netrw_banner=0
let g:netrw_browse_split=4
let g:netrw_altv=1
let g:netrw_liststyle=3
let g:netrw_list_hide=netrw_gitignore#Hide()
let g:netrw_list_hide.=',\(^\|\s\s\)\zs\.\S\+'
