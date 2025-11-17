

local M = {}

local function test()
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
