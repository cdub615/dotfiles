return {
  "alexghergh/nvim-tmux-navigation",
  config = function()
    require('nvim-tmux-navigation').setup({})
    vim.keymap.set("n", "<C-m>", "<Cmd>NvimTmuxNavigateLeft<CR>", {})
    vim.keymap.set("n", "<C-n>", "<Cmd>NvimTmuxNavigateDown<CR>", {})
    vim.keymap.set("n", "<C-e>", "<Cmd>NvimTmuxNavigateUp<CR>", {})
    vim.keymap.set("n", "<C-i>", "<Cmd>NvimTmuxNavigateRight<CR>", {})
  end,
}
