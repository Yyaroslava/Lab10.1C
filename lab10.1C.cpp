// ���� ��������� ���� t.  
// ��������, �� � ����� ��� ������� ���� ����� ���� "aa" ��� "bb" ��� "cc"(�������� � ������ �������).
// C

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>

using namespace std; 

bool Find(FILE* f);

int main() {
    FILE* f;
    // ��������� ���� ��� �������
    if (fopen_s(&f, "t.txt", "r") != 0) {
        cerr << "Error opening file 't.txt'" << endl;
        exit(1);
    }
        
    bool found = Find(f);
    if (found) {
        cout << "Pairs 'aa' or 'bb' or 'cc' were found successfully." << endl;
    }
    else {
        cout << "Pairs 'aa' or 'bb' or 'cc' were NOT found." << endl;
    }

    fclose(f);

    return 0;
}

bool Find(FILE *f) {
    char p = 0;
    char c;
    do {
        // ������ �� ������ ������� � ����� "t"
        c = getc(f);
        if (c == 'a' && p == 'a') return true;
        if (c == 'b' && p == 'b') return true;
        if (c == 'c' && p == 'c') return true;
        p = c;
    }
    while (c != EOF);
    return false;
}
