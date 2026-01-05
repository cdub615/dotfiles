return {
  {
    "mfussenegger/nvim-dap",
    opts = function()
      local dap = require("dap")
      -- Add common .NET launch configurations
      if not dap.configurations.cs then
        dap.configurations.cs = {}
      end
      table.insert(dap.configurations.cs, {
        type = "coreclr",
        name = "launch - netcoredbg",
        request = "launch",
        program = function()
          return vim.fn.input('Path to dll: ', vim.fn.getcwd() .. '/bin/Debug/', 'file')
        end,
      })
    end,
  },
}
