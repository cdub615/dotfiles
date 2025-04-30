return {

  {
    "catppuccin/nvim",
    name = "catppuccin",
    priority = 1000,
    lazy = false,
    init = function()
      vim.cmd.colorscheme("catppuccin-mocha")
      vim.opt.termguicolors = true
    end,
    config = function()
      require("catppuccin").setup({
        flavour = "mocha",
        term_colors = true,
        transparent_background = true,
      })
    end,
  },

  { "rktjmp/lush.nvim" },

  {
    "LazyVim/LazyVim",
    opts = {
      colorscheme = "catppuccin-mocha",
    },
    -- init = function()
    --   vim.g.autoformat = false
    -- end,
  },

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
      }
    }
  },

  -- { "theprimeagen/harpoon" },

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

  { "ThePrimeagen/vim-be-good" },

  -- override nvim-cmp and add cmp-emoji
  {
    "hrsh7th/nvim-cmp",
    dependencies = { "hrsh7th/cmp-emoji" },
    opts = function(_, opts)
      table.insert(opts.sources, { name = "emoji" })
    end,
  },

  -- use lazy.nvim
  {
    "LintaoAmons/scratch.nvim",
    event = "VeryLazy",
  },

  {
    "rmagatti/goto-preview",
    event = "BufEnter",
    config = function()
      require("goto-preview").setup({
        default_mappings = true,
      })
    end,
  },

  {
    "luckasRanarison/tailwind-tools.nvim",
    name = "tailwind-tools",
    build = ":UpdateRemotePlugins",
    dependencies = {
      "nvim-treesitter/nvim-treesitter",
      "nvim-telescope/telescope.nvim",
    },
    opts = {},
  },

  -- the opts function can also be used to change the default opts:
  {
    "nvim-lualine/lualine.nvim",
    event = "VeryLazy",
    opts = function(_, opts)
      table.insert(opts.sections.lualine_x, "😄")
      opts.options = {
        theme = "auto",
      }
    end,
  },

  -- add any tools you want to have installed below
  {
    "williamboman/mason.nvim",
    opts = {
      ensure_installed = {
        "stylua",
        "shellcheck",
        "shfmt",
        "flake8",
      },
    },
  },

  -- change some telescope options and a keymap to browse plugin files
  {
    "nvim-telescope/telescope.nvim",
    keys = {
      -- add a keymap to browse plugin files
      -- stylua: ignore
      {
        "<leader>fp",
        function() require("telescope.builtin").find_files({ cwd = require("lazy.core.config").options.root }) end,
        desc = "Find Plugin File",
      },
    },
    -- change some options
    opts = {
      defaults = {
        layout_strategy = "horizontal",
        layout_config = { prompt_position = "top" },
        sorting_strategy = "ascending",
        winblend = 0,
      },
    },
  },

  -- {
  --   "akinsho/toggleterm.nvim",
  --   version = "*",
  --   opts = {
  --     size = 10,
  --     open_mapping = [[<c-\>]],
  --     hide_numbers = true,
  --     shade_filetypes = {},
  --     shade_terminals = true,
  --     shading_factor = 2,
  --     start_in_insert = true,
  --     insert_mappings = true,
  --     persist_size = true,
  --     direction = "horizontal",
  --     close_on_exit = true,
  --     shell = vim.o.shell,
  --   },
  -- },

  -- {
  --   "doctorfree/cheatsheet.nvim",
  --   event = "VeryLazy",
  --   dependencies = {
  --     { "nvim-telescope/telescope.nvim" },
  --     { "nvim-lua/popup.nvim" },
  --     { "nvim-lua/plenary.nvim" },
  --   },
  --   config = function()
  --     local ctactions = require("cheatsheet.telescope.actions")
  --     require("cheatsheet").setup({
  --       bundled_cheetsheets = {
  --         enabled = { "default", "lua", "markdown", "regex", "netrw", "unicode" },
  --         disabled = { "nerd-fonts" },
  --       },
  --       bundled_plugin_cheatsheets = {
  --         enabled = {
  --           "auto-session",
  --           "goto-preview",
  --           "octo.nvim",
  --           "telescope.nvim",
  --           "vim-easy-align",
  --           "vim-sandwich",
  --         },
  --         disabled = { "gitsigns" },
  --       },
  --       include_only_installed_plugins = true,
  --       telescope_mappings = {
  --         ["<CR>"] = ctactions.select_or_fill_commandline,
  --         ["<A-CR>"] = ctactions.select_or_execute,
  --         ["<C-Y>"] = ctactions.copy_cheat_value,
  --         ["<C-E>"] = ctactions.edit_user_cheatsheet,
  --       },
  --     })
  --   end,
  -- },

  {
    "tpope/vim-unimpaired",
  },

  {
    "amitds1997/remote-nvim.nvim",
    version = "*",                     -- Pin to GitHub release
    dependencies = {
      "nvim-lua/plenary.nvim",         -- for standard functions
      "MunifTanjim/nui.nvim",          -- to build the plugin UI
      "nvim-telescope/telescope.nvim", -- for picking between different remote methods
    },
    config = true,
  },

  { "christoomey/vim-tmux-navigator" },

  {
    "vim-test/vim-test",
    dependencies = {
      "preservim/vimux",
    },
    config = function()
      vim.g["test#strategy"] = "vimux"
    end,
  },

  {
    "nvim-treesitter/nvim-treesitter",
    opts = function(_, opts)
      if type(opts.ensure_installed) == "table" then
        vim.list_extend(opts.ensure_installed, { "vue" })
      end
    end,
  },

  {
    "esensar/nvim-dev-container",
    config = function()
      require("devcontainer").setup({
        -- Add any plugin-specific configuration here
      })
    end,
    -- keys = {
    --   {
    --     "<leader>R",
    --     name = "+Devcontainer",
    --     c = { "<cmd>DevcontainerStart<CR>", "Start Devcontainer" },
    --     a = { "<cmd>DevcontainerAttach<CR>", "Attach to Devcontainer" },
    --     l = { "<cmd>DevcontainerLogs<CR>", "Show Devcontainer Logs" },
    --     s = { "<cmd>DevcontainerStop<CR>", "Stop Devcontainer" },
    --     r = { "<cmd>DevcontainerRemove<CR>", "Remove Devcontainer" },
    --     b = { "<cmd>DevcontainerBuild<CR>", "Build Devcontainer" },
    --     x = { "<cmd>DevcontainerExec<CR>", "Execute in Devcontainer" },
    --     i = { "<cmd>DevcontainerImageRun<CR>", "Run Devcontainer Image" },
    --     -- Add more commands as needed
    --   },
    -- },
  },

  -- {
  --   "folke/which-key.nvim",
  --   opts = {
  --     spec = {
  --       ["<leader>R"] = { name = "+Devcontainer", group = "Devcontainer" },
  --     },
  --   },
  -- },

}
