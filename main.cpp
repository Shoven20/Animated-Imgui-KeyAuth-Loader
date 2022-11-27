#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include <Windows.h>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <winbase.h>
#include <tchar.h>
#include <WinInet.h>
#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")
#include <D3dx9tex.h>
#pragma comment(lib, "D3dx9")
IDirect3DTexture9* DiscordLogo;
IDirect3DTexture9* RustLogo;
IDirect3DTexture9* DeadSideLogo;
IDirect3DTexture9* ValorantLogo;
IDirect3DTexture9* ApexLegendsLogo;
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"Wininet.lib")

#pragma comment(lib, "winmm.lib")

#define _WIN32_WINNT 0x0500


using namespace std;

ImFont* tab_title;
ImFont* icon;
ImFont* small_icon;
ImFont* big_icon;

// Defines
#define ALPHA (ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar)
#define NO_ALPHA (ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar)


using namespace KeyAuth;


std::string name = _xor_(" ");
std::string ownerid = _xor_(" ");
std::string secret = _xor_(" ");
std::string version = _xor_("1.0");
std::string channelname = _xor_("Chat"); // name of the channel for sending and reading messages

api KeyAuthApp(name, ownerid, secret, version);
void MouseCur(int Deger)
{
    const char* mouse_cursors_names[] = { "Arrow", "TextInput", "ResizeAll", "ResizeNS", "ResizeEW", "ResizeNESW", "ResizeNWSE", "Hand", "NotAllowed" };
    IM_ASSERT(IM_ARRAYSIZE(mouse_cursors_names) == ImGuiMouseCursor_COUNT);
    if (ImGui::IsItemHovered())
        ImGui::SetMouseCursor(Deger);
}

