// main.c  —— 一个最小的把 Lua 嵌入到 C 程序
#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int main(int argc, char **argv) {
    // 1. 创建 Lua 状态机
    lua_State *L = luaL_newstate();
    if (L == NULL) {
        printf("无法创建 lua_State\n");
        return 1;
    }

    // 2. 打开标准库（print、table、math 等）
    luaL_openlibs(L);

    // 3. 方式一：直接运行字符串脚本
    const char *script = 
        "print('Hello from Lua!')\n"
        "a = 123 + 456\n"
        "print('a =', a)";
    
    if (luaL_dostring(L, script)) {
        // 如果有错误，打印错误信息
        printf("错误: %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
    }

    // 4. 方式二：加载并运行外部 .lua 文件
    if (argc > 1) {
        if (luaL_dofile(L, argv[1])) {
            printf("运行文件失败: %s\n", lua_tostring(L, -1));
            lua_pop(L, 1);
        }
    }

    // 5. C 和 Lua 互相调用示例
    // 把 C 的变量传给 Lua
    // lua_pushnumber(L, 3.14159);
    // lua_setglobal(L, "pi_from_c");

    // // 调用 Lua 函数并获取返回值
    // lua_getglobal(L, "math");      // 压入 table math
    // lua_getfield(L, -1, "sin");    // 压入 math.sin
    // lua_pushnumber(L, 1.57);
    // if (lua_pcall(L, 1, 1, 0) == LUA_OK) {
    //     printf("sin(1.57) ≈ %.4f\n", lua_tonumber(L, -1));
    //     lua_pop(L, 1);
    // }
    // lua_pop(L, 1); // 弹出 math table

    // 6. 关闭 Lua 状态机
    lua_close(L);
    return 0;
}