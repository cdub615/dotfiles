-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here
local dap = require("dap")
local dapui = require("dapui")

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

-- Keybindings (F-keys for efficiency)
vim.keymap.set('n', '<F5>', function() dap.continue() end, { desc = 'DAP Continue' })
vim.keymap.set('n', '<S-F5>', function() dap.terminate() end, { desc = 'DAP Terminate' })
vim.keymap.set('n', '<F9>', function() dap.toggle_breakpoint() end, { desc = 'DAP Toggle Breakpoint' })
vim.keymap.set('n', '<F10>', function() dap.step_over() end, { desc = 'DAP Step Over' })
vim.keymap.set('n', '<F11>', function() dap.step_into() end, { desc = 'DAP Step Into' })
vim.keymap.set('n', '<S-F11>', function() dap.step_out() end, { desc = 'DAP Step Out' })
vim.keymap.set('n', '<leader>dr', function() dap.repl.open() end, { desc = 'DAP REPL' })
vim.keymap.set('n', '<leader>du', function() dapui.toggle() end, { desc = 'DAP UI Toggle' })
