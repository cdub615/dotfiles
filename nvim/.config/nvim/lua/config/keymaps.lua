-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here
local keymap = vim.keymap

keymap.set("v", "N", ":m '>+1<CR>gv=gv", { desc = "Move line down" })
keymap.set("v", "E", ":m '<-2<CR>gv=gv", { desc = "Move line down" })
keymap.set("n", "n", "nzzzv", { desc = "Go to next instance and handle folds" })
keymap.set("n", "N", "Nzzzv", { desc = "Go to prev instance and handle folds" })
keymap.set("n", "J", "mzJ`z", { desc = "Join line without moving cursor" })
keymap.set("x", "<leader>p", '"_dP', { desc = "Paste without overwriting" })

keymap.set("n", "<leader>y", '"+y', { desc = "Yank to clipboard" })
keymap.set("v", "<leader>y", '"+y', { desc = "Yank to clipboard" })
keymap.set("n", "<leader>Y", '"+Y', { desc = "Yank to clipboard" })

keymap.set("n", "<leader>d", '"_d', { desc = "Delete without overwriting" })
keymap.set("v", "<leader>d", '"_d', { desc = "Delete without overwriting" })

keymap.set("i", "<C-c>", "<Esc>", { desc = "Escape insert mode" })

keymap.set("n", "<C-m>", "<Cmd>TmuxNavigateLeft<CR>", {})
keymap.set("n", "<C-n>", "<Cmd>TmuxNavigateDown<CR>", {})
keymap.set("n", "<C-e>", "<Cmd>TmuxNavigateUp<CR>", {})
keymap.set("n", "<C-i>", "<Cmd>TmuxNavigateRight<CR>", {})

-- vim test
keymap.set("n", "<leader>t", ":TestNearest<CR>")
keymap.set("n", "<leader>T", ":TestFile<CR>")
-- keymap.set("n", "<leader>a", ":TestSuite<CR>")
keymap.set("n", "<leader>l", ":TestLast<CR>")
keymap.set("n", "<leader>g", ":TestVisit<CR>")

vim.opt.swapfile = false

keymap.set("n", "<leader>j", "<cmd>lprev<CR>zz", { desc = "Prev location entry" })
keymap.set("n", "<leader>k", "<cmd>lnext<CR>zz", { desc = "Next location entry" })

keymap.set("n", "<leader>s", ":%s/\\<<C-r><C-w>\\>/<C-r><C-w>/gI<Left><Left><Left>")