bool kaydetmebasarili = false;
int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, LOADER_BRAND, NULL };
    RegisterClassEx(&wc);
    main_hwnd = CreateWindow(wc.lpszClassName, LOADER_BRAND, WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);


    if (!CreateDeviceD3D(main_hwnd)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }


    ShowWindow(main_hwnd, SW_HIDE);
    UpdateWindow(main_hwnd);


    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;


   
    ImGui_ImplWin32_Init(main_hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);



    DWORD window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

    RECT screen_rect;
    GetWindowRect(GetDesktopWindow(), &screen_rect);
    auto x = float(screen_rect.right - WINDOW_WIDTH) / 2.f;
    auto y = float(screen_rect.bottom - WINDOW_HEIGHT) / 2.f;

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));


    // Load Fonts
    ImFontConfig font_config;
    font_config.PixelSnapH = false;
    font_config.OversampleH = 5;
    font_config.OversampleV = 5;
    font_config.RasterizerMultiply = 1.2f;

    static const ImWchar ranges[] =
    {
        0x0020, 0x00FF, // Basic Latin + Latin Supplement
        0x0400, 0x052F, // Cyrillic + Cyrillic Supplement
        0x2DE0, 0x2DFF, // Cyrillic Extended-A
        0xA640, 0xA69F, // Cyrillic Extended-B
        0xE000, 0xE226, // icons
        0,
    };

    font_config.GlyphRanges = ranges;

    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\verdana.ttf", 14.0f, &font_config, ranges);
    tab_title = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arialbd.ttf", 17.0f, &font_config, ranges);
    icon = io.Fonts->AddFontFromMemoryTTF(loadericon, sizeof(loadericon), 14.0f, &font_config, ranges);
    small_icon = io.Fonts->AddFontFromMemoryTTF(loadericon, sizeof(loadericon), 11.0f, &font_config, ranges);
    big_icon = io.Fonts->AddFontFromMemoryTTF(loadericon, sizeof(loadericon), 26.0f, &font_config, ranges);

    D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, DiscordLogo2, sizeof(DiscordLogo2), 100, 100, D3DX_DEFAULT, D3DUSAGE_DYNAMIC, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &DiscordLogo);
    D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, Rust, sizeof(Rust), 100, 100, D3DX_DEFAULT, D3DUSAGE_DYNAMIC, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &RustLogo);
    D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, DeadSidee, sizeof(DeadSidee), 100, 100, D3DX_DEFAULT, D3DUSAGE_DYNAMIC, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &DeadSideLogo);
    D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, Valorantt, sizeof(Valorantt), 100, 100, D3DX_DEFAULT, D3DUSAGE_DYNAMIC, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &ValorantLogo);
    D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, ApexLegendss, sizeof(ApexLegendss), 100, 100, D3DX_DEFAULT, D3DUSAGE_DYNAMIC, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &ApexLegendsLogo);

    // Our state
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    FILE* RustDosya;
    if (RustDosya = fopen((RustLisansKonum.c_str()), ("r"))) {
        std::ifstream DosyaOku1(RustLisansKonum.c_str());
        std::string Anahtar1;
        std::getline(DosyaOku1, Anahtar1);
        DosyaOku1.close();
        fclose(RustDosya);

        int i;
        for (i = 0; i < 50; i++) {
            RustKey[i] = Anahtar1[i];
        }
    }
    FILE* DeadSideDosya;
    if (DeadSideDosya = fopen((DeadSideLisansKonum.c_str()), ("r"))) {
        std::ifstream DosyaOku2(DeadSideLisansKonum.c_str());
        std::string Anahtar2;
        std::getline(DosyaOku2, Anahtar2);
        DosyaOku2.close();
        fclose(DeadSideDosya);

        int i;
        for (i = 0; i < 50; i++) {
            DeadSide[i] = Anahtar2[i];
        }
    }
    FILE* ValoDosya;
    if (ValoDosya = fopen((ValorantLisansKonum.c_str()), ("r"))) {
        std::ifstream DosyaOku3(ValorantLisansKonum.c_str());
        std::string Anahtar3;
        std::getline(DosyaOku3, Anahtar3);
        DosyaOku3.close();
        fclose(ValoDosya);

        int i;
        for (i = 0; i < 50; i++) {
            ValoKey[i] = Anahtar3[i];
        }
    }
    FILE* ApexDosya;
    if (ApexDosya = fopen((ApexLisansKonum.c_str()), ("r"))) {
        std::ifstream DosyaOku4(ApexLisansKonum.c_str());
        std::string Anahtar4;
        std::getline(DosyaOku4, Anahtar4);
        DosyaOku4.close();
        fclose(ApexDosya);

        int i;
        for (i = 0; i < 50; i++) {
            ApexKey[i] = Anahtar4[i];
        }
    }
    FILE* Dosya;
    if (Dosya = fopen((DosyaKonumu.c_str()), ("r"))) {
        std::ifstream DosyaOku(DosyaKonumu.c_str());
        std::string Anahtar;
        std::getline(DosyaOku, Anahtar);
        DosyaOku.close();
        fclose(Dosya);

        int i;
        for (i = 0; i < 50; i++) {
            password[i] = Anahtar[i];
        }
    }
    std::string Anahtar2 = "";
    int index;
    for (index = 0; index < 50; index++) {
        Anahtar2[index] = password[index];
    }
    if (Anahtar2 == "") { RememberMe = false; }
    else { RememberMe = true; }
    KeyAuthApp.init();
    while (msg.message != WM_QUIT)
    {
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            void Theme(); {
                ImGuiStyle& style = ImGui::GetStyle();
                ImVec4* colors = style.Colors;

                colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
                colors[ImGuiCol_TextDisabled] = ImVec4(ImColor(255, 255, 255, 179));
                colors[ImGuiCol_WindowBg] = ImVec4(ImColor(17, 17, 17));
                colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
                colors[ImGuiCol_PopupBg] = ImVec4(ImColor(28, 28, 28));
                colors[ImGuiCol_Border] = ImVec4(ImColor(50, 50, 50));
                colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
                colors[ImGuiCol_FrameBg] = ImVec4(ImColor(28, 28, 28));
                colors[ImGuiCol_FrameBgHovered] = ImVec4(ImColor(23, 23, 23));
                colors[ImGuiCol_FrameBgActive] = ImVec4(accent_colour[0], accent_colour[1], accent_colour[2], accent_colour[3]);
                colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
                colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
                colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
                colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
                colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.00f);
                colors[ImGuiCol_ScrollbarGrab] = ImVec4(ImColor(20, 20, 20));
                colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(ImColor(20, 20, 20));
                colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(ImColor(20, 20, 20));
                colors[ImGuiCol_CheckMark] = ImVec4(accent_colour[0], accent_colour[1], accent_colour[2], accent_colour[3]);
                colors[ImGuiCol_SliderGrab] = ImVec4(accent_colour[0], accent_colour[1], accent_colour[2], accent_colour[3]);
                colors[ImGuiCol_SliderGrabActive] = ImVec4(ImColor(145, 47, 47));
                colors[ImGuiCol_Button] = ImVec4(accent_colour[0], accent_colour[1], accent_colour[2], accent_colour[3]);
                colors[ImGuiCol_ButtonHovered] = ImVec4(accent_colour[0], accent_colour[1], accent_colour[2], 0.70f);
                colors[ImGuiCol_ButtonActive] = ImVec4(accent_colour[0], accent_colour[1], accent_colour[2], 0.50f);
                colors[ImGuiCol_Header] = ImVec4(accent_colour[0], accent_colour[1], accent_colour[2], accent_colour[3]);
                colors[ImGuiCol_HeaderHovered] = ImVec4(accent_colour[0], accent_colour[1], accent_colour[2], accent_colour[3]);
                colors[ImGuiCol_HeaderActive] = ImVec4(ImColor(23, 23, 23));
                colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
                colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
                colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
                colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
                colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
                colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
                colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.80f);
                colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
                colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
                colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
                colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
                colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
                colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
                colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
                colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
                colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
                colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
                colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);   // Prefer using Alpha=1.0 here
                colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);   // Prefer using Alpha=1.0 here
                colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
                colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
                colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
                colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
                colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
                colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
                colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
            }
        }


        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }





        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(WINDOW_WIDTH* dpi_scale, WINDOW_HEIGHT* dpi_scale));
            ImGui::SetNextWindowBgAlpha(1.0f);
            ImGui::Begin("domain.com", &loader_active, ImGuiWindowFlags_NoDecoration);
            {
                auto draw = ImGui::GetWindowDrawList();
                ImVec2 pos = ImGui::GetWindowPos();
                ImVec2 size = ImGui::GetWindowSize();
                ImVec2 cheat_name_size = ImGui::CalcTextSize(cheat_name);

                draw->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + 23), ImColor(0, 0, 0), 8.0f, ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersTopRight);

                draw->AddText(icon, 14.0f, ImVec2(pos.x + 9, pos.y + 4), ImColor(accent_colour[0], accent_colour[1], accent_colour[2]), cheat_icon_symbol);
                draw->AddText(ImVec2(pos.x + 27, pos.y + 4), ImColor(200, 200, 200), cheat_name);
                draw->AddText(ImVec2(pos.x + 27 + cheat_name_size.x, pos.y + 4), ImColor(accent_colour[0], accent_colour[1], accent_colour[2]), cheat_domain);

                draw->AddLine(ImVec2(pos.x, pos.y + 23), ImVec2(pos.x + size.x, pos.y + 23), ImColor(46, 46, 46)); // upper line
                draw->AddRectFilledMultiColor(ImVec2(pos.x, pos.y + 24), ImVec2(pos.x + size.x, pos.y + WINDOW_HEIGHT * dpi_scale), ImColor(15, 15, 15), ImColor(0, 0, 0), ImColor(15, 15, 15, 0), ImColor(0, 0, 0, 0));

                ImGui::SetCursorPos(ImVec2(size.x - 15, 3));
                if (custom::selected("x", 2 == tab)) {
                    exit(0);
                }

                ImGui::SetCursorPos(ImVec2(size.x - 31, 5));
                ImGui::PushFont(small_icon);
                if (custom::selected("U", 2 == tab)) {
                    if (tab != 2) old_tab = tab;
                    tab == 2 ? tab = old_tab, content_animation = 0.0f : tab = 2, content_animation = 0.0f;
                }
                ImGui::PopFont();

                if (update_on_f5) { if (GetAsyncKeyState(VK_F5)) content_animation = 0.0f; } // lol
                content_animation = ImLerp(content_animation, content_animation < 1.0f ? 1.0f : 0.0f, 0.05f * (0.5f - ImGui::GetIO().DeltaTime));

                if (tab == 0) {
                    draw->AddText(tab_title, 17.0f, ImVec2(pos.x + size.x / 2 - ImGui::CalcTextSize("Giris Yap").x / 2 - 10, pos.y + 45 * content_animation), ImColor(0.8f, 0.8f, 0.8f, content_animation), "Giris Yap");

                    ImGui::SetCursorPos(ImVec2(155 * dpi_scale, 85 * content_animation));

                    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, content_animation);
                    ImGui::BeginChild("##LisansKismi", ImVec2(size.x / 1.8, size.y - 80));
                    {
                     
                        ImGui::InputText("Lisans", password, sizeof(password), ImGuiInputTextFlags_Password);
                        if (ImGui::Button("Giris Yap", ImVec2(188 * dpi_scale, 25 * dpi_scale))) KeyAuthApp.license(password);
                        ImGui::Checkbox("Beni Hatirla", &RememberMe);
                        if (animate == true)
                        {
                            ImGui::ProgressBar(progress, ImVec2(188 * dpi_scale, 15 * dpi_scale));
                            progress += progress_dir * 0.7f * ImGui::GetIO().DeltaTime;
                            if (progress >= +1.1f) { progress = +1.1f; Beep(150, 100); tab = 1, content_animation = 0.0f; }
                        }
                    }
                    ImGui::EndChild(); 

                    ImGui::PushFont(big_icon);
                    ImGui::SetCursorPos(ImVec2((((WINDOW_WIDTH / 2) + (WINDOW_WIDTH / 4)) - 365) * dpi_scale, (((WINDOW_HEIGHT / 2) + (WINDOW_HEIGHT / 4)) + 30)* dpi_scale));
                    ImGui::TextColored(ImColor(0,0,0), (cheat_icon_symbol));
                    if (ImGui::IsItemHovered())
                    {
                        MouseCur(7);
                        if (ImGui::IsItemClicked())
                        {
                            Sleep(30);
                            if (GetAsyncKeyState(VK_LBUTTON)) { system("start https://domain.com/"); }
                        }
                    }
                    ImGui::PopFont();
                    ImGui::SetCursorPos(ImVec2((((WINDOW_WIDTH / 2) + (WINDOW_WIDTH / 4)) + 75) * dpi_scale, (((WINDOW_HEIGHT / 2) + (WINDOW_HEIGHT / 4)) + 25) * dpi_scale));
                    ImGui::Image(DiscordLogo, ImVec2(36, 36));
                    if (ImGui::IsItemHovered())
                    {                        
                        MouseCur(7);
                        if (ImGui::IsItemClicked())
                        {
                            Sleep(30);
                            if (GetAsyncKeyState(VK_LBUTTON)) { system("start https://discord.gg/domain/"); }
                        }
                    }
                   

                    ImGui::PopStyleVar();
                }
                else if (tab == 1) {
                    time_t currtime;
                    struct tm* tminfo;
                    time(&currtime);
                    tminfo = localtime(&currtime);

                    std::time_t x = std::mktime(tminfo);
                    std::time_t y = std::mktime(&KeyAuthApp.user_data.expiry);
                    double difference;
                    if (x != (std::time_t)(-1) && y != (std::time_t)(-1))
                    {
                        difference = std::difftime(y, x) / (60 * 60 * 24);
                    }
                    std::string LisansinKalanZamani = std::to_string((int)difference) + " Days";

                    if (difference > 3000)
                        LisansinKalanZamani = "Omur Boyu\n\n\n";

                    
                    draw->AddText(tab_title, 17.0f, ImVec2(pos.x + size.x / 2 - ImGui::CalcTextSize("Panel").x / 2 - 10, pos.y + 45 * content_animation), ImColor(0.8f, 0.8f, 0.8f, content_animation), "Panel");
                   
                    draw->AddText(ImVec2(pos.x + 143, pos.y + size.y - 22), ImColor(accent_colour[0], accent_colour[1], accent_colour[2], content_animation), LisansinKalanZamani.c_str());
                    ImGui::SameLine();
                    draw->AddText(ImVec2(pos.x + 9, pos.y + size.y - 22), ImColor(0.8f, 0.8f, 0.8f, content_animation), "Lisansin Kalan Suresi:       ");


                    ImGui::SetCursorPos(ImVec2(size.x - 32 * dpi_scale, size.y - 32 * dpi_scale));
                    ImGui::PushFont(icon);
                    if (ImGui::Button("P", ImVec2(25 * dpi_scale, 25 * dpi_scale))) tab = 0, content_animation = 0.0f; animate = false; progress = 0.0f;
                    ImGui::PopFont();

                    ImGui::SetCursorPos(ImVec2(size.x - 123 * dpi_scale, size.y - 32 * dpi_scale));
                    if (ImGui::Button("Baslat", ImVec2(85 * dpi_scale, 25 * dpi_scale)))
                    {
                        if (game == 0)
                        {
                            std::string Rust = (("BURAYA INDIRME LINKI KOYUN"));
                            std::string RustKonum = (("C:\\Windows\\System\\RustCheat.exe"));
                            URLDownloadToFileA(NULL, Rust.c_str(), RustKonum.c_str(), 0, NULL);
                            Sleep(900);
                            ::ShowWindow(FindWindowA(0, "domain.com"), SW_HIDE);
                            Sleep(500);
                            system(("C:\\Windows\\System\\RustCheat.exe >nul 2>&1"));
                            Sleep(500);
                            exit(0);
                        }
                        if (game == 1)
                        {   
                            std::string Deadside = (("BURAYA INDIRME LINKI KOYUN"));
                            std::string DeadsideKonum = (("C:\\Windows\\System\\Deadside.exe"));
                            URLDownloadToFileA(NULL, Deadside.c_str(), DeadsideKonum.c_str(), 0, NULL);
                            Sleep(900);
                            ::ShowWindow(FindWindowA(0, "domain.com"), SW_HIDE);
                            Sleep(500);
                            system(("C:\\Windows\\System\\Deadside.exe >nul 2>&1"));
                            Sleep(500);
                            exit(0);
                        }
                        if (game == 2)
                        {

                        }
                        if (game == 3)
                        {

                        }
                      
                    }
                    ImGui::SetCursorPos(ImVec2(size.x - 123 * dpi_scale, size.y - 57 * dpi_scale));
                    if (ImGui::Button("Lisansi Kaydet", ImVec2(115 * dpi_scale, 20 * dpi_scale)))
                    {
                        if (game == 0)
                        {
                            remove(RustLisansKonum.c_str());
                            std::ofstream key2; key2.open(RustLisansKonum.c_str());
                            key2 << RustKey;
                            key2.close();
                        }
                        if (game == 1)
                        {
                            remove(DeadSideLisansKonum.c_str());
                            std::ofstream key2; key2.open(DeadSideLisansKonum.c_str());
                            key2 << DeadSide;
                            key2.close();
                        }
                        if (game == 2)
                        {
                            remove(ValorantLisansKonum.c_str());
                            std::ofstream key2; key2.open(ValorantLisansKonum.c_str());
                            key2 << ValoKey;
                            key2.close();
                        }
                        if (game == 3)
                        {
                            remove(ApexLisansKonum.c_str());
                            std::ofstream key2; key2.open(ApexLisansKonum.c_str());
                            key2 << ApexKey;
                            key2.close();
                        }
                        kaydetmebasarili = true;
                    }


                    if (game == 0)
                    {
                        ImGui::SetCursorPos(ImVec2(120 * dpi_scale, 85 * content_animation));
                        ImGui::Image(RustLogo, ImVec2(40, 40));
                        if (ImGui::IsItemHovered())
                        {
                            ImGui::BeginTooltip();
                            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                            ImGui::TextUnformatted("Rust Logo");
                            ImGui::PopTextWrapPos();
                            ImGui::EndTooltip();
                        }
                    }          
                    if (game == 1)
                    {
                        ImGui::SetCursorPos(ImVec2(120 * dpi_scale, 85 * content_animation));
                        ImGui::Image(DeadSideLogo, ImVec2(40, 40));
                        if (ImGui::IsItemHovered())
                        {
                            ImGui::BeginTooltip();
                            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                            ImGui::TextUnformatted("DeadSide Logo");
                            ImGui::PopTextWrapPos();
                            ImGui::EndTooltip();
                        }
                    }
                    if (game == 2)
                    {
                        ImGui::SetCursorPos(ImVec2(120 * dpi_scale, 85 * content_animation));
                        ImGui::Image(ValorantLogo, ImVec2(40, 40));
                        if (ImGui::IsItemHovered())
                        {
                            ImGui::BeginTooltip();
                            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                            ImGui::TextUnformatted("Valorant Logo");
                            ImGui::PopTextWrapPos();
                            ImGui::EndTooltip();
                        }
                    }
                    if (game == 3)
                    {
                        ImGui::SetCursorPos(ImVec2(120 * dpi_scale, 85 * content_animation));
                        ImGui::Image(ApexLegendsLogo, ImVec2(40, 40));
                        if (ImGui::IsItemHovered())
                        {
                            ImGui::BeginTooltip();
                            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                            ImGui::TextUnformatted("Apex Legends Logo");
                            ImGui::PopTextWrapPos();
                            ImGui::EndTooltip();
                        }
                    }
                    ImGui::SetCursorPos(ImVec2(155 * dpi_scale, 85 * content_animation));
                    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, content_animation);
                    ImGui::BeginChild("##Panel", ImVec2(size.x / 2 + 40, size.y - 140));
                    {
                        ImGui::Combo("Bir oyun sec", &game, games_list, IM_ARRAYSIZE(games_list));
                        if (game == 0)
                        {
                            ImGui::InputText("Rust lisans", RustKey, sizeof(RustKey), ImGuiInputTextFlags_Password);
                        }
                        if (game == 1)
                        {
                            ImGui::InputText("DeadSide lisans", DeadSide, sizeof(DeadSide), ImGuiInputTextFlags_Password);
                        }
                        if (game == 2)
                        {
                            ImGui::InputText("Valorant lisans", ValoKey, sizeof(ValoKey), ImGuiInputTextFlags_Password);
                        }
                        if (game == 3)
                        {
                            ImGui::InputText("Apex lisans", ApexKey, sizeof(ApexKey), ImGuiInputTextFlags_Password);
                        }

                         
                    }
                    ImGui::EndChild();
                    ImGui::PopStyleVar();
                }
                else if (tab == 2) {
                draw->AddText(tab_title, 17.0f, ImVec2(pos.x + size.x / 2 - ImGui::CalcTextSize("Ayarlar").x / 2, pos.y + 45 * content_animation), ImColor(0.8f, 0.8f, 0.8f, content_animation), "Ayarlar");

                ImGui::SetCursorPos(ImVec2(155 * dpi_scale, 85 * content_animation));

                ImGui::PushStyleVar(ImGuiStyleVar_Alpha, content_animation);
                ImGui::BeginChild("##settings_content", ImVec2(size.x / 2 - 40, size.y - 140));
                {
                    ImGui::Checkbox("Yenieme tusu F5", &update_on_f5);
                    ImGui::SliderFloat("Pencere boyutu", &dpi_scale, 1.0f, 1.5f, "%.3f", ImGuiSliderFlags_NoInput);
                    ImGui::Text("Tema Rengi"); ImGui::SameLine(); ImGui::ColorEdit4("##accent_colour", accent_colour, NO_ALPHA);
                    ImGui::SameLine();
                    if (ImGui::Button("Rengi Sifirla##reset", ImVec2(60 * dpi_scale, 18))) {
                        accent_colour[0] = { 173 / 255.f };
                        accent_colour[1] = { 57 / 255.f };
                        accent_colour[2] = { 57 / 255.f };
                    }
                }
                ImGui::EndChild();

                ImGui::SetCursorPos(ImVec2(size.x - 32 * dpi_scale, size.y - 32 * dpi_scale));
                ImGui::PushFont(icon);
                if (ImGui::Button("P", ImVec2(25 * dpi_scale, 25 * dpi_scale))) tab = 0, content_animation = 0.0f; animate = false; progress = 0.0f;
                ImGui::PopFont();

                ImGui::PopStyleVar();
            }
            }
            ImGui::End();
        }
        ImGui::EndFrame();

        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }


        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);


        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        if (!loader_active) {
            msg.message = WM_QUIT;
        }
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(main_hwnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

int main()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    WinMain(0, 0, 0, 0);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
