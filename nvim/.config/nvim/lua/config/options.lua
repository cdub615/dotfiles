-- Options are automatically loaded before lazy.nvim startup
-- Default options that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/options.lua
-- Add any additional options here
vim.opt.relativenumber = true
vim.opt.autoread = true  -- Enable autoread globally
vim.opt.updatetime = 200 -- Reduce delay for CursorHold events (already default in LazyVim) [web:3]

-- Autocommand to reload changed buffers
vim.api.nvim_create_autocmd({ "FocusGained", "CursorHold", "BufEnter" }, {
  callback = function()
    vim.cmd("checktime") -- Checks timestamp and reloads if changed
  end,
})
