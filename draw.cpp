
#include "hack.h"

static void fill_rect(int x, int y, int width, int height, DWORD color, LPDIRECT3DDEVICE8 device) {
    // Assemble the rectangle.
    D3DRECT rect = { x, x + width, y, y + height };

    // Draw the rectangle.
    device->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
}

static int draw_char_a(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     2, 1, color, device);
    fill_rect(x + 1, y + 3, 2, 1, color, device);
    fill_rect(x + 3, y,     1, 7, color, device);

    return 5;
}

static int draw_char_b(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     2, 1, color, device);
    fill_rect(x + 1, y + 3, 2, 1, color, device);
    fill_rect(x + 1, y + 6, 2, 1, color, device);
    fill_rect(x + 3, y,     1, 7, color, device);

    return 5;
}

static int draw_char_c(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     3, 1, color, device);
    fill_rect(x + 1, y + 6, 3, 1, color, device);

    return 5;
}

static int draw_char_d(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     2, 1, color, device);
    fill_rect(x + 1, y + 6, 2, 1, color, device);
    fill_rect(x + 3, y + 1, 1, 5, color, device);

    return 5;
}

static int draw_char_e(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     3, 1, color, device);
    fill_rect(x + 1, y + 3, 3, 1, color, device);
    fill_rect(x + 1, y + 6, 3, 1, color, device);

    return 5;
}

static int draw_char_f(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     3, 1, color, device);
    fill_rect(x + 1, y + 3, 3, 1, color, device);

    return 5;
}

static int draw_char_g(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     3, 1, color, device);
    fill_rect(x + 2, y + 3, 2, 1, color, device);
    fill_rect(x + 1, y + 6, 3, 1, color, device);
    fill_rect(x + 3, y + 4, 1, 2, color, device);

    return 5;
}

static int draw_char_h(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y + 3, 2, 1, color, device);
    fill_rect(x + 3, y,     1, 5, color, device);

    return 5;
}

static int draw_char_i(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 2, 7, 0xFF000000, device);

    fill_rect(x, y, 1, 7, color, device);

    return 2;
}

static int draw_char_j(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         3, 1, color, device);
    fill_rect(x + 2, y + 1, 1, 5, color, device);
    fill_rect(x, y + 6,     3, 1, color, device);

    return 5;
}

static int draw_char_k(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y + 3, 1, 1, color, device);
    fill_rect(x + 2, y + 2, 1, 1, color, device);
    fill_rect(x + 4, y,     1, 1, color, device);
    fill_rect(x + 2, y + 4, 1, 1, color, device);
    fill_rect(x + 3, y + 5, 1, 1, color, device);
    fill_rect(x + 4, y + 6, 1, 1, color, device);

    return 6;
}

static int draw_char_l(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y + 6, 3, 1, color, device);

    return 5;
}

static int draw_char_m(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y + 1, 1, 1, color, device);
    fill_rect(x + 2, y + 2, 1, 1, color, device);
    fill_rect(x + 3, y + 1, 1, 1, color, device);
    fill_rect(x + 4, y,     1, 7, color, device);

    return 6;
}

static int draw_char_n(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     1, 2, color, device);
    fill_rect(x + 2, y + 2, 1, 2, color, device);
    fill_rect(x + 3, y + 4, 1, 3, color, device);
    fill_rect(x + 4, y,     1, 7, color, device);

    return 6;
}

static int draw_char_o(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     2, 1, color, device);
    fill_rect(x + 1, y + 6, 2, 1, color, device);
    fill_rect(x + 3, y,     1, 7, color, device);

    return 5;
}

static int draw_char_p(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     3, 1, color, device);
    fill_rect(x + 1, y + 3, 3, 1, color, device);
    fill_rect(x + 4, y + 1, 1, 2, color, device);

    return 6;
}

static int draw_char_q(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     2, 1, color, device);
    fill_rect(x + 1, y + 6, 2, 1, color, device);
    fill_rect(x + 3, y,     1, 7, color, device);
    fill_rect(x + 2, y + 5, 1, 1, color, device);
    fill_rect(x + 4, y + 6, 1, 1, color, device);

    return 6;
}

static int draw_char_r(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y,     3, 1, color, device);
    fill_rect(x + 1, y + 3, 3, 1, color, device);
    fill_rect(x + 4, y + 1, 1, 2, color, device);
    fill_rect(x + 2, y + 4, 1, 1, color, device);
    fill_rect(x + 3, y + 5, 1, 2, color, device);
    fill_rect(x + 4, y + 6, 1, 1, color, device);

    return 6;
}

