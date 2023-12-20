#pragma once

#include <string>
#include <stdexcept>
#include <utility>

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#define DYLIB_CPP17
#include <filesystem>
#endif

#if (defined(_WIN32) || defined(_WIN64))
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN
#else
#include <windows.h>
#endif
#else
#include <dlfcn.h>
#endif

#if (defined(_WIN32) || defined(_WIN64))
#define DYLIB_WIN_MAC_OTHER(win_def, mac_def, other_def) win_def
#define DYLIB_WIN_OTHER(win_def, other_def) win_def
#elif defined(__APPLE__)
#define DYLIB_WIN_MAC_OTHER(win_def, mac_def, other_def) mac_def
#define DYLIB_WIN_OTHER(win_def, other_def) other_def
#else
#define DYLIB_WIN_MAC_OTHER(win_def, mac_def, other_def) other_def
#define DYLIB_WIN_OTHER(win_def, other_def) other_def
#endif

class dylib {
public:
    static constexpr const char *prefix = DYLIB_WIN_OTHER("", "lib");
    static constexpr const char *suffix = DYLIB_WIN_MAC_OTHER(".dll", ".dylib", ".so");
    
    using native_handle_type = DYLIB_WIN_OTHER(HINSTANCE, void *);
    using native_symbol_type = DYLIB_WIN_OTHER(FARPROC, void *);

    static_assert(std::is_pointer<native_handle_type>::value, "Expecting HINSTANCE to be a pointer");
    static_assert(std::is_pointer<native_symbol_type>::value, "Expecting FARPROC to be a pointer");

    static constexpr bool add_filename_decorations = true;
    static constexpr bool no_filename_decorations = false;

    static native_handle_type load_library(std::string dir_path, std::string lib_name, bool decorations = no_filename_decorations) noexcept {
        if (decorations) {
            lib_name = prefix + lib_name + suffix;
        }
        
        if (!dir_path.empty() && dir_path.find_last_of('/') != dir_path.size() - 1) {
            dir_path += '/';
        }

        auto full_path = dir_path + lib_name;
        
        native_handle_type handle = nullptr;
#if (defined(_WIN32) || defined(_WIN64))
        handle = LoadLibraryA(full_path.c_str());
#else
        handle = dlopen(full_path.c_str(), RTLD_NOW | RTLD_LOCAL);
#endif
        return handle;
    }

    static native_symbol_type get_symbol(native_handle_type lib, const std::string& name) noexcept {
        return DYLIB_WIN_OTHER(GetProcAddress, dlsym)(lib, name.c_str());
    }

    static void unload_library(native_handle_type lib) noexcept {
        DYLIB_WIN_OTHER(FreeLibrary, dlclose)(lib);
    }

    static std::string get_error_description() noexcept {
#if (defined(_WIN32) || defined(_WIN64))
        constexpr const size_t BUF_SIZE = 512;
        const auto error_code = GetLastError();
        if (!error_code)
            return "No error reported by GetLastError";
        char description[BUF_SIZE];
        const auto lang = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US);
        const DWORD length =
            FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, error_code, lang, description, BUF_SIZE, nullptr);
        return (length == 0) ? "Unknown error (FormatMessage failed)" : description;
#else
        const auto description = dlerror();
        return (description == nullptr) ? "No error reported by dlerror" : description;
#endif
    }
};

#undef DYLIB_WIN_MAC_OTHER
#undef DYLIB_WIN_OTHER
#undef DYLIB_CPP17
