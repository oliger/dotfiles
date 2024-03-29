" install vim-plug
if empty(glob('~/.config/nvim/autoload/plug.vim'))
  silent !curl -fLo ~/.config/nvim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  autocmd VimEnter * PlugInstall | source $MYVIMRC
endif

call plug#begin(expand('~/.config/nvim/plugged'))

Plug '/opt/homebrew/opt/fzf'
Plug 'junegunn/fzf.vim'
Plug 'Lokaltog/vim-monotone'
Plug 'neovim/nvim-lspconfig'
Plug 'nvim-lua/completion-nvim'
Plug 'preservim/nerdcommenter'
Plug 'preservim/nerdtree'
Plug 'prettier/vim-prettier', { 'do': 'yarn install --frozen-lockfile --production' }
Plug 'sheerun/vim-polyglot'
Plug 'tpope/vim-sensible'
Plug 'tpope/vim-surround'

call plug#end()

" nvim configuration
set hidden
set relativenumber
set completeopt=menuone,noinsert
set noerrorbells
set showcmd
set noswapfile
set nobackup
set splitright
set splitbelow
set autowrite
set termguicolors

filetype plugin on

" Theme
let g:monotone_contrast_factor = 1.1
colorscheme monotone

" keymaps
let mapleader = "\<Space>" 

imap jj <Esc>
nnoremap <Leader>v :e $MYVIMRC<CR>

" prettier
let g:prettier#autoformat = 1
let g:prettier#autoformat_require_pragma = 0
let g:prettier#exec_cmd_async = 1

" fzf
let g:fzf_layout = { 'down': '~20%' }
nmap <C-p> :GFiles<CR>

" NERDTree
let NERDTreeShowHidden=1

noremap <Leader>n :NERDTreeToggle<cr>

" NERDCommenter
let g:NERDSpaceDelims = 1
let g:NERDCommentEmptyLines = 1
let g:NERDTrimTrailingWhitespace = 1
let g:NERDToggleCheckAllLines = 1

map <leader>/ <plug>NERDCommenterToggle

" lsp configuration
lua require'lspconfig'.tsserver.setup{on_attach=require'completion'.on_attach}

if !exists('*ReloadVimrc')
  fun! ReloadVimrc()
    source $MYVIMRC
  endfun
endif
autocmd! BufWritePost $MYVIMRC call ReloadVimrc()