static int draw_char_s(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,     4, 1, color, device);
    fill_rect(x, y + 3, 4, 1, color, device);
    fill_rect(x, y + 6, 4, 1, color, device);

    fill_rect(x,     y + 1, 1, 2, color, device);
    fill_rect(x + 3, y + 4, 1, 2, color, device);

    return 5;
}

static int draw_char_t(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         5, 1, color, device);
    fill_rect(x + 2, y + 1, 1, 6, color, device);

    return 6;
}

static int draw_char_u(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 1, y + 6, 2, 1, color, device);
    fill_rect(x + 3, y,     1, 7, color, device);

    return 5;
}

static int draw_char_v(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 5, color, device);
    fill_rect(x + 1, y + 5, 1, 1, color, device);
    fill_rect(x + 2, y + 6, 1, 1, color, device);
    fill_rect(x + 3, y + 5, 1, 1, color, device);
    fill_rect(x + 4, y,     1, 5, color, device);

    return 6;
}

static int draw_char_w(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 6, color, device);
    fill_rect(x + 4, y,     1, 6, color, device);
    fill_rect(x + 2, y + 4, 1, 2, color, device);
    fill_rect(x + 1, y + 6, 3, 1, color, device);

    return 6;
}

static int draw_char_x(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 7, color, device);
    fill_rect(x + 4, y,     2, 1, color, device);
    fill_rect(x,     y + 6, 2, 1, color, device);
    fill_rect(x + 4, y + 1, 1, 5, color, device);
    fill_rect(x + 1, y,     1, 7, color, device);
    fill_rect(x + 3, y,     2, 1, color, device);
    fill_rect(x + 1, y + 4, 2, 1, color, device);
    fill_rect(x + 3, y + 4, 1, 5, color, device);
    fill_rect(x + 2, y + 3, 1, 1, color, device);

    return 6;
}

static int draw_char_y(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 6, 7, 0xFF000000, device);

    fill_rect(x, y,         1, 1, color, device);
    fill_rect(x + 1, y + 1, 1, 1, color, device);
    fill_rect(x + 4, y,     1, 1, color, device);
    fill_rect(x + 3, y + 1, 1, 1, color, device);
    fill_rect(x + 2, y + 2, 1, 5, color, device);

    return 6;
}

static int draw_char_z(int x, int y, DWORD color, LPDIRECT3DDEVICE8 device) {
    fill_rect(x, y, 5, 7, 0xFF000000, device);

    fill_rect(x,     y,     4, 1, color, device);
    fill_rect(x + 3, y + 1, 1, 2, color, device);
    fill_rect(x,     y + 4, 1, 2, color, device);
    fill_rect(x + 1, y + 3, 2, 1, color, device);
    fill_rect(x,     y + 6, 4, 1, color, device);

    return 5;
}

static void draw_text(int x, int y, const char* text, LPDIRECT3DDEVICE8 device) {
    int skip_count = 0;
    for (int i = 0; i < strlen(text); ++i) {
        switch (tolower(text[i])) {
            case ' ': {
                fill_rect(x + skip_count, y, 5, 7, 0xFF000000, device);
                skip_count += 5;
            } break;
            case 'a': {
                skip_count += draw_char_a(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'b': {
                skip_count += draw_char_b(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'c': {
                skip_count += draw_char_c(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'd': {
                skip_count += draw_char_d(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'e': {
                skip_count += draw_char_e(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'f': {
                skip_count += draw_char_f(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'g': {
                skip_count += draw_char_g(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'h': {
                skip_count += draw_char_h(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'i': {
                skip_count += draw_char_i(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'j': {
                skip_count += draw_char_j(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'k': {
                skip_count += draw_char_k(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'l': {
                skip_count += draw_char_l(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'm': {
                skip_count += draw_char_m(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'n': {
                skip_count += draw_char_n(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'o': {
                skip_count += draw_char_o(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'p': {
                skip_count += draw_char_p(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'q': {
                skip_count += draw_char_q(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'r': {
                skip_count += draw_char_r(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 's': {
                skip_count += draw_char_s(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 't': {
                skip_count += draw_char_t(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'u': {
                skip_count += draw_char_u(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'v': {
                skip_count += draw_char_v(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'w': {
                skip_count += draw_char_w(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'x': {
                skip_count += draw_char_x(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'y': {
                skip_count += draw_char_y(x + skip_count, y, 0xFFFFFF00, device);
            } break;
            case 'z': {
                skip_count += draw_char_z(x + skip_count, y, 0xFFFFFF00, device);
            } break;
        }
    }
}
