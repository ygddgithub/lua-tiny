local M = {}

local function add(a,b)
    return a+b
end


local function test()
    local a = 111
    local b = 222
    local c = add(a,b)
    print("cccccc",c)
    -- math del
    print("math",math) --nil
    -- utf8 del
    local s = "how delicious😘"
    print("utf8",utf8) --nil
    -- debug del
    print("debug",debug) --nil
    --io del
    print("io",io)
    --package del
    print("package",package)

    print("success")
end



test()
