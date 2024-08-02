#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream input_file;
    input_file.open("alter.in");
    
    long long rows, columns;
    input_file >> rows >> columns;

    ofstream outfile;
    outfile.open("alter.out");

    outfile << (columns / 2) + (rows / 2) << '\n';

    for (int row = 2; row <= rows; row += 2)
        outfile << row << ' ' << 1 << ' ' << row << ' ' << columns << '\n';
    for (int column = 2; column <= columns; column += 2)
        outfile << 1 << ' ' << column << ' ' << rows << ' ' << column << '\n';
    
    input_file.close();
    outfile.close();
    return 0;
}
