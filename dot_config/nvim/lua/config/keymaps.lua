-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here
local keymap = vim.keymap

keymap.set("n", "<C-d>", "<C-d>zz", { desc = "Recenter when page down" })
keymap.set("n", "<C-u>", "<C-u>zz", { desc = "Recenter when page up" })
keymap.set("v", "J", ":m '>+1<CR>gv=gv", { desc = "Move line down" })
keymap.set("v", "K", ":m '<-2<CR>gv=gv", { desc = "Move line down" })
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

keymap.set("n", "<C-h>", "<Cmd>TmuxNavigateLeft<CR>", {})
keymap.set("n", "<C-j>", "<Cmd>TmuxNavigateDown<CR>", {})
keymap.set("n", "<C-k>", "<Cmd>TmuxNavigateUp<CR>", {})
keymap.set("n", "<C-l>", "<Cmd>TmuxNavigateRight<CR>", {})

-- vim test
keymap.set("n", "<leader>t", ":TestNearest<CR>")
keymap.set("n", "<leader>T", ":TestFile<CR>")
keymap.set("n", "<leader>a", ":TestSuite<CR>")
keymap.set("n", "<leader>l", ":TestLast<CR>")
keymap.set("n", "<leader>g", ":TestVisit<CR>")

vim.opt.swapfile = false

keymap.set("n", "<leader>k", "<cmd>lnext<CR>zz", { desc = "Next location entry" })
keymap.set("n", "<leader>j", "<cmd>lprev<CR>zz", { desc = "Prev location entry" })

keymap.set("n", "<leader>s", ":%s/\\<<C-r><C-w>\\>/<C-r><C-w>/gI<Left><Left><Left>")

local gtp = require("goto-preview")
keymap.set("n", "gpc", function()
  gtp.close_all_win()
end, { desc = "Close preview" })

local mark = require("harpoon.mark")
local ui = require("harpoon.ui")
keymap.set("n", "<leader>a", mark.add_file)
keymap.set("n", "<C-e>", ui.toggle_quick_menu)

keymap.set("n", "<C-t>", function()
  ui.nav_file(1)
end)
keymap.set("n", "<C-y>", function()
  ui.nav_file(2)
end)
keymap.set("n", "<C-n>", function()
  ui.nav_file(3)
end)
keymap.set("n", "<C-m>", function()
  ui.nav_file(4)
end)
