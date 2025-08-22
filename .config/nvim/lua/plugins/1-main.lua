return {

  {
    "stevearc/conform.nvim",
    opts = {
      formatters_by_ft = {
        lua = { "stylelua" },
        python = { "isort", "black" },
        javascript = { "prettier" },
        typescript = { "prettier" },
        javascriptreact = { "prettier" },
        typescriptreact = { "prettier" },
        vue = { "prettier" },
        svelte = { "prettier" },
      },
    },
  },

  {
    "mg979/vim-visual-multi",
    event = "VeryLazy",
    init = function()
      vim.g.VM_default_mappings = 0
      vim.g.VM_add_cursor_at_pos_no_mappings = 1
      vim.g.VM_maps = {
        ["Find Under"] = "<M-C-n>",
        ["Select All"] = "<M-C-l>",
        ["Add Cursor Down"] = "<M-C-n>",
        ["Add Cursor Up"] = "<M-C-e>",
      }
    end,
  },

  { "tpope/vim-commentary" },

  { "christoomey/vim-tmux-navigator" },

  {
    "tpope/vim-unimpaired",
  },
}
