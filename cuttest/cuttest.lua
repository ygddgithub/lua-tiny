

local M = {}

local function test()
    -- math del
    print("math",math) --nil
    -- utf8 del
    local s = "how delicious😘"
    print("utf8",utf8) --nil
    -- 
    print("success")
end

test()
