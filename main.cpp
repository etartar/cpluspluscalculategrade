#include <iostream>
#include <fstream>

using namespace std;
int calculateGrade(int value, int *grade);
void writeGrade(int *grade);

int main()
{
    // infile is a variable name
    // j deðiþkeni sýnava girmeyen öðrenciler
    // k deðiþkeni sýnava giren öðrenciler
    // l deðiþkeni toplam not sayýsý
    int i = 0, j = 0, k = 0, l=0;
    int grades [12] = {};
    //
    ifstream infile("midterm.txt");
    while(infile >> i) {
        if(i == 0) {
            j++;
        } else {
            k++;
            calculateGrade(i, grades);
        }
        l +=i;
    }

    writeGrade(grades);
    cout << "Students : " << j+k << " = " << k << "+" << j << endl;
    cout << "Average of Grades : " << (float)l/(float)k << endl;

    return 0;
}

int calculateGrade(int getValue, int *grade) {
    if(getValue >= 0 && getValue < 10) {
        grade[1]++;
    } else if(getValue >= 10 && getValue < 20) {
        grade[2]++;
    } else if(getValue >= 20 && getValue < 30) {
        grade[3]++;
    } else if(getValue >= 30 && getValue < 40) {
        grade[4]++;
    } else if(getValue >= 40 && getValue < 50) {
        grade[5]++;
    } else if(getValue >= 50 && getValue < 60) {
        grade[6]++;
    } else if(getValue >= 60 && getValue < 70) {
        grade[7]++;
    } else if(getValue >= 70 && getValue < 80) {
        grade[8]++;
    } else if(getValue >= 80 && getValue < 90) {
        grade[9]++;
    } else if(getValue >= 90 && getValue < 100) {
        grade[10]++;
    } else {
        grade[11]++;
    }
}

void writeGrade(int *value) {
    int a, b;
    for(a = 45; a > 0; a--) {
        if(a > 9) { cout << a << " | "; } else { cout << "0" << a << " | "; }
        for(b = 1; b < 12; b++) {
            if(a <= value[b]) { cout << " ####" ; } else { cout << "     "; }
        }
        cout << "" << endl;
    }
    cout << "############################################################" << endl;
    cout << "       <10  <20  <30  <40  <50  <60  <70  <80  <90 <100  100" << endl;
}
