/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: longnumber.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
ONLY INCLUDE HERE. YOU CANNOT ADD ANYTHING HERE
-----------------------------------------------------------------*/
#include "longnumber.h"

longnumber::~longnumber() {
    free_();
}

longnumber::longnumber(const int n) {
    num_2_String_(n);
}

longnumber::longnumber(const char* a) {
    int n = int(strlen(a));
    assert(n);
    int i = 0;
    if (a[i] == '+') {
        assert(n > 1);
        sign_ = true;
        i++;
    }
    else if (a[i] == '-') {
        assert(n > 1);
        sign_ = false;
        i++;
    }
    bool readZero = false;
    for (i; i < n; i++) {
        assert(a[i] >= '0' && a[i] <= '9');
        if (a[i] == '0') {
            if (readZero == false) {
                readZero = true;
            }
        }
        else if ((a[i] != '0')) {
            break;
        }
    }
    int d = n - i + 1;
    if (readZero && d == 1){
        sign_ = true;
        allocate_(2);
        s_[0] = '0';
        s_[1] = '\0';
    }
    else {
        allocate_(d);
        int j = 0;
        for (i; i < n; i++) {
            assert(a[i] >= '0' && a[i] <= '9');
            s_[j++] = a[i];
        }
        assert(j == d  - 1);
        s_[j] = '\0';
    }
}

ostream& operator<<(ostream& o, const longnumber& l) {
    const int EOLNAT = 40;
    int size = l.num_digits();
    if (l.is_negative()) {
        cout << "-";
    }
    int j = 0;
    for (int i = 0; i < size; i++, j++) {
        if (j == EOLNAT) {
            j = 0;
            o << endl;
        }
        o << l[i];
    }
    return o;
}

bool operator ==(const longnumber& a, const longnumber& b) {
    if (a.sign_ == b.sign_) {
        if (a.num_digits() == b.num_digits()) {
            for (int i = 0; i < a.num_digits(); i++) {
                if (a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

bool operator !=(const longnumber& a, const longnumber& b) {
    return !(a == b);
}

longnumber operator +(const longnumber& a, const longnumber& b) {
    assert(a.is_positive());
    assert(b.is_positive());
    if (a == 0) {
        return b;
    }
    else if (b == 0) {
        return a;
    }
    int space = a.num_digits();
    if (b.num_digits() > space) {
        space = b.num_digits();
    }
    space = space + 1 + 1;
    longnumber c(0);
    c.reserve_(space);
    int al = a.num_digits() - 1;
    int bl = b.num_digits() - 1;
    int max = al;
    if (bl > max) {
        max = bl;
    }
    int z = 0;
    int k = 0;
    for (int i = max; i >= 0; i--) {
        int x = 0;
        if (al >= 0) {
            x = a[al--] - '0';
        }
        int y = 0;
        if (bl >= 0) {
            y = b[bl--] - '0';
        }
        int t = x + y + z;
        assert(t >= 0 && t <= 19);
        if (t < 10) {
            c.insert_at_pos_(t, space, k++);
            z = 0;
        }
        else {
            c.insert_at_pos_(t - 10, space, k++);
            z = 1;
        }
    }
    if (z == 1) {
        c.insert_at_pos_(1, space, k++);
    }
    assert(k < space);
    c[k] = '\0';
    c.reverse_();
    return c;
}

longnumber operator *(const longnumber& a, const int b) {
    assert(a.is_positive());
    if (a == 0 || (b == 0)) {
        return 0;
    }
    longnumber ans(a);
    int x = b;
    if (b < 0) {
        x = -b;
    }
    for (int i = 1; i < x; i++) {
        ans = ans + a;
    }
    if (x != b) {
        ans.change_sign(false);
    }
    return ans;
}

longnumber longnumber::fact(const int n) {
    longnumber a(1);
    for (int i = 2; i <= n; i++) {
        a = a * i;
    }
    return a;
}

void longnumber::insert_at_pos_(char c, int space, int pos) {
    longnumber& a = *(this);
    assert(pos >= 0 && pos < space);
    a[pos] = c;
}

void longnumber::insert_at_pos_(int i, int space, int pos) {
    assert(i >= 0 && i < 10);
    char c = i + '0';
    insert_at_pos_(c, space, pos);
}

void longnumber::num_2_String_(int n) {
    int s = 0;
    char a[100] = { 0 };
    sign_ = true;
    if (n < 0) {
        sign_ = false;
        n = -n;
    }
    do {
        a[s++] = n % 10 + '0';
        n = n / 10;
    } while (n);
    a[s] = '\0';
    for (int i = 0; i < s / 2; i++) {
        char t = a[i];
        a[i] = a[s - i - 1];
        a[s - i - 1] = t;
    }
    allocate_(s + 1);
    strcpy(s_, a);
}

void longnumber::reverse_() {
    longnumber& a = *(this);
    int n = a.num_digits();
    for (int i = 0; i < n / 2; i++) {
        char t = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = t;
    }
}
//EOF


