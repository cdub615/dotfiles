-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here

-- Ctrl+arrows are now for navigation, Alt+arrows for resizing
vim.keymap.set("n", "<C-Left>", "<Cmd>NvimTmuxNavigateLeft<CR>", { desc = "Navigate Left" })
vim.keymap.set("n", "<C-Down>", "<Cmd>NvimTmuxNavigateDown<CR>", { desc = "Navigate Down" })
vim.keymap.set("n", "<C-Up>", "<Cmd>NvimTmuxNavigateUp<CR>", { desc = "Navigate Up" })
vim.keymap.set("n", "<C-Right>", "<Cmd>NvimTmuxNavigateRight<CR>", { desc = "Navigate Right" })

-- New resizing bindings with Alt+arrows
vim.keymap.set("n", "<A-Up>", "<cmd>resize +2<cr>", { desc = "Increase Window Height" })
vim.keymap.set("n", "<A-Down>", "<cmd>resize -2<cr>", { desc = "Decrease Window Height" })
vim.keymap.set("n", "<A-Left>", "<cmd>vertical resize -2<cr>", { desc = "Decrease Window Width" })
vim.keymap.set("n", "<A-Right>", "<cmd>vertical resize +2<cr>", { desc = "Increase Window Width" })
